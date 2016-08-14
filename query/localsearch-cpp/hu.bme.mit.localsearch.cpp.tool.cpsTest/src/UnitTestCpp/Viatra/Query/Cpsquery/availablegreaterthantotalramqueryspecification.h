#ifndef VIATRA__QUERY__CPSQUERY__AVAILABLE_GREATER_THAN_TOTAL_RAM_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPSQUERY__AVAILABLE_GREATER_THAN_TOTAL_RAM_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/Cpsquery/AvailableGreaterThanTotalRamFrame_0.h"
#include "Viatra/Query/Cpsquery/CpsqueryQueryGroup.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class AvailableGreaterThanTotalRamMatcher;

template<class ModelRoot>
class AvailableGreaterThanTotalRamQuerySpecification {
public:
	using Matcher = AvailableGreaterThanTotalRamMatcher<ModelRoot>;

	using QueryGroup = CpsqueryQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<AvailableGreaterThanTotalRamFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<AvailableGreaterThanTotalRamFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&AvailableGreaterThanTotalRamFrame_0::_0, ::cyberPhysicalSystem::HostInstance::type_id, model));
		sp.add_operation(create_InstanceOfCheck(&AvailableGreaterThanTotalRamFrame_0::_0, ::cyberPhysicalSystem::HostInstance::type_id));
		sp.add_operation(create_InstanceOfCheck(&AvailableGreaterThanTotalRamFrame_0::_0, ::cyberPhysicalSystem::HostInstance::type_id));
		sp.add_operation(create_NavigateSingleAssociation(&AvailableGreaterThanTotalRamFrame_0::_0, &AvailableGreaterThanTotalRamFrame_0::_2, &::cyberPhysicalSystem::HostInstance::availableRam));
		sp.add_operation(create_NavigateSingleAssociation(&AvailableGreaterThanTotalRamFrame_0::_0, &AvailableGreaterThanTotalRamFrame_0::_1, &::cyberPhysicalSystem::HostInstance::totalRam));
		sp.add_operation(create_CheckExpression<AvailableGreaterThanTotalRamFrame_0>(
			[](int tRam, int aRam){
			return aRam > tRam;
			},
			&AvailableGreaterThanTotalRamFrame_0::_1, &AvailableGreaterThanTotalRamFrame_0::_2
		)
		);
		
		return sp;
	}

};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__AVAILABLE_GREATER_THAN_TOTAL_RAM_QUERY_SPECIFICATION_H_ */
