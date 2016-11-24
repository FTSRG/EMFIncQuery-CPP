#ifndef VIATRA__QUERY__SAFETYLOGIC__TRAIN_HITS_ANOTHER_TRAIN_NEXT_AFTER_NEXT_MATCHER_H_
#define VIATRA__QUERY__SAFETYLOGIC__TRAIN_HITS_ANOTHER_TRAIN_NEXT_AFTER_NEXT_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Distributed/QueryRunner.h"
#include "Viatra/Query/Plan/DistSearchPlanExecutor.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_0.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_1.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_10.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_11.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_12.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_13.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_14.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_15.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_16.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_17.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_18.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_19.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_2.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_20.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_21.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_22.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_23.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_24.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_25.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_26.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_27.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_28.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_29.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_3.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_30.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_31.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_32.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_33.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_34.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_35.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_36.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_37.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_38.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_39.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_4.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_40.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_41.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_42.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_43.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_44.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_45.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_46.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_47.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_48.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_49.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_5.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_50.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_51.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_52.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_53.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_54.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_55.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_56.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_57.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_58.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_59.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_6.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_60.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_61.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_62.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_63.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_64.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_65.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_66.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_67.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_68.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_69.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_7.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_70.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_71.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_72.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_73.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_74.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_75.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_76.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_77.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_78.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_79.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_8.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_80.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_81.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_82.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_83.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_84.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_85.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_86.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_87.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_88.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_89.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_9.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_90.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_91.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_92.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_93.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_94.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_95.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_96.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_97.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_98.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextFrame_99.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextMatch.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextAfterNextQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {

template<typename>class RootedTrainHitsAnotherTrainNextAfterNext;
		
template<class ModelRoot>
class TrainHitsAnotherTrainNextAfterNextMatcher {
	using QueryRunnerT = ::Viatra::Query::Distributed::QueryRunner<RootedTrainHitsAnotherTrainNextAfterNext<ModelRoot>>;
public:
	TrainHitsAnotherTrainNextAfterNextMatcher(
	const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context, QueryRunnerT * queryRunner) 
		: _model(model), _context(context), _queryRunner(queryRunner) {
	}
	std::unordered_set<TrainHitsAnotherTrainNextAfterNextMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<TrainHitsAnotherTrainNextAfterNextMatch> matches;
	
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__1(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_1>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__2(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_2>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__3(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_3>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__4(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_4>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__5(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_5>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__6(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_6>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__7(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_7>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__8(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_8>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__9(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_9>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__10(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_10>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__11(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_11>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__12(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_12>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__13(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_13>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__14(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_14>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__15(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_15>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__16(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_16>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__17(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_17>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__18(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_18>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__19(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_19>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__20(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_20>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__21(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_21>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__22(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_22>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__23(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_23>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__24(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_24>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__25(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_25>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__26(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_26>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__27(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_27>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__28(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_28>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__29(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_29>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__30(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_30>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__31(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_31>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__32(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_32>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__33(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_33>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__34(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_34>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__35(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_35>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__36(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_36>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__37(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_37>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__38(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_38>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__39(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_39>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__40(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_40>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__41(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_41>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__42(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_42>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__43(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_43>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__44(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_44>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__45(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_45>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__46(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_46>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__47(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_47>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__48(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_48>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__49(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_49>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__50(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_50>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__51(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_51>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__52(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_52>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__53(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_53>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__54(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_54>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__55(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_55>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__56(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_56>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__57(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_57>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__58(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_58>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__59(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_59>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__60(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_60>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__61(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_61>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__62(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_62>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__63(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_63>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__64(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_64>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__65(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_65>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__66(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_66>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__67(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_67>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__68(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_68>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__69(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_69>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__70(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_70>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__71(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_71>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__72(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_72>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__73(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_73>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__74(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_74>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__75(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_75>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__76(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_76>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__77(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_77>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__78(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_78>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__79(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_79>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__80(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_80>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__81(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_81>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__82(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_82>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__83(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_83>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__84(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_84>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__85(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_85>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__86(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_86>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__87(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_87>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__88(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_88>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__89(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_89>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__90(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_90>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__91(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_91>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__92(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_92>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__93(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_93>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__94(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_94>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__95(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_95>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__96(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_96>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__97(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_97>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__98(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_98>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__99(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_99>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
		void continue_0(TrainHitsAnotherTrainNextAfterNextFrame_0& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_0Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__0(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_0>(sp, *_context, 0, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_1(TrainHitsAnotherTrainNextAfterNextFrame_1& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_1Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__1(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_1>(sp, *_context, 1, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_2(TrainHitsAnotherTrainNextAfterNextFrame_2& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_2Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__2(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_2>(sp, *_context, 2, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_3(TrainHitsAnotherTrainNextAfterNextFrame_3& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_3Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__3(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_3>(sp, *_context, 3, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_4(TrainHitsAnotherTrainNextAfterNextFrame_4& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_4Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__4(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_4>(sp, *_context, 4, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_5(TrainHitsAnotherTrainNextAfterNextFrame_5& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_5Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__5(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_5>(sp, *_context, 5, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_6(TrainHitsAnotherTrainNextAfterNextFrame_6& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_6Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__6(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_6>(sp, *_context, 6, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_7(TrainHitsAnotherTrainNextAfterNextFrame_7& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_7Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__7(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_7>(sp, *_context, 7, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_8(TrainHitsAnotherTrainNextAfterNextFrame_8& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_8Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__8(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_8>(sp, *_context, 8, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_9(TrainHitsAnotherTrainNextAfterNextFrame_9& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_9Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__9(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_9>(sp, *_context, 9, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_10(TrainHitsAnotherTrainNextAfterNextFrame_10& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_10Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__10(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_10>(sp, *_context, 10, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_11(TrainHitsAnotherTrainNextAfterNextFrame_11& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_11Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__11(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_11>(sp, *_context, 11, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_12(TrainHitsAnotherTrainNextAfterNextFrame_12& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_12Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__12(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_12>(sp, *_context, 12, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_13(TrainHitsAnotherTrainNextAfterNextFrame_13& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_13Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__13(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_13>(sp, *_context, 13, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_14(TrainHitsAnotherTrainNextAfterNextFrame_14& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_14Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__14(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_14>(sp, *_context, 14, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_15(TrainHitsAnotherTrainNextAfterNextFrame_15& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_15Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__15(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_15>(sp, *_context, 15, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_16(TrainHitsAnotherTrainNextAfterNextFrame_16& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_16Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__16(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_16>(sp, *_context, 16, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_17(TrainHitsAnotherTrainNextAfterNextFrame_17& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_17Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__17(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_17>(sp, *_context, 17, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_18(TrainHitsAnotherTrainNextAfterNextFrame_18& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_18Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__18(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_18>(sp, *_context, 18, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_19(TrainHitsAnotherTrainNextAfterNextFrame_19& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_19Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__19(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_19>(sp, *_context, 19, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_20(TrainHitsAnotherTrainNextAfterNextFrame_20& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_20Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__20(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_20>(sp, *_context, 20, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_21(TrainHitsAnotherTrainNextAfterNextFrame_21& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_21Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__21(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_21>(sp, *_context, 21, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_22(TrainHitsAnotherTrainNextAfterNextFrame_22& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_22Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__22(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_22>(sp, *_context, 22, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_23(TrainHitsAnotherTrainNextAfterNextFrame_23& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_23Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__23(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_23>(sp, *_context, 23, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_24(TrainHitsAnotherTrainNextAfterNextFrame_24& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_24Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__24(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_24>(sp, *_context, 24, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_25(TrainHitsAnotherTrainNextAfterNextFrame_25& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_25Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__25(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_25>(sp, *_context, 25, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_26(TrainHitsAnotherTrainNextAfterNextFrame_26& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_26Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__26(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_26>(sp, *_context, 26, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_27(TrainHitsAnotherTrainNextAfterNextFrame_27& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_27Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__27(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_27>(sp, *_context, 27, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_28(TrainHitsAnotherTrainNextAfterNextFrame_28& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_28Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__28(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_28>(sp, *_context, 28, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_29(TrainHitsAnotherTrainNextAfterNextFrame_29& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_29Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__29(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_29>(sp, *_context, 29, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_30(TrainHitsAnotherTrainNextAfterNextFrame_30& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_30Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__30(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_30>(sp, *_context, 30, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_31(TrainHitsAnotherTrainNextAfterNextFrame_31& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_31Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__31(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_31>(sp, *_context, 31, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_32(TrainHitsAnotherTrainNextAfterNextFrame_32& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_32Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__32(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_32>(sp, *_context, 32, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_33(TrainHitsAnotherTrainNextAfterNextFrame_33& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_33Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__33(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_33>(sp, *_context, 33, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_34(TrainHitsAnotherTrainNextAfterNextFrame_34& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_34Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__34(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_34>(sp, *_context, 34, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_35(TrainHitsAnotherTrainNextAfterNextFrame_35& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_35Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__35(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_35>(sp, *_context, 35, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_36(TrainHitsAnotherTrainNextAfterNextFrame_36& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_36Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__36(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_36>(sp, *_context, 36, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_37(TrainHitsAnotherTrainNextAfterNextFrame_37& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_37Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__37(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_37>(sp, *_context, 37, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_38(TrainHitsAnotherTrainNextAfterNextFrame_38& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_38Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__38(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_38>(sp, *_context, 38, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_39(TrainHitsAnotherTrainNextAfterNextFrame_39& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_39Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__39(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_39>(sp, *_context, 39, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_40(TrainHitsAnotherTrainNextAfterNextFrame_40& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_40Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__40(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_40>(sp, *_context, 40, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_41(TrainHitsAnotherTrainNextAfterNextFrame_41& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_41Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__41(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_41>(sp, *_context, 41, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_42(TrainHitsAnotherTrainNextAfterNextFrame_42& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_42Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__42(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_42>(sp, *_context, 42, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_43(TrainHitsAnotherTrainNextAfterNextFrame_43& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_43Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__43(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_43>(sp, *_context, 43, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_44(TrainHitsAnotherTrainNextAfterNextFrame_44& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_44Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__44(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_44>(sp, *_context, 44, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_45(TrainHitsAnotherTrainNextAfterNextFrame_45& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_45Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__45(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_45>(sp, *_context, 45, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_46(TrainHitsAnotherTrainNextAfterNextFrame_46& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_46Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__46(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_46>(sp, *_context, 46, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_47(TrainHitsAnotherTrainNextAfterNextFrame_47& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_47Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__47(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_47>(sp, *_context, 47, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_48(TrainHitsAnotherTrainNextAfterNextFrame_48& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_48Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__48(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_48>(sp, *_context, 48, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_49(TrainHitsAnotherTrainNextAfterNextFrame_49& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_49Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__49(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_49>(sp, *_context, 49, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_50(TrainHitsAnotherTrainNextAfterNextFrame_50& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_50Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__50(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_50>(sp, *_context, 50, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_51(TrainHitsAnotherTrainNextAfterNextFrame_51& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_51Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__51(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_51>(sp, *_context, 51, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_52(TrainHitsAnotherTrainNextAfterNextFrame_52& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_52Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__52(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_52>(sp, *_context, 52, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_53(TrainHitsAnotherTrainNextAfterNextFrame_53& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_53Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__53(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_53>(sp, *_context, 53, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_54(TrainHitsAnotherTrainNextAfterNextFrame_54& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_54Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__54(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_54>(sp, *_context, 54, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_55(TrainHitsAnotherTrainNextAfterNextFrame_55& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_55Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__55(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_55>(sp, *_context, 55, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_56(TrainHitsAnotherTrainNextAfterNextFrame_56& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_56Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__56(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_56>(sp, *_context, 56, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_57(TrainHitsAnotherTrainNextAfterNextFrame_57& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_57Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__57(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_57>(sp, *_context, 57, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_58(TrainHitsAnotherTrainNextAfterNextFrame_58& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_58Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__58(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_58>(sp, *_context, 58, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_59(TrainHitsAnotherTrainNextAfterNextFrame_59& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_59Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__59(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_59>(sp, *_context, 59, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_60(TrainHitsAnotherTrainNextAfterNextFrame_60& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_60Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__60(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_60>(sp, *_context, 60, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_61(TrainHitsAnotherTrainNextAfterNextFrame_61& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_61Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__61(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_61>(sp, *_context, 61, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_62(TrainHitsAnotherTrainNextAfterNextFrame_62& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_62Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__62(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_62>(sp, *_context, 62, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_63(TrainHitsAnotherTrainNextAfterNextFrame_63& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_63Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__63(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_63>(sp, *_context, 63, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_64(TrainHitsAnotherTrainNextAfterNextFrame_64& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_64Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__64(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_64>(sp, *_context, 64, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_65(TrainHitsAnotherTrainNextAfterNextFrame_65& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_65Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__65(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_65>(sp, *_context, 65, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_66(TrainHitsAnotherTrainNextAfterNextFrame_66& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_66Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__66(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_66>(sp, *_context, 66, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_67(TrainHitsAnotherTrainNextAfterNextFrame_67& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_67Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__67(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_67>(sp, *_context, 67, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_68(TrainHitsAnotherTrainNextAfterNextFrame_68& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_68Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__68(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_68>(sp, *_context, 68, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_69(TrainHitsAnotherTrainNextAfterNextFrame_69& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_69Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__69(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_69>(sp, *_context, 69, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_70(TrainHitsAnotherTrainNextAfterNextFrame_70& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_70Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__70(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_70>(sp, *_context, 70, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_71(TrainHitsAnotherTrainNextAfterNextFrame_71& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_71Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__71(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_71>(sp, *_context, 71, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_72(TrainHitsAnotherTrainNextAfterNextFrame_72& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_72Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__72(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_72>(sp, *_context, 72, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_73(TrainHitsAnotherTrainNextAfterNextFrame_73& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_73Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__73(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_73>(sp, *_context, 73, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_74(TrainHitsAnotherTrainNextAfterNextFrame_74& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_74Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__74(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_74>(sp, *_context, 74, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_75(TrainHitsAnotherTrainNextAfterNextFrame_75& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_75Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__75(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_75>(sp, *_context, 75, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_76(TrainHitsAnotherTrainNextAfterNextFrame_76& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_76Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__76(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_76>(sp, *_context, 76, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_77(TrainHitsAnotherTrainNextAfterNextFrame_77& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_77Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__77(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_77>(sp, *_context, 77, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_78(TrainHitsAnotherTrainNextAfterNextFrame_78& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_78Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__78(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_78>(sp, *_context, 78, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_79(TrainHitsAnotherTrainNextAfterNextFrame_79& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_79Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__79(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_79>(sp, *_context, 79, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_80(TrainHitsAnotherTrainNextAfterNextFrame_80& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_80Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__80(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_80>(sp, *_context, 80, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_81(TrainHitsAnotherTrainNextAfterNextFrame_81& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_81Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__81(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_81>(sp, *_context, 81, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_82(TrainHitsAnotherTrainNextAfterNextFrame_82& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_82Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__82(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_82>(sp, *_context, 82, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_83(TrainHitsAnotherTrainNextAfterNextFrame_83& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_83Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__83(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_83>(sp, *_context, 83, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_84(TrainHitsAnotherTrainNextAfterNextFrame_84& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_84Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__84(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_84>(sp, *_context, 84, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_85(TrainHitsAnotherTrainNextAfterNextFrame_85& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_85Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__85(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_85>(sp, *_context, 85, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_86(TrainHitsAnotherTrainNextAfterNextFrame_86& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_86Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__86(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_86>(sp, *_context, 86, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_87(TrainHitsAnotherTrainNextAfterNextFrame_87& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_87Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__87(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_87>(sp, *_context, 87, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_88(TrainHitsAnotherTrainNextAfterNextFrame_88& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_88Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__88(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_88>(sp, *_context, 88, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_89(TrainHitsAnotherTrainNextAfterNextFrame_89& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_89Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__89(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_89>(sp, *_context, 89, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_90(TrainHitsAnotherTrainNextAfterNextFrame_90& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_90Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__90(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_90>(sp, *_context, 90, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_91(TrainHitsAnotherTrainNextAfterNextFrame_91& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_91Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__91(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_91>(sp, *_context, 91, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_92(TrainHitsAnotherTrainNextAfterNextFrame_92& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_92Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__92(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_92>(sp, *_context, 92, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_93(TrainHitsAnotherTrainNextAfterNextFrame_93& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_93Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__93(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_93>(sp, *_context, 93, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_94(TrainHitsAnotherTrainNextAfterNextFrame_94& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_94Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__94(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_94>(sp, *_context, 94, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_95(TrainHitsAnotherTrainNextAfterNextFrame_95& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_95Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__95(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_95>(sp, *_context, 95, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_96(TrainHitsAnotherTrainNextAfterNextFrame_96& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_96Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__96(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_96>(sp, *_context, 96, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_97(TrainHitsAnotherTrainNextAfterNextFrame_97& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_97Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__97(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_97>(sp, *_context, 97, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_98(TrainHitsAnotherTrainNextAfterNextFrame_98& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_98Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__98(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_98>(sp, *_context, 98, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_99(TrainHitsAnotherTrainNextAfterNextFrame_99& frame, int startOpIndex, TrainHitsAnotherTrainNextAfterNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_99Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextAfterNextQuerySpecification<ModelRoot>::get_plan_unbound__99(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextAfterNextFrame_99>(sp, *_context, 99, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextAfterNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		
	TrainHitsAnotherTrainNextAfterNextMatchSet continueExec(std::string strFrameVector, int bodyID, int startOpIndex){
		switch(bodyID){
			case 0: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_0Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_0Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_0& frame){
					continue_0(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 1: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_1Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_1Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_1& frame){
					continue_1(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 2: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_2Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_2Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_2& frame){
					continue_2(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 3: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_3Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_3Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_3& frame){
					continue_3(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 4: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_4Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_4Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_4& frame){
					continue_4(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 5: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_5Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_5Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_5& frame){
					continue_5(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 6: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_6Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_6Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_6& frame){
					continue_6(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 7: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_7Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_7Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_7& frame){
					continue_7(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 8: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_8Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_8Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_8& frame){
					continue_8(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 9: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_9Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_9Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_9& frame){
					continue_9(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 10: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_10Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_10Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_10& frame){
					continue_10(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 11: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_11Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_11Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_11& frame){
					continue_11(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 12: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_12Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_12Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_12& frame){
					continue_12(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 13: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_13Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_13Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_13& frame){
					continue_13(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 14: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_14Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_14Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_14& frame){
					continue_14(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 15: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_15Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_15Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_15& frame){
					continue_15(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 16: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_16Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_16Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_16& frame){
					continue_16(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 17: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_17Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_17Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_17& frame){
					continue_17(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 18: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_18Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_18Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_18& frame){
					continue_18(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 19: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_19Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_19Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_19& frame){
					continue_19(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 20: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_20Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_20Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_20& frame){
					continue_20(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 21: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_21Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_21Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_21& frame){
					continue_21(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 22: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_22Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_22Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_22& frame){
					continue_22(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 23: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_23Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_23Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_23& frame){
					continue_23(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 24: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_24Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_24Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_24& frame){
					continue_24(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 25: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_25Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_25Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_25& frame){
					continue_25(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 26: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_26Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_26Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_26& frame){
					continue_26(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 27: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_27Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_27Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_27& frame){
					continue_27(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 28: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_28Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_28Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_28& frame){
					continue_28(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 29: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_29Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_29Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_29& frame){
					continue_29(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 30: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_30Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_30Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_30& frame){
					continue_30(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 31: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_31Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_31Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_31& frame){
					continue_31(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 32: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_32Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_32Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_32& frame){
					continue_32(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 33: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_33Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_33Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_33& frame){
					continue_33(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 34: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_34Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_34Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_34& frame){
					continue_34(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 35: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_35Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_35Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_35& frame){
					continue_35(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 36: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_36Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_36Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_36& frame){
					continue_36(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 37: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_37Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_37Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_37& frame){
					continue_37(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 38: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_38Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_38Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_38& frame){
					continue_38(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 39: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_39Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_39Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_39& frame){
					continue_39(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 40: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_40Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_40Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_40& frame){
					continue_40(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 41: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_41Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_41Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_41& frame){
					continue_41(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 42: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_42Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_42Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_42& frame){
					continue_42(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 43: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_43Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_43Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_43& frame){
					continue_43(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 44: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_44Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_44Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_44& frame){
					continue_44(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 45: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_45Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_45Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_45& frame){
					continue_45(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 46: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_46Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_46Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_46& frame){
					continue_46(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 47: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_47Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_47Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_47& frame){
					continue_47(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 48: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_48Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_48Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_48& frame){
					continue_48(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 49: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_49Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_49Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_49& frame){
					continue_49(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 50: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_50Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_50Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_50& frame){
					continue_50(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 51: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_51Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_51Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_51& frame){
					continue_51(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 52: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_52Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_52Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_52& frame){
					continue_52(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 53: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_53Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_53Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_53& frame){
					continue_53(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 54: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_54Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_54Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_54& frame){
					continue_54(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 55: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_55Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_55Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_55& frame){
					continue_55(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 56: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_56Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_56Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_56& frame){
					continue_56(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 57: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_57Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_57Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_57& frame){
					continue_57(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 58: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_58Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_58Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_58& frame){
					continue_58(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 59: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_59Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_59Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_59& frame){
					continue_59(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 60: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_60Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_60Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_60& frame){
					continue_60(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 61: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_61Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_61Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_61& frame){
					continue_61(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 62: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_62Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_62Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_62& frame){
					continue_62(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 63: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_63Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_63Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_63& frame){
					continue_63(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 64: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_64Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_64Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_64& frame){
					continue_64(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 65: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_65Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_65Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_65& frame){
					continue_65(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 66: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_66Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_66Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_66& frame){
					continue_66(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 67: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_67Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_67Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_67& frame){
					continue_67(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 68: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_68Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_68Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_68& frame){
					continue_68(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 69: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_69Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_69Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_69& frame){
					continue_69(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 70: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_70Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_70Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_70& frame){
					continue_70(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 71: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_71Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_71Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_71& frame){
					continue_71(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 72: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_72Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_72Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_72& frame){
					continue_72(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 73: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_73Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_73Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_73& frame){
					continue_73(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 74: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_74Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_74Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_74& frame){
					continue_74(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 75: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_75Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_75Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_75& frame){
					continue_75(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 76: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_76Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_76Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_76& frame){
					continue_76(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 77: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_77Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_77Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_77& frame){
					continue_77(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 78: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_78Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_78Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_78& frame){
					continue_78(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 79: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_79Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_79Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_79& frame){
					continue_79(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 80: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_80Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_80Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_80& frame){
					continue_80(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 81: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_81Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_81Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_81& frame){
					continue_81(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 82: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_82Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_82Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_82& frame){
					continue_82(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 83: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_83Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_83Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_83& frame){
					continue_83(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 84: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_84Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_84Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_84& frame){
					continue_84(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 85: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_85Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_85Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_85& frame){
					continue_85(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 86: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_86Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_86Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_86& frame){
					continue_86(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 87: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_87Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_87Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_87& frame){
					continue_87(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 88: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_88Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_88Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_88& frame){
					continue_88(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 89: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_89Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_89Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_89& frame){
					continue_89(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 90: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_90Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_90Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_90& frame){
					continue_90(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 91: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_91Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_91Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_91& frame){
					continue_91(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 92: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_92Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_92Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_92& frame){
					continue_92(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 93: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_93Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_93Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_93& frame){
					continue_93(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 94: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_94Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_94Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_94& frame){
					continue_94(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 95: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_95Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_95Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_95& frame){
					continue_95(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 96: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_96Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_96Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_96& frame){
					continue_96(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 97: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_97Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_97Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_97& frame){
					continue_97(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 98: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_98Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_98Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_98& frame){
					continue_98(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 99: {
				TrainHitsAnotherTrainNextAfterNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextAfterNextFrame_99Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextAfterNextFrame_99Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextAfterNextFrame_99& frame){
					continue_99(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			default:
				throw "Matcher continue function has an unidentified bodyID";
			break;
		}
	}
			std::map<int, std::string> distributedStartPoint()
			{
				std::map<int, std::string> ret;
	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_0Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_0{});
					ret[0] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_1Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_1{});
					ret[1] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_2Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_2{});
					ret[2] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_3Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_3{});
					ret[3] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_4Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_4{});
					ret[4] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_5Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_5{});
					ret[5] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_6Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_6{});
					ret[6] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_7Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_7{});
					ret[7] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_8Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_8{});
					ret[8] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_9Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_9{});
					ret[9] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_10Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_10{});
					ret[10] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_11Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_11{});
					ret[11] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_12Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_12{});
					ret[12] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_13Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_13{});
					ret[13] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_14Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_14{});
					ret[14] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_15Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_15{});
					ret[15] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_16Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_16{});
					ret[16] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_17Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_17{});
					ret[17] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_18Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_18{});
					ret[18] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_19Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_19{});
					ret[19] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_20Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_20{});
					ret[20] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_21Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_21{});
					ret[21] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_22Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_22{});
					ret[22] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_23Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_23{});
					ret[23] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_24Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_24{});
					ret[24] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_25Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_25{});
					ret[25] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_26Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_26{});
					ret[26] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_27Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_27{});
					ret[27] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_28Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_28{});
					ret[28] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_29Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_29{});
					ret[29] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_30Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_30{});
					ret[30] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_31Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_31{});
					ret[31] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_32Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_32{});
					ret[32] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_33Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_33{});
					ret[33] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_34Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_34{});
					ret[34] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_35Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_35{});
					ret[35] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_36Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_36{});
					ret[36] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_37Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_37{});
					ret[37] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_38Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_38{});
					ret[38] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_39Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_39{});
					ret[39] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_40Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_40{});
					ret[40] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_41Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_41{});
					ret[41] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_42Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_42{});
					ret[42] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_43Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_43{});
					ret[43] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_44Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_44{});
					ret[44] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_45Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_45{});
					ret[45] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_46Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_46{});
					ret[46] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_47Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_47{});
					ret[47] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_48Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_48{});
					ret[48] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_49Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_49{});
					ret[49] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_50Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_50{});
					ret[50] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_51Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_51{});
					ret[51] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_52Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_52{});
					ret[52] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_53Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_53{});
					ret[53] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_54Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_54{});
					ret[54] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_55Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_55{});
					ret[55] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_56Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_56{});
					ret[56] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_57Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_57{});
					ret[57] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_58Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_58{});
					ret[58] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_59Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_59{});
					ret[59] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_60Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_60{});
					ret[60] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_61Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_61{});
					ret[61] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_62Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_62{});
					ret[62] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_63Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_63{});
					ret[63] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_64Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_64{});
					ret[64] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_65Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_65{});
					ret[65] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_66Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_66{});
					ret[66] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_67Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_67{});
					ret[67] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_68Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_68{});
					ret[68] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_69Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_69{});
					ret[69] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_70Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_70{});
					ret[70] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_71Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_71{});
					ret[71] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_72Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_72{});
					ret[72] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_73Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_73{});
					ret[73] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_74Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_74{});
					ret[74] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_75Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_75{});
					ret[75] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_76Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_76{});
					ret[76] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_77Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_77{});
					ret[77] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_78Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_78{});
					ret[78] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_79Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_79{});
					ret[79] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_80Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_80{});
					ret[80] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_81Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_81{});
					ret[81] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_82Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_82{});
					ret[82] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_83Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_83{});
					ret[83] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_84Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_84{});
					ret[84] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_85Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_85{});
					ret[85] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_86Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_86{});
					ret[86] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_87Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_87{});
					ret[87] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_88Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_88{});
					ret[88] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_89Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_89{});
					ret[89] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_90Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_90{});
					ret[90] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_91Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_91{});
					ret[91] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_92Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_92{});
					ret[92] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_93Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_93{});
					ret[93] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_94Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_94{});
					ret[94] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_95Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_95{});
					ret[95] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_96Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_96{});
					ret[96] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_97Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_97{});
					ret[97] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_98Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_98{});
					ret[98] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextAfterNextFrame_99Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextAfterNextFrame_99{});
					ret[99] = vector.SerializeAsString();
				}	
				return ret;
			}
							
private:
	QueryRunnerT * _queryRunner;
	const ModelRoot* _model;
	const ::Viatra::Query::Matcher::ISearchContext* _context;
};

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__TRAIN_HITS_ANOTHER_TRAIN_NEXT_AFTER_NEXT_MATCHER_H_ */
