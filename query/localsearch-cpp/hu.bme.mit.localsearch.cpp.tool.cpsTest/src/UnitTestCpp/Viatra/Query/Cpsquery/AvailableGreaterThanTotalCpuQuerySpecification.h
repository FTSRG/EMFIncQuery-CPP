#ifndef VIATRA__QUERY__CPSQUERY__AVAILABLE_GREATER_THAN_TOTAL_CPU_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPSQUERY__AVAILABLE_GREATER_THAN_TOTAL_CPU_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/Cpsquery/AvailableGreaterThanTotalCpuFrame_0.h"
#include "Viatra/Query/Cpsquery/CpsqueryQueryGroup.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class AvailableGreaterThanTotalCpuMatcher;

template<class ModelRoot>
class AvailableGreaterThanTotalCpuQuerySpecification {
public:
	using Matcher = AvailableGreaterThanTotalCpuMatcher<ModelRoot>;

	using QueryGroup = CpsqueryQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<AvailableGreaterThanTotalCpuFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<AvailableGreaterThanTotalCpuFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&AvailableGreaterThanTotalCpuFrame_0::_0, ::cyberPhysicalSystem::HostInstance::type_id, model));
		sp.add_operation(create_InstanceOfCheck(&AvailableGreaterThanTotalCpuFrame_0::_0, ::cyberPhysicalSystem::HostInstance::type_id));
		sp.add_operation(create_InstanceOfCheck(&AvailableGreaterThanTotalCpuFrame_0::_0, ::cyberPhysicalSystem::HostInstance::type_id));
		sp.add_operation(create_NavigateSingleAssociation(&AvailableGreaterThanTotalCpuFrame_0::_0, &AvailableGreaterThanTotalCpuFrame_0::_1, &::cyberPhysicalSystem::HostInstance::availableCpu));
		sp.add_operation(create_NavigateSingleAssociation(&AvailableGreaterThanTotalCpuFrame_0::_0, &AvailableGreaterThanTotalCpuFrame_0::_2, &::cyberPhysicalSystem::HostInstance::totalCpu));
		sp.add_operation(create_CheckExpression<AvailableGreaterThanTotalCpuFrame_0>(
			[](int aCpu, int tCpu){
				// Please implement the following 
				// <XFeatureCallImplCustom> > <XFeatureCallImplCustom>
				//
				
				static_assert(false, "Please implement the Check expression");	
			},
			&AvailableGreaterThanTotalCpuFrame_0::_1, &AvailableGreaterThanTotalCpuFrame_0::_2
		)
		);
		
		return sp;
	}

};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__AVAILABLE_GREATER_THAN_TOTAL_CPU_QUERY_SPECIFICATION_H_ */
