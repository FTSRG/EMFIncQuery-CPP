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
}
