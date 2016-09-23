package org.eclipse.viatra.query.tooling.cpp.localsearch.proto

import java.util.List
import org.eclipse.emf.ecore.EClassifier
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.BaseGenerator

class ProtoGenerator extends BaseGenerator {
	
	val List<ProtoCompiler> compilers
	
	new(List<ProtoCompiler> compilers)
	{
		this.compilers = compilers
	}
	
	override getFileName()
		'''proto_gen.proto'''
	
	override compile()'''
		syntax = "proto3";
			
		«FOR compiler : compilers»
			«compiler.compile»
			
		«ENDFOR»
	'''
	
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
		return TYPE_MAPPINGS.get(type.name);
	}
}