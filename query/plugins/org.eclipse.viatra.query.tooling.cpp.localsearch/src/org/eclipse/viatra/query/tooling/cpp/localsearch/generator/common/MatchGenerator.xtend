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
package org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common

import org.eclipse.emf.ecore.EClass
import org.eclipse.emf.ecore.EDataType
import org.eclipse.emf.ecore.impl.EEnumImpl
import org.eclipse.viatra.query.runtime.matchers.psystem.queries.PParameter
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.ViatraQueryHeaderGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.MatchingFrameDescriptor
import com.google.common.collect.ImmutableList
import org.eclipse.viatra.query.tooling.cpp.localsearch.proto.ProtobufHelper
import org.eclipse.xtend.lib.annotations.Accessors
import org.eclipse.emf.ecore.EEnum

/**
 * @author Robert Doczi
 */
class MatchGenerator extends ViatraQueryHeaderGenerator {

	val String queryName
	val String patternName
	
	// Accessing outside can be wrong because a pattern can have multiple matching frames
	@Accessors(PUBLIC_GETTER) 
	val MatchingFrameDescriptor oneOfTheMatchingFrames

	new(String queryName, String patternName, MatchingFrameDescriptor oneOfTheMatchingFrames) {
		super(#{queryName}, '''«patternName.toFirstUpper»Match''')
		this.queryName = queryName
		this.patternName = patternName
		this.oneOfTheMatchingFrames = oneOfTheMatchingFrames

	}

	override initialize() {
		includes += oneOfTheMatchingFrames.allTypes.map[strictType].map[
			switch it {
				EClass: Include::fromEClass(it)
				EDataType: if(it.name.toLowerCase.contains("string")) new Include("string", true)
				default: null
			}
		].filterNull
		includes += new Include("stdint.h", true);
		includes += new Include("proto_gen.pb.h", false);
		includes += new Include("Viatra/Query/MatchSet.h", false);
	}

	override compileInner() '''	
		class «unitName»Set;
		
		struct «unitName» {
			
			using MatchSet = «unitName»Set;
			
			«fields(oneOfTheMatchingFrames.parameters)»
			
			«equals(oneOfTheMatchingFrames.parameters)»
			
			«serializationOfMatch(oneOfTheMatchingFrames.parameters)»
		};

		«closeNamespaces»
		
		«hash(oneOfTheMatchingFrames.parameters)»
		
		«openNamespaces»
		
				
		class «unitName»Set 
			: public Viatra::Query::MatchSet
			, private std::unordered_set<«unitName»>
		{
			public:
			«FOR using : #["insert", "clear", "empty", "size", "begin", "end" ]»
				using std::unordered_set<«unitName»>::«using»;
			«ENDFOR»
			
			«serializationOfMatchSet(oneOfTheMatchingFrames.parameters)»
		};
	'''
	
	def serializationOfMatch(ImmutableList<PParameter> paramlist) '''
		// Serialization and deserialization
		
		std::string SerializeAsString()
		{
			PB_«unitName» pbMatch;
			
			«FOR param : paramlist»
				«val type = oneOfTheMatchingFrames.getVariableStrictType(oneOfTheMatchingFrames.getVariableFromParameter(param))»
				«val varName = param.name»
				«ProtobufHelper::setProtobufVar("pbMatch", "", varName, type)»
			«ENDFOR»
			
			return pbMatch.SerializeAsString();
		}
		
		template<typename ModelRoot>
		void ParseFromString(std::string str, ModelRoot *mr)
		{
			PB_«unitName» pbMatch;
			pbMatch.ParseFromString(str);
				
			«FOR param : paramlist»
				«val type = oneOfTheMatchingFrames.getVariableStrictType(oneOfTheMatchingFrames.getVariableFromParameter(param))»
				«val varName = param.name»
				«ProtobufHelper::setVarFromProtobuf(type, varName ,"pbMatch", "mr")»
			«ENDFOR»
		}
		'''
		
		def serializationOfMatchSet(ImmutableList<PParameter> paramlist) '''
		
		// Serialization and deserialization
		
		template<typename ModelRoot, typename Action>
		static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
		{
			PB_«unitName»Set pbMsgSet;
			pbMsgSet.ParseFromString(serialized_data);
			
			«unitName» match;
			for (auto & pbMatch : pbMsgSet.matches())
			{
				«FOR param : paramlist»
					«val type = oneOfTheMatchingFrames.getVariableStrictType(oneOfTheMatchingFrames.getVariableFromParameter(param))»
					«val varName = param.name»
					match.«ProtobufHelper::setVarFromProtobuf(type, varName ,"pbMatch", "mr")»
				«ENDFOR»
				
				action(match);
			}
		}
		
		std::string SerializeAsString()
		{
			PB_«unitName»Set pbMatchSet;
			
			for(auto& storedMatch: *this){
				auto & pbMatch = *pbMatchSet.add_matches();
				«FOR param : paramlist»
					«val type = oneOfTheMatchingFrames.getVariableStrictType(oneOfTheMatchingFrames.getVariableFromParameter(param))»
					«val varName = param.name»				
					«ProtobufHelper::setProtobufVar("pbMatch", "storedMatch.", varName, type)»
				«ENDFOR»
			}
			return pbMatchSet.SerializeAsString();
		}

	'''
					
	def getMatchName() {
		return unitName
	}
	
	private def fields(Iterable<PParameter> parameters) {
		'''
		«FOR parameter : parameters»
			«val type = oneOfTheMatchingFrames.getVariableStrictType(oneOfTheMatchingFrames.getVariableFromParameter(parameter))»
			«NameUtils::toTypeName(type)» «parameter.name»;
		«ENDFOR»
		'''
	}
	
	private def equals(Iterable<PParameter> parameters) {
		'''
		bool operator==(const «unitName»& other) const {
			return 
				«FOR variable : parameters SEPARATOR "&&"»
					«variable.toEquals»
				«ENDFOR»
			;
		}
		'''
	}
	
	private def toEquals(PParameter variable) {
		'''«variable.name» == other.«variable.name»'''
	}
	
	private def hash(Iterable<PParameter> parameters) {
		'''
		namespace std {
		
		template<> struct hash<«qualifiedName»> {
			size_t operator()(const «qualifiedName»& match) const {
				size_t h = 0;
				«FOR parameter : parameters SEPARATOR "\nh*=31;" »
					h+=«parameter.toHash»;
				«ENDFOR»
				return h;
			}
		};
				
		}
		'''
	}
	
	private def toHash(PParameter parameter){
		val looseType = oneOfTheMatchingFrames.getVariableLooseType(oneOfTheMatchingFrames.getVariableFromParameter(parameter));
		if(looseType instanceof EEnumImpl)
			return '''match.«parameter.name»'''
		else 
			return '''std::hash<decltype(match.«parameter.name»)>()(match.«parameter.name»)'''
	}
}