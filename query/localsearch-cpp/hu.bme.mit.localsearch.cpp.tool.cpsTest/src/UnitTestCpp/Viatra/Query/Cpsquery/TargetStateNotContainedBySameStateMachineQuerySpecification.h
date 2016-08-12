#ifndef VIATRA__QUERY__CPSQUERY__TARGET_STATE_NOT_CONTAINED_BY_SAME_STATE_MACHINE_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPSQUERY__TARGET_STATE_NOT_CONTAINED_BY_SAME_STATE_MACHINE_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/Cpsquery/CpsqueryQueryGroup.h"
#include "Viatra/Query/Cpsquery/StatemachineStateMatcher.h"
#include "Viatra/Query/Cpsquery/TargetStateNotContainedBySameStateMachineFrame_0.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class TargetStateNotContainedBySameStateMachineMatcher;

template<class ModelRoot>
class TargetStateNotContainedBySameStateMachineQuerySpecification {
public:
	using Matcher = TargetStateNotContainedBySameStateMachineMatcher<ModelRoot>;

	using QueryGroup = CpsqueryQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<TargetStateNotContainedBySameStateMachineFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<TargetStateNotContainedBySameStateMachineFrame_0> sp;
		
		StatemachineStateMatcher<ModelRoot> matcher_332886540(model,  CpsqueryQueryGroup::instance()->context());
		
		sp.add_operation(create_IterateOverInstances(&TargetStateNotContainedBySameStateMachineFrame_0::_2, ::cyberPhysicalSystem::StateMachine::type_id, model));
		sp.add_operation(create_NavigateMultiAssociation(&TargetStateNotContainedBySameStateMachineFrame_0::_2, &TargetStateNotContainedBySameStateMachineFrame_0::_3, &::cyberPhysicalSystem::StateMachine::states));
		sp.add_operation(create_InstanceOfCheck(&TargetStateNotContainedBySameStateMachineFrame_0::_2, ::cyberPhysicalSystem::StateMachine::type_id));
		sp.add_operation(create_InstanceOfCheck(&TargetStateNotContainedBySameStateMachineFrame_0::_3, ::cyberPhysicalSystem::State::type_id));
		sp.add_operation(create_IterateOverInstances(&TargetStateNotContainedBySameStateMachineFrame_0::_0, ::cyberPhysicalSystem::Transition::type_id, model));
		sp.add_operation(create_NavigateSingleAssociation(&TargetStateNotContainedBySameStateMachineFrame_0::_0, &TargetStateNotContainedBySameStateMachineFrame_0::_1, &::cyberPhysicalSystem::Transition::targetState));
		sp.add_operation(create_MultiAssociationCheck(&TargetStateNotContainedBySameStateMachineFrame_0::_3, &TargetStateNotContainedBySameStateMachineFrame_0::_0, &::cyberPhysicalSystem::State::outgoingTransitions));
		sp.add_operation(create_InstanceOfCheck(&TargetStateNotContainedBySameStateMachineFrame_0::_0, ::cyberPhysicalSystem::Transition::type_id));
		sp.add_operation(create_NACOperation<TargetStateNotContainedBySameStateMachineFrame_0>(matcher_332886540, &TargetStateNotContainedBySameStateMachineFrame_0::_2, &TargetStateNotContainedBySameStateMachineFrame_0::_1));
		
		return sp;
	}

};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__TARGET_STATE_NOT_CONTAINED_BY_SAME_STATE_MACHINE_QUERY_SPECIFICATION_H_ */
