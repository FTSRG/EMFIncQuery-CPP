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
package org.eclipse.viatra.query.tooling.cpp.localsearch.generator.iterator

import com.google.common.collect.Maps
import java.util.Map
import java.util.Set
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common.Include
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common.MatchGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common.MatcherGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common.NameUtils
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common.QuerySpecificationGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.DependentSearchOperationDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.PatternBodyDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.ISearchOperationDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.BinaryTransitiveClosureDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.BoundedPatternDescriptor

/**
 * @author Robert Doczi
 */
class IteratorMatcherGenerator extends MatcherGenerator {
	
	val Map<BoundedPatternDescriptor, Map<PatternBodyDescriptor, IteratorSearchOperationGenerator>> searchOperations
	
	new(String queryName, String patternName, Set<BoundedPatternDescriptor> patternGroup, MatchGenerator matchGenerator, QuerySpecificationGenerator querySpecification) {
		super(queryName, patternName, patternGroup, matchGenerator, querySpecification)
		this.searchOperations = Maps::asMap(patternGroup)[pattern |
			Maps::asMap(pattern.patternBodies) [patternBody|
				val sog = new IteratorSearchOperationGenerator(patternBody.searchOperations, matchGenerator, patternBody.matchingFrame)
				sog.initialize
				return sog
			]
		]
	}
	
	override initialize() {
		super.initialize
		includes += new Include("Viatra/Query/Util/IsNull.h")
		includes += new Include("type_traits", true)
		
		// TODO: this does not work with if there are multiple query files, somehow the related matcher generator needs to be accessed and its include path should be used
		searchOperations.keySet
			.map[it.patternBodies]
			.flatten
			.map[it.searchOperations]
			.flatten
			.filter(DependentSearchOperationDescriptor)
			.map[it.dependencies]
			.flatten
			.forEach[
				val matcherName = '''«it.referredQuery.fullyQualifiedName.substring(it.referredQuery.fullyQualifiedName.lastIndexOf('.')+1).toFirstUpper»Matcher'''
				includes += new Include('''«implementationNamespace.toString("/")»/«matcherName».h''')
			]
	}
	
	override protected compilePlanExecution(BoundedPatternDescriptor pattern, PatternBodyDescriptor patternBody) '''
		auto _classHelper = &_context->get_class_helper();		
		«assignParamsToVariables(pattern)»		
		«val sog = searchOperations.get(pattern).get(patternBody)»
		«sog.matchFoundHandler = ['''matches.insert(«it»);''']»		
		«val setupCode = new StringBuilder»
		«val executionCode = sog.compile(setupCode)»		
		«setupCode.toString»		
		«executionCode»
	'''
	
	def assignParamsToVariables(BoundedPatternDescriptor pattern) {
		val matchingFrame = pattern.patternBodies.head.matchingFrame
		'''«FOR param : pattern.boundParameters»
		«val varName = NameUtils::getPurgedName(param.toPVariable(matchingFrame))»
		«IF varName != param.name»
			auto «NameUtils::getPurgedName(param.toPVariable(matchingFrame))» = «param.name»;
		«ENDIF»
		«ENDFOR»
		'''
	}
	
	override compileInner() '''
		template<class ModelRoot>
		class «unitName» {
		public:
			«unitName»(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
				: _model(model), _context(context) {
			}
		
		«val generatedParamLists = newArrayList»
			«FOR pattern : patternGroup»
				«IF !generatedParamLists.contains(getParamList(pattern))»
					«val youShallNotPrint = generatedParamLists.add(getParamList(pattern))»
					«compileGetter(pattern)»
				«ENDIF»
			«ENDFOR»
			
		private:
			«FOR pattern : patternGroup»
				«FOR patternBody : pattern.patternBodies»
					«FOR operation : patternBody.searchOperations»
						«compileAdditionalFields(operation)»
					«ENDFOR»
				«ENDFOR»
			«ENDFOR»
			const ModelRoot* _model;
			const ::Viatra::Query::Matcher::ISearchContext* _context;
		};
		«FOR pattern : patternGroup»
			«FOR patternBody : pattern.patternBodies»
				«FOR operation : patternBody.searchOperations»
					«compileAdditionFunctions(operation)»
				«ENDFOR»
			«ENDFOR»
		«ENDFOR»
	'''
	
	private dispatch def compileAdditionalFields(ISearchOperationDescriptor descriptor)''''''
	
	var Boolean BTCFieldGenerated = false
		
	private dispatch def compileAdditionalFields(BinaryTransitiveClosureDescriptor descriptor)'''
		«IF !BTCFieldGenerated» «val youShallNotPrint = BTCFieldGenerated = true»
		template<class NavigationMatcher, class SrcType, class TrgType, class NavigationMatch, class NavigationTrgType>
		bool transitive_closure_check(NavigationMatcher matcher, NavigationTrgType NavigationMatch::* trgMember, SrcType src, TrgType trg) const;
		«ENDIF»
	'''
	private dispatch def compileAdditionFunctions(ISearchOperationDescriptor descriptor) ''''''
	
	var Boolean BTCFuncGenerated = false
	
	private dispatch def compileAdditionFunctions(BinaryTransitiveClosureDescriptor descriptor) '''
	«IF !BTCFuncGenerated» «val youShallNotPrint = BTCFuncGenerated = true»

	template<class ModelRoot>
	template<class NavigationMatcher, class SrcType, class TrgType, class NavigationMatch, class NavigationTrgType>
	inline bool «unitName»<ModelRoot>::transitive_closure_check(NavigationMatcher matcher, NavigationTrgType NavigationMatch::* trgMember, SrcType src, TrgType trg) const {
		std::unordered_set<SrcType> sourcesToEvaluate; 
		sourcesToEvaluate.insert(src);
		std::unordered_set<SrcType> sourceEvaluated; 
	
		do{
			auto it = sourcesToEvaluate.begin();
			auto currentSrc = *it;
			sourcesToEvaluate.erase(it);
			sourceEvaluated.insert(currentSrc);
	
			auto matches = matcher.matches(currentSrc);
			for(auto& match : matches)
			{
				auto foundTarget = match.*trgMember;
	
				if(trg == foundTarget) return true;
				else if( sourceEvaluated.count(foundTarget) == 0)
					sourcesToEvaluate.insert(foundTarget);
			}
		} while(!sourcesToEvaluate.empty());
		return false;
	}
	«ENDIF»
	'''
	
	override protected compileContinueDistQuery(BoundedPatternDescriptor descriptor, PatternBodyDescriptor descriptor2) {
		throw new UnsupportedOperationException("Distribution not implemented to iterator based approach");
	}
	
	
	
}