#ifndef VIATRA__QUERY__SAFETYLOGIC__TRAINS_ARE_TOO_CLOSE_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__SAFETYLOGIC__TRAINS_ARE_TOO_CLOSE_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Safetylogic/SafetylogicQueryGroup.h"
#include "Viatra/Query/Safetylogic/TrainsAreTooCloseFrame_0.h"
#include "Viatra/Query/Safetylogic/TrainsAreTooCloseFrame_1.h"
#include "Viatra/Query/Safetylogic/TrainsAreTooCloseFrame_2.h"
#include "Viatra/Query/Safetylogic/TrainsAreTooCloseFrame_3.h"
#include "Viatra/Query/Safetylogic/TrainsAreTooCloseFrame_4.h"
#include "Viatra/Query/Safetylogic/TrainsAreTooCloseMatch.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {

template<class ModelRoot>
class TrainsAreTooCloseMatcher;

template<class ModelRoot>
class TrainsAreTooCloseQuerySpecification {
public:
	using Matcher = TrainsAreTooCloseMatcher<ModelRoot>;
	using Match = TrainsAreTooCloseMatch;
	using QueryGroup = SafetylogicQueryGroup;
						
	static ::Viatra::Query::Plan::SearchPlan<TrainsAreTooCloseFrame_0> get_plan_unbound__0(const ModelRoot* model, std::map<int,TrainsAreTooCloseFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<TrainsAreTooCloseFrame_0> sp;
		
		
		sp.add_operation(create_GlobalIterateOverInstances<TrainsAreTooCloseFrame_0>(1, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainsAreTooCloseFrame_0::_0, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainsAreTooCloseFrame_0>(3, subFrames, &TrainsAreTooCloseFrame_0::_0));
		sp.add_operation(create_NavigateSingleAssociation(&TrainsAreTooCloseFrame_0::_0, &TrainsAreTooCloseFrame_0::_2, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_0::_2, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_0::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_0::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<TrainsAreTooCloseFrame_0>(8, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainsAreTooCloseFrame_0::_1, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainsAreTooCloseFrame_0>(10, subFrames, &TrainsAreTooCloseFrame_0::_1));
		sp.add_operation(create_NavigateSingleAssociation(&TrainsAreTooCloseFrame_0::_1, &TrainsAreTooCloseFrame_0::_3, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_0::_3, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_0::_3, ::railRoadModel::ISegment::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_0::_3, ::railRoadModel::ISegment::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainsAreTooCloseFrame_0>(15, subFrames, &TrainsAreTooCloseFrame_0::_3));
		sp.add_operation(create_MultiAssociationCheck(&TrainsAreTooCloseFrame_0::_3, &TrainsAreTooCloseFrame_0::_2, &::railRoadModel::ISegment::get_connectedTo));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_0::_1, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_0::_1, ::railRoadModel::ITrain::get_static_type_id()));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<TrainsAreTooCloseFrame_1> get_plan_unbound__1(const ModelRoot* model, std::map<int,TrainsAreTooCloseFrame_1Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<TrainsAreTooCloseFrame_1> sp;
		
		
		sp.add_operation(create_ConstantValueExtend(&TrainsAreTooCloseFrame_1::_2, true));
		sp.add_operation(create_GlobalIterateOverInstances<TrainsAreTooCloseFrame_1>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainsAreTooCloseFrame_1::_0, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainsAreTooCloseFrame_1>(4, subFrames, &TrainsAreTooCloseFrame_1::_0));
		sp.add_operation(create_NavigateSingleAssociation(&TrainsAreTooCloseFrame_1::_0, &TrainsAreTooCloseFrame_1::_4, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_1::_4, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_1::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_1::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<TrainsAreTooCloseFrame_1>(9, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainsAreTooCloseFrame_1::_1, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainsAreTooCloseFrame_1>(11, subFrames, &TrainsAreTooCloseFrame_1::_1));
		sp.add_operation(create_NavigateSingleAssociation(&TrainsAreTooCloseFrame_1::_1, &TrainsAreTooCloseFrame_1::_3, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_1::_3, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_1::_3, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_1::_3, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainsAreTooCloseFrame_1>(16, subFrames, &TrainsAreTooCloseFrame_1::_3));
		sp.add_operation(create_SingleAssociationCheck(&TrainsAreTooCloseFrame_1::_3, &TrainsAreTooCloseFrame_1::_2, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_1::_3, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainsAreTooCloseFrame_1>(19, subFrames, &TrainsAreTooCloseFrame_1::_3));
		sp.add_operation(create_SingleAssociationCheck(&TrainsAreTooCloseFrame_1::_3, &TrainsAreTooCloseFrame_1::_4, &::railRoadModel::ITurnout::get_divergent));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_1::_1, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_1::_1, ::railRoadModel::ITrain::get_static_type_id()));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<TrainsAreTooCloseFrame_2> get_plan_unbound__2(const ModelRoot* model, std::map<int,TrainsAreTooCloseFrame_2Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<TrainsAreTooCloseFrame_2> sp;
		
		
		sp.add_operation(create_ConstantValueExtend(&TrainsAreTooCloseFrame_2::_4, false));
		sp.add_operation(create_GlobalIterateOverInstances<TrainsAreTooCloseFrame_2>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainsAreTooCloseFrame_2::_0, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainsAreTooCloseFrame_2>(4, subFrames, &TrainsAreTooCloseFrame_2::_0));
		sp.add_operation(create_NavigateSingleAssociation(&TrainsAreTooCloseFrame_2::_0, &TrainsAreTooCloseFrame_2::_2, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_2::_2, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_2::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_2::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<TrainsAreTooCloseFrame_2>(9, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainsAreTooCloseFrame_2::_1, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainsAreTooCloseFrame_2>(11, subFrames, &TrainsAreTooCloseFrame_2::_1));
		sp.add_operation(create_NavigateSingleAssociation(&TrainsAreTooCloseFrame_2::_1, &TrainsAreTooCloseFrame_2::_3, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_2::_3, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_2::_3, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_2::_3, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainsAreTooCloseFrame_2>(16, subFrames, &TrainsAreTooCloseFrame_2::_3));
		sp.add_operation(create_SingleAssociationCheck(&TrainsAreTooCloseFrame_2::_3, &TrainsAreTooCloseFrame_2::_4, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_2::_3, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainsAreTooCloseFrame_2>(19, subFrames, &TrainsAreTooCloseFrame_2::_3));
		sp.add_operation(create_SingleAssociationCheck(&TrainsAreTooCloseFrame_2::_3, &TrainsAreTooCloseFrame_2::_2, &::railRoadModel::ITurnout::get_straight));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_2::_1, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_2::_1, ::railRoadModel::ITrain::get_static_type_id()));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<TrainsAreTooCloseFrame_3> get_plan_unbound__3(const ModelRoot* model, std::map<int,TrainsAreTooCloseFrame_3Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<TrainsAreTooCloseFrame_3> sp;
		
		
		sp.add_operation(create_ConstantValueExtend(&TrainsAreTooCloseFrame_3::_3, false));
		sp.add_operation(create_GlobalIterateOverInstances<TrainsAreTooCloseFrame_3>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainsAreTooCloseFrame_3::_0, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainsAreTooCloseFrame_3>(4, subFrames, &TrainsAreTooCloseFrame_3::_0));
		sp.add_operation(create_NavigateSingleAssociation(&TrainsAreTooCloseFrame_3::_0, &TrainsAreTooCloseFrame_3::_2, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_3::_2, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_3::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_3::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<TrainsAreTooCloseFrame_3>(9, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainsAreTooCloseFrame_3::_1, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainsAreTooCloseFrame_3>(11, subFrames, &TrainsAreTooCloseFrame_3::_1));
		sp.add_operation(create_NavigateSingleAssociation(&TrainsAreTooCloseFrame_3::_1, &TrainsAreTooCloseFrame_3::_4, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_3::_4, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_3::_4, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_3::_4, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainsAreTooCloseFrame_3>(16, subFrames, &TrainsAreTooCloseFrame_3::_4));
		sp.add_operation(create_SingleAssociationCheck(&TrainsAreTooCloseFrame_3::_4, &TrainsAreTooCloseFrame_3::_3, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_3::_4, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainsAreTooCloseFrame_3>(19, subFrames, &TrainsAreTooCloseFrame_3::_4));
		sp.add_operation(create_SingleAssociationCheck(&TrainsAreTooCloseFrame_3::_4, &TrainsAreTooCloseFrame_3::_2, &::railRoadModel::ITurnout::get_top));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_3::_1, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_3::_1, ::railRoadModel::ITrain::get_static_type_id()));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<TrainsAreTooCloseFrame_4> get_plan_unbound__4(const ModelRoot* model, std::map<int,TrainsAreTooCloseFrame_4Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<TrainsAreTooCloseFrame_4> sp;
		
		
		sp.add_operation(create_ConstantValueExtend(&TrainsAreTooCloseFrame_4::_2, true));
		sp.add_operation(create_GlobalIterateOverInstances<TrainsAreTooCloseFrame_4>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainsAreTooCloseFrame_4::_0, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainsAreTooCloseFrame_4>(4, subFrames, &TrainsAreTooCloseFrame_4::_0));
		sp.add_operation(create_NavigateSingleAssociation(&TrainsAreTooCloseFrame_4::_0, &TrainsAreTooCloseFrame_4::_3, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_4::_3, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_4::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_4::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<TrainsAreTooCloseFrame_4>(9, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainsAreTooCloseFrame_4::_1, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainsAreTooCloseFrame_4>(11, subFrames, &TrainsAreTooCloseFrame_4::_1));
		sp.add_operation(create_NavigateSingleAssociation(&TrainsAreTooCloseFrame_4::_1, &TrainsAreTooCloseFrame_4::_4, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_4::_4, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_4::_4, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_4::_4, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainsAreTooCloseFrame_4>(16, subFrames, &TrainsAreTooCloseFrame_4::_4));
		sp.add_operation(create_SingleAssociationCheck(&TrainsAreTooCloseFrame_4::_4, &TrainsAreTooCloseFrame_4::_2, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_4::_4, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainsAreTooCloseFrame_4>(19, subFrames, &TrainsAreTooCloseFrame_4::_4));
		sp.add_operation(create_SingleAssociationCheck(&TrainsAreTooCloseFrame_4::_4, &TrainsAreTooCloseFrame_4::_3, &::railRoadModel::ITurnout::get_top));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_4::_1, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainsAreTooCloseFrame_4::_1, ::railRoadModel::ITrain::get_static_type_id()));
		
		return sp;
	}

};

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__TRAINS_ARE_TOO_CLOSE_QUERY_SPECIFICATION_H_ */
