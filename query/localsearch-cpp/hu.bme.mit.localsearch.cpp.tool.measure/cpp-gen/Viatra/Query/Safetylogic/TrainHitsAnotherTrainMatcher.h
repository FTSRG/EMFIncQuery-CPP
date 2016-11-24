#ifndef VIATRA__QUERY__SAFETYLOGIC__TRAIN_HITS_ANOTHER_TRAIN_MATCHER_H_
#define VIATRA__QUERY__SAFETYLOGIC__TRAIN_HITS_ANOTHER_TRAIN_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Distributed/QueryRunner.h"
#include "Viatra/Query/Plan/DistSearchPlanExecutor.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_0.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_1.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_10.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_100.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_101.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_102.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_103.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_104.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_105.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_106.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_107.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_108.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_109.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_11.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_110.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_111.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_112.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_113.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_114.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_12.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_13.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_14.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_15.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_16.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_17.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_18.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_19.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_2.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_20.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_21.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_22.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_23.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_24.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_25.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_26.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_27.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_28.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_29.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_3.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_30.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_31.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_32.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_33.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_34.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_35.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_36.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_37.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_38.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_39.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_4.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_40.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_41.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_42.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_43.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_44.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_45.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_46.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_47.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_48.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_49.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_5.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_50.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_51.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_52.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_53.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_54.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_55.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_56.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_57.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_58.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_59.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_6.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_60.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_61.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_62.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_63.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_64.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_65.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_66.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_67.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_68.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_69.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_7.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_70.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_71.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_72.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_73.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_74.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_75.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_76.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_77.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_78.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_79.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_8.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_80.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_81.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_82.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_83.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_84.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_85.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_86.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_87.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_88.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_89.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_9.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_90.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_91.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_92.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_93.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_94.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_95.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_96.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_97.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_98.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainFrame_99.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainMatch.h"
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {

template<typename>class RootedTrainHitsAnotherTrain;
		
template<class ModelRoot>
class TrainHitsAnotherTrainMatcher {
	using QueryRunnerT = ::Viatra::Query::Distributed::QueryRunner<RootedTrainHitsAnotherTrain<ModelRoot>>;
public:
	TrainHitsAnotherTrainMatcher(
	const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context, QueryRunnerT * queryRunner) 
		: _model(model), _context(context), _queryRunner(queryRunner) {
	}
	std::unordered_set<TrainHitsAnotherTrainMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<TrainHitsAnotherTrainMatch> matches;
	
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__1(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_1>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__2(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_2>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__3(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_3>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__4(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_4>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__5(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_5>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__6(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_6>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__7(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_7>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__8(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_8>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__9(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_9>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__10(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_10>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__11(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_11>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__12(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_12>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__13(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_13>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__14(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_14>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__15(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_15>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__16(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_16>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__17(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_17>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__18(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_18>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__19(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_19>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__20(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_20>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__21(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_21>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__22(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_22>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__23(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_23>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__24(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_24>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__25(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_25>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__26(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_26>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__27(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_27>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__28(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_28>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__29(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_29>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__30(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_30>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__31(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_31>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__32(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_32>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__33(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_33>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__34(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_34>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__35(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_35>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__36(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_36>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__37(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_37>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__38(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_38>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__39(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_39>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__40(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_40>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__41(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_41>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__42(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_42>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__43(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_43>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__44(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_44>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__45(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_45>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__46(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_46>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__47(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_47>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__48(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_48>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__49(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_49>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__50(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_50>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__51(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_51>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__52(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_52>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__53(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_53>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__54(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_54>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__55(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_55>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__56(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_56>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__57(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_57>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__58(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_58>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__59(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_59>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__60(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_60>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__61(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_61>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__62(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_62>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__63(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_63>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__64(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_64>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__65(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_65>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__66(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_66>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__67(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_67>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__68(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_68>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__69(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_69>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__70(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_70>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__71(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_71>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__72(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_72>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__73(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_73>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__74(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_74>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__75(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_75>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__76(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_76>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__77(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_77>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__78(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_78>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__79(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_79>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__80(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_80>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__81(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_81>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__82(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_82>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__83(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_83>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__84(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_84>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__85(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_85>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__86(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_86>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__87(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_87>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__88(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_88>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__89(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_89>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__90(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_90>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__91(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_91>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__92(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_92>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__93(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_93>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__94(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_94>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__95(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_95>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__96(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_96>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__97(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_97>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__98(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_98>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__99(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_99>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__100(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_100>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__101(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_101>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__102(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_102>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__103(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_103>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__104(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_104>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__105(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_105>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__106(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_106>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__107(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_107>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__108(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_108>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__109(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_109>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__110(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_110>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__111(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_111>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__112(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_112>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__113(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_113>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__114(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainFrame_114>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
		void continue_0(TrainHitsAnotherTrainFrame_0& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_0Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__0(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_0>(sp, *_context, 0, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_1(TrainHitsAnotherTrainFrame_1& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_1Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__1(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_1>(sp, *_context, 1, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_2(TrainHitsAnotherTrainFrame_2& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_2Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__2(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_2>(sp, *_context, 2, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_3(TrainHitsAnotherTrainFrame_3& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_3Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__3(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_3>(sp, *_context, 3, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_4(TrainHitsAnotherTrainFrame_4& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_4Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__4(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_4>(sp, *_context, 4, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_5(TrainHitsAnotherTrainFrame_5& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_5Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__5(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_5>(sp, *_context, 5, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_6(TrainHitsAnotherTrainFrame_6& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_6Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__6(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_6>(sp, *_context, 6, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_7(TrainHitsAnotherTrainFrame_7& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_7Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__7(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_7>(sp, *_context, 7, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_8(TrainHitsAnotherTrainFrame_8& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_8Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__8(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_8>(sp, *_context, 8, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_9(TrainHitsAnotherTrainFrame_9& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_9Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__9(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_9>(sp, *_context, 9, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_10(TrainHitsAnotherTrainFrame_10& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_10Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__10(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_10>(sp, *_context, 10, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_11(TrainHitsAnotherTrainFrame_11& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_11Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__11(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_11>(sp, *_context, 11, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_12(TrainHitsAnotherTrainFrame_12& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_12Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__12(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_12>(sp, *_context, 12, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_13(TrainHitsAnotherTrainFrame_13& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_13Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__13(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_13>(sp, *_context, 13, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_14(TrainHitsAnotherTrainFrame_14& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_14Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__14(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_14>(sp, *_context, 14, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_15(TrainHitsAnotherTrainFrame_15& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_15Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__15(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_15>(sp, *_context, 15, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_16(TrainHitsAnotherTrainFrame_16& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_16Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__16(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_16>(sp, *_context, 16, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_17(TrainHitsAnotherTrainFrame_17& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_17Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__17(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_17>(sp, *_context, 17, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_18(TrainHitsAnotherTrainFrame_18& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_18Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__18(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_18>(sp, *_context, 18, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_19(TrainHitsAnotherTrainFrame_19& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_19Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__19(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_19>(sp, *_context, 19, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_20(TrainHitsAnotherTrainFrame_20& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_20Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__20(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_20>(sp, *_context, 20, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_21(TrainHitsAnotherTrainFrame_21& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_21Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__21(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_21>(sp, *_context, 21, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_22(TrainHitsAnotherTrainFrame_22& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_22Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__22(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_22>(sp, *_context, 22, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_23(TrainHitsAnotherTrainFrame_23& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_23Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__23(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_23>(sp, *_context, 23, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_24(TrainHitsAnotherTrainFrame_24& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_24Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__24(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_24>(sp, *_context, 24, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_25(TrainHitsAnotherTrainFrame_25& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_25Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__25(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_25>(sp, *_context, 25, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_26(TrainHitsAnotherTrainFrame_26& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_26Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__26(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_26>(sp, *_context, 26, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_27(TrainHitsAnotherTrainFrame_27& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_27Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__27(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_27>(sp, *_context, 27, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_28(TrainHitsAnotherTrainFrame_28& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_28Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__28(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_28>(sp, *_context, 28, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_29(TrainHitsAnotherTrainFrame_29& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_29Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__29(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_29>(sp, *_context, 29, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_30(TrainHitsAnotherTrainFrame_30& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_30Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__30(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_30>(sp, *_context, 30, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_31(TrainHitsAnotherTrainFrame_31& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_31Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__31(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_31>(sp, *_context, 31, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_32(TrainHitsAnotherTrainFrame_32& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_32Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__32(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_32>(sp, *_context, 32, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_33(TrainHitsAnotherTrainFrame_33& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_33Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__33(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_33>(sp, *_context, 33, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_34(TrainHitsAnotherTrainFrame_34& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_34Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__34(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_34>(sp, *_context, 34, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_35(TrainHitsAnotherTrainFrame_35& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_35Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__35(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_35>(sp, *_context, 35, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_36(TrainHitsAnotherTrainFrame_36& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_36Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__36(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_36>(sp, *_context, 36, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_37(TrainHitsAnotherTrainFrame_37& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_37Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__37(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_37>(sp, *_context, 37, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_38(TrainHitsAnotherTrainFrame_38& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_38Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__38(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_38>(sp, *_context, 38, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_39(TrainHitsAnotherTrainFrame_39& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_39Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__39(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_39>(sp, *_context, 39, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_40(TrainHitsAnotherTrainFrame_40& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_40Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__40(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_40>(sp, *_context, 40, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_41(TrainHitsAnotherTrainFrame_41& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_41Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__41(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_41>(sp, *_context, 41, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_42(TrainHitsAnotherTrainFrame_42& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_42Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__42(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_42>(sp, *_context, 42, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_43(TrainHitsAnotherTrainFrame_43& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_43Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__43(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_43>(sp, *_context, 43, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_44(TrainHitsAnotherTrainFrame_44& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_44Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__44(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_44>(sp, *_context, 44, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_45(TrainHitsAnotherTrainFrame_45& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_45Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__45(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_45>(sp, *_context, 45, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_46(TrainHitsAnotherTrainFrame_46& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_46Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__46(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_46>(sp, *_context, 46, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_47(TrainHitsAnotherTrainFrame_47& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_47Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__47(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_47>(sp, *_context, 47, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_48(TrainHitsAnotherTrainFrame_48& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_48Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__48(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_48>(sp, *_context, 48, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_49(TrainHitsAnotherTrainFrame_49& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_49Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__49(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_49>(sp, *_context, 49, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_50(TrainHitsAnotherTrainFrame_50& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_50Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__50(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_50>(sp, *_context, 50, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_51(TrainHitsAnotherTrainFrame_51& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_51Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__51(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_51>(sp, *_context, 51, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_52(TrainHitsAnotherTrainFrame_52& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_52Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__52(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_52>(sp, *_context, 52, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_53(TrainHitsAnotherTrainFrame_53& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_53Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__53(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_53>(sp, *_context, 53, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_54(TrainHitsAnotherTrainFrame_54& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_54Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__54(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_54>(sp, *_context, 54, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_55(TrainHitsAnotherTrainFrame_55& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_55Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__55(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_55>(sp, *_context, 55, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_56(TrainHitsAnotherTrainFrame_56& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_56Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__56(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_56>(sp, *_context, 56, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_57(TrainHitsAnotherTrainFrame_57& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_57Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__57(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_57>(sp, *_context, 57, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_58(TrainHitsAnotherTrainFrame_58& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_58Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__58(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_58>(sp, *_context, 58, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_59(TrainHitsAnotherTrainFrame_59& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_59Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__59(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_59>(sp, *_context, 59, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_60(TrainHitsAnotherTrainFrame_60& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_60Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__60(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_60>(sp, *_context, 60, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_61(TrainHitsAnotherTrainFrame_61& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_61Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__61(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_61>(sp, *_context, 61, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_62(TrainHitsAnotherTrainFrame_62& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_62Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__62(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_62>(sp, *_context, 62, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_63(TrainHitsAnotherTrainFrame_63& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_63Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__63(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_63>(sp, *_context, 63, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_64(TrainHitsAnotherTrainFrame_64& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_64Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__64(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_64>(sp, *_context, 64, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_65(TrainHitsAnotherTrainFrame_65& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_65Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__65(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_65>(sp, *_context, 65, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_66(TrainHitsAnotherTrainFrame_66& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_66Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__66(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_66>(sp, *_context, 66, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_67(TrainHitsAnotherTrainFrame_67& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_67Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__67(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_67>(sp, *_context, 67, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_68(TrainHitsAnotherTrainFrame_68& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_68Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__68(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_68>(sp, *_context, 68, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_69(TrainHitsAnotherTrainFrame_69& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_69Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__69(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_69>(sp, *_context, 69, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_70(TrainHitsAnotherTrainFrame_70& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_70Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__70(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_70>(sp, *_context, 70, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_71(TrainHitsAnotherTrainFrame_71& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_71Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__71(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_71>(sp, *_context, 71, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_72(TrainHitsAnotherTrainFrame_72& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_72Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__72(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_72>(sp, *_context, 72, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_73(TrainHitsAnotherTrainFrame_73& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_73Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__73(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_73>(sp, *_context, 73, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_74(TrainHitsAnotherTrainFrame_74& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_74Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__74(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_74>(sp, *_context, 74, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_75(TrainHitsAnotherTrainFrame_75& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_75Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__75(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_75>(sp, *_context, 75, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_76(TrainHitsAnotherTrainFrame_76& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_76Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__76(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_76>(sp, *_context, 76, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_77(TrainHitsAnotherTrainFrame_77& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_77Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__77(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_77>(sp, *_context, 77, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_78(TrainHitsAnotherTrainFrame_78& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_78Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__78(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_78>(sp, *_context, 78, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_79(TrainHitsAnotherTrainFrame_79& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_79Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__79(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_79>(sp, *_context, 79, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_80(TrainHitsAnotherTrainFrame_80& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_80Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__80(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_80>(sp, *_context, 80, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_81(TrainHitsAnotherTrainFrame_81& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_81Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__81(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_81>(sp, *_context, 81, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_82(TrainHitsAnotherTrainFrame_82& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_82Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__82(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_82>(sp, *_context, 82, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_83(TrainHitsAnotherTrainFrame_83& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_83Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__83(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_83>(sp, *_context, 83, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_84(TrainHitsAnotherTrainFrame_84& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_84Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__84(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_84>(sp, *_context, 84, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_85(TrainHitsAnotherTrainFrame_85& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_85Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__85(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_85>(sp, *_context, 85, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_86(TrainHitsAnotherTrainFrame_86& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_86Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__86(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_86>(sp, *_context, 86, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_87(TrainHitsAnotherTrainFrame_87& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_87Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__87(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_87>(sp, *_context, 87, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_88(TrainHitsAnotherTrainFrame_88& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_88Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__88(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_88>(sp, *_context, 88, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_89(TrainHitsAnotherTrainFrame_89& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_89Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__89(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_89>(sp, *_context, 89, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_90(TrainHitsAnotherTrainFrame_90& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_90Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__90(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_90>(sp, *_context, 90, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_91(TrainHitsAnotherTrainFrame_91& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_91Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__91(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_91>(sp, *_context, 91, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_92(TrainHitsAnotherTrainFrame_92& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_92Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__92(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_92>(sp, *_context, 92, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_93(TrainHitsAnotherTrainFrame_93& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_93Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__93(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_93>(sp, *_context, 93, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_94(TrainHitsAnotherTrainFrame_94& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_94Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__94(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_94>(sp, *_context, 94, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_95(TrainHitsAnotherTrainFrame_95& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_95Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__95(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_95>(sp, *_context, 95, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_96(TrainHitsAnotherTrainFrame_96& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_96Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__96(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_96>(sp, *_context, 96, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_97(TrainHitsAnotherTrainFrame_97& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_97Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__97(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_97>(sp, *_context, 97, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_98(TrainHitsAnotherTrainFrame_98& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_98Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__98(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_98>(sp, *_context, 98, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_99(TrainHitsAnotherTrainFrame_99& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_99Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__99(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_99>(sp, *_context, 99, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_100(TrainHitsAnotherTrainFrame_100& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_100Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__100(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_100>(sp, *_context, 100, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_101(TrainHitsAnotherTrainFrame_101& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_101Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__101(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_101>(sp, *_context, 101, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_102(TrainHitsAnotherTrainFrame_102& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_102Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__102(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_102>(sp, *_context, 102, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_103(TrainHitsAnotherTrainFrame_103& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_103Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__103(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_103>(sp, *_context, 103, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_104(TrainHitsAnotherTrainFrame_104& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_104Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__104(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_104>(sp, *_context, 104, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_105(TrainHitsAnotherTrainFrame_105& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_105Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__105(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_105>(sp, *_context, 105, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_106(TrainHitsAnotherTrainFrame_106& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_106Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__106(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_106>(sp, *_context, 106, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_107(TrainHitsAnotherTrainFrame_107& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_107Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__107(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_107>(sp, *_context, 107, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_108(TrainHitsAnotherTrainFrame_108& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_108Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__108(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_108>(sp, *_context, 108, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_109(TrainHitsAnotherTrainFrame_109& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_109Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__109(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_109>(sp, *_context, 109, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_110(TrainHitsAnotherTrainFrame_110& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_110Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__110(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_110>(sp, *_context, 110, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_111(TrainHitsAnotherTrainFrame_111& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_111Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__111(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_111>(sp, *_context, 111, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_112(TrainHitsAnotherTrainFrame_112& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_112Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__112(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_112>(sp, *_context, 112, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_113(TrainHitsAnotherTrainFrame_113& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_113Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__113(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_113>(sp, *_context, 113, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_114(TrainHitsAnotherTrainFrame_114& frame, int startOpIndex, TrainHitsAnotherTrainMatchSet& results, std::map<int, TrainHitsAnotherTrainFrame_114Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainQuerySpecification<ModelRoot>::get_plan_unbound__114(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainFrame_114>(sp, *_context, 114, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		
	TrainHitsAnotherTrainMatchSet continueExec(std::string strFrameVector, int bodyID, int startOpIndex){
		switch(bodyID){
			case 0: {
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_0Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_0Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_0& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_1Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_1Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_1& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_2Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_2Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_2& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_3Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_3Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_3& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_4Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_4Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_4& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_5Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_5Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_5& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_6Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_6Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_6& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_7Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_7Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_7& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_8Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_8Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_8& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_9Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_9Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_9& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_10Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_10Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_10& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_11Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_11Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_11& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_12Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_12Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_12& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_13Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_13Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_13& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_14Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_14Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_14& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_15Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_15Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_15& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_16Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_16Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_16& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_17Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_17Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_17& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_18Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_18Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_18& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_19Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_19Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_19& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_20Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_20Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_20& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_21Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_21Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_21& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_22Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_22Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_22& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_23Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_23Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_23& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_24Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_24Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_24& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_25Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_25Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_25& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_26Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_26Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_26& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_27Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_27Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_27& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_28Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_28Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_28& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_29Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_29Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_29& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_30Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_30Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_30& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_31Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_31Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_31& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_32Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_32Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_32& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_33Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_33Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_33& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_34Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_34Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_34& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_35Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_35Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_35& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_36Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_36Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_36& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_37Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_37Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_37& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_38Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_38Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_38& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_39Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_39Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_39& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_40Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_40Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_40& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_41Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_41Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_41& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_42Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_42Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_42& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_43Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_43Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_43& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_44Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_44Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_44& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_45Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_45Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_45& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_46Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_46Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_46& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_47Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_47Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_47& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_48Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_48Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_48& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_49Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_49Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_49& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_50Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_50Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_50& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_51Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_51Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_51& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_52Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_52Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_52& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_53Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_53Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_53& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_54Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_54Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_54& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_55Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_55Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_55& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_56Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_56Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_56& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_57Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_57Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_57& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_58Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_58Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_58& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_59Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_59Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_59& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_60Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_60Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_60& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_61Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_61Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_61& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_62Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_62Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_62& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_63Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_63Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_63& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_64Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_64Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_64& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_65Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_65Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_65& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_66Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_66Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_66& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_67Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_67Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_67& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_68Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_68Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_68& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_69Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_69Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_69& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_70Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_70Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_70& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_71Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_71Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_71& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_72Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_72Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_72& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_73Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_73Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_73& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_74Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_74Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_74& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_75Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_75Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_75& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_76Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_76Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_76& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_77Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_77Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_77& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_78Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_78Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_78& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_79Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_79Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_79& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_80Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_80Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_80& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_81Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_81Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_81& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_82Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_82Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_82& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_83Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_83Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_83& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_84Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_84Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_84& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_85Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_85Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_85& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_86Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_86Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_86& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_87Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_87Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_87& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_88Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_88Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_88& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_89Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_89Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_89& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_90Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_90Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_90& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_91Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_91Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_91& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_92Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_92Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_92& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_93Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_93Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_93& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_94Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_94Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_94& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_95Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_95Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_95& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_96Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_96Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_96& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_97Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_97Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_97& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_98Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_98Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_98& frame){
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
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_99Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_99Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_99& frame){
					continue_99(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 100: {
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_100Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_100Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_100& frame){
					continue_100(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 101: {
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_101Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_101Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_101& frame){
					continue_101(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 102: {
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_102Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_102Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_102& frame){
					continue_102(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 103: {
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_103Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_103Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_103& frame){
					continue_103(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 104: {
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_104Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_104Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_104& frame){
					continue_104(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 105: {
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_105Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_105Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_105& frame){
					continue_105(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 106: {
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_106Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_106Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_106& frame){
					continue_106(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 107: {
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_107Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_107Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_107& frame){
					continue_107(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 108: {
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_108Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_108Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_108& frame){
					continue_108(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 109: {
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_109Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_109Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_109& frame){
					continue_109(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 110: {
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_110Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_110Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_110& frame){
					continue_110(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 111: {
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_111Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_111Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_111& frame){
					continue_111(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 112: {
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_112Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_112Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_112& frame){
					continue_112(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 113: {
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_113Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_113Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_113& frame){
					continue_113(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			case 114: {
				TrainHitsAnotherTrainMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainFrame_114Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainFrame_114Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainFrame_114& frame){
					continue_114(frame, startOpIndex, resultSet, frameVectors);														
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
					TrainHitsAnotherTrainFrame_0Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_0{});
					ret[0] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_1Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_1{});
					ret[1] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_2Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_2{});
					ret[2] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_3Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_3{});
					ret[3] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_4Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_4{});
					ret[4] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_5Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_5{});
					ret[5] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_6Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_6{});
					ret[6] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_7Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_7{});
					ret[7] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_8Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_8{});
					ret[8] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_9Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_9{});
					ret[9] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_10Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_10{});
					ret[10] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_11Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_11{});
					ret[11] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_12Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_12{});
					ret[12] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_13Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_13{});
					ret[13] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_14Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_14{});
					ret[14] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_15Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_15{});
					ret[15] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_16Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_16{});
					ret[16] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_17Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_17{});
					ret[17] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_18Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_18{});
					ret[18] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_19Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_19{});
					ret[19] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_20Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_20{});
					ret[20] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_21Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_21{});
					ret[21] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_22Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_22{});
					ret[22] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_23Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_23{});
					ret[23] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_24Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_24{});
					ret[24] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_25Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_25{});
					ret[25] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_26Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_26{});
					ret[26] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_27Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_27{});
					ret[27] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_28Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_28{});
					ret[28] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_29Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_29{});
					ret[29] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_30Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_30{});
					ret[30] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_31Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_31{});
					ret[31] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_32Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_32{});
					ret[32] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_33Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_33{});
					ret[33] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_34Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_34{});
					ret[34] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_35Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_35{});
					ret[35] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_36Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_36{});
					ret[36] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_37Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_37{});
					ret[37] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_38Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_38{});
					ret[38] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_39Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_39{});
					ret[39] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_40Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_40{});
					ret[40] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_41Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_41{});
					ret[41] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_42Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_42{});
					ret[42] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_43Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_43{});
					ret[43] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_44Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_44{});
					ret[44] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_45Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_45{});
					ret[45] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_46Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_46{});
					ret[46] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_47Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_47{});
					ret[47] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_48Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_48{});
					ret[48] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_49Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_49{});
					ret[49] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_50Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_50{});
					ret[50] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_51Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_51{});
					ret[51] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_52Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_52{});
					ret[52] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_53Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_53{});
					ret[53] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_54Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_54{});
					ret[54] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_55Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_55{});
					ret[55] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_56Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_56{});
					ret[56] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_57Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_57{});
					ret[57] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_58Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_58{});
					ret[58] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_59Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_59{});
					ret[59] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_60Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_60{});
					ret[60] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_61Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_61{});
					ret[61] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_62Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_62{});
					ret[62] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_63Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_63{});
					ret[63] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_64Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_64{});
					ret[64] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_65Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_65{});
					ret[65] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_66Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_66{});
					ret[66] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_67Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_67{});
					ret[67] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_68Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_68{});
					ret[68] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_69Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_69{});
					ret[69] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_70Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_70{});
					ret[70] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_71Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_71{});
					ret[71] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_72Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_72{});
					ret[72] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_73Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_73{});
					ret[73] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_74Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_74{});
					ret[74] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_75Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_75{});
					ret[75] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_76Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_76{});
					ret[76] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_77Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_77{});
					ret[77] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_78Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_78{});
					ret[78] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_79Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_79{});
					ret[79] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_80Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_80{});
					ret[80] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_81Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_81{});
					ret[81] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_82Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_82{});
					ret[82] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_83Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_83{});
					ret[83] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_84Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_84{});
					ret[84] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_85Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_85{});
					ret[85] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_86Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_86{});
					ret[86] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_87Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_87{});
					ret[87] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_88Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_88{});
					ret[88] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_89Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_89{});
					ret[89] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_90Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_90{});
					ret[90] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_91Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_91{});
					ret[91] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_92Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_92{});
					ret[92] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_93Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_93{});
					ret[93] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_94Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_94{});
					ret[94] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_95Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_95{});
					ret[95] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_96Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_96{});
					ret[96] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_97Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_97{});
					ret[97] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_98Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_98{});
					ret[98] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_99Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_99{});
					ret[99] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_100Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_100{});
					ret[100] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_101Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_101{});
					ret[101] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_102Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_102{});
					ret[102] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_103Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_103{});
					ret[103] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_104Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_104{});
					ret[104] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_105Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_105{});
					ret[105] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_106Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_106{});
					ret[106] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_107Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_107{});
					ret[107] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_108Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_108{});
					ret[108] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_109Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_109{});
					ret[109] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_110Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_110{});
					ret[110] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_111Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_111{});
					ret[111] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_112Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_112{});
					ret[112] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_113Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_113{});
					ret[113] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainFrame_114Vector	vector;
					vector.push_back(TrainHitsAnotherTrainFrame_114{});
					ret[114] = vector.SerializeAsString();
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


#endif /*  VIATRA__QUERY__SAFETYLOGIC__TRAIN_HITS_ANOTHER_TRAIN_MATCHER_H_ */
