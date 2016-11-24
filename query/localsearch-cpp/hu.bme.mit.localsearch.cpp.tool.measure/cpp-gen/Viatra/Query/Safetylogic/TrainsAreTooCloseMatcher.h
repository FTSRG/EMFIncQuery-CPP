#ifndef VIATRA__QUERY__SAFETYLOGIC__TRAINS_ARE_TOO_CLOSE_MATCHER_H_
#define VIATRA__QUERY__SAFETYLOGIC__TRAINS_ARE_TOO_CLOSE_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Distributed/QueryRunner.h"
#include "Viatra/Query/Plan/DistSearchPlanExecutor.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Safetylogic/TrainsAreTooCloseFrame_0.h"
#include "Viatra/Query/Safetylogic/TrainsAreTooCloseFrame_1.h"
#include "Viatra/Query/Safetylogic/TrainsAreTooCloseFrame_2.h"
#include "Viatra/Query/Safetylogic/TrainsAreTooCloseFrame_3.h"
#include "Viatra/Query/Safetylogic/TrainsAreTooCloseFrame_4.h"
#include "Viatra/Query/Safetylogic/TrainsAreTooCloseMatch.h"
#include "Viatra/Query/Safetylogic/TrainsAreTooCloseQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {

template<typename>class RootedTrainsAreTooClose;
		
template<class ModelRoot>
class TrainsAreTooCloseMatcher {
	using QueryRunnerT = ::Viatra::Query::Distributed::QueryRunner<RootedTrainsAreTooClose<ModelRoot>>;
public:
	TrainsAreTooCloseMatcher(
	const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context, QueryRunnerT * queryRunner) 
		: _model(model), _context(context), _queryRunner(queryRunner) {
	}
	std::unordered_set<TrainsAreTooCloseMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<TrainsAreTooCloseMatch> matches;
	
		{
			auto sp = TrainsAreTooCloseQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<TrainsAreTooCloseFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainsAreTooCloseMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainsAreTooCloseQuerySpecification<ModelRoot>::get_plan_unbound__1(_model);
			auto exec = SearchPlanExecutor<TrainsAreTooCloseFrame_1>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainsAreTooCloseMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainsAreTooCloseQuerySpecification<ModelRoot>::get_plan_unbound__2(_model);
			auto exec = SearchPlanExecutor<TrainsAreTooCloseFrame_2>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainsAreTooCloseMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainsAreTooCloseQuerySpecification<ModelRoot>::get_plan_unbound__3(_model);
			auto exec = SearchPlanExecutor<TrainsAreTooCloseFrame_3>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainsAreTooCloseMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = TrainsAreTooCloseQuerySpecification<ModelRoot>::get_plan_unbound__4(_model);
			auto exec = SearchPlanExecutor<TrainsAreTooCloseFrame_4>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TrainsAreTooCloseMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
		void continue_0(TrainsAreTooCloseFrame_0& frame, int startOpIndex, TrainsAreTooCloseMatchSet& results, std::map<int, TrainsAreTooCloseFrame_0Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainsAreTooCloseQuerySpecification<ModelRoot>::get_plan_unbound__0(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainsAreTooCloseFrame_0>(sp, *_context, 0, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainsAreTooCloseMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_1(TrainsAreTooCloseFrame_1& frame, int startOpIndex, TrainsAreTooCloseMatchSet& results, std::map<int, TrainsAreTooCloseFrame_1Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainsAreTooCloseQuerySpecification<ModelRoot>::get_plan_unbound__1(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainsAreTooCloseFrame_1>(sp, *_context, 1, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainsAreTooCloseMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_2(TrainsAreTooCloseFrame_2& frame, int startOpIndex, TrainsAreTooCloseMatchSet& results, std::map<int, TrainsAreTooCloseFrame_2Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainsAreTooCloseQuerySpecification<ModelRoot>::get_plan_unbound__2(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainsAreTooCloseFrame_2>(sp, *_context, 2, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainsAreTooCloseMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_3(TrainsAreTooCloseFrame_3& frame, int startOpIndex, TrainsAreTooCloseMatchSet& results, std::map<int, TrainsAreTooCloseFrame_3Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainsAreTooCloseQuerySpecification<ModelRoot>::get_plan_unbound__3(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainsAreTooCloseFrame_3>(sp, *_context, 3, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainsAreTooCloseMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_4(TrainsAreTooCloseFrame_4& frame, int startOpIndex, TrainsAreTooCloseMatchSet& results, std::map<int, TrainsAreTooCloseFrame_4Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = TrainsAreTooCloseQuerySpecification<ModelRoot>::get_plan_unbound__4(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<TrainsAreTooCloseFrame_4>(sp, *_context, 4, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				TrainsAreTooCloseMatch match;
			
				match.Offender = static_cast<::railRoadModel::ITrain*>(frame._0);
				match.Victim = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		
	TrainsAreTooCloseMatchSet continueExec(std::string strFrameVector, int bodyID, int startOpIndex){
		switch(bodyID){
			case 0: {
				TrainsAreTooCloseMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainsAreTooCloseFrame_0Vector> frameVectors;
				
				// For each frame
				TrainsAreTooCloseFrame_0Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainsAreTooCloseFrame_0& frame){
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
				TrainsAreTooCloseMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainsAreTooCloseFrame_1Vector> frameVectors;
				
				// For each frame
				TrainsAreTooCloseFrame_1Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainsAreTooCloseFrame_1& frame){
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
				TrainsAreTooCloseMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainsAreTooCloseFrame_2Vector> frameVectors;
				
				// For each frame
				TrainsAreTooCloseFrame_2Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainsAreTooCloseFrame_2& frame){
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
				TrainsAreTooCloseMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainsAreTooCloseFrame_3Vector> frameVectors;
				
				// For each frame
				TrainsAreTooCloseFrame_3Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainsAreTooCloseFrame_3& frame){
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
				TrainsAreTooCloseMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, TrainsAreTooCloseFrame_4Vector> frameVectors;
				
				// For each frame
				TrainsAreTooCloseFrame_4Vector::ParseFromStringCallback( strFrameVector, _model, [&](TrainsAreTooCloseFrame_4& frame){
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
					TrainsAreTooCloseFrame_0Vector	vector;
					vector.push_back(TrainsAreTooCloseFrame_0{});
					ret[0] = vector.SerializeAsString();
				}	
				{
					TrainsAreTooCloseFrame_1Vector	vector;
					vector.push_back(TrainsAreTooCloseFrame_1{});
					ret[1] = vector.SerializeAsString();
				}	
				{
					TrainsAreTooCloseFrame_2Vector	vector;
					vector.push_back(TrainsAreTooCloseFrame_2{});
					ret[2] = vector.SerializeAsString();
				}	
				{
					TrainsAreTooCloseFrame_3Vector	vector;
					vector.push_back(TrainsAreTooCloseFrame_3{});
					ret[3] = vector.SerializeAsString();
				}	
				{
					TrainsAreTooCloseFrame_4Vector	vector;
					vector.push_back(TrainsAreTooCloseFrame_4{});
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


#endif /*  VIATRA__QUERY__SAFETYLOGIC__TRAINS_ARE_TOO_CLOSE_MATCHER_H_ */
