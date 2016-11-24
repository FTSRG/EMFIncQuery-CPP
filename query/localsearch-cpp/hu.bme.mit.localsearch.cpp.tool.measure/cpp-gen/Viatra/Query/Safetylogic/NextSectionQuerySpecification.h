#ifndef VIATRA__QUERY__SAFETYLOGIC__NEXT_SECTION_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__SAFETYLOGIC__NEXT_SECTION_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Safetylogic/NextSectionFrame_0.h"
#include "Viatra/Query/Safetylogic/NextSectionFrame_1.h"
#include "Viatra/Query/Safetylogic/NextSectionFrame_2.h"
#include "Viatra/Query/Safetylogic/NextSectionFrame_3.h"
#include "Viatra/Query/Safetylogic/NextSectionFrame_4.h"
#include "Viatra/Query/Safetylogic/NextSectionFrame_5.h"
#include "Viatra/Query/Safetylogic/NextSectionFrame_6.h"
#include "Viatra/Query/Safetylogic/NextSectionFrame_7.h"
#include "Viatra/Query/Safetylogic/NextSectionFrame_8.h"
#include "Viatra/Query/Safetylogic/NextSectionFrame_9.h"
#include "Viatra/Query/Safetylogic/NextSectionMatch.h"
#include "Viatra/Query/Safetylogic/NotNullMatcher.h"
#include "Viatra/Query/Safetylogic/SafetylogicQueryGroup.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {

template<class ModelRoot>
class NextSectionMatcher;

template<class ModelRoot>
class NextSectionQuerySpecification {
public:
	using Matcher = NextSectionMatcher<ModelRoot>;
	using Match = NextSectionMatch;
	using QueryGroup = SafetylogicQueryGroup;
						
	static ::Viatra::Query::Plan::SearchPlan<NextSectionFrame_0> get_plan_unbound__0(const ModelRoot* model, std::map<int,NextSectionFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<NextSectionFrame_0> sp;
		
		
		sp.add_operation(create_ConstantValueExtend(&NextSectionFrame_0::_5, true));
		sp.add_operation(create_GlobalIterateOverInstances<NextSectionFrame_0>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&NextSectionFrame_0::_3, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_0>(4, subFrames, &NextSectionFrame_0::_3));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_0::_3, &NextSectionFrame_0::_4, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_0::_3, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_0::_3, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_0::_3, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_0::_3, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_0::_3, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_0::_3, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_0::_3, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_0>(13, subFrames, &NextSectionFrame_0::_3));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_0::_3, &NextSectionFrame_0::_6, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_0>(15, subFrames, &NextSectionFrame_0::_3));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_0::_3, &NextSectionFrame_0::_1, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_0::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_0::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_0::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_0>(20, subFrames, &NextSectionFrame_0::_1));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_0::_1, &NextSectionFrame_0::_5, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_0::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_0>(23, subFrames, &NextSectionFrame_0::_1));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_0::_1, &NextSectionFrame_0::_6, &::railRoadModel::ITurnout::get_top));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_0::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_0>(26, subFrames, &NextSectionFrame_0::_1));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_0::_1, &NextSectionFrame_0::_4, &::railRoadModel::ITurnout::get_divergent));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_0::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_0>(29, subFrames, &NextSectionFrame_0::_3));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_0::_3, &NextSectionFrame_0::_1, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_0>(31, subFrames, &NextSectionFrame_0::_3));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_0::_3, &NextSectionFrame_0::_0, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_0::_0, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_0>(34, subFrames, &NextSectionFrame_0::_3));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_0::_3, &NextSectionFrame_0::_2, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_0::_2, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<NextSectionFrame_1> get_plan_unbound__1(const ModelRoot* model, std::map<int,NextSectionFrame_1Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<NextSectionFrame_1> sp;
		
		
		sp.add_operation(create_GlobalIterateOverInstances<NextSectionFrame_1>(1, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&NextSectionFrame_1::_5, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_1>(3, subFrames, &NextSectionFrame_1::_5));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_1::_5, &NextSectionFrame_1::_4, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_1::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_1::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_1::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_1::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_1::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_1::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_1::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_1>(12, subFrames, &NextSectionFrame_1::_5));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_1::_5, &NextSectionFrame_1::_3, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InequalityCheck(&NextSectionFrame_1::_4, &NextSectionFrame_1::_3));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_1>(15, subFrames, &NextSectionFrame_1::_5));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_1::_5, &NextSectionFrame_1::_1, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_1::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_1::_1, ::railRoadModel::ISegment::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_1::_1, ::railRoadModel::ISegment::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_1>(20, subFrames, &NextSectionFrame_1::_1));
		sp.add_operation(create_MultiAssociationCheck(&NextSectionFrame_1::_1, &NextSectionFrame_1::_4, &::railRoadModel::ISegment::get_connectedTo));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_1::_1, ::railRoadModel::ISegment::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_1>(23, subFrames, &NextSectionFrame_1::_1));
		sp.add_operation(create_MultiAssociationCheck(&NextSectionFrame_1::_1, &NextSectionFrame_1::_3, &::railRoadModel::ISegment::get_connectedTo));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_1::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_1>(26, subFrames, &NextSectionFrame_1::_5));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_1::_5, &NextSectionFrame_1::_1, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_1>(28, subFrames, &NextSectionFrame_1::_5));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_1::_5, &NextSectionFrame_1::_0, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_1::_0, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_1>(31, subFrames, &NextSectionFrame_1::_5));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_1::_5, &NextSectionFrame_1::_2, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_1::_2, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<NextSectionFrame_2> get_plan_unbound__2(const ModelRoot* model, std::map<int,NextSectionFrame_2Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<NextSectionFrame_2> sp;
		
		
		sp.add_operation(create_ConstantValueExtend(&NextSectionFrame_2::_3, true));
		sp.add_operation(create_GlobalIterateOverInstances<NextSectionFrame_2>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&NextSectionFrame_2::_5, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_2>(4, subFrames, &NextSectionFrame_2::_5));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_2::_5, &NextSectionFrame_2::_6, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_2::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_2::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_2::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_2::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_2::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_2::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_2::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_2>(13, subFrames, &NextSectionFrame_2::_5));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_2::_5, &NextSectionFrame_2::_4, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_2>(15, subFrames, &NextSectionFrame_2::_5));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_2::_5, &NextSectionFrame_2::_1, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_2::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_2::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_2::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_2>(20, subFrames, &NextSectionFrame_2::_1));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_2::_1, &NextSectionFrame_2::_3, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_2::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_2>(23, subFrames, &NextSectionFrame_2::_1));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_2::_1, &NextSectionFrame_2::_6, &::railRoadModel::ITurnout::get_top));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_2::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_2>(26, subFrames, &NextSectionFrame_2::_1));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_2::_1, &NextSectionFrame_2::_4, &::railRoadModel::ITurnout::get_divergent));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_2::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_2>(29, subFrames, &NextSectionFrame_2::_5));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_2::_5, &NextSectionFrame_2::_1, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_2>(31, subFrames, &NextSectionFrame_2::_5));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_2::_5, &NextSectionFrame_2::_0, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_2::_0, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_2>(34, subFrames, &NextSectionFrame_2::_5));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_2::_5, &NextSectionFrame_2::_2, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_2::_2, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<NextSectionFrame_3> get_plan_unbound__3(const ModelRoot* model, std::map<int,NextSectionFrame_3Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<NextSectionFrame_3> sp;
		
		NotNullMatcher<ModelRoot> matcher_684426198(model,  SafetylogicQueryGroup::instance()->context());
		
		sp.add_operation(create_ConstantValueExtend(&NextSectionFrame_3::_4, false));
		sp.add_operation(create_GlobalIterateOverInstances<NextSectionFrame_3>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&NextSectionFrame_3::_3, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_3>(4, subFrames, &NextSectionFrame_3::_3));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_3::_3, &NextSectionFrame_3::_5, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_3::_3, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_3::_3, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_3::_3, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_3::_3, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_3::_3, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_3::_3, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_3::_3, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_3>(13, subFrames, &NextSectionFrame_3::_3));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_3::_3, &NextSectionFrame_3::_6, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_3>(15, subFrames, &NextSectionFrame_3::_3));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_3::_3, &NextSectionFrame_3::_7, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_3>(17, subFrames, &NextSectionFrame_3::_3));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_3::_3, &NextSectionFrame_3::_1, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_3::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_3::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_3::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_3>(22, subFrames, &NextSectionFrame_3::_1));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_3::_1, &NextSectionFrame_3::_4, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_3::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_3>(25, subFrames, &NextSectionFrame_3::_1));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_3::_1, &NextSectionFrame_3::_6, &::railRoadModel::ITurnout::get_top));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_3::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_3>(28, subFrames, &NextSectionFrame_3::_1));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_3::_1, &NextSectionFrame_3::_5, &::railRoadModel::ITurnout::get_straight));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_3::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_3>(31, subFrames, &NextSectionFrame_3::_3));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_3::_3, &NextSectionFrame_3::_1, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_3>(33, subFrames, &NextSectionFrame_3::_3));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_3::_3, &NextSectionFrame_3::_2, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_3::_2, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<NextSectionFrame_3>(36, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&NextSectionFrame_3::_0, ::railRoadModel::IRailRoadElement::get_static_type_id(), model));
		sp.add_operation(create_NACOperation<NextSectionFrame_3>(matcher_684426198, &NextSectionFrame_3::_0));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<NextSectionFrame_4> get_plan_unbound__4(const ModelRoot* model, std::map<int,NextSectionFrame_4Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<NextSectionFrame_4> sp;
		
		NotNullMatcher<ModelRoot> matcher_1497789527(model,  SafetylogicQueryGroup::instance()->context());
		
		sp.add_operation(create_ConstantValueExtend(&NextSectionFrame_4::_3, false));
		sp.add_operation(create_GlobalIterateOverInstances<NextSectionFrame_4>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&NextSectionFrame_4::_4, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_4>(4, subFrames, &NextSectionFrame_4::_4));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_4::_4, &NextSectionFrame_4::_7, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_4::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_4::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_4::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_4::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_4::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_4::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_4::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_4>(13, subFrames, &NextSectionFrame_4::_4));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_4::_4, &NextSectionFrame_4::_5, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_4>(15, subFrames, &NextSectionFrame_4::_4));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_4::_4, &NextSectionFrame_4::_6, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_4>(17, subFrames, &NextSectionFrame_4::_4));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_4::_4, &NextSectionFrame_4::_1, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_4::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_4::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_4::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_4>(22, subFrames, &NextSectionFrame_4::_1));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_4::_1, &NextSectionFrame_4::_3, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_4::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_4>(25, subFrames, &NextSectionFrame_4::_1));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_4::_1, &NextSectionFrame_4::_7, &::railRoadModel::ITurnout::get_top));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_4::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_4>(28, subFrames, &NextSectionFrame_4::_1));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_4::_1, &NextSectionFrame_4::_5, &::railRoadModel::ITurnout::get_straight));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_4::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_4>(31, subFrames, &NextSectionFrame_4::_4));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_4::_4, &NextSectionFrame_4::_1, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_4>(33, subFrames, &NextSectionFrame_4::_4));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_4::_4, &NextSectionFrame_4::_2, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_4::_2, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<NextSectionFrame_4>(36, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&NextSectionFrame_4::_0, ::railRoadModel::IRailRoadElement::get_static_type_id(), model));
		sp.add_operation(create_NACOperation<NextSectionFrame_4>(matcher_1497789527, &NextSectionFrame_4::_0));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<NextSectionFrame_5> get_plan_unbound__5(const ModelRoot* model, std::map<int,NextSectionFrame_5Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<NextSectionFrame_5> sp;
		
		
		sp.add_operation(create_ConstantValueExtend(&NextSectionFrame_5::_6, false));
		sp.add_operation(create_GlobalIterateOverInstances<NextSectionFrame_5>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&NextSectionFrame_5::_5, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_5>(4, subFrames, &NextSectionFrame_5::_5));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_5::_5, &NextSectionFrame_5::_3, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_5::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_5::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_5::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_5::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_5::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_5::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_5::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_5>(13, subFrames, &NextSectionFrame_5::_5));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_5::_5, &NextSectionFrame_5::_4, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_5>(15, subFrames, &NextSectionFrame_5::_5));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_5::_5, &NextSectionFrame_5::_1, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_5::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_5::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_5::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_5>(20, subFrames, &NextSectionFrame_5::_1));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_5::_1, &NextSectionFrame_5::_6, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_5::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_5>(23, subFrames, &NextSectionFrame_5::_1));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_5::_1, &NextSectionFrame_5::_4, &::railRoadModel::ITurnout::get_top));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_5::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_5>(26, subFrames, &NextSectionFrame_5::_1));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_5::_1, &NextSectionFrame_5::_3, &::railRoadModel::ITurnout::get_straight));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_5::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_5>(29, subFrames, &NextSectionFrame_5::_5));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_5::_5, &NextSectionFrame_5::_1, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_5>(31, subFrames, &NextSectionFrame_5::_5));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_5::_5, &NextSectionFrame_5::_0, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_5::_0, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_5>(34, subFrames, &NextSectionFrame_5::_5));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_5::_5, &NextSectionFrame_5::_2, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_5::_2, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<NextSectionFrame_6> get_plan_unbound__6(const ModelRoot* model, std::map<int,NextSectionFrame_6Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<NextSectionFrame_6> sp;
		
		NotNullMatcher<ModelRoot> matcher_741828531(model,  SafetylogicQueryGroup::instance()->context());
		
		sp.add_operation(create_ConstantValueExtend(&NextSectionFrame_6::_3, true));
		sp.add_operation(create_GlobalIterateOverInstances<NextSectionFrame_6>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&NextSectionFrame_6::_4, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_6>(4, subFrames, &NextSectionFrame_6::_4));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_6::_4, &NextSectionFrame_6::_5, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_6::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_6::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_6::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_6::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_6::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_6::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_6::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_6>(13, subFrames, &NextSectionFrame_6::_4));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_6::_4, &NextSectionFrame_6::_6, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_6>(15, subFrames, &NextSectionFrame_6::_4));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_6::_4, &NextSectionFrame_6::_7, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_6>(17, subFrames, &NextSectionFrame_6::_4));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_6::_4, &NextSectionFrame_6::_1, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_6::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_6::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_6::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_6>(22, subFrames, &NextSectionFrame_6::_1));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_6::_1, &NextSectionFrame_6::_3, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_6::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_6>(25, subFrames, &NextSectionFrame_6::_1));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_6::_1, &NextSectionFrame_6::_5, &::railRoadModel::ITurnout::get_top));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_6::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_6>(28, subFrames, &NextSectionFrame_6::_1));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_6::_1, &NextSectionFrame_6::_6, &::railRoadModel::ITurnout::get_divergent));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_6::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_6>(31, subFrames, &NextSectionFrame_6::_4));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_6::_4, &NextSectionFrame_6::_1, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_6>(33, subFrames, &NextSectionFrame_6::_4));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_6::_4, &NextSectionFrame_6::_2, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_6::_2, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<NextSectionFrame_6>(36, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&NextSectionFrame_6::_0, ::railRoadModel::IRailRoadElement::get_static_type_id(), model));
		sp.add_operation(create_NACOperation<NextSectionFrame_6>(matcher_741828531, &NextSectionFrame_6::_0));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<NextSectionFrame_7> get_plan_unbound__7(const ModelRoot* model, std::map<int,NextSectionFrame_7Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<NextSectionFrame_7> sp;
		
		NotNullMatcher<ModelRoot> matcher_505239895(model,  SafetylogicQueryGroup::instance()->context());
		
		sp.add_operation(create_GlobalIterateOverInstances<NextSectionFrame_7>(1, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&NextSectionFrame_7::_6, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_7>(3, subFrames, &NextSectionFrame_7::_6));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_7::_6, &NextSectionFrame_7::_3, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_7::_6, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_7::_6, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_7::_6, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_7::_6, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_7::_6, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_7::_6, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_7::_6, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_7>(12, subFrames, &NextSectionFrame_7::_6));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_7::_6, &NextSectionFrame_7::_5, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InequalityCheck(&NextSectionFrame_7::_3, &NextSectionFrame_7::_5));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_7>(15, subFrames, &NextSectionFrame_7::_6));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_7::_6, &NextSectionFrame_7::_4, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_7>(17, subFrames, &NextSectionFrame_7::_6));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_7::_6, &NextSectionFrame_7::_1, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_7::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_7::_1, ::railRoadModel::ISegment::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_7::_1, ::railRoadModel::ISegment::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_7>(22, subFrames, &NextSectionFrame_7::_1));
		sp.add_operation(create_MultiAssociationCheck(&NextSectionFrame_7::_1, &NextSectionFrame_7::_3, &::railRoadModel::ISegment::get_connectedTo));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_7::_1, ::railRoadModel::ISegment::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_7>(25, subFrames, &NextSectionFrame_7::_1));
		sp.add_operation(create_MultiAssociationCheck(&NextSectionFrame_7::_1, &NextSectionFrame_7::_5, &::railRoadModel::ISegment::get_connectedTo));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_7::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_7>(28, subFrames, &NextSectionFrame_7::_6));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_7::_6, &NextSectionFrame_7::_1, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_7>(30, subFrames, &NextSectionFrame_7::_6));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_7::_6, &NextSectionFrame_7::_2, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_7::_2, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<NextSectionFrame_7>(33, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&NextSectionFrame_7::_0, ::railRoadModel::IRailRoadElement::get_static_type_id(), model));
		sp.add_operation(create_NACOperation<NextSectionFrame_7>(matcher_505239895, &NextSectionFrame_7::_0));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<NextSectionFrame_8> get_plan_unbound__8(const ModelRoot* model, std::map<int,NextSectionFrame_8Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<NextSectionFrame_8> sp;
		
		NotNullMatcher<ModelRoot> matcher_1911491251(model,  SafetylogicQueryGroup::instance()->context());
		
		sp.add_operation(create_ConstantValueExtend(&NextSectionFrame_8::_5, true));
		sp.add_operation(create_GlobalIterateOverInstances<NextSectionFrame_8>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&NextSectionFrame_8::_4, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_8>(4, subFrames, &NextSectionFrame_8::_4));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_8::_4, &NextSectionFrame_8::_6, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_8::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_8::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_8::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_8::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_8::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_8::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_8::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_8>(13, subFrames, &NextSectionFrame_8::_4));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_8::_4, &NextSectionFrame_8::_7, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_8>(15, subFrames, &NextSectionFrame_8::_4));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_8::_4, &NextSectionFrame_8::_3, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_8>(17, subFrames, &NextSectionFrame_8::_4));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_8::_4, &NextSectionFrame_8::_1, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_8::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_8::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_8::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_8>(22, subFrames, &NextSectionFrame_8::_1));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_8::_1, &NextSectionFrame_8::_5, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_8::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_8>(25, subFrames, &NextSectionFrame_8::_1));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_8::_1, &NextSectionFrame_8::_7, &::railRoadModel::ITurnout::get_top));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_8::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_8>(28, subFrames, &NextSectionFrame_8::_1));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_8::_1, &NextSectionFrame_8::_6, &::railRoadModel::ITurnout::get_divergent));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_8::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_8>(31, subFrames, &NextSectionFrame_8::_4));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_8::_4, &NextSectionFrame_8::_1, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_8>(33, subFrames, &NextSectionFrame_8::_4));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_8::_4, &NextSectionFrame_8::_2, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_8::_2, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<NextSectionFrame_8>(36, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&NextSectionFrame_8::_0, ::railRoadModel::IRailRoadElement::get_static_type_id(), model));
		sp.add_operation(create_NACOperation<NextSectionFrame_8>(matcher_1911491251, &NextSectionFrame_8::_0));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<NextSectionFrame_9> get_plan_unbound__9(const ModelRoot* model, std::map<int,NextSectionFrame_9Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<NextSectionFrame_9> sp;
		
		
		sp.add_operation(create_ConstantValueExtend(&NextSectionFrame_9::_3, false));
		sp.add_operation(create_GlobalIterateOverInstances<NextSectionFrame_9>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&NextSectionFrame_9::_4, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_9>(4, subFrames, &NextSectionFrame_9::_4));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_9::_4, &NextSectionFrame_9::_6, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_9::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_9::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_9::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_9::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_9::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_9::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_9::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_9>(13, subFrames, &NextSectionFrame_9::_4));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_9::_4, &NextSectionFrame_9::_5, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_9>(15, subFrames, &NextSectionFrame_9::_4));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_9::_4, &NextSectionFrame_9::_1, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_9::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_9::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_9::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_9>(20, subFrames, &NextSectionFrame_9::_1));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_9::_1, &NextSectionFrame_9::_3, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_9::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_9>(23, subFrames, &NextSectionFrame_9::_1));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_9::_1, &NextSectionFrame_9::_6, &::railRoadModel::ITurnout::get_top));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_9::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_9>(26, subFrames, &NextSectionFrame_9::_1));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_9::_1, &NextSectionFrame_9::_5, &::railRoadModel::ITurnout::get_straight));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_9::_1, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_9>(29, subFrames, &NextSectionFrame_9::_4));
		sp.add_operation(create_SingleAssociationCheck(&NextSectionFrame_9::_4, &NextSectionFrame_9::_1, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_9>(31, subFrames, &NextSectionFrame_9::_4));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_9::_4, &NextSectionFrame_9::_0, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_9::_0, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<NextSectionFrame_9>(34, subFrames, &NextSectionFrame_9::_4));
		sp.add_operation(create_NavigateSingleAssociation(&NextSectionFrame_9::_4, &NextSectionFrame_9::_2, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&NextSectionFrame_9::_2, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		
		return sp;
	}

};

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__NEXT_SECTION_QUERY_SPECIFICATION_H_ */
