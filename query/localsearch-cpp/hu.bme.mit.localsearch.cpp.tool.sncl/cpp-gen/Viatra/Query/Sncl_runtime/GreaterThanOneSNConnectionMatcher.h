#ifndef VIATRA__QUERY__SNCL_RUNTIME__GREATER_THAN_ONE_S_N_CONNECTION_MATCHER_H_
#define VIATRA__QUERY__SNCL_RUNTIME__GREATER_THAN_ONE_S_N_CONNECTION_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Distributed/QueryRunner.h"
#include "Viatra/Query/Plan/DistSearchPlanExecutor.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Sncl_runtime/GreaterThanOneSNConnectionFrame_0.h"
#include "Viatra/Query/Sncl_runtime/GreaterThanOneSNConnectionMatch.h"
#include "Viatra/Query/Sncl_runtime/GreaterThanOneSNConnectionQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

template<typename>class RootedGreaterThanOneSNConnection;
		
template<class ModelRoot>
class GreaterThanOneSNConnectionMatcher {
	using QueryRunnerT = ::Viatra::Query::Distributed::QueryRunner<RootedGreaterThanOneSNConnection<ModelRoot>>;
public:
	GreaterThanOneSNConnectionMatcher(
	const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context, QueryRunnerT * queryRunner) 
		: _model(model), _context(context), _queryRunner(queryRunner) {
	}
	std::unordered_set<GreaterThanOneSNConnectionMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<GreaterThanOneSNConnectionMatch> matches;
	
		{
			auto sp = GreaterThanOneSNConnectionQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<GreaterThanOneSNConnectionFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				GreaterThanOneSNConnectionMatch match;
			
				match.C1 = static_cast<::arch::ICL*>(frame._0);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
		void continue_0(GreaterThanOneSNConnectionFrame_0& frame, int startOpIndex, GreaterThanOneSNConnectionMatchSet& results, std::map<int, GreaterThanOneSNConnectionFrame_0Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = GreaterThanOneSNConnectionQuerySpecification<ModelRoot>::get_plan_unbound__0(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<GreaterThanOneSNConnectionFrame_0>(sp, *_context, 0, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				GreaterThanOneSNConnectionMatch match;
			
				match.C1 = static_cast<::arch::ICL*>(frame._0);
			
				results.insert(match);
			}
		
		}
		
		
	GreaterThanOneSNConnectionMatchSet continueExec(std::string strFrameVector, int bodyID, int startOpIndex){
		switch(bodyID){
			case 0: {
				GreaterThanOneSNConnectionMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, GreaterThanOneSNConnectionFrame_0Vector> frameVectors;
				
				// For each frame
				GreaterThanOneSNConnectionFrame_0Vector::ParseFromStringCallback( strFrameVector, _model, [&](GreaterThanOneSNConnectionFrame_0& frame){
					continue_0(frame, startOpIndex, resultSet, frameVectors);														
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
					GreaterThanOneSNConnectionFrame_0Vector	vector;
					vector.push_back(GreaterThanOneSNConnectionFrame_0{});
					ret[0] = vector.SerializeAsString();
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


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__GREATER_THAN_ONE_S_N_CONNECTION_MATCHER_H_ */
