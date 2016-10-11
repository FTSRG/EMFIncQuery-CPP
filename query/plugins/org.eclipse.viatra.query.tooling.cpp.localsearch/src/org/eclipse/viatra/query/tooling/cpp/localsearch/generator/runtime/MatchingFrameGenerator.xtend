/*******************************************************************************
 * Copyright (c) 2014-2016 Robert Doczi, IncQuery Labs Ltd.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     Robert Doczi - initial API and implementation
 *******************************************************************************/
package org.eclipse.viatra.query.tooling.cpp.localsearch.generator.runtime

import org.eclipse.emf.ecore.EClass
import org.eclipse.emf.ecore.EDataType
import org.eclipse.viatra.query.runtime.matchers.psystem.PVariable
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.ViatraQueryHeaderGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common.Include
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.MatchingFrameDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.proto.ProtobufHelper
import org.eclipse.viatra.query.tooling.cpp.localsearch.util.generators.CppHelper
import org.eclipse.xtend.lib.annotations.Accessors

/**
 * @author Robert Doczi
 */
class MatchingFrameGenerator extends ViatraQueryHeaderGenerator {

	val String queryName
	val String patternName
	@Accessors val MatchingFrameDescriptor matchingFrame
	@Accessors val int index
	
	new(String queryName, String patternName, int index, MatchingFrameDescriptor matchingFrame) {
		super(#{queryName}, '''«patternName.toFirstUpper»Frame_«index»''')
		this.queryName = queryName
		this.patternName = patternName
		this.matchingFrame = matchingFrame
		this.index = index
	}

	override initialize() {
		includes += matchingFrame.allTypes.map[looseType].map[
			switch it {
				EClass: Include::fromEClass(it)
				EDataType: if(it.name.toLowerCase.contains("string")) new Include("string", true)
				default: null
			}
		].filterNull
		includes += new Include("stdint.h", true);
		includes += new Include("vector", true);
		includes += new Include("proto_gen.pb.h", false);		
	}

	override compileInner() '''
		
		class «unitName»Vector;
	
		struct «unitName» {
			
			using PBFrame = PB_«unitName»;
			using FrameVector = «unitName»Vector;
			
			«FOR param : matchingFrame.allVariables.sortBy[matchingFrame.getVariablePosition(it)]»
				«val type = matchingFrame.getVariableLooseType(param)»
				«IF type instanceof EClass»
					«val typeFQN = CppHelper::getTypeHelper(type).FQN»
					«val pos = matchingFrame.getVariablePosition(param)»
					«typeFQN»* «pos.variableName»;
				«ELSEIF type instanceof EDataType»
					«val typeFQN = CppHelper::getTypeHelper(type).FQN»
					«val pos = matchingFrame.getVariablePosition(param)»
					«typeFQN» «pos.variableName»;
				«ENDIF»
			«ENDFOR»
		
			«generateFrameSerialization»
		};
				
		class «unitName»Vector 
			: private std::vector<«unitName»>
		{
			public:
			«FOR using : #["push_back", "clear", "empty", "size", "begin", "end" ]»
				using std::vector<«unitName»>::«using»;
			«ENDFOR»
			
			«generateFrameVectorSerialization»
		};
		
	'''
	
	def generateFrameSerialization() '''
		// Serialization and deserialization
		
		std::string SerializeAsString()
		{
			PB_«unitName» pbframe;
			
			«FOR param : matchingFrame.allVariables.sortBy[matchingFrame.getVariablePosition(it)]»
				«val type = matchingFrame.getVariableLooseType(param)»
				«val varName = matchingFrame.getVariablePosition(param).variableName.toString»
				«ProtobufHelper::setProtobufVar("pbframe", "", varName, type)»
			«ENDFOR»

			return pbframe.SerializeAsString();
		}
	
		template<typename ModelRoot>
		void ParseFromString(std::string str, ModelRoot *mr)
		{
			PB_«unitName» pbframe;
			pbframe.ParseFromString(str);
	
			«FOR param : matchingFrame.allVariables.sortBy[matchingFrame.getVariablePosition(it)]»
				«val type = matchingFrame.getVariableLooseType(param)»
				«val name = param.variableName.toString»
				«ProtobufHelper::setVarFromProtobuf(type, name ,"pbframe", "mr")»
			«ENDFOR»
		}
		'''


	def generateFrameVectorSerialization() '''
		// Serialization and deserialization
		
		template<typename ModelRoot, typename Action>
		static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
		{
			PB_«unitName»Vector pbFrameVector;
			pbFrameVector.ParseFromString(serialized_data);
			
			«unitName» frame;
			for (auto & pbFrame : pbFrameVector.frames())
			{
				«FOR param : matchingFrame.allVariables.sortBy[matchingFrame.getVariablePosition(it)]»
					«val type = matchingFrame.getVariableLooseType(param)»
					«val varName = param.variableName.toString»
					frame.«ProtobufHelper::setVarFromProtobuf(type, varName ,"pbFrame", "mr")»
				«ENDFOR»
				
				action(frame);
			}
		}
		
		std::string SerializeAsString()
		{
			PB_«unitName»Vector pbFrameVector;
			
			for(auto& storedVector: *this){
				auto & pbFrame= *pbFrameVector.add_frames();
				«FOR param : matchingFrame.allVariables.sortBy[matchingFrame.getVariablePosition(it)]»
					«val type = matchingFrame.getVariableLooseType(param)»
					«val varName = param.variableName.toString»
					«ProtobufHelper::setProtobufVar("pbFrame", "storedVector.", varName, type)»
				«ENDFOR»
			}
			return pbFrameVector.SerializeAsString();
		}
	'''
	

	def getVariableName(PVariable variable) {
		getVariableName(matchingFrame.getVariablePosition(variable))
	}
	
	def getFrameName() {
		unitName
	}

	private def getVariableName(int position) '''_«position»'''

}