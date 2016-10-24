package org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common

import java.util.Set
import org.eclipse.emf.ecore.EClass
import org.eclipse.viatra.query.runtime.matchers.psystem.PVariable
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.ViatraQueryHeaderGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.BoundedPatternDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.planner.util.CompilerHelper
import org.eclipse.viatra.query.runtime.localsearch.exceptions.LocalSearchException
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.PatternGroupDescriptor

class RefAPIGenerator extends ViatraQueryHeaderGenerator {
	
	protected val String name
	protected val BoundedPatternDescriptor pattern
	protected val MatchGenerator matchGenerator
	protected val MatcherGenerator matcherGenerator
	
	protected val QuerySpecificationGenerator querySpecification
	protected val CharSequence featureName
	protected val int arity
	protected val PVariable src
	protected val EClass srcClassifier
	protected val PVariable srcID
	protected val PVariable trg
	

	new(String queryName, String patternName, CharSequence featureName, PatternGroupDescriptor patternGroup, MatchGenerator matchGenerator, MatcherGenerator matcherGenerator, QuerySpecificationGenerator querySpecification) {
		super(#{queryName}, '''«patternName.toFirstUpper»RefUpdater''')
		this.name = patternName.toFirstUpper
		this.pattern = patternGroup.boundedPatterns.maxBy[it | it.boundParameters.size]
		this.matchGenerator = matchGenerator
		this.matcherGenerator = matcherGenerator
		this.querySpecification = querySpecification
		this.featureName = featureName
		
		//Refactor not guaranteed the order
		this.src = this.pattern.patternBodies.head.PBody.allVariables.get(0)
		this.srcID = this.pattern.patternBodies.head.PBody.allVariables.get(1)
		this.trg = this.pattern.patternBodies.head.PBody.allVariables.get(2)
		
		this.srcClassifier = CompilerHelper::getLeastStrictType(this.src) as EClass
		if(this.srcClassifier == null) throw new LocalSearchException("Query Based Feature doesn't exists")
		this.arity = this.srcClassifier.getEStructuralFeature(this.featureName.toString).upperBound
	}
	
	override initialize() {
		includes += new Include("stdexcept", true)
		includes += new Include("algorithm", true)
		includes += new Include("Viatra/Query/QueryEngine.h")
		includes += new Include("Viatra/Query/Matcher/ModelIndex.h")
		includes += new Include('''Viatra/Query/«querySpecification.queryGroupName»/«name»Matcher.h''')
	}
	
	override compileInner() '''
	«val srcPointerType = matcherGenerator.type(src,matchGenerator.oneOfTheMatchingFrames)»
	«val srcType = srcPointerType.subSequence(0,srcPointerType.length-1)»
	«val trgPointerType = matcherGenerator.type(trg,matchGenerator.oneOfTheMatchingFrames)»
	«val trgType = trgPointerType.subSequence(0,trgPointerType.length-1)»
	struct «name»RefUpdate{
		/*
		 * It is generated for update a reference collection in src's environment.
		 */
		static void update(Viatra::Query::Model::ModelRoot modelRoot,«matcherGenerator.getParamList(pattern)»){
			/*
			 * Critical Section START
			 * Atomicity is mandatory
			 * Not supported parallel modifications and queries
			 */
			auto srcInstanceList = ModelIndex<typename std::remove_pointer< «srcType» >::type, ModelRoot>::instances(&modelRoot);
			auto srcIDPredicate = [«srcID.name»](const «srcPointerType» src){
				return src->id() == «srcID.name»;
			};
	
			auto srcIt = std::find_if(srcInstanceList.begin(), srcInstanceList.end(), srcIDPredicate);
	
			if(srcIt == srcInstanceList.end()) throw std::invalid_argument("«srcType» ID not found in RefUpdater");
	
			auto engine = QueryEngine<ModelRoot>::of(&modelRoot);
			auto «featureName»Matcher = engine.template matcher< «querySpecification.querySpecificationName» >();
			auto matches = «featureName»Matcher.matches(«pattern.boundParameters.map[it.name].join(", ")»);
			
			if(matches.size() > 0){ 
			
				auto trgInstanceList = ModelIndex<typename std::remove_pointer< «trgType» >::type, ModelRoot>::instances(&modelRoot);
				
				«IF arity != 1 »
				std::vector< «trgPointerType» > newDerivedList;
				
				for(auto match : matches){
					if(newDerivedList.end() == std::find(newDerivedList.begin(), newDerivedList.end(), match.«trg.name»)) newDerivedList.push_back(match.«trg.name»);
				}
				(*srcIt)->set_«featureName»(std::move(newDerivedList));
				«ELSE»
				«trgPointerType» newDerivedMember = nullptr;
				for(auto match : matches){
					newDerivedMember = match.«trg.name»;
				}
				if(newDerivedMember != nullptr) (*srcIt)->set_«featureName»(newDerivedMember);
				«ENDIF»
			}
			/*
			* Critical Section END
			*/
		}
	};
	'''
	
	override compileOuter() '''
	
	'''
	
}