#ifndef VIATRA__QUERY__SNCL_RUNTIME__COUNT_LINKS_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__SNCL_RUNTIME__COUNT_LINKS_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Sncl_runtime/CountLinksFrame_0.h"
#include "Viatra/Query/Sncl_runtime/CountLinksMatch.h"
#include "Viatra/Query/Sncl_runtime/LinkedMatcher.h"
#include "Viatra/Query/Sncl_runtime/PconnectedMatcher.h"
#include "Viatra/Query/Sncl_runtime/Sncl_runtimeQueryGroup.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

template<class ModelRoot>
class CountLinksMatcher;

template<class ModelRoot>
class CountLinksQuerySpecification {
public:
	using Matcher = CountLinksMatcher<ModelRoot>;
	using Match = CountLinksMatch;
	using QueryGroup = Sncl_runtimeQueryGroup;
						
	static ::Viatra::Query::Plan::SearchPlan<CountLinksFrame_0> get_plan_unbound__0(const ModelRoot* model, std::map<int,CountLinksFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<CountLinksFrame_0> sp;
		
		LinkedMatcher<ModelRoot> matcher_576540774(model,  Sncl_runtimeQueryGroup::instance()->context());
		PconnectedMatcher<ModelRoot> matcher_683581715(model,  Sncl_runtimeQueryGroup::instance()->context());
		
		sp.add_operation(create_GlobalIterateOverInstances<CountLinksFrame_0>(1, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&CountLinksFrame_0::_0, ::arch::ICL::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<CountLinksFrame_0>(3, subFrames, &CountLinksFrame_0::_0));
		sp.add_operation(create_NavigateSingleAssociation(&CountLinksFrame_0::_0, &CountLinksFrame_0::_4, &::arch::ICL::get_cnn));
		sp.add_operation(create_InstanceOfCheck(&CountLinksFrame_0::_0, ::arch::ICL::get_static_type_id()));
		sp.add_operation(create_PatternMatchCounterExtend<CountLinksFrame_0>(matcher_576540774, &CountLinksFrame_0::_1, &CountLinksFrame_0::_4));
		sp.add_operation(create_PatternMatchCounterExtend<CountLinksFrame_0>(matcher_683581715, &CountLinksFrame_0::_2, &CountLinksFrame_0::_0));
		
		return sp;
	}

};

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__COUNT_LINKS_QUERY_SPECIFICATION_H_ */
