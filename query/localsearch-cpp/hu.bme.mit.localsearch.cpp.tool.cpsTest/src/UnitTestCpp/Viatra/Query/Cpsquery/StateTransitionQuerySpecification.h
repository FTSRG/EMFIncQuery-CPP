#ifndef VIATRA__QUERY__CPSQUERY__STATE_TRANSITION_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPSQUERY__STATE_TRANSITION_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/Cpsquery/CpsqueryQueryGroup.h"
#include "Viatra/Query/Cpsquery/StateTransitionFrame_0.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class StateTransitionMatcher;

template<class ModelRoot>
class StateTransitionQuerySpecification {
public:
	using Matcher = StateTransitionMatcher<ModelRoot>;

	using QueryGroup = CpsqueryQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<StateTransitionFrame_0> get_plan_source_transition__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<StateTransitionFrame_0> sp;
		
		
		sp.add_operation(create_InstanceOfCheck(&StateTransitionFrame_0::_0, ::cyberPhysicalSystem::State::type_id));
		sp.add_operation(create_MultiAssociationCheck(&StateTransitionFrame_0::_0, &StateTransitionFrame_0::_1, &::cyberPhysicalSystem::State::outgoingTransitions));
		sp.add_operation(create_InstanceOfCheck(&StateTransitionFrame_0::_1, ::cyberPhysicalSystem::Transition::type_id));
		sp.add_operation(create_NavigateSingleAssociation(&StateTransitionFrame_0::_1, &StateTransitionFrame_0::_2, &::cyberPhysicalSystem::Transition::targetState));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<StateTransitionFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<StateTransitionFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&StateTransitionFrame_0::_0, ::cyberPhysicalSystem::State::type_id, model));
		sp.add_operation(create_NavigateMultiAssociation(&StateTransitionFrame_0::_0, &StateTransitionFrame_0::_1, &::cyberPhysicalSystem::State::outgoingTransitions));
		sp.add_operation(create_InstanceOfCheck(&StateTransitionFrame_0::_0, ::cyberPhysicalSystem::State::type_id));
		sp.add_operation(create_InstanceOfCheck(&StateTransitionFrame_0::_1, ::cyberPhysicalSystem::Transition::type_id));
		sp.add_operation(create_NavigateSingleAssociation(&StateTransitionFrame_0::_1, &StateTransitionFrame_0::_2, &::cyberPhysicalSystem::Transition::targetState));
		
		return sp;
	}

};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__STATE_TRANSITION_QUERY_SPECIFICATION_H_ */
