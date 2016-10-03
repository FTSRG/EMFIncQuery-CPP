package org.eclipse.viatra.query.tooling.cpp.localsearch.generator.runtime

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.File
import java.io.FileWriter
import java.io.IOException
import java.io.InputStreamReader
import java.util.Set
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.BaseGenerator

class QueryRunnerFactoryGenerator extends BaseGenerator {
	
	val Set<org.eclipse.viatra.query.tooling.cpp.localsearch.proto.ProtoCompiler> compilers
	
	new(Set<org.eclipse.viatra.query.tooling.cpp.localsearch.proto.ProtoCompiler> compilers)
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
		
		val protoPath = folderPath
		var BufferedWriter output
		var command = ""
		if(System.getProperty ("os.name").toLowerCase().contains("windows"))
			command = '''cmd /C protoc --proto_path="«protoPath»" --cpp_out="«folderPath»" "«input»" '''
		else {
			try {
				command = '''bash «protoPath»/proto_make.sh'''
				
				val File file = new File('''«protoPath»/proto_make.sh''');
			
				if (file.createNewFile()){
					System.out.println("Proto_make.sh is created!");
				}else{
					System.out.println("Proto_make.sh already exists.");
				}
				output = new BufferedWriter(new FileWriter(file))
				output.write('''#!/bin/bash 
cmd=( sh -c 'protoc --proto_path="«protoPath»" --cpp_out="«folderPath»" "«input»"')
"${cmd[@]}"''')
				
			} catch (IOException e) {
				e.printStackTrace();
			} finally{
				if (output != null) output.close()
			}
		}

		System.out.println(command);
		try{
			val Process p = Runtime.getRuntime().exec(
			command
			);
			val reader = new BufferedReader(new InputStreamReader(p.getErrorStream()))
			
			var String line;
			while((line = reader.readLine()) != null){
				System.out.println("<Error>");
				System.out.println(line);
				System.out.println("</Error>");
			}
			val int exitValue = p.waitFor()
			if(exitValue != 0)
				System.out.println("Exit value: "+ exitValue);
			System.out.println("-- done -- ");
			reader.close()
		}catch(Throwable t){
			t.printStackTrace();
		}
			
	}
	
}
