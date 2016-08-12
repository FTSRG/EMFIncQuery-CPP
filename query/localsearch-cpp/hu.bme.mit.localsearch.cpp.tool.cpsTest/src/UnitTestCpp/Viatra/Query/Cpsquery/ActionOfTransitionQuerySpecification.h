#ifndef VIATRA__QUERY__CPSQUERY__ACTION_OF_TRANSITION_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPSQUERY__ACTION_OF_TRANSITION_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/Cpsquery/ActionOfTransitionFrame_0.h"
#include "Viatra/Query/Cpsquery/CpsqueryQueryGroup.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class ActionOfTransitionMatcher;

template<class ModelRoot>
class ActionOfTransitionQuerySpecification {
public:
	using Matcher = ActionOfTransitionMatcher<ModelRoot>;

	using QueryGroup = CpsqueryQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<ActionOfTransitionFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<ActionOfTransitionFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&ActionOfTransitionFrame_0::_0, ::cyberPhysicalSystem::Transition::type_id, model));
		sp.add_operation(create_NavigateSingleAssociation(&ActionOfTransitionFrame_0::_0, &ActionOfTransitionFrame_0::_1, &::cyberPhysicalSystem::Transition::action));
		sp.add_operation(create_InstanceOfCheck(&ActionOfTransitionFrame_0::_0, ::cyberPhysicalSystem::Transition::type_id));
		
		return sp;
	}

};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__ACTION_OF_TRANSITION_QUERY_SPECIFICATION_H_ */
