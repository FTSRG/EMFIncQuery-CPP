#ifndef VIATRA__QUERY__SNCL_RUNTIME__NUM_EQUALITY_WITH_MEMBER_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__SNCL_RUNTIME__NUM_EQUALITY_WITH_MEMBER_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Sncl_runtime/LinkedMatcher.h"
#include "Viatra/Query/Sncl_runtime/NumEqualityWithMemberFrame_0.h"
#include "Viatra/Query/Sncl_runtime/NumEqualityWithMemberMatch.h"
#include "Viatra/Query/Sncl_runtime/Sncl_runtimeQueryGroup.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

template<class ModelRoot>
class NumEqualityWithMemberMatcher;

template<class ModelRoot>
class NumEqualityWithMemberQuerySpecification {
public:
	using Matcher = NumEqualityWithMemberMatcher<ModelRoot>;
	using Match = NumEqualityWithMemberMatch;
	using QueryGroup = Sncl_runtimeQueryGroup;
						
	static ::Viatra::Query::Plan::SearchPlan<NumEqualityWithMemberFrame_0> get_plan_unbound__0(const ModelRoot* model, std::map<int,NumEqualityWithMemberFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<NumEqualityWithMemberFrame_0> sp;
		
		LinkedMatcher<ModelRoot> matcher_2143840536(model,  Sncl_runtimeQueryGroup::instance()->context());
		
		sp.add_operation(create_GlobalIterateOverInstances<NumEqualityWithMemberFrame_0>(1, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&NumEqualityWithMemberFrame_0::_0, ::arch::ICL::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<NumEqualityWithMemberFrame_0>(3, subFrames, &NumEqualityWithMemberFrame_0::_0));
		sp.add_operation(create_NavigateSingleAssociation(&NumEqualityWithMemberFrame_0::_0, &NumEqualityWithMemberFrame_0::_1, &::arch::ICL::get_cnn));
		sp.add_operation(create_InstanceOfCheck(&NumEqualityWithMemberFrame_0::_0, ::arch::ICL::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NumEqualityWithMemberFrame_0::_0, ::arch::ICL::get_static_type_id()));
		sp.add_operation(create_PatternMatchCounterExtend<NumEqualityWithMemberFrame_0>(matcher_2143840536, &NumEqualityWithMemberFrame_0::_2, &NumEqualityWithMemberFrame_0::_1));
		sp.add_operation(create_DistributeIfNotPresent<NumEqualityWithMemberFrame_0>(8, subFrames, &NumEqualityWithMemberFrame_0::_0));
		sp.add_operation(create_SingleAssociationCheck(&NumEqualityWithMemberFrame_0::_0, &NumEqualityWithMemberFrame_0::_2, &::arch::ICL::get_countReachableSN));
		
		return sp;
	}

};

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__NUM_EQUALITY_WITH_MEMBER_QUERY_SPECIFICATION_H_ */
