#ifndef VIATRA__QUERY__DISTRIBUTED_QUERIES__IS_DANGEROUS_MATCHER_H_
#define VIATRA__QUERY__DISTRIBUTED_QUERIES__IS_DANGEROUS_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Distributed/QueryRunner.h"
#include "Viatra/Query/DistributedQueries/IsDangerousFrame_0.h"
#include "Viatra/Query/DistributedQueries/IsDangerousMatch.h"
#include "Viatra/Query/DistributedQueries/IsDangerousQuerySpecification.h"
#include "Viatra/Query/Plan/DistSearchPlanExecutor.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace DistributedQueries {

template<typename>class RootedIsDangerous;
		
template<class ModelRoot>
class IsDangerousMatcher {
	using QueryRunnerT = ::Viatra::Query::Distributed::QueryRunner<RootedIsDangerous<ModelRoot>>;
public:
	IsDangerousMatcher(
	const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context, QueryRunnerT * queryRunner) 
		: _model(model), _context(context), _queryRunner(queryRunner) {
	}
	std::unordered_set<IsDangerousMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<IsDangerousMatch> matches;
	
		{
			auto sp = IsDangerousQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<IsDangerousFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				IsDangerousMatch match;
			
				match.segment = frame._0;
				match.turnout = frame._1;
				match.train = frame._2;
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
		void continue_0(IsDangerousFrame_0& frame, int startOpIndex, IsDangerousMatchSet& results, std::map<int, IsDangerousFrame_0Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = IsDangerousQuerySpecification<ModelRoot>::get_plan_unbound__0(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<IsDangerousFrame_0>(sp, *_context, 0, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				IsDangerousMatch match;
			
				match.segment = static_cast<::railRoadModel::ISegment*>(frame._0);
				match.turnout = static_cast<::railRoadModel::ITurnout*>(frame._1);
				match.train = static_cast<::railRoadModel::ITrain*>(frame._2);
			
				results.insert(match);
			}
		
		}
		
		
	IsDangerousMatchSet continueExec(std::string strFrameVector, int bodyID, int startOpIndex){
		switch(bodyID){
			case 0: {
				IsDangerousMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, IsDangerousFrame_0Vector> frameVectors;
				
				// For each frame
				IsDangerousFrame_0Vector::ParseFromStringCallback( strFrameVector, _model, [&](IsDangerousFrame_0& frame){
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
					IsDangerousFrame_0Vector	vector;
					vector.push_back(IsDangerousFrame_0{});
					ret[0] = vector.SerializeAsString();
				}	
				return ret;
			}
							
private:
	QueryRunnerT * _queryRunner;
	const ModelRoot* _model;
	const ::Viatra::Query::Matcher::ISearchContext* _context;
};

} /* namespace DistributedQueries */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DISTRIBUTED_QUERIES__IS_DANGEROUS_MATCHER_H_ */
