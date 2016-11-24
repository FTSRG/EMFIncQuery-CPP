#ifndef VIATRA__QUERY__SAFETYLOGIC__VIABLE_PATHS_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__SAFETYLOGIC__VIABLE_PATHS_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Safetylogic/SafetylogicQueryGroup.h"
#include "Viatra/Query/Safetylogic/ViablePathsFrame_0.h"
#include "Viatra/Query/Safetylogic/ViablePathsFrame_1.h"
#include "Viatra/Query/Safetylogic/ViablePathsFrame_2.h"
#include "Viatra/Query/Safetylogic/ViablePathsFrame_3.h"
#include "Viatra/Query/Safetylogic/ViablePathsFrame_4.h"
#include "Viatra/Query/Safetylogic/ViablePathsMatch.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {

template<class ModelRoot>
class ViablePathsMatcher;

template<class ModelRoot>
class ViablePathsQuerySpecification {
public:
	using Matcher = ViablePathsMatcher<ModelRoot>;
	using Match = ViablePathsMatch;
	using QueryGroup = SafetylogicQueryGroup;
						
	static ::Viatra::Query::Plan::SearchPlan<ViablePathsFrame_0> get_plan_unbound__0(const ModelRoot* model, std::map<int,ViablePathsFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<ViablePathsFrame_0> sp;
		
		
		sp.add_operation(create_ConstantValueExtend(&ViablePathsFrame_0::_2, false));
		sp.add_operation(create_GlobalIterateOverInstances<ViablePathsFrame_0>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&ViablePathsFrame_0::_1, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_0>(4, subFrames, &ViablePathsFrame_0::_1));
		sp.add_operation(create_NavigateSingleAssociation(&ViablePathsFrame_0::_1, &ViablePathsFrame_0::_3, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_0::_1, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_0::_1, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_0::_1, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_0::_1, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_0>(10, subFrames, &ViablePathsFrame_0::_1));
		sp.add_operation(create_NavigateSingleAssociation(&ViablePathsFrame_0::_1, &ViablePathsFrame_0::_4, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_0>(12, subFrames, &ViablePathsFrame_0::_1));
		sp.add_operation(create_NavigateSingleAssociation(&ViablePathsFrame_0::_1, &ViablePathsFrame_0::_0, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_0::_0, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_0::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_0::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_0>(17, subFrames, &ViablePathsFrame_0::_0));
		sp.add_operation(create_SingleAssociationCheck(&ViablePathsFrame_0::_0, &ViablePathsFrame_0::_2, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_0::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_0>(20, subFrames, &ViablePathsFrame_0::_0));
		sp.add_operation(create_SingleAssociationCheck(&ViablePathsFrame_0::_0, &ViablePathsFrame_0::_4, &::railRoadModel::ITurnout::get_top));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_0::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_0>(23, subFrames, &ViablePathsFrame_0::_0));
		sp.add_operation(create_SingleAssociationCheck(&ViablePathsFrame_0::_0, &ViablePathsFrame_0::_3, &::railRoadModel::ITurnout::get_straight));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<ViablePathsFrame_1> get_plan_unbound__1(const ModelRoot* model, std::map<int,ViablePathsFrame_1Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<ViablePathsFrame_1> sp;
		
		
		sp.add_operation(create_GlobalIterateOverInstances<ViablePathsFrame_1>(1, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&ViablePathsFrame_1::_1, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_1>(3, subFrames, &ViablePathsFrame_1::_1));
		sp.add_operation(create_NavigateSingleAssociation(&ViablePathsFrame_1::_1, &ViablePathsFrame_1::_2, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_1::_1, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_1::_1, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_1::_1, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_1::_1, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_1>(9, subFrames, &ViablePathsFrame_1::_1));
		sp.add_operation(create_NavigateSingleAssociation(&ViablePathsFrame_1::_1, &ViablePathsFrame_1::_3, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InequalityCheck(&ViablePathsFrame_1::_2, &ViablePathsFrame_1::_3));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_1>(12, subFrames, &ViablePathsFrame_1::_1));
		sp.add_operation(create_NavigateSingleAssociation(&ViablePathsFrame_1::_1, &ViablePathsFrame_1::_0, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_1::_0, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_1::_0, ::railRoadModel::ISegment::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_1::_0, ::railRoadModel::ISegment::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_1>(17, subFrames, &ViablePathsFrame_1::_0));
		sp.add_operation(create_MultiAssociationCheck(&ViablePathsFrame_1::_0, &ViablePathsFrame_1::_2, &::railRoadModel::ISegment::get_connectedTo));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_1::_0, ::railRoadModel::ISegment::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_1>(20, subFrames, &ViablePathsFrame_1::_0));
		sp.add_operation(create_MultiAssociationCheck(&ViablePathsFrame_1::_0, &ViablePathsFrame_1::_3, &::railRoadModel::ISegment::get_connectedTo));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<ViablePathsFrame_2> get_plan_unbound__2(const ModelRoot* model, std::map<int,ViablePathsFrame_2Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<ViablePathsFrame_2> sp;
		
		
		sp.add_operation(create_ConstantValueExtend(&ViablePathsFrame_2::_4, false));
		sp.add_operation(create_GlobalIterateOverInstances<ViablePathsFrame_2>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&ViablePathsFrame_2::_1, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_2>(4, subFrames, &ViablePathsFrame_2::_1));
		sp.add_operation(create_NavigateSingleAssociation(&ViablePathsFrame_2::_1, &ViablePathsFrame_2::_2, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_2::_1, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_2::_1, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_2::_1, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_2::_1, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_2>(10, subFrames, &ViablePathsFrame_2::_1));
		sp.add_operation(create_NavigateSingleAssociation(&ViablePathsFrame_2::_1, &ViablePathsFrame_2::_3, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_2>(12, subFrames, &ViablePathsFrame_2::_1));
		sp.add_operation(create_NavigateSingleAssociation(&ViablePathsFrame_2::_1, &ViablePathsFrame_2::_0, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_2::_0, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_2::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_2::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_2>(17, subFrames, &ViablePathsFrame_2::_0));
		sp.add_operation(create_SingleAssociationCheck(&ViablePathsFrame_2::_0, &ViablePathsFrame_2::_4, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_2::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_2>(20, subFrames, &ViablePathsFrame_2::_0));
		sp.add_operation(create_SingleAssociationCheck(&ViablePathsFrame_2::_0, &ViablePathsFrame_2::_2, &::railRoadModel::ITurnout::get_top));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_2::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_2>(23, subFrames, &ViablePathsFrame_2::_0));
		sp.add_operation(create_SingleAssociationCheck(&ViablePathsFrame_2::_0, &ViablePathsFrame_2::_3, &::railRoadModel::ITurnout::get_straight));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<ViablePathsFrame_3> get_plan_unbound__3(const ModelRoot* model, std::map<int,ViablePathsFrame_3Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<ViablePathsFrame_3> sp;
		
		
		sp.add_operation(create_ConstantValueExtend(&ViablePathsFrame_3::_3, true));
		sp.add_operation(create_GlobalIterateOverInstances<ViablePathsFrame_3>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&ViablePathsFrame_3::_1, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_3>(4, subFrames, &ViablePathsFrame_3::_1));
		sp.add_operation(create_NavigateSingleAssociation(&ViablePathsFrame_3::_1, &ViablePathsFrame_3::_2, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_3::_1, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_3::_1, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_3::_1, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_3::_1, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_3>(10, subFrames, &ViablePathsFrame_3::_1));
		sp.add_operation(create_NavigateSingleAssociation(&ViablePathsFrame_3::_1, &ViablePathsFrame_3::_4, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_3>(12, subFrames, &ViablePathsFrame_3::_1));
		sp.add_operation(create_NavigateSingleAssociation(&ViablePathsFrame_3::_1, &ViablePathsFrame_3::_0, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_3::_0, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_3::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_3::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_3>(17, subFrames, &ViablePathsFrame_3::_0));
		sp.add_operation(create_SingleAssociationCheck(&ViablePathsFrame_3::_0, &ViablePathsFrame_3::_3, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_3::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_3>(20, subFrames, &ViablePathsFrame_3::_0));
		sp.add_operation(create_SingleAssociationCheck(&ViablePathsFrame_3::_0, &ViablePathsFrame_3::_2, &::railRoadModel::ITurnout::get_top));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_3::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_3>(23, subFrames, &ViablePathsFrame_3::_0));
		sp.add_operation(create_SingleAssociationCheck(&ViablePathsFrame_3::_0, &ViablePathsFrame_3::_4, &::railRoadModel::ITurnout::get_divergent));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<ViablePathsFrame_4> get_plan_unbound__4(const ModelRoot* model, std::map<int,ViablePathsFrame_4Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<ViablePathsFrame_4> sp;
		
		
		sp.add_operation(create_ConstantValueExtend(&ViablePathsFrame_4::_3, true));
		sp.add_operation(create_GlobalIterateOverInstances<ViablePathsFrame_4>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&ViablePathsFrame_4::_1, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_4>(4, subFrames, &ViablePathsFrame_4::_1));
		sp.add_operation(create_NavigateSingleAssociation(&ViablePathsFrame_4::_1, &ViablePathsFrame_4::_4, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_4::_1, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_4::_1, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_4::_1, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_4::_1, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_4>(10, subFrames, &ViablePathsFrame_4::_1));
		sp.add_operation(create_NavigateSingleAssociation(&ViablePathsFrame_4::_1, &ViablePathsFrame_4::_2, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_4>(12, subFrames, &ViablePathsFrame_4::_1));
		sp.add_operation(create_NavigateSingleAssociation(&ViablePathsFrame_4::_1, &ViablePathsFrame_4::_0, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_4::_0, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_4::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_4::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_4>(17, subFrames, &ViablePathsFrame_4::_0));
		sp.add_operation(create_SingleAssociationCheck(&ViablePathsFrame_4::_0, &ViablePathsFrame_4::_3, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_4::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_4>(20, subFrames, &ViablePathsFrame_4::_0));
		sp.add_operation(create_SingleAssociationCheck(&ViablePathsFrame_4::_0, &ViablePathsFrame_4::_2, &::railRoadModel::ITurnout::get_top));
		sp.add_operation(create_InstanceOfCheck(&ViablePathsFrame_4::_0, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<ViablePathsFrame_4>(23, subFrames, &ViablePathsFrame_4::_0));
		sp.add_operation(create_SingleAssociationCheck(&ViablePathsFrame_4::_0, &ViablePathsFrame_4::_4, &::railRoadModel::ITurnout::get_divergent));
		
		return sp;
	}

};

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__VIABLE_PATHS_QUERY_SPECIFICATION_H_ */
