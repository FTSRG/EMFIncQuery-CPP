package org.eclipse.viatra.query.tooling.cpp.localsearch.proto

import org.eclipse.emf.ecore.EClassifier
import org.eclipse.emf.ecore.EEnum
import org.eclipse.emf.ecore.EClass
import org.eclipse.viatra.query.tooling.cpp.localsearch.util.generators.CppHelper
import org.eclipse.emf.ecore.EDataType

class ProtobufHelper {
	
	static val TYPE_MAPPINGS = #{
		"EString" -> "string",
		"EInt" -> "int32",
		"ELong" -> "int64",
		"EDouble" -> "double",
		"EFloat" -> "float",
		"EShort" -> "int16",
		"EChar" -> "char",
		"EBoolean" -> "bool"
	}
	
	static def protobufType(EClassifier type)
	{
		if(type instanceof EEnum || type instanceof EClass)
			return "int32"
		return TYPE_MAPPINGS.get(type.name);
	}
	
	static def setVarFromProtobuf(EClassifier type, String name, String pbStruct, String modelRoot ) '''
		«val typeFQN = CppHelper::getTypeHelper(type).FQN»
		«IF type instanceof EClass»
			«name» = («pbStruct».«name.toLowerCase»() == -1) 
				? nullptr 
				: dynamic_cast<«typeFQN»*>(«modelRoot»->findModelElementByID(«pbStruct».«name.toLowerCase»()));
			
		«ELSEIF type instanceof EEnum»
			«name» = («typeFQN»)«pbStruct».«name.toLowerCase»();
			
		«ELSEIF type instanceof EDataType»
			«name» = «pbStruct».«name.toLowerCase»();
			
		«ENDIF»
	'''
	
	def static setProtobufVar(String pbStruct, String varName, EClassifier type) '''
		«IF type instanceof EClass»
			«pbStruct».set_«varName.toLowerCase»(«varName» == nullptr ? -1 : «varName»->id());
		«ELSEIF type instanceof EEnum»
			«pbStruct».set_«varName.toLowerCase»((int32_t)«varName»);
		«ELSEIF type instanceof EDataType»
			«pbStruct».set_«varName.toLowerCase»(«varName»);
		«ENDIF»
	'''
	
	def static setProtoBufSet(String pbStruct, String varName, EClassifier type) '''
		«IF type instanceof EDataType»
			«pbStruct»->set_«varName.toLowerCase»(storedMatch.«varName»);
		«ELSEIF type instanceof EEnum »
			«pbStruct»->set_«varName.toLowerCase»((int32_t)storedMatch.«varName»);
		«ELSE»
			«pbStruct»->set_«varName.toLowerCase»(storedMatch.«varName» == nullptr ? -1 : storedMatch.«varName»->id());
		«ENDIF»
	'''
	
}