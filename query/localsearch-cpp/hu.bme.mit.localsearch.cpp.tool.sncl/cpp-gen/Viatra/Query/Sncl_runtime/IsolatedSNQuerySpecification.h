#ifndef VIATRA__QUERY__SNCL_RUNTIME__ISOLATED_S_N_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__SNCL_RUNTIME__ISOLATED_S_N_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Sncl_runtime/IsolatedSNFrame_0.h"
#include "Viatra/Query/Sncl_runtime/IsolatedSNMatch.h"
#include "Viatra/Query/Sncl_runtime/LinkedMatcher.h"
#include "Viatra/Query/Sncl_runtime/Sncl_runtimeQueryGroup.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

template<class ModelRoot>
class IsolatedSNMatcher;

template<class ModelRoot>
class IsolatedSNQuerySpecification {
public:
	using Matcher = IsolatedSNMatcher<ModelRoot>;
	using Match = IsolatedSNMatch;
	using QueryGroup = Sncl_runtimeQueryGroup;
						
	static ::Viatra::Query::Plan::SearchPlan<IsolatedSNFrame_0> get_plan_unbound__0(const ModelRoot* model, std::map<int,IsolatedSNFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<IsolatedSNFrame_0> sp;
		
		LinkedMatcher<ModelRoot> matcher_1392164172(model,  Sncl_runtimeQueryGroup::instance()->context());
		
		sp.add_operation(create_GlobalIterateOverInstances<IsolatedSNFrame_0>(1, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&IsolatedSNFrame_0::_0, ::arch::ICL::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<IsolatedSNFrame_0>(3, subFrames, &IsolatedSNFrame_0::_0));
		sp.add_operation(create_NavigateSingleAssociation(&IsolatedSNFrame_0::_0, &IsolatedSNFrame_0::_2, &::arch::ICL::get_cnn));
		sp.add_operation(create_InstanceOfCheck(&IsolatedSNFrame_0::_0, ::arch::ICL::get_static_type_id()));
		sp.add_operation(create_NACOperation<IsolatedSNFrame_0>(matcher_1392164172, &IsolatedSNFrame_0::_2));
		
		return sp;
	}

};

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__ISOLATED_S_N_QUERY_SPECIFICATION_H_ */
