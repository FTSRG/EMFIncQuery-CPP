#ifndef VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__APP_INSTANCES_WITH_ALLOCATION_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__APP_INSTANCES_WITH_ALLOCATION_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/CpsModelViewerCommon/AppInstancesWithAllocationFrame_0.h"
#include "Viatra/Query/CpsModelViewerCommon/CpsModelViewerCommonQueryGroup.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace CpsModelViewerCommon {

template<class ModelRoot>
class AppInstancesWithAllocationMatcher;

template<class ModelRoot>
class AppInstancesWithAllocationQuerySpecification {
public:
	using Matcher = AppInstancesWithAllocationMatcher<ModelRoot>;

	using QueryGroup = CpsModelViewerCommonQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<AppInstancesWithAllocationFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<AppInstancesWithAllocationFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&AppInstancesWithAllocationFrame_0::_0, ::cyberPhysicalSystem::ApplicationInstance::type_id, model));
		sp.add_operation(create_InstanceOfCheck(&AppInstancesWithAllocationFrame_0::_0, ::cyberPhysicalSystem::ApplicationInstance::type_id));
		sp.add_operation(create_NavigateSingleAssociation(&AppInstancesWithAllocationFrame_0::_0, &AppInstancesWithAllocationFrame_0::_1, &::cyberPhysicalSystem::ApplicationInstance::allocatedTo));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<AppInstancesWithAllocationFrame_0> get_plan_app__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<AppInstancesWithAllocationFrame_0> sp;
		
		
		sp.add_operation(create_InstanceOfCheck(&AppInstancesWithAllocationFrame_0::_0, ::cyberPhysicalSystem::ApplicationInstance::type_id));
		sp.add_operation(create_InstanceOfCheck(&AppInstancesWithAllocationFrame_0::_0, ::cyberPhysicalSystem::ApplicationInstance::type_id));
		sp.add_operation(create_NavigateSingleAssociation(&AppInstancesWithAllocationFrame_0::_0, &AppInstancesWithAllocationFrame_0::_1, &::cyberPhysicalSystem::ApplicationInstance::allocatedTo));
		
		return sp;
	}

};

} /* namespace CpsModelViewerCommon */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__APP_INSTANCES_WITH_ALLOCATION_QUERY_SPECIFICATION_H_ */
