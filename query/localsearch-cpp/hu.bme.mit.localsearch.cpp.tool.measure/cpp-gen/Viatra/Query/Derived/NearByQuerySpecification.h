#ifndef VIATRA__QUERY__DERIVED__NEAR_BY_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__DERIVED__NEAR_BY_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/Derived/DerivedQueryGroup.h"
#include "Viatra/Query/Derived/NearByFrame_0.h"
#include "Viatra/Query/Derived/NearByMatch.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Derived {

template<class ModelRoot>
class NearByMatcher;

template<class ModelRoot>
class NearByQuerySpecification {
public:
	using Matcher = NearByMatcher<ModelRoot>;
	using Match = NearByMatch;
	using QueryGroup = DerivedQueryGroup;
						
	static ::Viatra::Query::Plan::SearchPlan<NearByFrame_0> get_plan_unbound__0(const ModelRoot* model, std::map<int,NearByFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<NearByFrame_0> sp;
		
		
		sp.add_operation(create_LocalIterateOverInstances(&NearByFrame_0::_12, ::railRoadModel::ISegment::get_static_type_id(), model));
		sp.add_operation(create_NavigateMultiAssociation(&NearByFrame_0::_12, &NearByFrame_0::_11, &::railRoadModel::ISegment::get_connectedTo));
		sp.add_operation(create_InstanceOfCheck(&NearByFrame_0::_12, ::railRoadModel::ISegment::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NearByFrame_0::_12, ::railRoadModel::ISegment::get_static_type_id()));
		sp.add_operation(create_NavigateSingleAssociation(&NearByFrame_0::_12, &NearByFrame_0::_4, &::railRoadModel::ISegment::get_id));
		sp.add_operation(create_LocalIterateOverInstances(&NearByFrame_0::_0, ::railRoadModel::IRobotPart::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&NearByFrame_0::_0, ::railRoadModel::IRobotPart::get_static_type_id()));
		sp.add_operation(create_LocalIterateOverInstances(&NearByFrame_0::_2, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_NavigateSingleAssociation(&NearByFrame_0::_2, &NearByFrame_0::_3, &::railRoadModel::ITrain::get_id));
		sp.add_operation(create_InstanceOfCheck(&NearByFrame_0::_2, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NearByFrame_0::_2, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NearByFrame_0::_2, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_SingleAssociationCheck(&NearByFrame_0::_2, &NearByFrame_0::_11, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_NavigateSingleAssociation(&NearByFrame_0::_0, &NearByFrame_0::_1, &::railRoadModel::IRobotPart::get_id));
		sp.add_operation(create_CheckExpression<NearByFrame_0>(
			[](double robX, double segX, double segZ, double segY, double robY, double robZ){
				// check(<XBinaryOperationImplCustom> < <XNumberLiteralImpl>);
				return (((((robX-segX)*(robX-segX))+((robY-segY)*(robY-segY)))+((robZ-segZ)*(robZ-segZ)))<100);
			},
			&NearByFrame_0::_5, &NearByFrame_0::_8, &NearByFrame_0::_10, &NearByFrame_0::_9, &NearByFrame_0::_6, &NearByFrame_0::_7
		)
		);
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<NearByFrame_0> get_plan_robotPartID_trainID_segID_robX_robY_robZ_segX_segY_segZ__0(const ModelRoot* model, std::map<int,NearByFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<NearByFrame_0> sp;
		
		
		sp.add_operation(create_CheckExpression<NearByFrame_0>(
			[](double robX, double segX, double segZ, double segY, double robY, double robZ){
				// check(<XBinaryOperationImplCustom> < <XNumberLiteralImpl>);
				return (((((robX-segX)*(robX-segX))+((robY-segY)*(robY-segY)))+((robZ-segZ)*(robZ-segZ)))<100);
			},
			&NearByFrame_0::_5, &NearByFrame_0::_8, &NearByFrame_0::_10, &NearByFrame_0::_9, &NearByFrame_0::_6, &NearByFrame_0::_7
		)
		);
		sp.add_operation(create_LocalIterateOverInstances(&NearByFrame_0::_12, ::railRoadModel::ISegment::get_static_type_id(), model));
		sp.add_operation(create_SingleAssociationCheck(&NearByFrame_0::_12, &NearByFrame_0::_4, &::railRoadModel::ISegment::get_id));
		sp.add_operation(create_InstanceOfCheck(&NearByFrame_0::_12, ::railRoadModel::ISegment::get_static_type_id()));
		sp.add_operation(create_LocalIterateOverInstances(&NearByFrame_0::_0, ::railRoadModel::IRobotPart::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&NearByFrame_0::_0, ::railRoadModel::IRobotPart::get_static_type_id()));
		sp.add_operation(create_SingleAssociationCheck(&NearByFrame_0::_0, &NearByFrame_0::_1, &::railRoadModel::IRobotPart::get_id));
		sp.add_operation(create_NavigateMultiAssociation(&NearByFrame_0::_12, &NearByFrame_0::_11, &::railRoadModel::ISegment::get_connectedTo));
		sp.add_operation(create_LocalIterateOverInstances(&NearByFrame_0::_2, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&NearByFrame_0::_2, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_SingleAssociationCheck(&NearByFrame_0::_2, &NearByFrame_0::_3, &::railRoadModel::ITrain::get_id));
		sp.add_operation(create_InstanceOfCheck(&NearByFrame_0::_2, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_SingleAssociationCheck(&NearByFrame_0::_2, &NearByFrame_0::_11, &::railRoadModel::ITrain::get_currentlyOn));
		
		return sp;
	}

};

} /* namespace Derived */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED__NEAR_BY_QUERY_SPECIFICATION_H_ */