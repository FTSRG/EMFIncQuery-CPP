#ifndef VIATRA__QUERY__SNCL_RUNTIME__RING_MEMBERS_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__SNCL_RUNTIME__RING_MEMBERS_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Sncl_runtime/LinkedMatcher.h"
#include "Viatra/Query/Sncl_runtime/PconnectedMatcher.h"
#include "Viatra/Query/Sncl_runtime/RingMembersFrame_0.h"
#include "Viatra/Query/Sncl_runtime/RingMembersMatch.h"
#include "Viatra/Query/Sncl_runtime/Sncl_runtimeQueryGroup.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

template<class ModelRoot>
class RingMembersMatcher;

template<class ModelRoot>
class RingMembersQuerySpecification {
public:
	using Matcher = RingMembersMatcher<ModelRoot>;
	using Match = RingMembersMatch;
	using QueryGroup = Sncl_runtimeQueryGroup;
						
	static ::Viatra::Query::Plan::SearchPlan<RingMembersFrame_0> get_plan_unbound__0(const ModelRoot* model, std::map<int,RingMembersFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<RingMembersFrame_0> sp;
		
		PconnectedMatcher<ModelRoot> matcher_401343568(model,  Sncl_runtimeQueryGroup::instance()->context());
		LinkedMatcher<ModelRoot> matcher_1070190758(model,  Sncl_runtimeQueryGroup::instance()->context());
		
		sp.add_operation(create_ConstantValueExtend(&RingMembersFrame_0::_5, 2));
		sp.add_operation(create_ConstantValueExtend(&RingMembersFrame_0::_2, 4));
		sp.add_operation(create_GlobalIterateOverInstances<RingMembersFrame_0>(3, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&RingMembersFrame_0::_0, ::arch::ICL::get_static_type_id(), model));
		sp.add_operation(create_PatternMatchCounterCheck<RingMembersFrame_0>(matcher_401343568, &RingMembersFrame_0::_2, &RingMembersFrame_0::_0));
		sp.add_operation(create_DistributeIfNotPresent<RingMembersFrame_0>(6, subFrames, &RingMembersFrame_0::_0));
		sp.add_operation(create_NavigateSingleAssociation(&RingMembersFrame_0::_0, &RingMembersFrame_0::_4, &::arch::ICL::get_cnn));
		sp.add_operation(create_PatternMatchCounterCheck<RingMembersFrame_0>(matcher_1070190758, &RingMembersFrame_0::_5, &RingMembersFrame_0::_4));
		
		return sp;
	}

};

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__RING_MEMBERS_QUERY_SPECIFICATION_H_ */
