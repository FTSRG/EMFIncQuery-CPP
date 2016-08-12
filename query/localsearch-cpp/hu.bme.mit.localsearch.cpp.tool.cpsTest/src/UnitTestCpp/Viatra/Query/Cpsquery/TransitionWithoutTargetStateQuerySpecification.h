#ifndef VIATRA__QUERY__CPSQUERY__TRANSITION_WITHOUT_TARGET_STATE_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPSQUERY__TRANSITION_WITHOUT_TARGET_STATE_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/Cpsquery/CpsqueryQueryGroup.h"
#include "Viatra/Query/Cpsquery/StateTransitionMatcher.h"
#include "Viatra/Query/Cpsquery/TransitionWithoutTargetStateFrame_0.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class TransitionWithoutTargetStateMatcher;

template<class ModelRoot>
class TransitionWithoutTargetStateQuerySpecification {
public:
	using Matcher = TransitionWithoutTargetStateMatcher<ModelRoot>;

	using QueryGroup = CpsqueryQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<TransitionWithoutTargetStateFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<TransitionWithoutTargetStateFrame_0> sp;
		
		StateTransitionMatcher<ModelRoot> matcher_1595386013(model,  CpsqueryQueryGroup::instance()->context());
		
		sp.add_operation(create_IterateOverInstances(&TransitionWithoutTargetStateFrame_0::_2, ::cyberPhysicalSystem::State::type_id, model));
		sp.add_operation(create_NavigateMultiAssociation(&TransitionWithoutTargetStateFrame_0::_2, &TransitionWithoutTargetStateFrame_0::_0, &::cyberPhysicalSystem::State::outgoingTransitions));
		sp.add_operation(create_InstanceOfCheck(&TransitionWithoutTargetStateFrame_0::_2, ::cyberPhysicalSystem::State::type_id));
		sp.add_operation(create_NACOperation<TransitionWithoutTargetStateFrame_0>(matcher_1595386013, &TransitionWithoutTargetStateFrame_0::_2, &TransitionWithoutTargetStateFrame_0::_0));
		
		return sp;
	}

};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__TRANSITION_WITHOUT_TARGET_STATE_QUERY_SPECIFICATION_H_ */
