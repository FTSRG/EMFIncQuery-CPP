#ifndef VIATRA__QUERY__SNCL_RUNTIME__ISOLATED_C_L_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__SNCL_RUNTIME__ISOLATED_C_L_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Sncl_runtime/IsolatedCLFrame_0.h"
#include "Viatra/Query/Sncl_runtime/IsolatedCLMatch.h"
#include "Viatra/Query/Sncl_runtime/PconnectedMatcher.h"
#include "Viatra/Query/Sncl_runtime/Sncl_runtimeQueryGroup.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

template<class ModelRoot>
class IsolatedCLMatcher;

template<class ModelRoot>
class IsolatedCLQuerySpecification {
public:
	using Matcher = IsolatedCLMatcher<ModelRoot>;
	using Match = IsolatedCLMatch;
	using QueryGroup = Sncl_runtimeQueryGroup;
						
	static ::Viatra::Query::Plan::SearchPlan<IsolatedCLFrame_0> get_plan_unbound__0(const ModelRoot* model, std::map<int,IsolatedCLFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<IsolatedCLFrame_0> sp;
		
		PconnectedMatcher<ModelRoot> matcher_78551071(model,  Sncl_runtimeQueryGroup::instance()->context());
		
		sp.add_operation(create_GlobalIterateOverInstances<IsolatedCLFrame_0>(1, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&IsolatedCLFrame_0::_0, ::arch::ICL::get_static_type_id(), model));
		sp.add_operation(create_NACOperation<IsolatedCLFrame_0>(matcher_78551071, &IsolatedCLFrame_0::_0));
		
		return sp;
	}

};

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__ISOLATED_C_L_QUERY_SPECIFICATION_H_ */
