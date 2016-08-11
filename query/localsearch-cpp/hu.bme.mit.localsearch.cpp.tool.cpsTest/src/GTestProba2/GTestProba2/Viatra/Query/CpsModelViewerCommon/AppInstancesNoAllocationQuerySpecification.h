#ifndef VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__APP_INSTANCES_NO_ALLOCATION_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__APP_INSTANCES_NO_ALLOCATION_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/CpsModelViewerCommon/AppInstancesNoAllocationFrame_0.h"
#include "Viatra/Query/CpsModelViewerCommon/AppInstancesWithAllocationMatcher.h"
#include "Viatra/Query/CpsModelViewerCommon/CpsModelViewerCommonQueryGroup.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace CpsModelViewerCommon {

template<class ModelRoot>
class AppInstancesNoAllocationMatcher;

template<class ModelRoot>
class AppInstancesNoAllocationQuerySpecification {
public:
	using Matcher = AppInstancesNoAllocationMatcher<ModelRoot>;

	using QueryGroup = CpsModelViewerCommonQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<AppInstancesNoAllocationFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<AppInstancesNoAllocationFrame_0> sp;
		
		AppInstancesWithAllocationMatcher<ModelRoot> matcher_63076438(model,  CpsModelViewerCommonQueryGroup::instance()->context());
		
		sp.add_operation(create_IterateOverInstances(&AppInstancesNoAllocationFrame_0::_0, ::cyberPhysicalSystem::ApplicationInstance::type_id, model));
		sp.add_operation(create_NACOperation<AppInstancesNoAllocationFrame_0>(matcher_63076438, &AppInstancesNoAllocationFrame_0::_0));
		
		return sp;
	}

};

} /* namespace CpsModelViewerCommon */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__APP_INSTANCES_NO_ALLOCATION_QUERY_SPECIFICATION_H_ */
