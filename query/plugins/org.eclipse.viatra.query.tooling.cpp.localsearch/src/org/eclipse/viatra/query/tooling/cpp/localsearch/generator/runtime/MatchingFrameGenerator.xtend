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
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.ViatraQueryHeaderGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common.Include
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.MatchingFrameDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.util.generators.CppHelper
import org.eclipse.viatra.query.runtime.matchers.psystem.PVariable
import org.eclipse.xtend.lib.annotations.Accessors
import org.eclipse.emf.ecore.EEnum
import org.eclipse.viatra.query.tooling.cpp.localsearch.util.generators.TypeHelper

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
		includes += new Include("Viatra/Query/Model/ModelRoot.h", true);
		includes += new Include("proto_gen.pb.h", false);		
	}

	override compileInner() '''
		struct «unitName» {
			
			«FOR param : matchingFrame.allVariables.sortBy[matchingFrame.getVariablePosition(it)]»
				«val type = matchingFrame.getVariableLooseType(param)»
				«IF type instanceof EClass»
					«val typeFQN = CppHelper::getTypeHelper(type).FQN»
					«val pos = matchingFrame.getVariablePosition(param)»
					«typeFQN»* «pos.variableName»;
«««					static «typeFQN»* «pos.getter»(«frameName»& frame) {
«««						return frame.«pos.paramName»;
«««					}
«««					
«««					static void «pos.setter»(«frameName»& frame, «typeFQN»* value) {
«««						frame.«pos.paramName» = value;
«««					}
				«ELSEIF type instanceof EDataType»
					«val typeFQN = CppHelper::getTypeHelper(type).FQN»
					«val pos = matchingFrame.getVariablePosition(param)»
					«typeFQN» «pos.variableName»;
«««					static «typeFQN»& «pos.getter»(«frameName»& frame) {
«««						return frame.«pos.paramName»;
«««					}
«««					
«««					static void «pos.setter»(«frameName»& frame, «typeFQN» value) {
«««						frame.«pos.paramName» = value;
«««					}
				«ENDIF»
			«ENDFOR»
		
			// Serialization and deserialization
			
			std::string SerializeAsString()
			{
				PB_QueryAFrame_0 frame;
				
				«FOR param : matchingFrame.allVariables.sortBy[matchingFrame.getVariablePosition(it)]»
					«val type = matchingFrame.getVariableLooseType(param)»
					«IF type instanceof EClass»
						«val pos = matchingFrame.getVariablePosition(param)»
						frame.set_«pos.variableName»(«pos.variableName» == nullptr ? -1 : «pos.variableName»->id());
					«ELSEIF type instanceof EEnum»
						«val pos = matchingFrame.getVariablePosition(param)»
						frame.set_«pos.variableName»((int32_t)«pos.variableName»);
					«ELSEIF type instanceof EDataType»
						«val pos = matchingFrame.getVariablePosition(param)»
						frame.set_«pos.variableName»(«pos.variableName»);
					«ENDIF»
				«ENDFOR»

				return frame.SerializeAsString();
			}
		
			void ParseFromString(std::string str, Viatra::Query::Model::ModelRoot *mr)
			{
				PB_QueryAFrame_0 pbf;
				pbf.ParseFromString(str);
		
				«FOR param : matchingFrame.allVariables.sortBy[matchingFrame.getVariablePosition(it)]»
					«val type = matchingFrame.getVariableLooseType(param)»
					«IF type instanceof EClass»
						«val typeFQN = CppHelper::getTypeHelper(type).FQN»
						«val pos = matchingFrame.getVariablePosition(param)»
						«pos.variableName» = (pbf.«pos.variableName»() == -1) 
							? nullptr 
							: dynamic_cast<«typeFQN»*>(mr->findModelElementByID(pbf.«pos.variableName»()));
						
					«ELSEIF type instanceof EEnum»
						«val pos = matchingFrame.getVariablePosition(param)»
						«val typeFQN = CppHelper::getTypeHelper(type).FQN»
						«pos.variableName» = («typeFQN»)pbf.«pos.variableName»();
						
					«ELSEIF type instanceof EDataType»
						«val pos = matchingFrame.getVariablePosition(param)»
						«pos.variableName» = pbf.«pos.variableName»();
						
					«ENDIF»
				«ENDFOR»
			}
		};
	'''

	def getVariableName(PVariable variable) {
		getVariableName(matchingFrame.getVariablePosition(variable))
	}
	
	def getFrameName() {
		unitName
	}

	private def getVariableName(int position) '''_«position»'''

}