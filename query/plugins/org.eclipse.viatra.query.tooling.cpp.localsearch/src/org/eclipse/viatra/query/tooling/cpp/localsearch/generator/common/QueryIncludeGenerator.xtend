package org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common

import java.util.Set
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.ViatraQueryHeaderGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.BoundedPatternDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.PatternGroupDescriptor

class QueryIncludeGenerator extends ViatraQueryHeaderGenerator {
	
	protected val PatternGroupDescriptor patternGroup;
	protected val String queryGroupName
	protected val String patternName
	
	
	new(String queryGroupName, PatternGroupDescriptor patternGroup) {
		super(#{queryGroupName.toFirstUpper}, '''«patternGroup.name.toFirstUpper»''')

		this.queryGroupName = queryGroupName.toFirstUpper
		this.patternGroup = patternGroup
		this.patternName = patternGroup.name.toFirstUpper
	}
	
	override initialize() {
		includes += new Include('''Viatra/Query/«queryGroupName»/«patternName»QuerySpecification.h''')
		includes += new Include('''Viatra/Query/«queryGroupName»/«patternName»Matcher.h''')
		includes += new Include('''Viatra/Query/«queryGroupName»/«patternName»Match.h''')		
	}

	// TODO: Iterating over the bodies giving them indices makes the generated code nondeterministic
	override compileInner() '''
	
		template<class ModelRootParam>
		class Rooted«unitName» {
		public:
			using ModelRoot = ModelRootParam;
			using Matcher = «patternName»Matcher<ModelRoot>;
			using QuerySpecification = «patternName»QuerySpecification<ModelRoot>;
			using Match = «patternName»Match;
			using QueryGroup = «queryGroupName»QueryGroup;
			
			static constexpr int queryID = «patternName»QuerySpecification<ModelRoot>::queryID;
		};
		

		class «unitName» {
		public:
			template<typename ModelRoot>
			using RootedQuery = Rooted«unitName»<ModelRoot>
			using ModelRoot = ModelRootParam;
			using Matcher = «patternName»Matcher<ModelRoot>;
			using QuerySpecification = «patternName»QuerySpecification<ModelRoot>;
			using Match = «patternName»Match;
			using QueryGroup = «queryGroupName»QueryGroup;
			
			static constexpr int queryID = «patternName»QuerySpecification<ModelRoot>::queryID;
			
			
			
			
		};
	
	'''
}