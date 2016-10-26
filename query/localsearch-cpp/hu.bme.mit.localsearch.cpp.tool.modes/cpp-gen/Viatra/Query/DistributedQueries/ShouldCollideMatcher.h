#ifndef VIATRA__QUERY__DISTRIBUTED_QUERIES__SHOULD_COLLIDE_MATCHER_H_
#define VIATRA__QUERY__DISTRIBUTED_QUERIES__SHOULD_COLLIDE_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Distributed/QueryRunner.h"
#include "Viatra/Query/DistributedQueries/ShouldCollideFrame_0.h"
#include "Viatra/Query/DistributedQueries/ShouldCollideMatch.h"
#include "Viatra/Query/DistributedQueries/ShouldCollideQuerySpecification.h"
#include "Viatra/Query/Plan/DistSearchPlanExecutor.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace DistributedQueries {

template<typename>class RootedShouldCollide;
		
template<class ModelRoot>
class ShouldCollideMatcher {
	using QueryRunnerT = ::Viatra::Query::Distributed::QueryRunner<RootedShouldCollide<ModelRoot>>;
public:
	ShouldCollideMatcher(
	const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context, QueryRunnerT * queryRunner) 
		: _model(model), _context(context), _queryRunner(queryRunner) {
	}
	std::unordered_set<ShouldCollideMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<ShouldCollideMatch> matches;
	
		{
			auto sp = ShouldCollideQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<ShouldCollideFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				ShouldCollideMatch match;
			
				match.rp = static_cast<::railRoadModel::IRobotPart*>(frame._0);
				match.tr = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
		void continue_0(ShouldCollideFrame_0& frame, int startOpIndex, ShouldCollideMatchSet& results, std::map<int, ShouldCollideFrame_0Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = ShouldCollideQuerySpecification<ModelRoot>::get_plan_unbound__0(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<ShouldCollideFrame_0>(sp, *_context, 0, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				ShouldCollideMatch match;
			
				match.rp = static_cast<::railRoadModel::IRobotPart*>(frame._0);
				match.tr = static_cast<::railRoadModel::ITrain*>(frame._1);
			
				results.insert(match);
			}
		
		}
		
		
	ShouldCollideMatchSet continueExec(std::string strFrameVector, int bodyID, int startOpIndex){
		switch(bodyID){
			case 0: {
				ShouldCollideMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, ShouldCollideFrame_0Vector> frameVectors;
				
				// For each frame
				ShouldCollideFrame_0Vector::ParseFromStringCallback( strFrameVector, _model, [&](ShouldCollideFrame_0& frame){
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
					ShouldCollideFrame_0Vector	vector;
					vector.push_back(ShouldCollideFrame_0{});
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


#endif /*  VIATRA__QUERY__DISTRIBUTED_QUERIES__SHOULD_COLLIDE_MATCHER_H_ */
