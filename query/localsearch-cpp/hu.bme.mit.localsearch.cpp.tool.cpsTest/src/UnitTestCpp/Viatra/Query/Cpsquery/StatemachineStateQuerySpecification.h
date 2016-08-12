#ifndef VIATRA__QUERY__CPSQUERY__STATEMACHINE_STATE_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPSQUERY__STATEMACHINE_STATE_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/Cpsquery/CpsqueryQueryGroup.h"
#include "Viatra/Query/Cpsquery/StatemachineStateFrame_0.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class StatemachineStateMatcher;

template<class ModelRoot>
class StatemachineStateQuerySpecification {
public:
	using Matcher = StatemachineStateMatcher<ModelRoot>;

	using QueryGroup = CpsqueryQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<StatemachineStateFrame_0> get_plan_statemachine_state__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<StatemachineStateFrame_0> sp;
		
		
		sp.add_operation(create_InstanceOfCheck(&StatemachineStateFrame_0::_0, ::cyberPhysicalSystem::StateMachine::type_id));
		sp.add_operation(create_MultiAssociationCheck(&StatemachineStateFrame_0::_0, &StatemachineStateFrame_0::_1, &::cyberPhysicalSystem::StateMachine::states));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<StatemachineStateFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<StatemachineStateFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&StatemachineStateFrame_0::_0, ::cyberPhysicalSystem::StateMachine::type_id, model));
		sp.add_operation(create_NavigateMultiAssociation(&StatemachineStateFrame_0::_0, &StatemachineStateFrame_0::_1, &::cyberPhysicalSystem::StateMachine::states));
		sp.add_operation(create_InstanceOfCheck(&StatemachineStateFrame_0::_0, ::cyberPhysicalSystem::StateMachine::type_id));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<StatemachineStateFrame_0> get_plan_statemachine_state__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<StatemachineStateFrame_0> sp;
		
		
		sp.add_operation(create_InstanceOfCheck(&StatemachineStateFrame_0::_0, ::cyberPhysicalSystem::StateMachine::type_id));
		sp.add_operation(create_MultiAssociationCheck(&StatemachineStateFrame_0::_0, &StatemachineStateFrame_0::_1, &::cyberPhysicalSystem::StateMachine::states));
		
		return sp;
	}

};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__STATEMACHINE_STATE_QUERY_SPECIFICATION_H_ */
