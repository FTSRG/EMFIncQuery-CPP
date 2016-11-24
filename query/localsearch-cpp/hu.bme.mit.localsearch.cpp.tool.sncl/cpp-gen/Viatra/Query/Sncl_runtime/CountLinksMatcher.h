#ifndef VIATRA__QUERY__SNCL_RUNTIME__COUNT_LINKS_MATCHER_H_
#define VIATRA__QUERY__SNCL_RUNTIME__COUNT_LINKS_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Distributed/QueryRunner.h"
#include "Viatra/Query/Plan/DistSearchPlanExecutor.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Sncl_runtime/CountLinksFrame_0.h"
#include "Viatra/Query/Sncl_runtime/CountLinksMatch.h"
#include "Viatra/Query/Sncl_runtime/CountLinksQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

template<typename>class RootedCountLinks;
		
template<class ModelRoot>
class CountLinksMatcher {
	using QueryRunnerT = ::Viatra::Query::Distributed::QueryRunner<RootedCountLinks<ModelRoot>>;
public:
	CountLinksMatcher(
	const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context, QueryRunnerT * queryRunner) 
		: _model(model), _context(context), _queryRunner(queryRunner) {
	}
	std::unordered_set<CountLinksMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<CountLinksMatch> matches;
	
		{
			auto sp = CountLinksQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<CountLinksFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				CountLinksMatch match;
			
				match.C1 = static_cast<::arch::ICL*>(frame._0);
				match.numOfSN = static_cast<int>(frame._1);
				match.numOfCL = static_cast<int>(frame._2);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
		void continue_0(CountLinksFrame_0& frame, int startOpIndex, CountLinksMatchSet& results, std::map<int, CountLinksFrame_0Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = CountLinksQuerySpecification<ModelRoot>::get_plan_unbound__0(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<CountLinksFrame_0>(sp, *_context, 0, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				CountLinksMatch match;
			
				match.C1 = static_cast<::arch::ICL*>(frame._0);
				match.numOfSN = static_cast<int>(frame._1);
				match.numOfCL = static_cast<int>(frame._2);
			
				results.insert(match);
			}
		
		}
		
		
	CountLinksMatchSet continueExec(std::string strFrameVector, int bodyID, int startOpIndex){
		switch(bodyID){
			case 0: {
				CountLinksMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, CountLinksFrame_0Vector> frameVectors;
				
				// For each frame
				CountLinksFrame_0Vector::ParseFromStringCallback( strFrameVector, _model, [&](CountLinksFrame_0& frame){
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
					CountLinksFrame_0Vector	vector;
					vector.push_back(CountLinksFrame_0{});
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


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__COUNT_LINKS_MATCHER_H_ */
