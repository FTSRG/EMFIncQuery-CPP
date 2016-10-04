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
package org.eclipse.viatra.query.tooling.cpp.localsearch.proto

import org.eclipse.viatra.query.runtime.matchers.psystem.PVariable
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.MatchingFrameDescriptor

/**
 * @author Robert Doczi
 */
class ProtobufMatchCompiler extends ProtoCompiler {

	
	val String queryName
	val String patternName
	val MatchingFrameDescriptor aMatchingFrame
	
		
	/* 
	new(String queryName, Set<PatternDescriptor> patternGroup, Map<PatternBodyDescriptor, MatchingFrameGenerator> frameGenerators) {
		super(#{queryName}, '''«patternName.toFirstUpper»Match''')
	*/
	
	new(String queryName,
		String patternName,
		MatchingFrameDescriptor aMatchingFrame)
	{
		super('''«patternName.toFirstUpper»Match''')
		this.queryName = queryName
		this.patternName = patternName
		this.aMatchingFrame = aMatchingFrame
		
	}
	
	override compile() '''
		«var FieldNum = 1»
		message «this.unitName.MessageName» {
			«FOR parameter : aMatchingFrame.parameters»
				«val variable = aMatchingFrame.getVariableFromParameter(parameter)»
				«val type = aMatchingFrame.getVariableLooseType(variable)»
				«ProtobufHelper::protobufType(type)» «parameter.name» = «FieldNum++»;
			«ENDFOR»
		};
		
		«compileSet»
	'''
	
	def compileSet() '''
		message «(this.unitName+"Set").MessageName» {
			repeated «this.unitName.MessageName» matches = 1;
		};
	'''
	


	static def getVariableName(PVariable variable, MatchingFrameDescriptor matchingFrame) {
		getVariableName(matchingFrame.getVariablePosition(variable))
	}
	
			
	static def MessageName(String unitName)
	'''PB_«unitName»'''
	
	def getFrameName() {
		unitName
	}

	private static def getVariableName(int position) '''_«position»'''
	
	

}
