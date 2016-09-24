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
			«name» = («pbStruct».«name»() == -1) 
				? nullptr 
				: dynamic_cast<«typeFQN»*>(«modelRoot»->findModelElementByID(«pbStruct».«name»()));
			
		«ELSEIF type instanceof EEnum»
			«name» = («typeFQN»)«pbStruct».«name»();
			
		«ELSEIF type instanceof EDataType»
			«name» = «pbStruct».«name»();
			
		«ENDIF»
	'''
	
	def static setProtobufVar(String pbStruct, String varName, EClassifier type) '''
		«IF type instanceof EClass»
			«pbStruct».set_«varName»(«varName» == nullptr ? -1 : «varName»->id());
		«ELSEIF type instanceof EEnum»
			«pbStruct».set_«varName»((int32_t)«varName»);
		«ELSEIF type instanceof EDataType»
			«pbStruct».set_«varName»(«varName»);
		«ENDIF»
	'''
	
}