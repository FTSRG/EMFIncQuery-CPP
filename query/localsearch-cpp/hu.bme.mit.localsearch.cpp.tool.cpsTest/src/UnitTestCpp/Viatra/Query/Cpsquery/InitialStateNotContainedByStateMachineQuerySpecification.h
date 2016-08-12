#ifndef VIATRA__QUERY__CPSQUERY__INITIAL_STATE_NOT_CONTAINED_BY_STATE_MACHINE_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPSQUERY__INITIAL_STATE_NOT_CONTAINED_BY_STATE_MACHINE_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/Cpsquery/CpsqueryQueryGroup.h"
#include "Viatra/Query/Cpsquery/InitialStateNotContainedByStateMachineFrame_0.h"
#include "Viatra/Query/Cpsquery/StatemachineStateMatcher.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class InitialStateNotContainedByStateMachineMatcher;

template<class ModelRoot>
class InitialStateNotContainedByStateMachineQuerySpecification {
public:
	using Matcher = InitialStateNotContainedByStateMachineMatcher<ModelRoot>;

	using QueryGroup = CpsqueryQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<InitialStateNotContainedByStateMachineFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<InitialStateNotContainedByStateMachineFrame_0> sp;
		
		StatemachineStateMatcher<ModelRoot> matcher_1479528232(model,  CpsqueryQueryGroup::instance()->context());
		
		sp.add_operation(create_IterateOverInstances(&InitialStateNotContainedByStateMachineFrame_0::_0, ::cyberPhysicalSystem::StateMachine::type_id, model));
		sp.add_operation(create_NavigateSingleAssociation(&InitialStateNotContainedByStateMachineFrame_0::_0, &InitialStateNotContainedByStateMachineFrame_0::_1, &::cyberPhysicalSystem::StateMachine::initial));
		sp.add_operation(create_InstanceOfCheck(&InitialStateNotContainedByStateMachineFrame_0::_0, ::cyberPhysicalSystem::StateMachine::type_id));
		sp.add_operation(create_NACOperation<InitialStateNotContainedByStateMachineFrame_0>(matcher_1479528232, &InitialStateNotContainedByStateMachineFrame_0::_0, &InitialStateNotContainedByStateMachineFrame_0::_1));
		
		return sp;
	}

};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__INITIAL_STATE_NOT_CONTAINED_BY_STATE_MACHINE_QUERY_SPECIFICATION_H_ */
