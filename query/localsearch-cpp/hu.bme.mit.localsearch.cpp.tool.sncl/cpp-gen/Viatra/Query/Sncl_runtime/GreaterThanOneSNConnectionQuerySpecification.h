#ifndef VIATRA__QUERY__SNCL_RUNTIME__GREATER_THAN_ONE_S_N_CONNECTION_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__SNCL_RUNTIME__GREATER_THAN_ONE_S_N_CONNECTION_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Sncl_runtime/GreaterThanOneSNConnectionFrame_0.h"
#include "Viatra/Query/Sncl_runtime/GreaterThanOneSNConnectionMatch.h"
#include "Viatra/Query/Sncl_runtime/LinkedMatcher.h"
#include "Viatra/Query/Sncl_runtime/Sncl_runtimeQueryGroup.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

template<class ModelRoot>
class GreaterThanOneSNConnectionMatcher;

template<class ModelRoot>
class GreaterThanOneSNConnectionQuerySpecification {
public:
	using Matcher = GreaterThanOneSNConnectionMatcher<ModelRoot>;
	using Match = GreaterThanOneSNConnectionMatch;
	using QueryGroup = Sncl_runtimeQueryGroup;
						
	static ::Viatra::Query::Plan::SearchPlan<GreaterThanOneSNConnectionFrame_0> get_plan_unbound__0(const ModelRoot* model, std::map<int,GreaterThanOneSNConnectionFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<GreaterThanOneSNConnectionFrame_0> sp;
		
		LinkedMatcher<ModelRoot> matcher_1947456199(model,  Sncl_runtimeQueryGroup::instance()->context());
		LinkedMatcher<ModelRoot> matcher_1296017970(model,  Sncl_runtimeQueryGroup::instance()->context());
		
		sp.add_operation(create_ConstantValueExtend(&GreaterThanOneSNConnectionFrame_0::_3, 0));
		sp.add_operation(create_ConstantValueExtend(&GreaterThanOneSNConnectionFrame_0::_5, 1));
		sp.add_operation(create_GlobalIterateOverInstances<GreaterThanOneSNConnectionFrame_0>(3, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&GreaterThanOneSNConnectionFrame_0::_0, ::arch::ICL::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<GreaterThanOneSNConnectionFrame_0>(5, subFrames, &GreaterThanOneSNConnectionFrame_0::_0));
		sp.add_operation(create_NavigateSingleAssociation(&GreaterThanOneSNConnectionFrame_0::_0, &GreaterThanOneSNConnectionFrame_0::_6, &::arch::ICL::get_cnn));
		sp.add_operation(create_InstanceOfCheck(&GreaterThanOneSNConnectionFrame_0::_0, ::arch::ICL::get_static_type_id()));
		sp.add_operation(create_PatternMatchCounterExtend<GreaterThanOneSNConnectionFrame_0>(matcher_1947456199, &GreaterThanOneSNConnectionFrame_0::_2, &GreaterThanOneSNConnectionFrame_0::_6));
		sp.add_operation(create_InequalityCheck(&GreaterThanOneSNConnectionFrame_0::_3, &GreaterThanOneSNConnectionFrame_0::_2));
		sp.add_operation(create_PatternMatchCounterExtend<GreaterThanOneSNConnectionFrame_0>(matcher_1296017970, &GreaterThanOneSNConnectionFrame_0::_1, &GreaterThanOneSNConnectionFrame_0::_6));
		sp.add_operation(create_InequalityCheck(&GreaterThanOneSNConnectionFrame_0::_5, &GreaterThanOneSNConnectionFrame_0::_1));
		
		return sp;
	}

};

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__GREATER_THAN_ONE_S_N_CONNECTION_QUERY_SPECIFICATION_H_ */
