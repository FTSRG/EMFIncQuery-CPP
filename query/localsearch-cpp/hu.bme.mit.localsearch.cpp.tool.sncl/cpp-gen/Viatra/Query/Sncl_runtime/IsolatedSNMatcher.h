#ifndef VIATRA__QUERY__SNCL_RUNTIME__ISOLATED_S_N_MATCHER_H_
#define VIATRA__QUERY__SNCL_RUNTIME__ISOLATED_S_N_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Distributed/QueryRunner.h"
#include "Viatra/Query/Plan/DistSearchPlanExecutor.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Sncl_runtime/IsolatedSNFrame_0.h"
#include "Viatra/Query/Sncl_runtime/IsolatedSNMatch.h"
#include "Viatra/Query/Sncl_runtime/IsolatedSNQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

template<typename>class RootedIsolatedSN;
		
template<class ModelRoot>
class IsolatedSNMatcher {
	using QueryRunnerT = ::Viatra::Query::Distributed::QueryRunner<RootedIsolatedSN<ModelRoot>>;
public:
	IsolatedSNMatcher(
	const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context, QueryRunnerT * queryRunner) 
		: _model(model), _context(context), _queryRunner(queryRunner) {
	}
	std::unordered_set<IsolatedSNMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<IsolatedSNMatch> matches;
	
		{
			auto sp = IsolatedSNQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<IsolatedSNFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				IsolatedSNMatch match;
			
				match.C1 = static_cast<::arch::ICL*>(frame._0);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
		void continue_0(IsolatedSNFrame_0& frame, int startOpIndex, IsolatedSNMatchSet& results, std::map<int, IsolatedSNFrame_0Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = IsolatedSNQuerySpecification<ModelRoot>::get_plan_unbound__0(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<IsolatedSNFrame_0>(sp, *_context, 0, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				IsolatedSNMatch match;
			
				match.C1 = static_cast<::arch::ICL*>(frame._0);
			
				results.insert(match);
			}
		
		}
		
		
	IsolatedSNMatchSet continueExec(std::string strFrameVector, int bodyID, int startOpIndex){
		switch(bodyID){
			case 0: {
				IsolatedSNMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, IsolatedSNFrame_0Vector> frameVectors;
				
				// For each frame
				IsolatedSNFrame_0Vector::ParseFromStringCallback( strFrameVector, _model, [&](IsolatedSNFrame_0& frame){
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
					IsolatedSNFrame_0Vector	vector;
					vector.push_back(IsolatedSNFrame_0{});
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


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__ISOLATED_S_N_MATCHER_H_ */
