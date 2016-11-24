#ifndef VIATRA__QUERY__SAFETYLOGIC__NEXT_SECTION_MATCHER_H_
#define VIATRA__QUERY__SAFETYLOGIC__NEXT_SECTION_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Distributed/QueryRunner.h"
#include "Viatra/Query/Plan/DistSearchPlanExecutor.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
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
#include "Viatra/Query/Safetylogic/NextSectionQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {

template<typename>class RootedNextSection;
		
template<class ModelRoot>
class NextSectionMatcher {
	using QueryRunnerT = ::Viatra::Query::Distributed::QueryRunner<RootedNextSection<ModelRoot>>;
public:
	NextSectionMatcher(
	const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context, QueryRunnerT * queryRunner) 
		: _model(model), _context(context), _queryRunner(queryRunner) {
	}
	std::unordered_set<NextSectionMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<NextSectionMatch> matches;
	
		{
			auto sp = NextSectionQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<NextSectionFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				NextSectionMatch match;
			
				match.Current = static_cast<::railRoadModel::ITurnout*>(frame._1);
				match.Old = static_cast<::railRoadModel::IRailRoadElement*>(frame._0);
				match.Next = static_cast<::railRoadModel::IRailRoadElement*>(frame._2);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = NextSectionQuerySpecification<ModelRoot>::get_plan_unbound__1(_model);
			auto exec = SearchPlanExecutor<NextSectionFrame_1>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				NextSectionMatch match;
			
				match.Current = static_cast<::railRoadModel::ISegment*>(frame._1);
				match.Old = static_cast<::railRoadModel::IRailRoadElement*>(frame._0);
				match.Next = static_cast<::railRoadModel::IRailRoadElement*>(frame._2);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = NextSectionQuerySpecification<ModelRoot>::get_plan_unbound__2(_model);
			auto exec = SearchPlanExecutor<NextSectionFrame_2>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				NextSectionMatch match;
			
				match.Current = static_cast<::railRoadModel::ITurnout*>(frame._1);
				match.Old = static_cast<::railRoadModel::IRailRoadElement*>(frame._0);
				match.Next = static_cast<::railRoadModel::IRailRoadElement*>(frame._2);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = NextSectionQuerySpecification<ModelRoot>::get_plan_unbound__3(_model);
			auto exec = SearchPlanExecutor<NextSectionFrame_3>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				NextSectionMatch match;
			
				match.Current = static_cast<::railRoadModel::ITurnout*>(frame._1);
				match.Old = static_cast<::railRoadModel::IRailRoadElement*>(frame._0);
				match.Next = static_cast<::railRoadModel::IRailRoadElement*>(frame._2);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = NextSectionQuerySpecification<ModelRoot>::get_plan_unbound__4(_model);
			auto exec = SearchPlanExecutor<NextSectionFrame_4>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				NextSectionMatch match;
			
				match.Current = static_cast<::railRoadModel::ITurnout*>(frame._1);
				match.Old = static_cast<::railRoadModel::IRailRoadElement*>(frame._0);
				match.Next = static_cast<::railRoadModel::IRailRoadElement*>(frame._2);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = NextSectionQuerySpecification<ModelRoot>::get_plan_unbound__5(_model);
			auto exec = SearchPlanExecutor<NextSectionFrame_5>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				NextSectionMatch match;
			
				match.Current = static_cast<::railRoadModel::ITurnout*>(frame._1);
				match.Old = static_cast<::railRoadModel::IRailRoadElement*>(frame._0);
				match.Next = static_cast<::railRoadModel::IRailRoadElement*>(frame._2);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = NextSectionQuerySpecification<ModelRoot>::get_plan_unbound__6(_model);
			auto exec = SearchPlanExecutor<NextSectionFrame_6>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				NextSectionMatch match;
			
				match.Current = static_cast<::railRoadModel::ITurnout*>(frame._1);
				match.Old = static_cast<::railRoadModel::IRailRoadElement*>(frame._0);
				match.Next = static_cast<::railRoadModel::IRailRoadElement*>(frame._2);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = NextSectionQuerySpecification<ModelRoot>::get_plan_unbound__7(_model);
			auto exec = SearchPlanExecutor<NextSectionFrame_7>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				NextSectionMatch match;
			
				match.Current = static_cast<::railRoadModel::ISegment*>(frame._1);
				match.Old = static_cast<::railRoadModel::IRailRoadElement*>(frame._0);
				match.Next = static_cast<::railRoadModel::IRailRoadElement*>(frame._2);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = NextSectionQuerySpecification<ModelRoot>::get_plan_unbound__8(_model);
			auto exec = SearchPlanExecutor<NextSectionFrame_8>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				NextSectionMatch match;
			
				match.Current = static_cast<::railRoadModel::ITurnout*>(frame._1);
				match.Old = static_cast<::railRoadModel::IRailRoadElement*>(frame._0);
				match.Next = static_cast<::railRoadModel::IRailRoadElement*>(frame._2);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = NextSectionQuerySpecification<ModelRoot>::get_plan_unbound__9(_model);
			auto exec = SearchPlanExecutor<NextSectionFrame_9>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				NextSectionMatch match;
			
				match.Current = static_cast<::railRoadModel::ITurnout*>(frame._1);
				match.Old = static_cast<::railRoadModel::IRailRoadElement*>(frame._0);
				match.Next = static_cast<::railRoadModel::IRailRoadElement*>(frame._2);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
		void continue_0(NextSectionFrame_0& frame, int startOpIndex, NextSectionMatchSet& results, std::map<int, NextSectionFrame_0Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = NextSectionQuerySpecification<ModelRoot>::get_plan_unbound__0(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<NextSectionFrame_0>(sp, *_context, 0, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				NextSectionMatch match;
			
				match.Current = static_cast<::railRoadModel::ITurnout*>(frame._1);
				match.Old = static_cast<::railRoadModel::IRailRoadElement*>(frame._0);
				match.Next = static_cast<::railRoadModel::IRailRoadElement*>(frame._2);
			
				results.insert(match);
			}
		
		}
		
		void continue_1(NextSectionFrame_1& frame, int startOpIndex, NextSectionMatchSet& results, std::map<int, NextSectionFrame_1Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = NextSectionQuerySpecification<ModelRoot>::get_plan_unbound__1(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<NextSectionFrame_1>(sp, *_context, 1, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				NextSectionMatch match;
			
				match.Current = static_cast<::railRoadModel::ISegment*>(frame._1);
				match.Old = static_cast<::railRoadModel::IRailRoadElement*>(frame._0);
				match.Next = static_cast<::railRoadModel::IRailRoadElement*>(frame._2);
			
				results.insert(match);
			}
		
		}
		
		void continue_2(NextSectionFrame_2& frame, int startOpIndex, NextSectionMatchSet& results, std::map<int, NextSectionFrame_2Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = NextSectionQuerySpecification<ModelRoot>::get_plan_unbound__2(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<NextSectionFrame_2>(sp, *_context, 2, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				NextSectionMatch match;
			
				match.Current = static_cast<::railRoadModel::ITurnout*>(frame._1);
				match.Old = static_cast<::railRoadModel::IRailRoadElement*>(frame._0);
				match.Next = static_cast<::railRoadModel::IRailRoadElement*>(frame._2);
			
				results.insert(match);
			}
		
		}
		
		void continue_3(NextSectionFrame_3& frame, int startOpIndex, NextSectionMatchSet& results, std::map<int, NextSectionFrame_3Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = NextSectionQuerySpecification<ModelRoot>::get_plan_unbound__3(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<NextSectionFrame_3>(sp, *_context, 3, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				NextSectionMatch match;
			
				match.Current = static_cast<::railRoadModel::ITurnout*>(frame._1);
				match.Old = static_cast<::railRoadModel::IRailRoadElement*>(frame._0);
				match.Next = static_cast<::railRoadModel::IRailRoadElement*>(frame._2);
			
				results.insert(match);
			}
		
		}
		
		void continue_4(NextSectionFrame_4& frame, int startOpIndex, NextSectionMatchSet& results, std::map<int, NextSectionFrame_4Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = NextSectionQuerySpecification<ModelRoot>::get_plan_unbound__4(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<NextSectionFrame_4>(sp, *_context, 4, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				NextSectionMatch match;
			
				match.Current = static_cast<::railRoadModel::ITurnout*>(frame._1);
				match.Old = static_cast<::railRoadModel::IRailRoadElement*>(frame._0);
				match.Next = static_cast<::railRoadModel::IRailRoadElement*>(frame._2);
			
				results.insert(match);
			}
		
		}
		
		void continue_5(NextSectionFrame_5& frame, int startOpIndex, NextSectionMatchSet& results, std::map<int, NextSectionFrame_5Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = NextSectionQuerySpecification<ModelRoot>::get_plan_unbound__5(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<NextSectionFrame_5>(sp, *_context, 5, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				NextSectionMatch match;
			
				match.Current = static_cast<::railRoadModel::ITurnout*>(frame._1);
				match.Old = static_cast<::railRoadModel::IRailRoadElement*>(frame._0);
				match.Next = static_cast<::railRoadModel::IRailRoadElement*>(frame._2);
			
				results.insert(match);
			}
		
		}
		
		void continue_6(NextSectionFrame_6& frame, int startOpIndex, NextSectionMatchSet& results, std::map<int, NextSectionFrame_6Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = NextSectionQuerySpecification<ModelRoot>::get_plan_unbound__6(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<NextSectionFrame_6>(sp, *_context, 6, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				NextSectionMatch match;
			
				match.Current = static_cast<::railRoadModel::ITurnout*>(frame._1);
				match.Old = static_cast<::railRoadModel::IRailRoadElement*>(frame._0);
				match.Next = static_cast<::railRoadModel::IRailRoadElement*>(frame._2);
			
				results.insert(match);
			}
		
		}
		
		void continue_7(NextSectionFrame_7& frame, int startOpIndex, NextSectionMatchSet& results, std::map<int, NextSectionFrame_7Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = NextSectionQuerySpecification<ModelRoot>::get_plan_unbound__7(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<NextSectionFrame_7>(sp, *_context, 7, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				NextSectionMatch match;
			
				match.Current = static_cast<::railRoadModel::ISegment*>(frame._1);
				match.Old = static_cast<::railRoadModel::IRailRoadElement*>(frame._0);
				match.Next = static_cast<::railRoadModel::IRailRoadElement*>(frame._2);
			
				results.insert(match);
			}
		
		}
		
		void continue_8(NextSectionFrame_8& frame, int startOpIndex, NextSectionMatchSet& results, std::map<int, NextSectionFrame_8Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = NextSectionQuerySpecification<ModelRoot>::get_plan_unbound__8(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<NextSectionFrame_8>(sp, *_context, 8, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				NextSectionMatch match;
			
				match.Current = static_cast<::railRoadModel::ITurnout*>(frame._1);
				match.Old = static_cast<::railRoadModel::IRailRoadElement*>(frame._0);
				match.Next = static_cast<::railRoadModel::IRailRoadElement*>(frame._2);
			
				results.insert(match);
			}
		
		}
		
		void continue_9(NextSectionFrame_9& frame, int startOpIndex, NextSectionMatchSet& results, std::map<int, NextSectionFrame_9Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = NextSectionQuerySpecification<ModelRoot>::get_plan_unbound__9(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<NextSectionFrame_9>(sp, *_context, 9, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				NextSectionMatch match;
			
				match.Current = static_cast<::railRoadModel::ITurnout*>(frame._1);
				match.Old = static_cast<::railRoadModel::IRailRoadElement*>(frame._0);
				match.Next = static_cast<::railRoadModel::IRailRoadElement*>(frame._2);
			
				results.insert(match);
			}
		
		}
		
		
	NextSectionMatchSet continueExec(std::string strFrameVector, int bodyID, int startOpIndex){
		switch(bodyID){
			case 0: {
				NextSectionMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, NextSectionFrame_0Vector> frameVectors;
				
				// For each frame
				NextSectionFrame_0Vector::ParseFromStringCallback( strFrameVector, _model, [&](NextSectionFrame_0& frame){
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
				NextSectionMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, NextSectionFrame_1Vector> frameVectors;
				
				// For each frame
				NextSectionFrame_1Vector::ParseFromStringCallback( strFrameVector, _model, [&](NextSectionFrame_1& frame){
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
				NextSectionMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, NextSectionFrame_2Vector> frameVectors;
				
				// For each frame
				NextSectionFrame_2Vector::ParseFromStringCallback( strFrameVector, _model, [&](NextSectionFrame_2& frame){
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
				NextSectionMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, NextSectionFrame_3Vector> frameVectors;
				
				// For each frame
				NextSectionFrame_3Vector::ParseFromStringCallback( strFrameVector, _model, [&](NextSectionFrame_3& frame){
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
				NextSectionMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, NextSectionFrame_4Vector> frameVectors;
				
				// For each frame
				NextSectionFrame_4Vector::ParseFromStringCallback( strFrameVector, _model, [&](NextSectionFrame_4& frame){
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
				NextSectionMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, NextSectionFrame_5Vector> frameVectors;
				
				// For each frame
				NextSectionFrame_5Vector::ParseFromStringCallback( strFrameVector, _model, [&](NextSectionFrame_5& frame){
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
				NextSectionMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, NextSectionFrame_6Vector> frameVectors;
				
				// For each frame
				NextSectionFrame_6Vector::ParseFromStringCallback( strFrameVector, _model, [&](NextSectionFrame_6& frame){
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
				NextSectionMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, NextSectionFrame_7Vector> frameVectors;
				
				// For each frame
				NextSectionFrame_7Vector::ParseFromStringCallback( strFrameVector, _model, [&](NextSectionFrame_7& frame){
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
				NextSectionMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, NextSectionFrame_8Vector> frameVectors;
				
				// For each frame
				NextSectionFrame_8Vector::ParseFromStringCallback( strFrameVector, _model, [&](NextSectionFrame_8& frame){
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
				NextSectionMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, NextSectionFrame_9Vector> frameVectors;
				
				// For each frame
				NextSectionFrame_9Vector::ParseFromStringCallback( strFrameVector, _model, [&](NextSectionFrame_9& frame){
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
					NextSectionFrame_0Vector	vector;
					vector.push_back(NextSectionFrame_0{});
					ret[0] = vector.SerializeAsString();
				}	
				{
					NextSectionFrame_1Vector	vector;
					vector.push_back(NextSectionFrame_1{});
					ret[1] = vector.SerializeAsString();
				}	
				{
					NextSectionFrame_2Vector	vector;
					vector.push_back(NextSectionFrame_2{});
					ret[2] = vector.SerializeAsString();
				}	
				{
					NextSectionFrame_3Vector	vector;
					vector.push_back(NextSectionFrame_3{});
					ret[3] = vector.SerializeAsString();
				}	
				{
					NextSectionFrame_4Vector	vector;
					vector.push_back(NextSectionFrame_4{});
					ret[4] = vector.SerializeAsString();
				}	
				{
					NextSectionFrame_5Vector	vector;
					vector.push_back(NextSectionFrame_5{});
					ret[5] = vector.SerializeAsString();
				}	
				{
					NextSectionFrame_6Vector	vector;
					vector.push_back(NextSectionFrame_6{});
					ret[6] = vector.SerializeAsString();
				}	
				{
					NextSectionFrame_7Vector	vector;
					vector.push_back(NextSectionFrame_7{});
					ret[7] = vector.SerializeAsString();
				}	
				{
					NextSectionFrame_8Vector	vector;
					vector.push_back(NextSectionFrame_8{});
					ret[8] = vector.SerializeAsString();
				}	
				{
					NextSectionFrame_9Vector	vector;
					vector.push_back(NextSectionFrame_9{});
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


#endif /*  VIATRA__QUERY__SAFETYLOGIC__NEXT_SECTION_MATCHER_H_ */
