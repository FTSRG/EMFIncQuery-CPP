package org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common

import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.ViatraQueryHeaderGenerator

class QueryIncludeGenerator extends ViatraQueryHeaderGenerator {
	
	protected val String queryGroupName
	protected val String patternName
	
	
	new(String queryGroupName, String patternName) {
		super(#{queryGroupName.toFirstUpper}, '''«patternName.toFirstUpper»''')

		this.queryGroupName = queryGroupName.toFirstUpper
		
		this.patternName = patternName.toFirstUpper;
	}
	
	override initialize() {
		includes += new Include('''Viatra/Query/«queryGroupName»/«patternName»QuerySpecification.h''')
		includes += new Include('''Viatra/Query/«queryGroupName»/«patternName»Matcher.h''')
		includes += new Include('''Viatra/Query/«queryGroupName»/«patternName»Match.h''')		
	}

	// TODO: Iterating over the bodies giving them indices makes the generated code nondeterministic
	override compileInner() '''
	
		template<class ModelRootParam>
		class «unitName» {
		public:
			using ModelRoot = ModelRootParam;
			using Matcher = «patternName»Matcher<ModelRoot>;
			using QuerySpecification = «patternName»QuerySpecification<ModelRoot>;
			using Match = «patternName»Match;
			using QueryGroup = «queryGroupName»QueryGroup;
			
			static constexpr int queryID = «patternName»QuerySpecification<ModelRoot>::queryID;
		};
	
	'''
}