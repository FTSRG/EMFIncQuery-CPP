#ifndef VIATRA__QUERY__SAFETYLOGIC__CURRENTLY_CONNECTED_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__SAFETYLOGIC__CURRENTLY_CONNECTED_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Safetylogic/CurrentlyConnectedFrame_0.h"
#include "Viatra/Query/Safetylogic/CurrentlyConnectedFrame_1.h"
#include "Viatra/Query/Safetylogic/CurrentlyConnectedFrame_2.h"
#include "Viatra/Query/Safetylogic/CurrentlyConnectedFrame_3.h"
#include "Viatra/Query/Safetylogic/CurrentlyConnectedFrame_4.h"
#include "Viatra/Query/Safetylogic/CurrentlyConnectedMatch.h"
#include "Viatra/Query/Safetylogic/SafetylogicQueryGroup.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {

template<class ModelRoot>
class CurrentlyConnectedMatcher;

template<class ModelRoot>
class CurrentlyConnectedQuerySpecification {
public:
	using Matcher = CurrentlyConnectedMatcher<ModelRoot>;
	using Match = CurrentlyConnectedMatch;
	using QueryGroup = SafetylogicQueryGroup;
						
	static ::Viatra::Query::Plan::SearchPlan<CurrentlyConnectedFrame_0> get_plan_unbound__0(const ModelRoot* model, std::map<int,CurrentlyConnectedFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<CurrentlyConnectedFrame_0> sp;
		
		
		sp.add_operation(create_ConstantValueExtend(&CurrentlyConnectedFrame_0::_2, true));
		sp.add_operation(create_GlobalIterateOverInstances<CurrentlyConnectedFrame_0>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&CurrentlyConnectedFrame_0::_0, ::railRoadModel::ITurnout::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<CurrentlyConnectedFrame_0>(4, subFrames, &CurrentlyConnectedFrame_0::_0));
		sp.add_operation(create_NavigateSingleAssociation(&CurrentlyConnectedFrame_0::_0, &CurrentlyConnectedFrame_0::_1, &::railRoadModel::ITurnout::get_divergent));
		sp.add_operation(create_InstanceOfCheck(&CurrentlyConnectedFrame_0::_0, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&CurrentlyConnectedFrame_0::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&CurrentlyConnectedFrame_0::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&CurrentlyConnectedFrame_0::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<CurrentlyConnectedFrame_0>(10, subFrames, &CurrentlyConnectedFrame_0::_0));
		sp.add_operation(create_SingleAssociationCheck(&CurrentlyConnectedFrame_0::_0, &CurrentlyConnectedFrame_0::_2, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&CurrentlyConnectedFrame_0::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<CurrentlyConnectedFrame_1> get_plan_unbound__1(const ModelRoot* model, std::map<int,CurrentlyConnectedFrame_1Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<CurrentlyConnectedFrame_1> sp;
		
		
		sp.add_operation(create_GlobalIterateOverInstances<CurrentlyConnectedFrame_1>(1, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&CurrentlyConnectedFrame_1::_0, ::railRoadModel::ISegment::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<CurrentlyConnectedFrame_1>(3, subFrames, &CurrentlyConnectedFrame_1::_0));
		sp.add_operation(create_NavigateMultiAssociation(&CurrentlyConnectedFrame_1::_0, &CurrentlyConnectedFrame_1::_1, &::railRoadModel::ISegment::get_connectedTo));
		sp.add_operation(create_InstanceOfCheck(&CurrentlyConnectedFrame_1::_0, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&CurrentlyConnectedFrame_1::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&CurrentlyConnectedFrame_1::_0, ::railRoadModel::ISegment::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&CurrentlyConnectedFrame_1::_0, ::railRoadModel::ISegment::get_static_type_id()));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<CurrentlyConnectedFrame_2> get_plan_unbound__2(const ModelRoot* model, std::map<int,CurrentlyConnectedFrame_2Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<CurrentlyConnectedFrame_2> sp;
		
		
		sp.add_operation(create_ConstantValueExtend(&CurrentlyConnectedFrame_2::_2, true));
		sp.add_operation(create_GlobalIterateOverInstances<CurrentlyConnectedFrame_2>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&CurrentlyConnectedFrame_2::_0, ::railRoadModel::ITurnout::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<CurrentlyConnectedFrame_2>(4, subFrames, &CurrentlyConnectedFrame_2::_0));
		sp.add_operation(create_NavigateSingleAssociation(&CurrentlyConnectedFrame_2::_0, &CurrentlyConnectedFrame_2::_1, &::railRoadModel::ITurnout::get_top));
		sp.add_operation(create_InstanceOfCheck(&CurrentlyConnectedFrame_2::_0, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&CurrentlyConnectedFrame_2::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&CurrentlyConnectedFrame_2::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&CurrentlyConnectedFrame_2::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<CurrentlyConnectedFrame_2>(10, subFrames, &CurrentlyConnectedFrame_2::_0));
		sp.add_operation(create_SingleAssociationCheck(&CurrentlyConnectedFrame_2::_0, &CurrentlyConnectedFrame_2::_2, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&CurrentlyConnectedFrame_2::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<CurrentlyConnectedFrame_3> get_plan_unbound__3(const ModelRoot* model, std::map<int,CurrentlyConnectedFrame_3Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<CurrentlyConnectedFrame_3> sp;
		
		
		sp.add_operation(create_ConstantValueExtend(&CurrentlyConnectedFrame_3::_2, false));
		sp.add_operation(create_GlobalIterateOverInstances<CurrentlyConnectedFrame_3>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&CurrentlyConnectedFrame_3::_0, ::railRoadModel::ITurnout::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<CurrentlyConnectedFrame_3>(4, subFrames, &CurrentlyConnectedFrame_3::_0));
		sp.add_operation(create_NavigateSingleAssociation(&CurrentlyConnectedFrame_3::_0, &CurrentlyConnectedFrame_3::_1, &::railRoadModel::ITurnout::get_straight));
		sp.add_operation(create_InstanceOfCheck(&CurrentlyConnectedFrame_3::_0, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&CurrentlyConnectedFrame_3::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&CurrentlyConnectedFrame_3::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&CurrentlyConnectedFrame_3::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<CurrentlyConnectedFrame_3>(10, subFrames, &CurrentlyConnectedFrame_3::_0));
		sp.add_operation(create_SingleAssociationCheck(&CurrentlyConnectedFrame_3::_0, &CurrentlyConnectedFrame_3::_2, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&CurrentlyConnectedFrame_3::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<CurrentlyConnectedFrame_4> get_plan_unbound__4(const ModelRoot* model, std::map<int,CurrentlyConnectedFrame_4Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<CurrentlyConnectedFrame_4> sp;
		
		
		sp.add_operation(create_ConstantValueExtend(&CurrentlyConnectedFrame_4::_2, false));
		sp.add_operation(create_GlobalIterateOverInstances<CurrentlyConnectedFrame_4>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&CurrentlyConnectedFrame_4::_0, ::railRoadModel::ITurnout::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<CurrentlyConnectedFrame_4>(4, subFrames, &CurrentlyConnectedFrame_4::_0));
		sp.add_operation(create_NavigateSingleAssociation(&CurrentlyConnectedFrame_4::_0, &CurrentlyConnectedFrame_4::_1, &::railRoadModel::ITurnout::get_top));
		sp.add_operation(create_InstanceOfCheck(&CurrentlyConnectedFrame_4::_0, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&CurrentlyConnectedFrame_4::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&CurrentlyConnectedFrame_4::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&CurrentlyConnectedFrame_4::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<CurrentlyConnectedFrame_4>(10, subFrames, &CurrentlyConnectedFrame_4::_0));
		sp.add_operation(create_SingleAssociationCheck(&CurrentlyConnectedFrame_4::_0, &CurrentlyConnectedFrame_4::_2, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&CurrentlyConnectedFrame_4::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		
		return sp;
	}

};

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__CURRENTLY_CONNECTED_QUERY_SPECIFICATION_H_ */
