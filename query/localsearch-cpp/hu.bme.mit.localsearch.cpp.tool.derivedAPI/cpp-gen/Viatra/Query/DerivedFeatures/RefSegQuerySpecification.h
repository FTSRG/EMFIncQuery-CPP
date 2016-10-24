#ifndef VIATRA__QUERY__DERIVED_FEATURES__REF_SEG_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__DERIVED_FEATURES__REF_SEG_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/DerivedFeatures/DerivedFeaturesQueryGroup.h"
#include "Viatra/Query/DerivedFeatures/RefSegFrame_0.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace DerivedFeatures {

template<class ModelRoot>
class RefSegMatcher;

template<class ModelRoot>
class RefSegQuerySpecification {
public:
	using Matcher = RefSegMatcher<ModelRoot>;
	using Match = RefSegMatcher<ModelRoot>;
	using QueryGroup = DerivedFeaturesQueryGroup;
	
	static constexpr int queryID = 12;
			
	// queryID = 12
	static ::Viatra::Query::Plan::SearchPlan<RefSegFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<RefSegFrame_0> sp;
		
		
		sp.add_operation(create_GlobalIterateOverInstances(&RefSegFrame_0::_0, ::RailRoadModel::IRobotPart::get_type_id(), model));
		sp.add_operation(create_LocalIterateOverInstances(&RefSegFrame_0::_0, ::RailRoadModel::IRobotPart::get_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_0, ::RailRoadModel::IRobotPart::get_type_id()));
		sp.add_operation(create_NavigateSingleAssociation(&RefSegFrame_0::_0, &RefSegFrame_0::_1, &::RailRoadModel::IRobotPart::id));
		sp.add_operation(create_GlobalIterateOverInstances(&RefSegFrame_0::_2, ::RailRoadModel::IRailRoadElement::get_type_id(), model));
		sp.add_operation(create_LocalIterateOverInstances(&RefSegFrame_0::_2, ::RailRoadModel::IRailRoadElement::get_type_id(), model));
		sp.add_operation(create_NavigateSingleAssociation(&RefSegFrame_0::_2, &RefSegFrame_0::_3, &::RailRoadModel::ISegment::id));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_2, ::RailRoadModel::ISegment::get_type_id()));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_2, ::RailRoadModel::ISegment::get_type_id()));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_2, ::RailRoadModel::ISegment::get_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances(&RefSegFrame_0::_8, ::RailRoadModel::IPoint::get_type_id(), model));
		sp.add_operation(create_LocalIterateOverInstances(&RefSegFrame_0::_8, ::RailRoadModel::IPoint::get_type_id(), model));
		sp.add_operation(create_NavigateSingleAssociation(&RefSegFrame_0::_8, &RefSegFrame_0::_9, &::RailRoadModel::IPoint::x));
		sp.add_operation(create_MultiAssociationCheck(&RefSegFrame_0::_2, &RefSegFrame_0::_8, &::RailRoadModel::ISegment::points));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_8, ::RailRoadModel::IPoint::get_type_id()));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_8, ::RailRoadModel::IPoint::get_type_id()));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_8, ::RailRoadModel::IPoint::get_type_id()));
		sp.add_operation(create_NavigateSingleAssociation(&RefSegFrame_0::_8, &RefSegFrame_0::_7, &::RailRoadModel::IPoint::y));
		sp.add_operation(create_NavigateSingleAssociation(&RefSegFrame_0::_8, &RefSegFrame_0::_10, &::RailRoadModel::IPoint::z));
		sp.add_operation(create_CheckExpression<RefSegFrame_0>(
			[](double robX, double robY, double sY, double sX, double sZ, double robZ){
				// Please implement the following 
				// <XBinaryOperationImplCustom> && <XBinaryOperationImplCustom>
				//
				
				static_assert(false, "Please implement the Check expression");	
			},
			&RefSegFrame_0::_4, &RefSegFrame_0::_5, &RefSegFrame_0::_7, &RefSegFrame_0::_9, &RefSegFrame_0::_10, &RefSegFrame_0::_6
		)
		);
		
		return sp;
	}
	// queryID = 13
	static ::Viatra::Query::Plan::SearchPlan<RefSegFrame_0> get_plan_robotPartID_robX_robY_robZ__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<RefSegFrame_0> sp;
		
		
		sp.add_operation(create_GlobalIterateOverInstances(&RefSegFrame_0::_0, ::RailRoadModel::IRobotPart::get_type_id(), model));
		sp.add_operation(create_LocalIterateOverInstances(&RefSegFrame_0::_0, ::RailRoadModel::IRobotPart::get_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_0, ::RailRoadModel::IRobotPart::get_type_id()));
		sp.add_operation(create_SingleAssociationCheck(&RefSegFrame_0::_0, &RefSegFrame_0::_1, &::RailRoadModel::IRobotPart::id));
		sp.add_operation(create_GlobalIterateOverInstances(&RefSegFrame_0::_2, ::RailRoadModel::IRailRoadElement::get_type_id(), model));
		sp.add_operation(create_LocalIterateOverInstances(&RefSegFrame_0::_2, ::RailRoadModel::IRailRoadElement::get_type_id(), model));
		sp.add_operation(create_NavigateSingleAssociation(&RefSegFrame_0::_2, &RefSegFrame_0::_3, &::RailRoadModel::ISegment::id));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_2, ::RailRoadModel::ISegment::get_type_id()));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_2, ::RailRoadModel::ISegment::get_type_id()));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_2, ::RailRoadModel::ISegment::get_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances(&RefSegFrame_0::_8, ::RailRoadModel::IPoint::get_type_id(), model));
		sp.add_operation(create_LocalIterateOverInstances(&RefSegFrame_0::_8, ::RailRoadModel::IPoint::get_type_id(), model));
		sp.add_operation(create_NavigateSingleAssociation(&RefSegFrame_0::_8, &RefSegFrame_0::_9, &::RailRoadModel::IPoint::x));
		sp.add_operation(create_MultiAssociationCheck(&RefSegFrame_0::_2, &RefSegFrame_0::_8, &::RailRoadModel::ISegment::points));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_8, ::RailRoadModel::IPoint::get_type_id()));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_8, ::RailRoadModel::IPoint::get_type_id()));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_8, ::RailRoadModel::IPoint::get_type_id()));
		sp.add_operation(create_NavigateSingleAssociation(&RefSegFrame_0::_8, &RefSegFrame_0::_7, &::RailRoadModel::IPoint::y));
		sp.add_operation(create_NavigateSingleAssociation(&RefSegFrame_0::_8, &RefSegFrame_0::_10, &::RailRoadModel::IPoint::z));
		sp.add_operation(create_CheckExpression<RefSegFrame_0>(
			[](double robX, double robY, double sY, double sX, double sZ, double robZ){
				// Please implement the following 
				// <XBinaryOperationImplCustom> && <XBinaryOperationImplCustom>
				//
				
				static_assert(false, "Please implement the Check expression");	
			},
			&RefSegFrame_0::_4, &RefSegFrame_0::_5, &RefSegFrame_0::_7, &RefSegFrame_0::_9, &RefSegFrame_0::_10, &RefSegFrame_0::_6
		)
		);
		
		return sp;
	}

};

} /* namespace DerivedFeatures */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED_FEATURES__REF_SEG_QUERY_SPECIFICATION_H_ */
