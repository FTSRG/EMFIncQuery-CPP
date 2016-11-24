#ifndef VIATRA__QUERY__SAFETYLOGIC__TRAIN_HITS_ANOTHER_TRAIN_NEXT_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__SAFETYLOGIC__TRAIN_HITS_ANOTHER_TRAIN_NEXT_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Safetylogic/NotNullMatcher.h"
#include "Viatra/Query/Safetylogic/SafetylogicQueryGroup.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextFrame_0.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextFrame_1.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextFrame_2.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextFrame_3.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextFrame_4.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextFrame_5.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextFrame_6.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextFrame_7.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextFrame_8.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextFrame_9.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextMatch.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {

template<class ModelRoot>
class TrainHitsAnotherTrainNextMatcher;

template<class ModelRoot>
class TrainHitsAnotherTrainNextQuerySpecification {
public:
	using Matcher = TrainHitsAnotherTrainNextMatcher<ModelRoot>;
	using Match = TrainHitsAnotherTrainNextMatch;
	using QueryGroup = SafetylogicQueryGroup;
						
	static ::Viatra::Query::Plan::SearchPlan<TrainHitsAnotherTrainNextFrame_0> get_plan_unbound__0(const ModelRoot* model, std::map<int,TrainHitsAnotherTrainNextFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<TrainHitsAnotherTrainNextFrame_0> sp;
		
		
		sp.add_operation(create_ConstantValueExtend(&TrainHitsAnotherTrainNextFrame_0::_8, true));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_0>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_0::_4, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_0>(4, subFrames, &TrainHitsAnotherTrainNextFrame_0::_4));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_0::_4, &TrainHitsAnotherTrainNextFrame_0::_7, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_0::_7, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_0::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_0::_7, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_0::_7, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_0>(10, subFrames, &TrainHitsAnotherTrainNextFrame_0::_7));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_0::_7, &TrainHitsAnotherTrainNextFrame_0::_8, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_0::_7, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_0::_7, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_0::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_0::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_0::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_0::_7, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_0::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_0::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_0>(20, subFrames, &TrainHitsAnotherTrainNextFrame_0::_4));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_0::_4, &TrainHitsAnotherTrainNextFrame_0::_7, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_0::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_0>(23, subFrames, &TrainHitsAnotherTrainNextFrame_0::_7));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_0::_7, &TrainHitsAnotherTrainNextFrame_0::_2, &::railRoadModel::ITurnout::get_top));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_0>(25, subFrames, &TrainHitsAnotherTrainNextFrame_0::_4));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_0::_4, &TrainHitsAnotherTrainNextFrame_0::_2, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_0>(27, subFrames, &TrainHitsAnotherTrainNextFrame_0::_7));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_0::_7, &TrainHitsAnotherTrainNextFrame_0::_6, &::railRoadModel::ITurnout::get_divergent));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_0>(29, subFrames, &TrainHitsAnotherTrainNextFrame_0::_4));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_0::_4, &TrainHitsAnotherTrainNextFrame_0::_6, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_0>(31, subFrames, &TrainHitsAnotherTrainNextFrame_0::_4));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_0::_4, &TrainHitsAnotherTrainNextFrame_0::_5, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_0::_5, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_0>(34, subFrames, &TrainHitsAnotherTrainNextFrame_0::_4));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_0::_4, &TrainHitsAnotherTrainNextFrame_0::_3, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_0::_3, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_0>(37, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_0::_0, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_0::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_0>(40, subFrames, &TrainHitsAnotherTrainNextFrame_0::_0));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_0::_0, &TrainHitsAnotherTrainNextFrame_0::_7, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_0::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_0>(43, subFrames, &TrainHitsAnotherTrainNextFrame_0::_0));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_0::_0, &TrainHitsAnotherTrainNextFrame_0::_5, &::railRoadModel::ITrain::get_previouslyOn));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_0>(45, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_0::_1, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_0::_1, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_0>(48, subFrames, &TrainHitsAnotherTrainNextFrame_0::_1));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_0::_1, &TrainHitsAnotherTrainNextFrame_0::_3, &::railRoadModel::ITrain::get_currentlyOn));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<TrainHitsAnotherTrainNextFrame_1> get_plan_unbound__1(const ModelRoot* model, std::map<int,TrainHitsAnotherTrainNextFrame_1Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<TrainHitsAnotherTrainNextFrame_1> sp;
		
		NotNullMatcher<ModelRoot> matcher_418289578(model,  SafetylogicQueryGroup::instance()->context());
		
		sp.add_operation(create_ConstantValueExtend(&TrainHitsAnotherTrainNextFrame_1::_6, false));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_1>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_1::_4, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_1>(4, subFrames, &TrainHitsAnotherTrainNextFrame_1::_4));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_1::_4, &TrainHitsAnotherTrainNextFrame_1::_3, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_1::_3, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_1::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_1::_3, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_1::_3, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_1>(10, subFrames, &TrainHitsAnotherTrainNextFrame_1::_3));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_1::_3, &TrainHitsAnotherTrainNextFrame_1::_6, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_1::_3, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_1::_3, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_1::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_1::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_1::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_1::_3, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_1::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_1::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_1>(20, subFrames, &TrainHitsAnotherTrainNextFrame_1::_4));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_1::_4, &TrainHitsAnotherTrainNextFrame_1::_3, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_1::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_1>(23, subFrames, &TrainHitsAnotherTrainNextFrame_1::_3));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_1::_3, &TrainHitsAnotherTrainNextFrame_1::_9, &::railRoadModel::ITurnout::get_top));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_1>(25, subFrames, &TrainHitsAnotherTrainNextFrame_1::_4));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_1::_4, &TrainHitsAnotherTrainNextFrame_1::_9, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_1>(27, subFrames, &TrainHitsAnotherTrainNextFrame_1::_3));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_1::_3, &TrainHitsAnotherTrainNextFrame_1::_2, &::railRoadModel::ITurnout::get_straight));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_1>(29, subFrames, &TrainHitsAnotherTrainNextFrame_1::_4));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_1::_4, &TrainHitsAnotherTrainNextFrame_1::_2, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_1>(31, subFrames, &TrainHitsAnotherTrainNextFrame_1::_4));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_1::_4, &TrainHitsAnotherTrainNextFrame_1::_8, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_1>(33, subFrames, &TrainHitsAnotherTrainNextFrame_1::_4));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_1::_4, &TrainHitsAnotherTrainNextFrame_1::_5, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_1::_5, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_1>(36, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_1::_1, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_1::_1, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_1>(39, subFrames, &TrainHitsAnotherTrainNextFrame_1::_1));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_1::_1, &TrainHitsAnotherTrainNextFrame_1::_5, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_1>(41, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_1::_0, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_1>(43, subFrames, &TrainHitsAnotherTrainNextFrame_1::_0));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_1::_0, &TrainHitsAnotherTrainNextFrame_1::_7, &::railRoadModel::ITrain::get_previouslyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_1::_7, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_1::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_1::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_1>(48, subFrames, &TrainHitsAnotherTrainNextFrame_1::_0));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_1::_0, &TrainHitsAnotherTrainNextFrame_1::_3, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_1::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_NACOperation<TrainHitsAnotherTrainNextFrame_1>(matcher_418289578, &TrainHitsAnotherTrainNextFrame_1::_7));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<TrainHitsAnotherTrainNextFrame_2> get_plan_unbound__2(const ModelRoot* model, std::map<int,TrainHitsAnotherTrainNextFrame_2Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<TrainHitsAnotherTrainNextFrame_2> sp;
		
		NotNullMatcher<ModelRoot> matcher_1289608346(model,  SafetylogicQueryGroup::instance()->context());
		
		sp.add_operation(create_ConstantValueExtend(&TrainHitsAnotherTrainNextFrame_2::_7, true));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_2>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_2::_8, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_2>(4, subFrames, &TrainHitsAnotherTrainNextFrame_2::_8));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_2::_8, &TrainHitsAnotherTrainNextFrame_2::_2, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_2::_2, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_2::_8, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_2::_2, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_2::_2, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_2>(10, subFrames, &TrainHitsAnotherTrainNextFrame_2::_2));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_2::_2, &TrainHitsAnotherTrainNextFrame_2::_7, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_2::_2, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_2::_2, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_2::_8, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_2::_8, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_2::_8, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_2::_2, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_2::_8, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_2::_8, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_2>(20, subFrames, &TrainHitsAnotherTrainNextFrame_2::_8));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_2::_8, &TrainHitsAnotherTrainNextFrame_2::_2, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_2::_8, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_2>(23, subFrames, &TrainHitsAnotherTrainNextFrame_2::_2));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_2::_2, &TrainHitsAnotherTrainNextFrame_2::_4, &::railRoadModel::ITurnout::get_top));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_2>(25, subFrames, &TrainHitsAnotherTrainNextFrame_2::_8));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_2::_8, &TrainHitsAnotherTrainNextFrame_2::_4, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_2>(27, subFrames, &TrainHitsAnotherTrainNextFrame_2::_2));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_2::_2, &TrainHitsAnotherTrainNextFrame_2::_5, &::railRoadModel::ITurnout::get_divergent));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_2>(29, subFrames, &TrainHitsAnotherTrainNextFrame_2::_8));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_2::_8, &TrainHitsAnotherTrainNextFrame_2::_5, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_2>(31, subFrames, &TrainHitsAnotherTrainNextFrame_2::_8));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_2::_8, &TrainHitsAnotherTrainNextFrame_2::_9, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_2>(33, subFrames, &TrainHitsAnotherTrainNextFrame_2::_8));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_2::_8, &TrainHitsAnotherTrainNextFrame_2::_3, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_2::_3, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_2>(36, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_2::_1, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_2::_1, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_2>(39, subFrames, &TrainHitsAnotherTrainNextFrame_2::_1));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_2::_1, &TrainHitsAnotherTrainNextFrame_2::_3, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_2>(41, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_2::_0, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_2>(43, subFrames, &TrainHitsAnotherTrainNextFrame_2::_0));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_2::_0, &TrainHitsAnotherTrainNextFrame_2::_6, &::railRoadModel::ITrain::get_previouslyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_2::_6, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_2::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_2::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_2>(48, subFrames, &TrainHitsAnotherTrainNextFrame_2::_0));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_2::_0, &TrainHitsAnotherTrainNextFrame_2::_2, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_2::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_NACOperation<TrainHitsAnotherTrainNextFrame_2>(matcher_1289608346, &TrainHitsAnotherTrainNextFrame_2::_6));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<TrainHitsAnotherTrainNextFrame_3> get_plan_unbound__3(const ModelRoot* model, std::map<int,TrainHitsAnotherTrainNextFrame_3Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<TrainHitsAnotherTrainNextFrame_3> sp;
		
		
		sp.add_operation(create_ConstantValueExtend(&TrainHitsAnotherTrainNextFrame_3::_2, false));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_3>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_3::_4, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_3>(4, subFrames, &TrainHitsAnotherTrainNextFrame_3::_4));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_3::_4, &TrainHitsAnotherTrainNextFrame_3::_6, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_3::_6, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_3::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_3::_6, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_3::_6, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_3>(10, subFrames, &TrainHitsAnotherTrainNextFrame_3::_6));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_3::_6, &TrainHitsAnotherTrainNextFrame_3::_2, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_3::_6, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_3::_6, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_3::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_3::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_3::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_3::_6, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_3::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_3::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_3>(20, subFrames, &TrainHitsAnotherTrainNextFrame_3::_4));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_3::_4, &TrainHitsAnotherTrainNextFrame_3::_6, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_3::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_3>(23, subFrames, &TrainHitsAnotherTrainNextFrame_3::_6));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_3::_6, &TrainHitsAnotherTrainNextFrame_3::_5, &::railRoadModel::ITurnout::get_top));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_3>(25, subFrames, &TrainHitsAnotherTrainNextFrame_3::_4));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_3::_4, &TrainHitsAnotherTrainNextFrame_3::_5, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_3>(27, subFrames, &TrainHitsAnotherTrainNextFrame_3::_6));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_3::_6, &TrainHitsAnotherTrainNextFrame_3::_7, &::railRoadModel::ITurnout::get_straight));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_3>(29, subFrames, &TrainHitsAnotherTrainNextFrame_3::_4));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_3::_4, &TrainHitsAnotherTrainNextFrame_3::_7, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_3>(31, subFrames, &TrainHitsAnotherTrainNextFrame_3::_4));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_3::_4, &TrainHitsAnotherTrainNextFrame_3::_8, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_3::_8, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_3>(34, subFrames, &TrainHitsAnotherTrainNextFrame_3::_4));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_3::_4, &TrainHitsAnotherTrainNextFrame_3::_3, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_3::_3, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_3>(37, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_3::_0, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_3::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_3>(40, subFrames, &TrainHitsAnotherTrainNextFrame_3::_0));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_3::_0, &TrainHitsAnotherTrainNextFrame_3::_6, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_3::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_3>(43, subFrames, &TrainHitsAnotherTrainNextFrame_3::_0));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_3::_0, &TrainHitsAnotherTrainNextFrame_3::_8, &::railRoadModel::ITrain::get_previouslyOn));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_3>(45, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_3::_1, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_3::_1, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_3>(48, subFrames, &TrainHitsAnotherTrainNextFrame_3::_1));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_3::_1, &TrainHitsAnotherTrainNextFrame_3::_3, &::railRoadModel::ITrain::get_currentlyOn));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<TrainHitsAnotherTrainNextFrame_4> get_plan_unbound__4(const ModelRoot* model, std::map<int,TrainHitsAnotherTrainNextFrame_4Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<TrainHitsAnotherTrainNextFrame_4> sp;
		
		NotNullMatcher<ModelRoot> matcher_1623376420(model,  SafetylogicQueryGroup::instance()->context());
		
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_4>(1, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_4::_2, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_4>(3, subFrames, &TrainHitsAnotherTrainNextFrame_4::_2));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_4::_2, &TrainHitsAnotherTrainNextFrame_4::_6, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_4::_6, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_4::_2, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_4::_6, ::railRoadModel::ISegment::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_4::_6, ::railRoadModel::ISegment::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_4::_6, ::railRoadModel::ISegment::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_4::_2, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_4::_2, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_4::_2, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_4::_6, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_4::_2, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_4::_2, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_4>(16, subFrames, &TrainHitsAnotherTrainNextFrame_4::_2));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_4::_2, &TrainHitsAnotherTrainNextFrame_4::_6, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_4::_2, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_4>(19, subFrames, &TrainHitsAnotherTrainNextFrame_4::_6));
		sp.add_operation(create_NavigateMultiAssociation(&TrainHitsAnotherTrainNextFrame_4::_6, &TrainHitsAnotherTrainNextFrame_4::_5, &::railRoadModel::ISegment::get_connectedTo));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_4>(21, subFrames, &TrainHitsAnotherTrainNextFrame_4::_2));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_4::_2, &TrainHitsAnotherTrainNextFrame_4::_5, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_4>(23, subFrames, &TrainHitsAnotherTrainNextFrame_4::_6));
		sp.add_operation(create_NavigateMultiAssociation(&TrainHitsAnotherTrainNextFrame_4::_6, &TrainHitsAnotherTrainNextFrame_4::_7, &::railRoadModel::ISegment::get_connectedTo));
		sp.add_operation(create_InequalityCheck(&TrainHitsAnotherTrainNextFrame_4::_5, &TrainHitsAnotherTrainNextFrame_4::_7));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_4>(26, subFrames, &TrainHitsAnotherTrainNextFrame_4::_2));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_4::_2, &TrainHitsAnotherTrainNextFrame_4::_7, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_4>(28, subFrames, &TrainHitsAnotherTrainNextFrame_4::_2));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_4::_2, &TrainHitsAnotherTrainNextFrame_4::_4, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_4>(30, subFrames, &TrainHitsAnotherTrainNextFrame_4::_2));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_4::_2, &TrainHitsAnotherTrainNextFrame_4::_8, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_4::_8, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_4>(33, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_4::_1, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_4::_1, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_4>(36, subFrames, &TrainHitsAnotherTrainNextFrame_4::_1));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_4::_1, &TrainHitsAnotherTrainNextFrame_4::_8, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_4>(38, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_4::_0, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_4>(40, subFrames, &TrainHitsAnotherTrainNextFrame_4::_0));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_4::_0, &TrainHitsAnotherTrainNextFrame_4::_3, &::railRoadModel::ITrain::get_previouslyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_4::_3, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_4::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_4::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_4>(45, subFrames, &TrainHitsAnotherTrainNextFrame_4::_0));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_4::_0, &TrainHitsAnotherTrainNextFrame_4::_6, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_4::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_NACOperation<TrainHitsAnotherTrainNextFrame_4>(matcher_1623376420, &TrainHitsAnotherTrainNextFrame_4::_3));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<TrainHitsAnotherTrainNextFrame_5> get_plan_unbound__5(const ModelRoot* model, std::map<int,TrainHitsAnotherTrainNextFrame_5Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<TrainHitsAnotherTrainNextFrame_5> sp;
		
		NotNullMatcher<ModelRoot> matcher_511802059(model,  SafetylogicQueryGroup::instance()->context());
		
		sp.add_operation(create_ConstantValueExtend(&TrainHitsAnotherTrainNextFrame_5::_9, false));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_5>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_5::_5, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_5>(4, subFrames, &TrainHitsAnotherTrainNextFrame_5::_5));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_5::_5, &TrainHitsAnotherTrainNextFrame_5::_2, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_5::_2, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_5::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_5::_2, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_5::_2, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_5>(10, subFrames, &TrainHitsAnotherTrainNextFrame_5::_2));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_5::_2, &TrainHitsAnotherTrainNextFrame_5::_9, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_5::_2, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_5::_2, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_5::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_5::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_5::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_5::_2, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_5::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_5::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_5>(20, subFrames, &TrainHitsAnotherTrainNextFrame_5::_5));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_5::_5, &TrainHitsAnotherTrainNextFrame_5::_2, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_5::_5, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_5>(23, subFrames, &TrainHitsAnotherTrainNextFrame_5::_2));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_5::_2, &TrainHitsAnotherTrainNextFrame_5::_7, &::railRoadModel::ITurnout::get_top));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_5>(25, subFrames, &TrainHitsAnotherTrainNextFrame_5::_5));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_5::_5, &TrainHitsAnotherTrainNextFrame_5::_7, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_5>(27, subFrames, &TrainHitsAnotherTrainNextFrame_5::_2));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_5::_2, &TrainHitsAnotherTrainNextFrame_5::_4, &::railRoadModel::ITurnout::get_straight));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_5>(29, subFrames, &TrainHitsAnotherTrainNextFrame_5::_5));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_5::_5, &TrainHitsAnotherTrainNextFrame_5::_4, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_5>(31, subFrames, &TrainHitsAnotherTrainNextFrame_5::_5));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_5::_5, &TrainHitsAnotherTrainNextFrame_5::_8, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_5>(33, subFrames, &TrainHitsAnotherTrainNextFrame_5::_5));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_5::_5, &TrainHitsAnotherTrainNextFrame_5::_3, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_5::_3, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_5>(36, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_5::_1, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_5::_1, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_5>(39, subFrames, &TrainHitsAnotherTrainNextFrame_5::_1));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_5::_1, &TrainHitsAnotherTrainNextFrame_5::_3, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_5>(41, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_5::_0, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_5>(43, subFrames, &TrainHitsAnotherTrainNextFrame_5::_0));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_5::_0, &TrainHitsAnotherTrainNextFrame_5::_6, &::railRoadModel::ITrain::get_previouslyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_5::_6, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_5::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_5::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_5>(48, subFrames, &TrainHitsAnotherTrainNextFrame_5::_0));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_5::_0, &TrainHitsAnotherTrainNextFrame_5::_2, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_5::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_NACOperation<TrainHitsAnotherTrainNextFrame_5>(matcher_511802059, &TrainHitsAnotherTrainNextFrame_5::_6));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<TrainHitsAnotherTrainNextFrame_6> get_plan_unbound__6(const ModelRoot* model, std::map<int,TrainHitsAnotherTrainNextFrame_6Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<TrainHitsAnotherTrainNextFrame_6> sp;
		
		
		sp.add_operation(create_ConstantValueExtend(&TrainHitsAnotherTrainNextFrame_6::_6, false));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_6>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_6::_4, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_6>(4, subFrames, &TrainHitsAnotherTrainNextFrame_6::_4));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_6::_4, &TrainHitsAnotherTrainNextFrame_6::_8, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_6::_8, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_6::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_6::_8, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_6::_8, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_6>(10, subFrames, &TrainHitsAnotherTrainNextFrame_6::_8));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_6::_8, &TrainHitsAnotherTrainNextFrame_6::_6, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_6::_8, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_6::_8, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_6::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_6::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_6::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_6::_8, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_6::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_6::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_6>(20, subFrames, &TrainHitsAnotherTrainNextFrame_6::_4));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_6::_4, &TrainHitsAnotherTrainNextFrame_6::_8, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_6::_4, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_6>(23, subFrames, &TrainHitsAnotherTrainNextFrame_6::_8));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_6::_8, &TrainHitsAnotherTrainNextFrame_6::_5, &::railRoadModel::ITurnout::get_top));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_6>(25, subFrames, &TrainHitsAnotherTrainNextFrame_6::_4));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_6::_4, &TrainHitsAnotherTrainNextFrame_6::_5, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_6>(27, subFrames, &TrainHitsAnotherTrainNextFrame_6::_8));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_6::_8, &TrainHitsAnotherTrainNextFrame_6::_3, &::railRoadModel::ITurnout::get_straight));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_6>(29, subFrames, &TrainHitsAnotherTrainNextFrame_6::_4));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_6::_4, &TrainHitsAnotherTrainNextFrame_6::_3, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_6>(31, subFrames, &TrainHitsAnotherTrainNextFrame_6::_4));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_6::_4, &TrainHitsAnotherTrainNextFrame_6::_2, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_6::_2, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_6>(34, subFrames, &TrainHitsAnotherTrainNextFrame_6::_4));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_6::_4, &TrainHitsAnotherTrainNextFrame_6::_7, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_6::_7, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_6>(37, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_6::_0, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_6::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_6>(40, subFrames, &TrainHitsAnotherTrainNextFrame_6::_0));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_6::_0, &TrainHitsAnotherTrainNextFrame_6::_8, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_6::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_6>(43, subFrames, &TrainHitsAnotherTrainNextFrame_6::_0));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_6::_0, &TrainHitsAnotherTrainNextFrame_6::_2, &::railRoadModel::ITrain::get_previouslyOn));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_6>(45, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_6::_1, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_6::_1, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_6>(48, subFrames, &TrainHitsAnotherTrainNextFrame_6::_1));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_6::_1, &TrainHitsAnotherTrainNextFrame_6::_7, &::railRoadModel::ITrain::get_currentlyOn));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<TrainHitsAnotherTrainNextFrame_7> get_plan_unbound__7(const ModelRoot* model, std::map<int,TrainHitsAnotherTrainNextFrame_7Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<TrainHitsAnotherTrainNextFrame_7> sp;
		
		
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_7>(1, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_7::_2, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_7>(3, subFrames, &TrainHitsAnotherTrainNextFrame_7::_2));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_7::_2, &TrainHitsAnotherTrainNextFrame_7::_6, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_7::_6, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_7::_2, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_7::_6, ::railRoadModel::ISegment::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_7::_6, ::railRoadModel::ISegment::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_7::_6, ::railRoadModel::ISegment::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_7::_2, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_7::_2, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_7::_2, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_7::_6, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_7::_2, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_7::_2, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_7>(16, subFrames, &TrainHitsAnotherTrainNextFrame_7::_2));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_7::_2, &TrainHitsAnotherTrainNextFrame_7::_6, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_7::_2, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_7>(19, subFrames, &TrainHitsAnotherTrainNextFrame_7::_6));
		sp.add_operation(create_NavigateMultiAssociation(&TrainHitsAnotherTrainNextFrame_7::_6, &TrainHitsAnotherTrainNextFrame_7::_7, &::railRoadModel::ISegment::get_connectedTo));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_7>(21, subFrames, &TrainHitsAnotherTrainNextFrame_7::_2));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_7::_2, &TrainHitsAnotherTrainNextFrame_7::_7, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_7>(23, subFrames, &TrainHitsAnotherTrainNextFrame_7::_6));
		sp.add_operation(create_NavigateMultiAssociation(&TrainHitsAnotherTrainNextFrame_7::_6, &TrainHitsAnotherTrainNextFrame_7::_4, &::railRoadModel::ISegment::get_connectedTo));
		sp.add_operation(create_InequalityCheck(&TrainHitsAnotherTrainNextFrame_7::_7, &TrainHitsAnotherTrainNextFrame_7::_4));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_7>(26, subFrames, &TrainHitsAnotherTrainNextFrame_7::_2));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_7::_2, &TrainHitsAnotherTrainNextFrame_7::_4, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_7>(28, subFrames, &TrainHitsAnotherTrainNextFrame_7::_2));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_7::_2, &TrainHitsAnotherTrainNextFrame_7::_5, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_7::_5, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_7>(31, subFrames, &TrainHitsAnotherTrainNextFrame_7::_2));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_7::_2, &TrainHitsAnotherTrainNextFrame_7::_3, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_7::_3, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_7>(34, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_7::_0, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_7::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_7>(37, subFrames, &TrainHitsAnotherTrainNextFrame_7::_0));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_7::_0, &TrainHitsAnotherTrainNextFrame_7::_6, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_7::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_7>(40, subFrames, &TrainHitsAnotherTrainNextFrame_7::_0));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_7::_0, &TrainHitsAnotherTrainNextFrame_7::_5, &::railRoadModel::ITrain::get_previouslyOn));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_7>(42, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_7::_1, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_7::_1, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_7>(45, subFrames, &TrainHitsAnotherTrainNextFrame_7::_1));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_7::_1, &TrainHitsAnotherTrainNextFrame_7::_3, &::railRoadModel::ITrain::get_currentlyOn));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<TrainHitsAnotherTrainNextFrame_8> get_plan_unbound__8(const ModelRoot* model, std::map<int,TrainHitsAnotherTrainNextFrame_8Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<TrainHitsAnotherTrainNextFrame_8> sp;
		
		
		sp.add_operation(create_ConstantValueExtend(&TrainHitsAnotherTrainNextFrame_8::_7, true));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_8>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_8::_6, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_8>(4, subFrames, &TrainHitsAnotherTrainNextFrame_8::_6));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_8::_6, &TrainHitsAnotherTrainNextFrame_8::_5, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_8::_5, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_8::_6, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_8::_5, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_8::_5, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_8>(10, subFrames, &TrainHitsAnotherTrainNextFrame_8::_5));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_8::_5, &TrainHitsAnotherTrainNextFrame_8::_7, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_8::_5, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_8::_5, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_8::_6, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_8::_6, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_8::_6, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_8::_5, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_8::_6, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_8::_6, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_8>(20, subFrames, &TrainHitsAnotherTrainNextFrame_8::_6));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_8::_6, &TrainHitsAnotherTrainNextFrame_8::_5, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_8::_6, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_8>(23, subFrames, &TrainHitsAnotherTrainNextFrame_8::_5));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_8::_5, &TrainHitsAnotherTrainNextFrame_8::_4, &::railRoadModel::ITurnout::get_top));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_8>(25, subFrames, &TrainHitsAnotherTrainNextFrame_8::_6));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_8::_6, &TrainHitsAnotherTrainNextFrame_8::_4, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_8>(27, subFrames, &TrainHitsAnotherTrainNextFrame_8::_5));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_8::_5, &TrainHitsAnotherTrainNextFrame_8::_8, &::railRoadModel::ITurnout::get_divergent));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_8>(29, subFrames, &TrainHitsAnotherTrainNextFrame_8::_6));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_8::_6, &TrainHitsAnotherTrainNextFrame_8::_8, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_8>(31, subFrames, &TrainHitsAnotherTrainNextFrame_8::_6));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_8::_6, &TrainHitsAnotherTrainNextFrame_8::_3, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_8::_3, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_8>(34, subFrames, &TrainHitsAnotherTrainNextFrame_8::_6));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_8::_6, &TrainHitsAnotherTrainNextFrame_8::_2, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_8::_2, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_8>(37, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_8::_0, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_8::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_8>(40, subFrames, &TrainHitsAnotherTrainNextFrame_8::_0));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_8::_0, &TrainHitsAnotherTrainNextFrame_8::_5, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_8::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_8>(43, subFrames, &TrainHitsAnotherTrainNextFrame_8::_0));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_8::_0, &TrainHitsAnotherTrainNextFrame_8::_3, &::railRoadModel::ITrain::get_previouslyOn));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_8>(45, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_8::_1, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_8::_1, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_8>(48, subFrames, &TrainHitsAnotherTrainNextFrame_8::_1));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_8::_1, &TrainHitsAnotherTrainNextFrame_8::_2, &::railRoadModel::ITrain::get_currentlyOn));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<TrainHitsAnotherTrainNextFrame_9> get_plan_unbound__9(const ModelRoot* model, std::map<int,TrainHitsAnotherTrainNextFrame_9Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<TrainHitsAnotherTrainNextFrame_9> sp;
		
		NotNullMatcher<ModelRoot> matcher_1627699711(model,  SafetylogicQueryGroup::instance()->context());
		
		sp.add_operation(create_ConstantValueExtend(&TrainHitsAnotherTrainNextFrame_9::_4, true));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_9>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_9::_6, ::railRoadModel::IPath::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_9>(4, subFrames, &TrainHitsAnotherTrainNextFrame_9::_6));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_9::_6, &TrainHitsAnotherTrainNextFrame_9::_3, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_9::_3, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_9::_6, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_9::_3, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_9::_3, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_9>(10, subFrames, &TrainHitsAnotherTrainNextFrame_9::_3));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_9::_3, &TrainHitsAnotherTrainNextFrame_9::_4, &::railRoadModel::ITurnout::get_currentlyDivergent));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_9::_3, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_9::_3, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_9::_6, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_9::_6, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_9::_6, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_9::_3, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_9::_6, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_9::_6, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_9>(20, subFrames, &TrainHitsAnotherTrainNextFrame_9::_6));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_9::_6, &TrainHitsAnotherTrainNextFrame_9::_3, &::railRoadModel::IPath::get_via));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_9::_6, ::railRoadModel::IPath::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_9>(23, subFrames, &TrainHitsAnotherTrainNextFrame_9::_3));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_9::_3, &TrainHitsAnotherTrainNextFrame_9::_2, &::railRoadModel::ITurnout::get_top));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_9>(25, subFrames, &TrainHitsAnotherTrainNextFrame_9::_6));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_9::_6, &TrainHitsAnotherTrainNextFrame_9::_2, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_9>(27, subFrames, &TrainHitsAnotherTrainNextFrame_9::_3));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_9::_3, &TrainHitsAnotherTrainNextFrame_9::_9, &::railRoadModel::ITurnout::get_divergent));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_9>(29, subFrames, &TrainHitsAnotherTrainNextFrame_9::_6));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_9::_6, &TrainHitsAnotherTrainNextFrame_9::_9, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_9>(31, subFrames, &TrainHitsAnotherTrainNextFrame_9::_6));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_9::_6, &TrainHitsAnotherTrainNextFrame_9::_7, &::railRoadModel::IPath::get_from));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_9>(33, subFrames, &TrainHitsAnotherTrainNextFrame_9::_6));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_9::_6, &TrainHitsAnotherTrainNextFrame_9::_8, &::railRoadModel::IPath::get_to));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_9::_8, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_9>(36, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_9::_1, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_9::_1, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_9>(39, subFrames, &TrainHitsAnotherTrainNextFrame_9::_1));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_9::_1, &TrainHitsAnotherTrainNextFrame_9::_8, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_GlobalIterateOverInstances<TrainHitsAnotherTrainNextFrame_9>(41, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&TrainHitsAnotherTrainNextFrame_9::_0, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_9>(43, subFrames, &TrainHitsAnotherTrainNextFrame_9::_0));
		sp.add_operation(create_NavigateSingleAssociation(&TrainHitsAnotherTrainNextFrame_9::_0, &TrainHitsAnotherTrainNextFrame_9::_5, &::railRoadModel::ITrain::get_previouslyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_9::_5, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_9::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_9::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<TrainHitsAnotherTrainNextFrame_9>(48, subFrames, &TrainHitsAnotherTrainNextFrame_9::_0));
		sp.add_operation(create_SingleAssociationCheck(&TrainHitsAnotherTrainNextFrame_9::_0, &TrainHitsAnotherTrainNextFrame_9::_3, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&TrainHitsAnotherTrainNextFrame_9::_0, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_NACOperation<TrainHitsAnotherTrainNextFrame_9>(matcher_1627699711, &TrainHitsAnotherTrainNextFrame_9::_5));
		
		return sp;
	}

};

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__TRAIN_HITS_ANOTHER_TRAIN_NEXT_QUERY_SPECIFICATION_H_ */
