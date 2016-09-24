package org.eclipse.viatra.query.tooling.cpp.localsearch.proto

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.List
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
		
	override postGenerationTask(String folderPath)
	{
		//val directory = System.getProperty("user.dir");
		// 
		System.out.println("-- Post generation task for ProtoBuf --");
		val input = '''«folderPath»/proto_gen.proto''';		
		
		var protoc = "protoc";
		if(System.getProperty ("os.name").toLowerCase().contains("windows"))
			protoc = "cmd /C protoc";
			
		val protoPath = folderPath;
			
		val command = '''«protoc» --proto_path="«protoPath»" --cpp_out="«folderPath»" "«input»" '''

		System.out.println(command);
		val Process p = Runtime.getRuntime().exec(
			command
			);
		val reader = new BufferedReader(new InputStreamReader(p.getInputStream()));
		var String line;
		while((line = reader.readLine()) != null)
			System.out.println(line);
		
		p.waitFor();
		System.out.println("-- done -- ");		
	}
	
}