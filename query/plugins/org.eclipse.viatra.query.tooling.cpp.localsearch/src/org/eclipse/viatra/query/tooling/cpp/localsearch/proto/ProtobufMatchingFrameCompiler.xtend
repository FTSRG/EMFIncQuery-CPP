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
class ProtobufMatchingFrameCompiler extends ProtoCompiler {

	
	val String queryName
	val String patternName
	val MatchingFrameDescriptor matchingFrame
	val int index
	
		
	/* 
	new(String queryName, Set<PatternDescriptor> patternGroup, Map<PatternBodyDescriptor, MatchingFrameGenerator> frameGenerators) {
		super(#{queryName}, '''«patternName.toFirstUpper»Match''')
	*/
	
	new(String queryName,
		String patternName,
		int index,
		MatchingFrameDescriptor matchingFrame)
	{
		super('''«patternName.toFirstUpper»Frame_«index»''')
		this.queryName = queryName
		this.patternName = patternName
		this.matchingFrame = matchingFrame
		this.index = index
	}
		
	override compile()'''
		«var FieldNum = 1»
		message «unitName.MessageName» {
			«FOR param : matchingFrame.allVariables.sortBy[matchingFrame.getVariablePosition(it)]»
				«val type = matchingFrame.getVariableLooseType(param)»
				«val typeName = ProtobufHelper::protobufType(type)»
				«val pos = matchingFrame.getVariablePosition(param)»
				«typeName» «pos.variableName» = «FieldNum++»;
			«ENDFOR»
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
