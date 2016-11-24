#ifndef VIATRA__QUERY__SNCL_RUNTIME__NOT_IN_RING_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__SNCL_RUNTIME__NOT_IN_RING_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Sncl_runtime/NotInRingFrame_0.h"
#include "Viatra/Query/Sncl_runtime/NotInRingMatch.h"
#include "Viatra/Query/Sncl_runtime/PconnectedMatcher.h"
#include "Viatra/Query/Sncl_runtime/Sncl_runtimeQueryGroup.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

template<class ModelRoot>
class NotInRingMatcher;

template<class ModelRoot>
class NotInRingQuerySpecification {
public:
	using Matcher = NotInRingMatcher<ModelRoot>;
	using Match = NotInRingMatch;
	using QueryGroup = Sncl_runtimeQueryGroup;
						
	static ::Viatra::Query::Plan::SearchPlan<NotInRingFrame_0> get_plan_unbound__0(const ModelRoot* model, std::map<int,NotInRingFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<NotInRingFrame_0> sp;
		
		PconnectedMatcher<ModelRoot> matcher_481546701(model,  Sncl_runtimeQueryGroup::instance()->context());
		
		sp.add_operation(create_ConstantValueExtend(&NotInRingFrame_0::_3, 4));
		sp.add_operation(create_GlobalIterateOverInstances<NotInRingFrame_0>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&NotInRingFrame_0::_0, ::arch::ICL::get_static_type_id(), model));
		sp.add_operation(create_PatternMatchCounterExtend<NotInRingFrame_0>(matcher_481546701, &NotInRingFrame_0::_1, &NotInRingFrame_0::_0));
		sp.add_operation(create_InequalityCheck(&NotInRingFrame_0::_1, &NotInRingFrame_0::_3));
		
		return sp;
	}

};

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__NOT_IN_RING_QUERY_SPECIFICATION_H_ */
