package org.eclipse.viatra.query.tooling.cpp.localsearch.generator.runtime

import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.ViatraQueryHeaderGenerator
import java.util.Set
import org.eclipse.viatra.query.tooling.cpp.localsearch.model.BoundedPatternDescriptor
import org.eclipse.viatra.query.tooling.cpp.localsearch.generator.common.Include

class QueryRunnerFactoryGenerator extends ViatraQueryHeaderGenerator {
	
	protected val Set<Set<BoundedPatternDescriptor>> patternGroupSet
	protected val String queryGroupName
	
	
	new(String queryGroupName, Set<Set<BoundedPatternDescriptor>> patternGroupSet) {
		super(#{queryGroupName.toFirstUpper}, '''QueryRunnerFactory''')
		this.patternGroupSet = patternGroupSet
		this.queryGroupName = queryGroupName.toFirstUpper
	}
	
	override initialize() {
		includes += new Include('''stdexcept''', true)
		includes += new Include('''memory''', true)
		
			includes += new Include('''Viatra/Query/Distributed/QueryRunner.h''')
			includes += new Include('''Viatra/Query/Distributed/QueryService.h''')
		
		for(patternGroup: patternGroupSet)
		{
			val pattern = patternGroup.head;
			includes += new Include('''Viatra/Query/«queryGroupName»/«pattern.name».h''')
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
					«FOR patternGroup : patternGroupSet»
						«val pattern = patternGroup.head»
						case «pattern.queryID»:
							return std::make_unique<
								Viatra::Query::Distributed::QueryRunner<«pattern.name.toFirstUpper»<ModelRoot>>
							>(sessionID, modelRoot, service);
					«ENDFOR»
				}
				throw std::invalid_argument("Cannot instantiate Query runner from the given queryID!");
			}	
		
		};
	'''
		
}
