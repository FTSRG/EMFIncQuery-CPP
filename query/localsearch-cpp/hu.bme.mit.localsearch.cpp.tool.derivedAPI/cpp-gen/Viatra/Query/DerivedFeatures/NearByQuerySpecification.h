#ifndef VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/DerivedFeatures/DerivedFeaturesQueryGroup.h"
#include "Viatra/Query/DerivedFeatures/NearByFrame_0.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace DerivedFeatures {

template<class ModelRoot>
class NearByMatcher;

template<class ModelRoot>
class NearByQuerySpecification {
public:
	using Matcher = NearByMatcher<ModelRoot>;

	using QueryGroup = DerivedFeaturesQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<NearByFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<NearByFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&NearByFrame_0::_0, ::RailRoadModel::RobotPart::type_id, model));
		sp.add_operation(create_InstanceOfCheck(&NearByFrame_0::_0, ::RailRoadModel::RobotPart::type_id));
		sp.add_operation(create_NavigateSingleAssociation(&NearByFrame_0::_0, &NearByFrame_0::_1, &::RailRoadModel::RobotPart::id));
		sp.add_operation(create_IterateOverInstances(&NearByFrame_0::_2, ::RailRoadModel::Train::type_id, model));
		sp.add_operation(create_NavigateSingleAssociation(&NearByFrame_0::_2, &NearByFrame_0::_3, &::RailRoadModel::Train::id));
		sp.add_operation(create_InstanceOfCheck(&NearByFrame_0::_2, ::RailRoadModel::Train::type_id));
		sp.add_operation(create_InstanceOfCheck(&NearByFrame_0::_2, ::RailRoadModel::Train::type_id));
		sp.add_operation(create_CheckExpression<NearByFrame_0>(
			[](double robY, double trX, double trY, double robX, double trZ, double robZ){
				// Please implement the following 
				// <XBinaryOperationImplCustom> && <XBinaryOperationImplCustom>
				//
				
				static_assert(false, "Please implement the Check expression");	
			},
			&NearByFrame_0::_5, &NearByFrame_0::_7, &NearByFrame_0::_8, &NearByFrame_0::_4, &NearByFrame_0::_9, &NearByFrame_0::_6
		)
		);
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<NearByFrame_0> get_plan_robotPartID_trainID_robX_robY_robZ_trX_trY_trZ__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<NearByFrame_0> sp;
		
		
		sp.add_operation(create_CheckExpression<NearByFrame_0>(
			[](double robY, double trX, double trY, double robX, double trZ, double robZ){
				// Please implement the following 
				// <XBinaryOperationImplCustom> && <XBinaryOperationImplCustom>
				//
				
				static_assert(false, "Please implement the Check expression");	
			},
			&NearByFrame_0::_5, &NearByFrame_0::_7, &NearByFrame_0::_8, &NearByFrame_0::_4, &NearByFrame_0::_9, &NearByFrame_0::_6
		)
		);
		sp.add_operation(create_IterateOverInstances(&NearByFrame_0::_0, ::RailRoadModel::RobotPart::type_id, model));
		sp.add_operation(create_InstanceOfCheck(&NearByFrame_0::_0, ::RailRoadModel::RobotPart::type_id));
		sp.add_operation(create_SingleAssociationCheck(&NearByFrame_0::_0, &NearByFrame_0::_1, &::RailRoadModel::RobotPart::id));
		sp.add_operation(create_IterateOverInstances(&NearByFrame_0::_2, ::RailRoadModel::Train::type_id, model));
		sp.add_operation(create_InstanceOfCheck(&NearByFrame_0::_2, ::RailRoadModel::Train::type_id));
		sp.add_operation(create_SingleAssociationCheck(&NearByFrame_0::_2, &NearByFrame_0::_3, &::RailRoadModel::Train::id));
		
		return sp;
	}

};

} /* namespace DerivedFeatures */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_QUERY_SPECIFICATION_H_ */
