#ifndef VIATRA__QUERY__SAFETYLOGIC__VIABLE_PATHS_MATCHER_H_
#define VIATRA__QUERY__SAFETYLOGIC__VIABLE_PATHS_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Distributed/QueryRunner.h"
#include "Viatra/Query/Plan/DistSearchPlanExecutor.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Safetylogic/ViablePathsFrame_0.h"
#include "Viatra/Query/Safetylogic/ViablePathsFrame_1.h"
#include "Viatra/Query/Safetylogic/ViablePathsFrame_2.h"
#include "Viatra/Query/Safetylogic/ViablePathsFrame_3.h"
#include "Viatra/Query/Safetylogic/ViablePathsFrame_4.h"
#include "Viatra/Query/Safetylogic/ViablePathsMatch.h"
#include "Viatra/Query/Safetylogic/ViablePathsQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {

template<typename>class RootedViablePaths;
		
template<class ModelRoot>
class ViablePathsMatcher {
	using QueryRunnerT = ::Viatra::Query::Distributed::QueryRunner<RootedViablePaths<ModelRoot>>;
public:
	ViablePathsMatcher(
	const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context, QueryRunnerT * queryRunner) 
		: _model(model), _context(context), _queryRunner(queryRunner) {
	}
	std::unordered_set<ViablePathsMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<ViablePathsMatch> matches;
	
		{
			auto sp = ViablePathsQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<ViablePathsFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				ViablePathsMatch match;
			
				match.This = static_cast<::railRoadModel::ITurnout*>(frame._0);
				match.path = static_cast<::railRoadModel::IPath*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = ViablePathsQuerySpecification<ModelRoot>::get_plan_unbound__1(_model);
			auto exec = SearchPlanExecutor<ViablePathsFrame_1>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				ViablePathsMatch match;
			
				match.This = static_cast<::railRoadModel::ISegment*>(frame._0);
				match.path = static_cast<::railRoadModel::IPath*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = ViablePathsQuerySpecification<ModelRoot>::get_plan_unbound__2(_model);
			auto exec = SearchPlanExecutor<ViablePathsFrame_2>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				ViablePathsMatch match;
			
				match.This = static_cast<::railRoadModel::ITurnout*>(frame._0);
				match.path = static_cast<::railRoadModel::IPath*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = ViablePathsQuerySpecification<ModelRoot>::get_plan_unbound__3(_model);
			auto exec = SearchPlanExecutor<ViablePathsFrame_3>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				ViablePathsMatch match;
			
				match.This = static_cast<::railRoadModel::ITurnout*>(frame._0);
				match.path = static_cast<::railRoadModel::IPath*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = ViablePathsQuerySpecification<ModelRoot>::get_plan_unbound__4(_model);
			auto exec = SearchPlanExecutor<ViablePathsFrame_4>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				ViablePathsMatch match;
			
				match.This = static_cast<::railRoadModel::ITurnout*>(frame._0);
				match.path = static_cast<::railRoadModel::IPath*>(frame._1);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
		void continue_0(ViablePathsFrame_0& frame, int startOpIndex, ViablePathsMatchSet& results, std::map<int, ViablePathsFrame_0Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = ViablePathsQuerySpecification<ModelRoot>::get_plan_unbound__0(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<ViablePathsFrame_0>(sp, *_context, 0, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				ViablePathsMatch match;
			
				match.This = static_cast<::railRoadModel::ITurnout*>(frame._0);
				match.path = static_cast<::railRoadModel::IPath*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_1(ViablePathsFrame_1& frame, int startOpIndex, ViablePathsMatchSet& results, std::map<int, ViablePathsFrame_1Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = ViablePathsQuerySpecification<ModelRoot>::get_plan_unbound__1(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<ViablePathsFrame_1>(sp, *_context, 1, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				ViablePathsMatch match;
			
				match.This = static_cast<::railRoadModel::ISegment*>(frame._0);
				match.path = static_cast<::railRoadModel::IPath*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_2(ViablePathsFrame_2& frame, int startOpIndex, ViablePathsMatchSet& results, std::map<int, ViablePathsFrame_2Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = ViablePathsQuerySpecification<ModelRoot>::get_plan_unbound__2(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<ViablePathsFrame_2>(sp, *_context, 2, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				ViablePathsMatch match;
			
				match.This = static_cast<::railRoadModel::ITurnout*>(frame._0);
				match.path = static_cast<::railRoadModel::IPath*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_3(ViablePathsFrame_3& frame, int startOpIndex, ViablePathsMatchSet& results, std::map<int, ViablePathsFrame_3Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = ViablePathsQuerySpecification<ModelRoot>::get_plan_unbound__3(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<ViablePathsFrame_3>(sp, *_context, 3, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				ViablePathsMatch match;
			
				match.This = static_cast<::railRoadModel::ITurnout*>(frame._0);
				match.path = static_cast<::railRoadModel::IPath*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_4(ViablePathsFrame_4& frame, int startOpIndex, ViablePathsMatchSet& results, std::map<int, ViablePathsFrame_4Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = ViablePathsQuerySpecification<ModelRoot>::get_plan_unbound__4(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<ViablePathsFrame_4>(sp, *_context, 4, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				ViablePathsMatch match;
			
				match.This = static_cast<::railRoadModel::ITurnout*>(frame._0);
				match.path = static_cast<::railRoadModel::IPath*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		
	ViablePathsMatchSet continueExec(std::string strFrameVector, int bodyID, int startOpIndex){
		switch(bodyID){
			case 0: {
				ViablePathsMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, ViablePathsFrame_0Vector> frameVectors;
				
				// For each frame
				ViablePathsFrame_0Vector::ParseFromStringCallback( strFrameVector, _model, [&](ViablePathsFrame_0& frame){
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
				ViablePathsMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, ViablePathsFrame_1Vector> frameVectors;
				
				// For each frame
				ViablePathsFrame_1Vector::ParseFromStringCallback( strFrameVector, _model, [&](ViablePathsFrame_1& frame){
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
				ViablePathsMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, ViablePathsFrame_2Vector> frameVectors;
				
				// For each frame
				ViablePathsFrame_2Vector::ParseFromStringCallback( strFrameVector, _model, [&](ViablePathsFrame_2& frame){
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
				ViablePathsMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, ViablePathsFrame_3Vector> frameVectors;
				
				// For each frame
				ViablePathsFrame_3Vector::ParseFromStringCallback( strFrameVector, _model, [&](ViablePathsFrame_3& frame){
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
				ViablePathsMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, ViablePathsFrame_4Vector> frameVectors;
				
				// For each frame
				ViablePathsFrame_4Vector::ParseFromStringCallback( strFrameVector, _model, [&](ViablePathsFrame_4& frame){
					continue_4(frame, startOpIndex, resultSet, frameVectors);														
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
					ViablePathsFrame_0Vector	vector;
					vector.push_back(ViablePathsFrame_0{});
					ret[0] = vector.SerializeAsString();
				}	
				{
					ViablePathsFrame_1Vector	vector;
					vector.push_back(ViablePathsFrame_1{});
					ret[1] = vector.SerializeAsString();
				}	
				{
					ViablePathsFrame_2Vector	vector;
					vector.push_back(ViablePathsFrame_2{});
					ret[2] = vector.SerializeAsString();
				}	
				{
					ViablePathsFrame_3Vector	vector;
					vector.push_back(ViablePathsFrame_3{});
					ret[3] = vector.SerializeAsString();
				}	
				{
					ViablePathsFrame_4Vector	vector;
					vector.push_back(ViablePathsFrame_4{});
					ret[4] = vector.SerializeAsString();
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


#endif /*  VIATRA__QUERY__SAFETYLOGIC__VIABLE_PATHS_MATCHER_H_ */
