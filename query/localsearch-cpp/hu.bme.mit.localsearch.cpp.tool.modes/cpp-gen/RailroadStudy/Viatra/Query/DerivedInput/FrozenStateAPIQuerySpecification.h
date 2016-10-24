#ifndef VIATRA__QUERY__DERIVED_INPUT__FROZEN_STATE_A_P_I_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__DERIVED_INPUT__FROZEN_STATE_A_P_I_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/DerivedInput/DerivedInputQueryGroup.h"
#include "Viatra/Query/DerivedInput/FrozenStateAPIFrame_0.h"
#include "Viatra/Query/DerivedInput/FrozenStateAPIMatch.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace DerivedInput {

template<class ModelRoot>
class FrozenStateAPIMatcher;

template<class ModelRoot>
class FrozenStateAPIQuerySpecification {
public:
	using Matcher = FrozenStateAPIMatcher<ModelRoot>;
	using Match = FrozenStateAPIMatch;
	using QueryGroup = DerivedInputQueryGroup;
						
	static ::Viatra::Query::Plan::SearchPlan<FrozenStateAPIFrame_0> get_plan_unbound__0(const ModelRoot* model, std::map<int,FrozenStateAPIFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<FrozenStateAPIFrame_0> sp;
		
		
		sp.add_operation(create_GlobalIterateOverInstances<FrozenStateAPIFrame_0>(1, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&FrozenStateAPIFrame_0::_0, ::railRoadModel::ITurnout::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&FrozenStateAPIFrame_0::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<FrozenStateAPIFrame_0>(4, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&FrozenStateAPIFrame_0::_2, ::railRoadModel::IState::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<FrozenStateAPIFrame_0>(6, subFrames, &FrozenStateAPIFrame_0::_2));
		sp.add_operation(create_NavigateSingleAssociation(&FrozenStateAPIFrame_0::_2, &FrozenStateAPIFrame_0::_3, &::railRoadModel::IFrozen::get_id));
		sp.add_operation(create_InstanceOfCheck(&FrozenStateAPIFrame_0::_2, ::railRoadModel::IFrozen::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&FrozenStateAPIFrame_0::_2, ::railRoadModel::IFrozen::get_static_type_id()));
		sp.add_operation(create_CheckExpression<FrozenStateAPIFrame_0>(
			[](double turnoutTemp){
			return turnoutTemp < 0;
			},
			&FrozenStateAPIFrame_0::_4
		)
		);
		sp.add_operation(create_DistributeIfNotPresent<FrozenStateAPIFrame_0>(11, subFrames, &FrozenStateAPIFrame_0::_0));
		sp.add_operation(create_NavigateSingleAssociation(&FrozenStateAPIFrame_0::_0, &FrozenStateAPIFrame_0::_1, &::railRoadModel::ITurnout::get_id));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<FrozenStateAPIFrame_0> get_plan_turnoutID_stateID_turnoutTemp__0(const ModelRoot* model, std::map<int,FrozenStateAPIFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<FrozenStateAPIFrame_0> sp;
		
		
		sp.add_operation(create_CheckExpression<FrozenStateAPIFrame_0>(
			[](double turnoutTemp){
				// Please implement the following 
				// <XFeatureCallImplCustom> < <XUnaryOperationImplCustom>
				//
			return turnoutTemp < 0;
			},
			&FrozenStateAPIFrame_0::_4
		)
		);
		sp.add_operation(create_GlobalIterateOverInstances<FrozenStateAPIFrame_0>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&FrozenStateAPIFrame_0::_0, ::railRoadModel::ITurnout::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&FrozenStateAPIFrame_0::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<FrozenStateAPIFrame_0>(5, subFrames, &FrozenStateAPIFrame_0::_0));
		sp.add_operation(create_SingleAssociationCheck(&FrozenStateAPIFrame_0::_0, &FrozenStateAPIFrame_0::_1, &::railRoadModel::ITurnout::id));
		sp.add_operation(create_GlobalIterateOverInstances<FrozenStateAPIFrame_0>(7, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&FrozenStateAPIFrame_0::_2, ::railRoadModel::IFrozen::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&FrozenStateAPIFrame_0::_2, ::railRoadModel::IFrozen::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<FrozenStateAPIFrame_0>(10, subFrames, &FrozenStateAPIFrame_0::_2));
		sp.add_operation(create_SingleAssociationCheck(&FrozenStateAPIFrame_0::_2, &FrozenStateAPIFrame_0::_3, &::railRoadModel::IFrozen::id));
		
		return sp;
	}

};

} /* namespace DerivedInput */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED_INPUT__FROZEN_STATE_A_P_I_QUERY_SPECIFICATION_H_ */
