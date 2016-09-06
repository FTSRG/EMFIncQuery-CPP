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
package org.eclipse.viatra.query.tooling.cpp.localsearch.generator.runtime

import java.util.Map
import java.util.Set
import org.eclipse.viatra.query.runtime.matchers.psystem.queries.PParameter
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common.Include
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common.MatchGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common.MatcherGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common.NameUtils
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.PatternBodyDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.PatternDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common.MatchingFrameGenerator

/**
 * @author Robert Doczi
 */
class RuntimeMatcherGenerator extends MatcherGenerator {
	
	val Map<PatternBodyDescriptor, MatchingFrameGenerator> frameGenerators
	
	new(String queryName, String patternName, Set<PatternDescriptor> patternGroup, Map<PatternBodyDescriptor, MatchingFrameGenerator> frameGenerators, MatchGenerator matchGenerator, RuntimeQuerySpecificationGenerator querySpecification) {
		super(queryName, patternName, patternGroup, matchGenerator, querySpecification)
		this.frameGenerators = frameGenerators
	}
	
	override initialize() {
		super.initialize
		
		includes += frameGenerators.values.map[it.include]
		
		includes += new Include("Viatra/Query/Plan/SearchPlanExecutor.h")
	}
	

	override protected compilePlanExecution(PatternDescriptor pattern, PatternBodyDescriptor patternBody) '''
		«val frame = frameGenerators.get(patternBody)»
		«val bodyNum = frame.index»
		auto sp = «name»QuerySpecification<ModelRoot>::get_plan_«NameUtils::getPlanName(pattern)»__«bodyNum»(_model);
		«IF pattern.bound»
			«initializeFrame(patternBody, pattern.boundParameters, bodyNum)»
			
			auto exec = SearchPlanExecutor<«frame.frameName»>(sp, *_context).prepare(frame);
		«ELSE»							
			auto exec = SearchPlanExecutor<«frame.frameName»>(sp, *_context);
		«ENDIF»
		
		
		for (auto&& frame : exec) {
			«name»Match match;
		
			«fillMatch(patternBody.matchingFrame)»
		
			matches.insert(match);
		}
	'''
	
	private def initializeFrame(PatternBodyDescriptor patternBody, Set<PParameter> boundParameters, int bodyNum) '''
		«val matchingFrameGen = frameGenerators.get(patternBody)»
		«val boundVariables = boundParameters.map[toPVariable(patternBody.matchingFrame)].toSet»
		«val boundParamNames = boundParameters.map[it.name].toSet»
		«name»Frame_«bodyNum» frame;
		«FOR boundVar : boundVariables»
			«FOR exportedParameter: matchingFrameGen.matchingFrame.getParameterFromVariable(boundVar)»
				«««TODO Incredible Hack, a bit ugly.
				«IF boundParamNames.contains(exportedParameter.name)»frame.«matchingFrameGen.getVariableName(boundVar)» = «exportedParameter.name»;«ENDIF»
			«ENDFOR»
		«ENDFOR»
	'''
}