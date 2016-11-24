#ifndef VIATRA__QUERY__SNCL_RUNTIME__NUM_IN_EQUALITY_WITH_MEMBER_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__SNCL_RUNTIME__NUM_IN_EQUALITY_WITH_MEMBER_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Sncl_runtime/LinkedMatcher.h"
#include "Viatra/Query/Sncl_runtime/NumInEqualityWithMemberFrame_0.h"
#include "Viatra/Query/Sncl_runtime/NumInEqualityWithMemberMatch.h"
#include "Viatra/Query/Sncl_runtime/Sncl_runtimeQueryGroup.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

template<class ModelRoot>
class NumInEqualityWithMemberMatcher;

template<class ModelRoot>
class NumInEqualityWithMemberQuerySpecification {
public:
	using Matcher = NumInEqualityWithMemberMatcher<ModelRoot>;
	using Match = NumInEqualityWithMemberMatch;
	using QueryGroup = Sncl_runtimeQueryGroup;
						
	static ::Viatra::Query::Plan::SearchPlan<NumInEqualityWithMemberFrame_0> get_plan_unbound__0(const ModelRoot* model, std::map<int,NumInEqualityWithMemberFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<NumInEqualityWithMemberFrame_0> sp;
		
		LinkedMatcher<ModelRoot> matcher_1258590225(model,  Sncl_runtimeQueryGroup::instance()->context());
		
		sp.add_operation(create_GlobalIterateOverInstances<NumInEqualityWithMemberFrame_0>(1, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&NumInEqualityWithMemberFrame_0::_0, ::arch::ICL::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<NumInEqualityWithMemberFrame_0>(3, subFrames, &NumInEqualityWithMemberFrame_0::_0));
		sp.add_operation(create_NavigateSingleAssociation(&NumInEqualityWithMemberFrame_0::_0, &NumInEqualityWithMemberFrame_0::_1, &::arch::ICL::get_countReachableSN));
		sp.add_operation(create_InstanceOfCheck(&NumInEqualityWithMemberFrame_0::_0, ::arch::ICL::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NumInEqualityWithMemberFrame_0::_0, ::arch::ICL::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NumInEqualityWithMemberFrame_0>(7, subFrames, &NumInEqualityWithMemberFrame_0::_0));
		sp.add_operation(create_NavigateSingleAssociation(&NumInEqualityWithMemberFrame_0::_0, &NumInEqualityWithMemberFrame_0::_2, &::arch::ICL::get_cnn));
		sp.add_operation(create_PatternMatchCounterExtend<NumInEqualityWithMemberFrame_0>(matcher_1258590225, &NumInEqualityWithMemberFrame_0::_4, &NumInEqualityWithMemberFrame_0::_2));
		sp.add_operation(create_InequalityCheck(&NumInEqualityWithMemberFrame_0::_4, &NumInEqualityWithMemberFrame_0::_1));
		
		return sp;
	}

};

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__NUM_IN_EQUALITY_WITH_MEMBER_QUERY_SPECIFICATION_H_ */
