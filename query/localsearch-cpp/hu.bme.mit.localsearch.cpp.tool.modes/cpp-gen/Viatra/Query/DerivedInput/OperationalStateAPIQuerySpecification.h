#ifndef VIATRA__QUERY__DERIVED_INPUT__OPERATIONAL_STATE_A_P_I_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__DERIVED_INPUT__OPERATIONAL_STATE_A_P_I_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/DerivedInput/DerivedInputQueryGroup.h"
#include "Viatra/Query/DerivedInput/OperationalStateAPIFrame_0.h"
#include "Viatra/Query/DerivedInput/OperationalStateAPIMatch.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace DerivedInput {

template<class ModelRoot>
class OperationalStateAPIMatcher;

template<class ModelRoot>
class OperationalStateAPIQuerySpecification {
public:
	using Matcher = OperationalStateAPIMatcher<ModelRoot>;
	using Match = OperationalStateAPIMatch;
	using QueryGroup = DerivedInputQueryGroup;
						
	static ::Viatra::Query::Plan::SearchPlan<OperationalStateAPIFrame_0> get_plan_unbound__0(const ModelRoot* model, std::map<int,OperationalStateAPIFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<OperationalStateAPIFrame_0> sp;
		
		
		sp.add_operation(create_LocalIterateOverInstances(&OperationalStateAPIFrame_0::_0, ::railRoadModel::ITurnout::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&OperationalStateAPIFrame_0::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_LocalIterateOverInstances(&OperationalStateAPIFrame_0::_2, ::railRoadModel::IState::get_static_type_id(), model));
		sp.add_operation(create_NavigateSingleAssociation(&OperationalStateAPIFrame_0::_2, &OperationalStateAPIFrame_0::_3, &::railRoadModel::IOperational::get_id));
		sp.add_operation(create_InstanceOfCheck(&OperationalStateAPIFrame_0::_2, ::railRoadModel::IOperational::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&OperationalStateAPIFrame_0::_2, ::railRoadModel::IOperational::get_static_type_id()));
		sp.add_operation(create_CheckExpression<OperationalStateAPIFrame_0>(
			[](double turnoutTemp){
				// check(<XFeatureCallImplCustom> >= <XUnaryOperationImplCustom>);
				return (turnoutTemp>=(-20));
			},
			&OperationalStateAPIFrame_0::_4
		)
		);
		sp.add_operation(create_NavigateSingleAssociation(&OperationalStateAPIFrame_0::_0, &OperationalStateAPIFrame_0::_1, &::railRoadModel::ITurnout::get_id));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<OperationalStateAPIFrame_0> get_plan_turnoutID_stateID_turnoutTemp__0(const ModelRoot* model, std::map<int,OperationalStateAPIFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<OperationalStateAPIFrame_0> sp;
		
		
		sp.add_operation(create_CheckExpression<OperationalStateAPIFrame_0>(
			[](double turnoutTemp){
				// check(<XFeatureCallImplCustom> >= <XUnaryOperationImplCustom>);
				return (turnoutTemp>=(-20));
			},
			&OperationalStateAPIFrame_0::_4
		)
		);
		sp.add_operation(create_LocalIterateOverInstances(&OperationalStateAPIFrame_0::_0, ::railRoadModel::ITurnout::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&OperationalStateAPIFrame_0::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_SingleAssociationCheck(&OperationalStateAPIFrame_0::_0, &OperationalStateAPIFrame_0::_1, &::railRoadModel::ITurnout::get_id));
		sp.add_operation(create_LocalIterateOverInstances(&OperationalStateAPIFrame_0::_2, ::railRoadModel::IOperational::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&OperationalStateAPIFrame_0::_2, ::railRoadModel::IOperational::get_static_type_id()));
		sp.add_operation(create_SingleAssociationCheck(&OperationalStateAPIFrame_0::_2, &OperationalStateAPIFrame_0::_3, &::railRoadModel::IOperational::get_id));
		
		return sp;
	}

};

} /* namespace DerivedInput */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED_INPUT__OPERATIONAL_STATE_A_P_I_QUERY_SPECIFICATION_H_ */
