#ifndef VIATRA__QUERY__SNCL_RUNTIME__LINKED_MATCHER_H_
#define VIATRA__QUERY__SNCL_RUNTIME__LINKED_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Distributed/QueryRunner.h"
#include "Viatra/Query/Plan/DistSearchPlanExecutor.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Sncl_runtime/LinkedFrame_0.h"
#include "Viatra/Query/Sncl_runtime/LinkedFrame_1.h"
#include "Viatra/Query/Sncl_runtime/LinkedMatch.h"
#include "Viatra/Query/Sncl_runtime/LinkedQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

template<typename>class RootedLinked;
		
template<class ModelRoot>
class LinkedMatcher {
	using QueryRunnerT = ::Viatra::Query::Distributed::QueryRunner<RootedLinked<ModelRoot>>;
public:
	LinkedMatcher(
	const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context, QueryRunnerT * queryRunner) 
		: _model(model), _context(context), _queryRunner(queryRunner) {
	}
	std::unordered_set<LinkedMatch> matches_S1(::arch::ISN* S1) const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<LinkedMatch> matches;
	
		{
			auto sp = LinkedQuerySpecification<ModelRoot>::get_plan_S1__0(_model);
			LinkedFrame_0 frame;
			frame._0 = S1;
			
			auto unprepared_exec = SearchPlanExecutor<LinkedFrame_0>(sp, *_context);
			auto exec = unprepared_exec.prepare(frame);
			
			
			for (auto&& frame : exec) {
				LinkedMatch match;
			
				match.S1 = static_cast<::arch::ISN*>(frame._0);
				match.S2 = static_cast<::arch::ISN*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = LinkedQuerySpecification<ModelRoot>::get_plan_S1__1(_model);
			LinkedFrame_1 frame;
			frame._0 = S1;
			
			auto unprepared_exec = SearchPlanExecutor<LinkedFrame_1>(sp, *_context);
			auto exec = unprepared_exec.prepare(frame);
			
			
			for (auto&& frame : exec) {
				LinkedMatch match;
			
				match.S1 = static_cast<::arch::ISN*>(frame._0);
				match.S2 = static_cast<::arch::ISN*>(frame._1);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
	std::unordered_set<LinkedMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<LinkedMatch> matches;
	
		{
			auto sp = LinkedQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<LinkedFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				LinkedMatch match;
			
				match.S1 = static_cast<::arch::ISN*>(frame._0);
				match.S2 = static_cast<::arch::ISN*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = LinkedQuerySpecification<ModelRoot>::get_plan_unbound__1(_model);
			auto exec = SearchPlanExecutor<LinkedFrame_1>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				LinkedMatch match;
			
				match.S1 = static_cast<::arch::ISN*>(frame._0);
				match.S2 = static_cast<::arch::ISN*>(frame._1);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
		void continue_0(LinkedFrame_0& frame, int startOpIndex, LinkedMatchSet& results, std::map<int, LinkedFrame_0Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = LinkedQuerySpecification<ModelRoot>::get_plan_unbound__0(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<LinkedFrame_0>(sp, *_context, 0, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				LinkedMatch match;
			
				match.S1 = static_cast<::arch::ISN*>(frame._0);
				match.S2 = static_cast<::arch::ISN*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		void continue_1(LinkedFrame_1& frame, int startOpIndex, LinkedMatchSet& results, std::map<int, LinkedFrame_1Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = LinkedQuerySpecification<ModelRoot>::get_plan_unbound__1(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<LinkedFrame_1>(sp, *_context, 1, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				LinkedMatch match;
			
				match.S1 = static_cast<::arch::ISN*>(frame._0);
				match.S2 = static_cast<::arch::ISN*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		
	LinkedMatchSet continueExec(std::string strFrameVector, int bodyID, int startOpIndex){
		switch(bodyID){
			case 0: {
				LinkedMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, LinkedFrame_0Vector> frameVectors;
				
				// For each frame
				LinkedFrame_0Vector::ParseFromStringCallback( strFrameVector, _model, [&](LinkedFrame_0& frame){
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
				LinkedMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, LinkedFrame_1Vector> frameVectors;
				
				// For each frame
				LinkedFrame_1Vector::ParseFromStringCallback( strFrameVector, _model, [&](LinkedFrame_1& frame){
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
					LinkedFrame_0Vector	vector;
					vector.push_back(LinkedFrame_0{});
					ret[0] = vector.SerializeAsString();
				}	
				{
					LinkedFrame_1Vector	vector;
					vector.push_back(LinkedFrame_1{});
					ret[1] = vector.SerializeAsString();
				}	
				return ret;
			}
	std::unordered_set<LinkedMatch> matches_S1_S2(::arch::ISN* S1, ::arch::ISN* S2) const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<LinkedMatch> matches;
	
		{
			auto sp = LinkedQuerySpecification<ModelRoot>::get_plan_S1_S2__0(_model);
			LinkedFrame_0 frame;
			frame._0 = S1;
			frame._1 = S2;
			
			auto unprepared_exec = SearchPlanExecutor<LinkedFrame_0>(sp, *_context);
			auto exec = unprepared_exec.prepare(frame);
			
			
			for (auto&& frame : exec) {
				LinkedMatch match;
			
				match.S1 = static_cast<::arch::ISN*>(frame._0);
				match.S2 = static_cast<::arch::ISN*>(frame._1);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = LinkedQuerySpecification<ModelRoot>::get_plan_S1_S2__1(_model);
			LinkedFrame_1 frame;
			frame._0 = S1;
			frame._1 = S2;
			
			auto unprepared_exec = SearchPlanExecutor<LinkedFrame_1>(sp, *_context);
			auto exec = unprepared_exec.prepare(frame);
			
			
			for (auto&& frame : exec) {
				LinkedMatch match;
			
				match.S1 = static_cast<::arch::ISN*>(frame._0);
				match.S2 = static_cast<::arch::ISN*>(frame._1);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
							
private:
	QueryRunnerT * _queryRunner;
	const ModelRoot* _model;
	const ::Viatra::Query::Matcher::ISearchContext* _context;
};

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__LINKED_MATCHER_H_ */
