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
package org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common

import java.util.Set
import org.eclipse.emf.ecore.EClassifier
import org.eclipse.viatra.query.runtime.matchers.psystem.PVariable
import org.eclipse.viatra.query.runtime.matchers.psystem.queries.PParameter
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.ViatraQueryHeaderGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.MatchingFrameDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.PatternBodyDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.BoundedPatternDescriptor

/**
 * @author Robert Doczi
 */
abstract class MatcherGenerator extends ViatraQueryHeaderGenerator {
	
	protected val String patternName
	protected val Set<BoundedPatternDescriptor> patternGroup
	protected val MatchGenerator matchGenerator
	
	protected val QuerySpecificationGenerator querySpecification

	new(String queryName, String patternName, Set<BoundedPatternDescriptor> patternGroup, MatchGenerator matchGenerator, QuerySpecificationGenerator querySpecification) {
		super(#{queryName}, '''«patternName.toFirstUpper»Matcher''')
		this.patternName = patternName.toFirstUpper
		this.patternGroup = patternGroup
		this.matchGenerator = matchGenerator
		this.querySpecification = querySpecification
	}
	
	override initialize() {
		includes += matchGenerator.include
		includes += querySpecification.include
		
		includes += new Include("Viatra/Query/QueryEngine.h")
		includes += new Include("unordered_set", true)
		// TODO: this is only required for the using statement, however this should be moved from here as it is not generally necessary
		includes += new Include("Viatra/Query/Plan/SearchPlanExecutor.h")
		includes += new Include("Viatra/Query/Distributed/QueryRunner.h", false);
	}
	
	override compileInner() '''
		template<typename>class «patternName»;
				
		template<class ModelRoot>
		class «unitName» {
			using QueryRunnerT = ::Viatra::Query::Distributed::QueryRunner<«patternName»<ModelRoot>>;
		public:
			«unitName»(
			const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context, QueryRunnerT * queryRunner) 
				: _model(model), _context(context), _queryRunner(queryRunner) {
			}
		«val generatedParamLists = newArrayList»
			«FOR pattern : patternGroup»
				«IF !generatedParamLists.contains(getParamList(pattern))»
					«val youShallNotPrint = generatedParamLists.add(getParamList(pattern))»
					«compileGetter(pattern)»
					«compileDistGetter(pattern)»
				«ENDIF»
			«ENDFOR»
			
		private:
			QueryRunnerT * _queryRunner;
			const ModelRoot* _model;
			const ::Viatra::Query::Matcher::ISearchContext* _context;
		};
	'''
	//Generate another function to unbounded plans. For distributed plan execution continue.
	def String compileDistGetter(BoundedPatternDescriptor pattern) '''
		«IF !pattern.bound»
			«FOR patternBody : pattern.patternBodies»
				«compileContinueDistQuery(pattern, patternBody)»
				
			«ENDFOR»
			
		std::unordered_set<«patternName»Match> continueExec(std::string strFrame, int bodyID, int startOpIndex){
			switch(bodyID){
				«FOR patternBody : pattern.patternBodies»
					«val bodyNum = patternBody.index»
					case «bodyNum»:
						«patternName»Frame_«bodyNum» frame«bodyNum»; frame«bodyNum».ParseFromString(strFrame, _model);
						return continue_«bodyNum»(frame«bodyNum», startOpIndex);
				«ENDFOR»
				default:
					throw "Matcher continue function has an unidentified bodyID";
				break;
			}
		}
		«ENDIF»
	'''
	
	protected abstract def String compileContinueDistQuery(BoundedPatternDescriptor descriptor, PatternBodyDescriptor descriptor2)
	
	protected def compileGetter(BoundedPatternDescriptor pattern) '''
		std::unordered_set<«patternName»Match> matches(«getParamList(pattern)») const {
			««« TODO: Move using statements
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::SearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			std::unordered_set<«patternName»Match> matches;
		
			«FOR patternBody : pattern.patternBodies»
				{
					«compilePlanExecution(pattern, patternBody)»
				}
				
			«ENDFOR»
		
			return matches;
		}
	'''
	protected abstract def String compilePlanExecution(BoundedPatternDescriptor pattern, PatternBodyDescriptor patternBody)
	
	protected def fillMatch(MatchingFrameDescriptor matchingFrame) '''
		«FOR parameter : matchingFrame.parameters»
			«val keyVariable = parameter.toPVariable(matchingFrame)»
			match.«parameter.name» = static_cast<«keyVariable.type(matchingFrame)»>(frame._«matchingFrame.getVariablePosition(keyVariable)»);
		«ENDFOR»
	'''
	
	protected def getParamList(BoundedPatternDescriptor pattern) {
		val matchingFrame = pattern.patternBodies.head.matchingFrame
		pattern.boundParameters.map[
			val variable = it.toPVariable(matchingFrame);
			'''«variable.type(matchingFrame)» «it.name»'''
		].join(", ")
	}
	
	private def toTypeName(EClassifier clazz) {
		NameUtils::toTypeName(clazz)		
	}
	
	protected def type(PVariable variable, MatchingFrameDescriptor matchingFrame) {
		matchingFrame.getVariableStrictType(variable).toTypeName
	}
	
	protected def toPVariable(PParameter pParameter, MatchingFrameDescriptor matchingFrame) {
		matchingFrame.getVariableFromParameter(pParameter)
	}
}
