#ifndef VIATRA__QUERY__CPSQUERY__AVAILABLE_GREATER_THAN_TOTAL_HDD_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPSQUERY__AVAILABLE_GREATER_THAN_TOTAL_HDD_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/Cpsquery/AvailableGreaterThanTotalHddFrame_0.h"
#include "Viatra/Query/Cpsquery/CpsqueryQueryGroup.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class AvailableGreaterThanTotalHddMatcher;

template<class ModelRoot>
class AvailableGreaterThanTotalHddQuerySpecification {
public:
	using Matcher = AvailableGreaterThanTotalHddMatcher<ModelRoot>;

	using QueryGroup = CpsqueryQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<AvailableGreaterThanTotalHddFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<AvailableGreaterThanTotalHddFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&AvailableGreaterThanTotalHddFrame_0::_0, ::cyberPhysicalSystem::HostInstance::type_id, model));
		sp.add_operation(create_InstanceOfCheck(&AvailableGreaterThanTotalHddFrame_0::_0, ::cyberPhysicalSystem::HostInstance::type_id));
		sp.add_operation(create_InstanceOfCheck(&AvailableGreaterThanTotalHddFrame_0::_0, ::cyberPhysicalSystem::HostInstance::type_id));
		sp.add_operation(create_NavigateSingleAssociation(&AvailableGreaterThanTotalHddFrame_0::_0, &AvailableGreaterThanTotalHddFrame_0::_1, &::cyberPhysicalSystem::HostInstance::availableHdd));
		sp.add_operation(create_NavigateSingleAssociation(&AvailableGreaterThanTotalHddFrame_0::_0, &AvailableGreaterThanTotalHddFrame_0::_2, &::cyberPhysicalSystem::HostInstance::totalHdd));
		sp.add_operation(create_CheckExpression<AvailableGreaterThanTotalHddFrame_0>(
			[](int aHdd, int tHdd){
				// Please implement the following 
				// <XFeatureCallImplCustom> > <XFeatureCallImplCustom>
				//
				
				static_assert(false, "Please implement the Check expression");	
			},
			&AvailableGreaterThanTotalHddFrame_0::_1, &AvailableGreaterThanTotalHddFrame_0::_2
		)
		);
		
		return sp;
	}

};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__AVAILABLE_GREATER_THAN_TOTAL_HDD_QUERY_SPECIFICATION_H_ */
