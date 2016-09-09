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

	using QueryGroup = DerivedFeaturesQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<RefSegFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;

		::Viatra::Query::Plan::SearchPlan<RefSegFrame_0> sp;


		sp.add_operation(create_IterateOverInstances(&RefSegFrame_0::_0, ::RailRoadModel::RobotPart::type_id, model));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_0, ::RailRoadModel::RobotPart::type_id));
		sp.add_operation(create_NavigateSingleAssociation(&RefSegFrame_0::_0, &RefSegFrame_0::_1, &::RailRoadModel::RobotPart::id));
		sp.add_operation(create_IterateOverInstances(&RefSegFrame_0::_2, ::RailRoadModel::RailRoadElement::type_id, model));
		sp.add_operation(create_NavigateSingleAssociation(&RefSegFrame_0::_2, &RefSegFrame_0::_3, &::RailRoadModel::Segment::id));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_2, ::RailRoadModel::Segment::type_id));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_2, ::RailRoadModel::Segment::type_id));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_2, ::RailRoadModel::Segment::type_id));
		sp.add_operation(create_IterateOverInstances(&RefSegFrame_0::_10, ::RailRoadModel::Point::type_id, model));
		sp.add_operation(create_NavigateSingleAssociation(&RefSegFrame_0::_10, &RefSegFrame_0::_9, &::RailRoadModel::Point::x));
		sp.add_operation(create_MultiAssociationCheck(&RefSegFrame_0::_2, &RefSegFrame_0::_10, &::RailRoadModel::Segment::points));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_10, ::RailRoadModel::Point::type_id));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_10, ::RailRoadModel::Point::type_id));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_10, ::RailRoadModel::Point::type_id));
		sp.add_operation(create_NavigateSingleAssociation(&RefSegFrame_0::_10, &RefSegFrame_0::_8, &::RailRoadModel::Point::y));
		sp.add_operation(create_NavigateSingleAssociation(&RefSegFrame_0::_10, &RefSegFrame_0::_7, &::RailRoadModel::Point::z));
		sp.add_operation(create_CheckExpression<RefSegFrame_0>(
			[](double robY, double sY, double sZ, double robZ, double sX, double robX){
				return sqrt(pow(robX-sX,2)+pow(robY-sY,2)+pow(robZ-sZ,2)) < 5;
			},
			&RefSegFrame_0::_5, &RefSegFrame_0::_8, &RefSegFrame_0::_7, &RefSegFrame_0::_6, &RefSegFrame_0::_9, &RefSegFrame_0::_4
		)
		);

		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<RefSegFrame_0> get_plan_robotPartID_robX_robY_robZ__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;

		::Viatra::Query::Plan::SearchPlan<RefSegFrame_0> sp;


		sp.add_operation(create_IterateOverInstances(&RefSegFrame_0::_0, ::RailRoadModel::RobotPart::type_id, model));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_0, ::RailRoadModel::RobotPart::type_id));
		sp.add_operation(create_SingleAssociationCheck(&RefSegFrame_0::_0, &RefSegFrame_0::_1, &::RailRoadModel::RobotPart::id));
		sp.add_operation(create_IterateOverInstances(&RefSegFrame_0::_2, ::RailRoadModel::RailRoadElement::type_id, model));
		sp.add_operation(create_NavigateSingleAssociation(&RefSegFrame_0::_2, &RefSegFrame_0::_3, &::RailRoadModel::Segment::id));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_2, ::RailRoadModel::Segment::type_id));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_2, ::RailRoadModel::Segment::type_id));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_2, ::RailRoadModel::Segment::type_id));
		sp.add_operation(create_IterateOverInstances(&RefSegFrame_0::_10, ::RailRoadModel::Point::type_id, model));
		sp.add_operation(create_NavigateSingleAssociation(&RefSegFrame_0::_10, &RefSegFrame_0::_9, &::RailRoadModel::Point::x));
		sp.add_operation(create_MultiAssociationCheck(&RefSegFrame_0::_2, &RefSegFrame_0::_10, &::RailRoadModel::Segment::points));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_10, ::RailRoadModel::Point::type_id));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_10, ::RailRoadModel::Point::type_id));
		sp.add_operation(create_InstanceOfCheck(&RefSegFrame_0::_10, ::RailRoadModel::Point::type_id));
		sp.add_operation(create_NavigateSingleAssociation(&RefSegFrame_0::_10, &RefSegFrame_0::_8, &::RailRoadModel::Point::y));
		sp.add_operation(create_NavigateSingleAssociation(&RefSegFrame_0::_10, &RefSegFrame_0::_7, &::RailRoadModel::Point::z));
		sp.add_operation(create_CheckExpression<RefSegFrame_0>(
			[](double robY, double sY, double sZ, double robZ, double sX, double robX){
				return sqrt(pow(robX-sX,2)+pow(robY-sX,2)+pow(robZ-sZ,2)) < 5;
			},
			&RefSegFrame_0::_5, &RefSegFrame_0::_8, &RefSegFrame_0::_7, &RefSegFrame_0::_6, &RefSegFrame_0::_9, &RefSegFrame_0::_4
		)
		);

		return sp;
	}

};

} /* namespace DerivedFeatures */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED_FEATURES__REF_SEG_QUERY_SPECIFICATION_H_ */
