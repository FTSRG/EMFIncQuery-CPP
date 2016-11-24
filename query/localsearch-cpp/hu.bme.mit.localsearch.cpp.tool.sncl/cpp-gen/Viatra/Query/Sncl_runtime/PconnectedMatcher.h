#ifndef VIATRA__QUERY__SNCL_RUNTIME__PCONNECTED_MATCHER_H_
#define VIATRA__QUERY__SNCL_RUNTIME__PCONNECTED_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Distributed/QueryRunner.h"
#include "Viatra/Query/Plan/DistSearchPlanExecutor.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Sncl_runtime/PconnectedFrame_0.h"
#include "Viatra/Query/Sncl_runtime/PconnectedFrame_1.h"
#include "Viatra/Query/Sncl_runtime/PconnectedMatch.h"
#include "Viatra/Query/Sncl_runtime/PconnectedQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

template<typename>class RootedPconnected;
		
template<class ModelRoot>
class PconnectedMatcher {
	using QueryRunnerT = ::Viatra::Query::Distributed::QueryRunner<RootedPconnected<ModelRoot>>;
public:
	PconnectedMatcher(
	const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context, QueryRunnerT * queryRunner) 
		: _model(model), _context(context), _queryRunner(queryRunner) {
	}
	std::unordered_set<PconnectedMatch> matches_C1(::arch::ICL* C1) const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<PconnectedMatch> matches;
	
		{
			auto sp = PconnectedQuerySpecification<ModelRoot>::get_plan_C1__0(_model);
			PconnectedFrame_0 frame;
			frame._0 = C1;
			
			auto unprepared_exec = SearchPlanExecutor<PconnectedFrame_0>(sp, *_context);
			auto exec = unprepared_exec.prepare(frame);
			
			
			for (auto&& frame : exec) {
				PconnectedMatch match;
			
				match.C1 = static_cast<::arch::ICL*>(frame._0);
				match.C2 = static_cast<::arch::ICL*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = PconnectedQuerySpecification<ModelRoot>::get_plan_C1__1(_model);
			PconnectedFrame_1 frame;
			frame._0 = C1;
			
			auto unprepared_exec = SearchPlanExecutor<PconnectedFrame_1>(sp, *_context);
			auto exec = unprepared_exec.prepare(frame);
			
			
			for (auto&& frame : exec) {
				PconnectedMatch match;
			
				match.C1 = static_cast<::arch::ICL*>(frame._0);
				match.C2 = static_cast<::arch::ICL*>(frame._1);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
	std::unordered_set<PconnectedMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<PconnectedMatch> matches;
	
		{
			auto sp = PconnectedQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<PconnectedFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				PconnectedMatch match;
			
				match.C1 = static_cast<::arch::ICL*>(frame._0);
				match.C2 = static_cast<::arch::ICL*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = PconnectedQuerySpecification<ModelRoot>::get_plan_unbound__1(_model);
			auto exec = SearchPlanExecutor<PconnectedFrame_1>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				PconnectedMatch match;
			
				match.C1 = static_cast<::arch::ICL*>(frame._0);
				match.C2 = static_cast<::arch::ICL*>(frame._1);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
		void continue_0(PconnectedFrame_0& frame, int startOpIndex, PconnectedMatchSet& results, std::map<int, PconnectedFrame_0Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = PconnectedQuerySpecification<ModelRoot>::get_plan_unbound__0(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<PconnectedFrame_0>(sp, *_context, 0, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				PconnectedMatch match;
			
				match.C1 = static_cast<::arch::ICL*>(frame._0);
				match.C2 = static_cast<::arch::ICL*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_1(PconnectedFrame_1& frame, int startOpIndex, PconnectedMatchSet& results, std::map<int, PconnectedFrame_1Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = PconnectedQuerySpecification<ModelRoot>::get_plan_unbound__1(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<PconnectedFrame_1>(sp, *_context, 1, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				PconnectedMatch match;
			
				match.C1 = static_cast<::arch::ICL*>(frame._0);
				match.C2 = static_cast<::arch::ICL*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		
	PconnectedMatchSet continueExec(std::string strFrameVector, int bodyID, int startOpIndex){
		switch(bodyID){
			case 0: {
				PconnectedMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, PconnectedFrame_0Vector> frameVectors;
				
				// For each frame
				PconnectedFrame_0Vector::ParseFromStringCallback( strFrameVector, _model, [&](PconnectedFrame_0& frame){
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
				PconnectedMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, PconnectedFrame_1Vector> frameVectors;
				
				// For each frame
				PconnectedFrame_1Vector::ParseFromStringCallback( strFrameVector, _model, [&](PconnectedFrame_1& frame){
					continue_1(frame, startOpIndex, resultSet, frameVectors);														
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
					PconnectedFrame_0Vector	vector;
					vector.push_back(PconnectedFrame_0{});
					ret[0] = vector.SerializeAsString();
				}	
				{
					PconnectedFrame_1Vector	vector;
					vector.push_back(PconnectedFrame_1{});
					ret[1] = vector.SerializeAsString();
				}	
				return ret;
			}
							
private:
	QueryRunnerT * _queryRunner;
	const ModelRoot* _model;
	const ::Viatra::Query::Matcher::ISearchContext* _context;
};

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__PCONNECTED_MATCHER_H_ */
