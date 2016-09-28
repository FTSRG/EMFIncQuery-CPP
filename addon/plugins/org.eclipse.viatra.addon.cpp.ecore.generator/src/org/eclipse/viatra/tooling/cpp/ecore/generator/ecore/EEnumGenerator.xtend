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
package org.eclipse.viatra.tooling.cpp.ecore.generator.ecore

import com.google.common.base.Joiner
import org.eclipse.emf.ecore.EEnum
import org.eclipse.viatra.query.tooling.cpp.localsearch.util.fs.FileSystemAccess
import org.eclipse.viatra.query.tooling.cpp.localsearch.util.generators.CppHelper
import org.eclipse.viatra.query.tooling.cpp.localsearch.util.generators.NamespaceHelper

import static extension org.eclipse.viatra.query.tooling.cpp.localsearch.util.fs.PathUtils.*
import org.eclipse.emf.ecore.EEnumLiteral

/**
 * @author Robert Doczi
 */
class EEnumGenerator {
		
	static def generateEnum(EEnum eenum, FileSystemAccess fsa) {
		fsa.generateFile(eenum.name.h, eenum.compileEnumHeader)
	}

	static def compileEnumHeader(EEnum eenum) '''
		«val guard = CppHelper::getGuardHelper(Joiner.on('_').join(NamespaceHelper::getNamespaceHelper(eenum)) + '_' + eenum.name)»
		«guard.start»
		
		«val ns = NamespaceHelper::getNamespaceHelper(eenum)»
		«FOR namespaceFragment : ns»
			namespace «namespaceFragment» {
		«ENDFOR»	
			
			enum «eenum.name» : int {
				«eenum.getELiterals().map[toLiteralValueForm].join(",\n")»				
			};
			
		«FOR namespaceFragment : ns»
			} /* namespace «namespaceFragment» */
		«ENDFOR»
		
		«guard.end»
		'''
		
	private static def toLiteralValueForm(EEnumLiteral literal){
		'''«literal.name» = «literal.value»'''
	}
	
	def static generateEnumHelper(Iterable<EEnum> enums, FileSystemAccess fsa) {
		
		if(enums.size > 0)
			fsa.generateFile("EnumHelper.h", enums.compileEnumHelperHeader)
	}
	
	static def compileEnumHelperHeader(Iterable<EEnum> enums) '''
		«val guard = CppHelper::getGuardHelper(Joiner.on('_').join(NamespaceHelper::getNamespaceHelper(enums.head)) + '_' + "ENUMHELPER")»
		«guard.start»
		
		#include<string>
		
		template<typename T>
		struct EnumHelper{
			static std::string ToString(T t)
			{
				throw "EnumHelper undefined for type";
			}
			
			static T ParseFromString(const std::string& str)
			{
				throw "EnumHelper undefined for type";
			}
		};
		
		«enums.map[compileEnumHelperEnum].join(",\n")»
		
		«guard.end»
		'''
	
	static def compileEnumHelperEnum(EEnum eenum) '''
		«val fqn = CppHelper::getTypeHelper(eenum).FQN»
		#include "«eenum.name».h"
		template<>
		struct EnumHelper< «fqn»> {
			static std::string ToString(«fqn» x)
			{
				switch (x)
				{
					«FOR literal : eenum.ELiterals»
						case «fqn»::«literal.name»: return "«literal.name»";
					«ENDFOR»
					
					default:
						throw "To String method undefined for enum";
				}
			}
			
			static «fqn» ParseFromString(const std::string& str)
			{
				«FOR literal : eenum.ELiterals»
					if(str == "«literal.name»")
						return «fqn»::«literal.name»;
				«ENDFOR»
					
				throw "EnumHelper ParseFromString method: input string cannot be interpreted.";
			}
		};
	'''
	
}