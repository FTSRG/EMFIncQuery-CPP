package org.eclipse.viatra.query.tooling.cpp.localsearch.generator.runtime

import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.ViatraQueryHeaderGenerator
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common.Include
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.QueryDescriptor

class QueryRunnerFactoryGenerator extends ViatraQueryHeaderGenerator {
	
	protected val QueryDescriptor query;
	
	
	new(QueryDescriptor query) {
		super(#{query.name.toFirstUpper}, '''QueryRunnerFactory''')
		this.query = query;
	}
	
	override initialize() {
		includes += new Include('''stdexcept''', true)
		includes += new Include('''memory''', true)
		
			includes += new Include('''Viatra/Query/Distributed/QueryRunner.h''')
			includes += new Include('''Viatra/Query/Distributed/QueryService.h''')
		
		for( patternGroup : query.patternGroups.values )
		{
			includes += new Include('''Viatra/Query/«query.name»/«patternGroup.name».h''')
		}
	}

	// TODO: Iterating over the bodies giving them indices makes the generated code nondeterministic
	override compileInner() '''
		template<class ModelRoot>
		class QueryRunnerFactory{
		public:

			static std::shared_ptr<Viatra::Query::Distributed::QueryRunnerBase> Create(int queryID, int64_t sessionID, ModelRoot * modelRoot, Viatra::Query::Distributed::QueryServiceBase * service)
			{
				switch(queryID){
					«FOR patternGroup : query.patternGroups.values»
						case «patternGroup.queryID»:
							return std::make_unique<
								Viatra::Query::Distributed::QueryRunner<Rooted«patternGroup.name.toFirstUpper»<ModelRoot>>
							>(sessionID, modelRoot, service);
					«ENDFOR»
				}
				throw std::invalid_argument("Cannot instantiate Query runner from the given queryID!");
			}	
		
		};
	'''
		
}
