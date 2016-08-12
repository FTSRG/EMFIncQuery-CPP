#ifndef VIATRA__QUERY__CPSQUERY__MULTIPLE_TRANSITIONS_WITH_SAME_ACTION_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPSQUERY__MULTIPLE_TRANSITIONS_WITH_SAME_ACTION_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/Cpsquery/CpsqueryQueryGroup.h"
#include "Viatra/Query/Cpsquery/MultipleTransitionsWithSameActionFrame_0.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class MultipleTransitionsWithSameActionMatcher;

template<class ModelRoot>
class MultipleTransitionsWithSameActionQuerySpecification {
public:
	using Matcher = MultipleTransitionsWithSameActionMatcher<ModelRoot>;

	using QueryGroup = CpsqueryQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<MultipleTransitionsWithSameActionFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<MultipleTransitionsWithSameActionFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&MultipleTransitionsWithSameActionFrame_0::_0, ::cyberPhysicalSystem::State::type_id, model));
		sp.add_operation(create_InstanceOfCheck(&MultipleTransitionsWithSameActionFrame_0::_0, ::cyberPhysicalSystem::State::type_id));
		sp.add_operation(create_NavigateMultiAssociation(&MultipleTransitionsWithSameActionFrame_0::_0, &MultipleTransitionsWithSameActionFrame_0::_3, &::cyberPhysicalSystem::State::outgoingTransitions));
		sp.add_operation(create_InstanceOfCheck(&MultipleTransitionsWithSameActionFrame_0::_3, ::cyberPhysicalSystem::Transition::type_id));
		sp.add_operation(create_IterateOverInstances(&MultipleTransitionsWithSameActionFrame_0::_2, ::cyberPhysicalSystem::Transition::type_id, model));
		sp.add_operation(create_NavigateSingleAssociation(&MultipleTransitionsWithSameActionFrame_0::_2, &MultipleTransitionsWithSameActionFrame_0::_1, &::cyberPhysicalSystem::Transition::action));
		sp.add_operation(create_InstanceOfCheck(&MultipleTransitionsWithSameActionFrame_0::_2, ::cyberPhysicalSystem::Transition::type_id));
		sp.add_operation(create_SingleAssociationCheck(&MultipleTransitionsWithSameActionFrame_0::_3, &MultipleTransitionsWithSameActionFrame_0::_1, &::cyberPhysicalSystem::Transition::action));
		sp.add_operation(create_MultiAssociationCheck(&MultipleTransitionsWithSameActionFrame_0::_0, &MultipleTransitionsWithSameActionFrame_0::_2, &::cyberPhysicalSystem::State::outgoingTransitions));
		sp.add_operation(create_InequalityCheck(&MultipleTransitionsWithSameActionFrame_0::_3, &MultipleTransitionsWithSameActionFrame_0::_2));
		
		return sp;
	}

};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__MULTIPLE_TRANSITIONS_WITH_SAME_ACTION_QUERY_SPECIFICATION_H_ */
