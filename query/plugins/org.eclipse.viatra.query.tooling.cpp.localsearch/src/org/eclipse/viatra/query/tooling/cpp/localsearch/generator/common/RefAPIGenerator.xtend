package org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common

import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.ViatraQueryHeaderGenerator
import java.util.Set
import org.eclipse.viatra.query.runtime.matchers.psystem.PVariable
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.BoundedPatternDescriptor

class RefAPIGenerator extends ViatraQueryHeaderGenerator {
	
	protected val String name
	protected val BoundedPatternDescriptor pattern
	protected val MatchGenerator matchGenerator
	protected val MatcherGenerator matcherGenerator
	
	protected val QuerySpecificationGenerator querySpecification
	protected val CharSequence featureName
	protected val PVariable src
	protected val PVariable srcID
	protected val PVariable trg
	

	new(String queryName, String patternName, CharSequence featureName, Set<BoundedPatternDescriptor> patternGroup, MatchGenerator matchGenerator, MatcherGenerator matcherGenerator, QuerySpecificationGenerator querySpecification) {
		super(#{queryName}, '''«patternName.toFirstUpper»Derived''')
		this.name = patternName.toFirstUpper
		this.pattern = patternGroup.maxBy[it | it.boundParameters.size]
		this.matchGenerator = matchGenerator
		this.matcherGenerator = matcherGenerator
		this.querySpecification = querySpecification
		this.featureName = featureName
		
		//Refactor not guaranteed the order
		this.src = this.pattern.patternBodies.head.PBody.allVariables.get(0)
		this.srcID = this.pattern.patternBodies.head.PBody.allVariables.get(1)
		this.trg = this.pattern.patternBodies.head.PBody.allVariables.get(2)
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
	template<class ModelRoot>
	struct «name»Update{
		/*
		 * It is generated for update a reference collection in src's environment.
		 */
		static void update(ModelRoot modelRoot,«matcherGenerator.getParamList(pattern)»){
			/*
			 * Critical Section START
			 * Atomicity is mandatory
			 * Not supported parallel modifications and queries
			 */
			auto srcInstanceList = ModelIndex<typename std::remove_pointer< «srcType» >::type, ModelRoot>::instances(&modelRoot);
			auto srcIDPredicate = [«srcID.name»](const «srcPointerType» src){
				return src->id == «srcID.name»;
			};
	
			auto srcIt = std::find_if(srcInstanceList.begin(), srcInstanceList.end(), srcIDPredicate);
	
			if(srcIt == srcInstanceList.end()) throw new std::invalid_argument("«srcType» ID not found.");
	
			auto engine = QueryEngine<ModelRoot>::of(&modelRoot);
			auto «featureName»Matcher = engine.template matcher< «querySpecification.querySpecificationName» >();
			auto matches = «featureName»Matcher.matches(«pattern.boundParameters.map[it.name].join(", ")»);
			auto trgInstanceList = ModelIndex<typename std::remove_pointer< «trgType» >::type, ModelRoot>::instances(&modelRoot);
	
			std::vector< «trgPointerType» > newDerivedList;
	
			for(auto match : matches){
				if(newDerivedList.end() == std::find(newDerivedList.begin(), newDerivedList.end(), match.«trg.name»)) newDerivedList.push_back(match.«trg.name»);
			}
	
			(*srcIt)->«featureName».clear();
			(*srcIt)->«featureName».insert((*srcIt)->«featureName».begin(), newDerivedList.begin(), newDerivedList.end());
	
			/*
			* Critical Section END
			*/
		}
	};
	'''
	
	override compileOuter() '''
	
	'''
	
}