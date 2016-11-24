#ifndef VIATRA__QUERY__SAFETYLOGIC__TRAIN_HITS_ANOTHER_TRAIN_NEXT_MATCHER_H_
#define VIATRA__QUERY__SAFETYLOGIC__TRAIN_HITS_ANOTHER_TRAIN_NEXT_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Distributed/QueryRunner.h"
#include "Viatra/Query/Plan/DistSearchPlanExecutor.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
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
#include "Viatra/Query/Safetylogic/TrainHitsAnotherTrainNextQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {

template<typename>class RootedTrainHitsAnotherTrainNext;
		
template<class ModelRoot>
class TrainHitsAnotherTrainNextMatcher {
	using QueryRunnerT = ::Viatra::Query::Distributed::QueryRunner<RootedTrainHitsAnotherTrainNext<ModelRoot>>;
public:
	TrainHitsAnotherTrainNextMatcher(
	const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context, QueryRunnerT * queryRunner) 
		: _model(model), _context(context), _queryRunner(queryRunner) {
	}
	std::unordered_set<TrainHitsAnotherTrainNextMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<TrainHitsAnotherTrainNextMatch> matches;
	
		{
			auto sp = TrainHitsAnotherTrainNextQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextQuerySpecification<ModelRoot>::get_plan_unbound__1(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextFrame_1>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextQuerySpecification<ModelRoot>::get_plan_unbound__2(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextFrame_2>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextQuerySpecification<ModelRoot>::get_plan_unbound__3(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextFrame_3>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextQuerySpecification<ModelRoot>::get_plan_unbound__4(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextFrame_4>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextQuerySpecification<ModelRoot>::get_plan_unbound__5(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextFrame_5>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextQuerySpecification<ModelRoot>::get_plan_unbound__6(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextFrame_6>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextQuerySpecification<ModelRoot>::get_plan_unbound__7(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextFrame_7>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextQuerySpecification<ModelRoot>::get_plan_unbound__8(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextFrame_8>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainHitsAnotherTrainNextQuerySpecification<ModelRoot>::get_plan_unbound__9(_model);
			auto exec = SearchPlanExecutor<TrainHitsAnotherTrainNextFrame_9>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
		void continue_0(TrainHitsAnotherTrainNextFrame_0& frame, int startOpIndex, TrainHitsAnotherTrainNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextFrame_0Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextQuerySpecification<ModelRoot>::get_plan_unbound__0(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextFrame_0>(sp, *_context, 0, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_1(TrainHitsAnotherTrainNextFrame_1& frame, int startOpIndex, TrainHitsAnotherTrainNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextFrame_1Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextQuerySpecification<ModelRoot>::get_plan_unbound__1(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextFrame_1>(sp, *_context, 1, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_2(TrainHitsAnotherTrainNextFrame_2& frame, int startOpIndex, TrainHitsAnotherTrainNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextFrame_2Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextQuerySpecification<ModelRoot>::get_plan_unbound__2(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextFrame_2>(sp, *_context, 2, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_3(TrainHitsAnotherTrainNextFrame_3& frame, int startOpIndex, TrainHitsAnotherTrainNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextFrame_3Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextQuerySpecification<ModelRoot>::get_plan_unbound__3(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextFrame_3>(sp, *_context, 3, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_4(TrainHitsAnotherTrainNextFrame_4& frame, int startOpIndex, TrainHitsAnotherTrainNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextFrame_4Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextQuerySpecification<ModelRoot>::get_plan_unbound__4(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextFrame_4>(sp, *_context, 4, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_5(TrainHitsAnotherTrainNextFrame_5& frame, int startOpIndex, TrainHitsAnotherTrainNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextFrame_5Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextQuerySpecification<ModelRoot>::get_plan_unbound__5(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextFrame_5>(sp, *_context, 5, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_6(TrainHitsAnotherTrainNextFrame_6& frame, int startOpIndex, TrainHitsAnotherTrainNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextFrame_6Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextQuerySpecification<ModelRoot>::get_plan_unbound__6(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextFrame_6>(sp, *_context, 6, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_7(TrainHitsAnotherTrainNextFrame_7& frame, int startOpIndex, TrainHitsAnotherTrainNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextFrame_7Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextQuerySpecification<ModelRoot>::get_plan_unbound__7(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextFrame_7>(sp, *_context, 7, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_8(TrainHitsAnotherTrainNextFrame_8& frame, int startOpIndex, TrainHitsAnotherTrainNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextFrame_8Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextQuerySpecification<ModelRoot>::get_plan_unbound__8(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextFrame_8>(sp, *_context, 8, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_9(TrainHitsAnotherTrainNextFrame_9& frame, int startOpIndex, TrainHitsAnotherTrainNextMatchSet& results, std::map<int, TrainHitsAnotherTrainNextFrame_9Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainHitsAnotherTrainNextQuerySpecification<ModelRoot>::get_plan_unbound__9(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainHitsAnotherTrainNextFrame_9>(sp, *_context, 9, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainHitsAnotherTrainNextMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		
	TrainHitsAnotherTrainNextMatchSet continueExec(std::string strFrameVector, int bodyID, int startOpIndex){
		switch(bodyID){
			case 0: {
				TrainHitsAnotherTrainNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextFrame_0Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextFrame_0Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextFrame_0& frame){
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
				TrainHitsAnotherTrainNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextFrame_1Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextFrame_1Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextFrame_1& frame){
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
				TrainHitsAnotherTrainNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextFrame_2Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextFrame_2Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextFrame_2& frame){
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
				TrainHitsAnotherTrainNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextFrame_3Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextFrame_3Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextFrame_3& frame){
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
				TrainHitsAnotherTrainNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextFrame_4Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextFrame_4Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextFrame_4& frame){
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
				TrainHitsAnotherTrainNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextFrame_5Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextFrame_5Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextFrame_5& frame){
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
				TrainHitsAnotherTrainNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextFrame_6Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextFrame_6Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextFrame_6& frame){
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
				TrainHitsAnotherTrainNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextFrame_7Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextFrame_7Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextFrame_7& frame){
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
				TrainHitsAnotherTrainNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextFrame_8Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextFrame_8Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextFrame_8& frame){
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
				TrainHitsAnotherTrainNextMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainHitsAnotherTrainNextFrame_9Vector> frameVectors;
				
				// For each frame
				TrainHitsAnotherTrainNextFrame_9Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainHitsAnotherTrainNextFrame_9& frame){
					continue_9(frame, startOpIndex, resultSet, frameVectors);														
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
					TrainHitsAnotherTrainNextFrame_0Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextFrame_0{});
					ret[0] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextFrame_1Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextFrame_1{});
					ret[1] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextFrame_2Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextFrame_2{});
					ret[2] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextFrame_3Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextFrame_3{});
					ret[3] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextFrame_4Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextFrame_4{});
					ret[4] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextFrame_5Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextFrame_5{});
					ret[5] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextFrame_6Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextFrame_6{});
					ret[6] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextFrame_7Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextFrame_7{});
					ret[7] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextFrame_8Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextFrame_8{});
					ret[8] = vector.SerializeAsString();
				}	
				{
					TrainHitsAnotherTrainNextFrame_9Vector	vector;
					vector.push_back(TrainHitsAnotherTrainNextFrame_9{});
					ret[9] = vector.SerializeAsString();
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


#endif /*  VIATRA__QUERY__SAFETYLOGIC__TRAIN_HITS_ANOTHER_TRAIN_NEXT_MATCHER_H_ */
