#ifndef VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__ALL_HOST_INSTANCES_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__ALL_HOST_INSTANCES_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/CpsModelViewerCommon/AllHostInstancesFrame_0.h"
#include "Viatra/Query/CpsModelViewerCommon/CpsModelViewerCommonQueryGroup.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace CpsModelViewerCommon {

template<class ModelRoot>
class AllHostInstancesMatcher;

template<class ModelRoot>
class AllHostInstancesQuerySpecification {
public:
	using Matcher = AllHostInstancesMatcher<ModelRoot>;

	using QueryGroup = CpsModelViewerCommonQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<AllHostInstancesFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<AllHostInstancesFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&AllHostInstancesFrame_0::_0, ::cyberPhysicalSystem::HostInstance::type_id, model));
		
		return sp;
	}

};

} /* namespace CpsModelViewerCommon */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__ALL_HOST_INSTANCES_QUERY_SPECIFICATION_H_ */
