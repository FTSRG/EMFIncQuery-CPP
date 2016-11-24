#ifndef VIATRA__QUERY__SAFETYLOGIC__NOT_NULL_MATCHER_H_
#define VIATRA__QUERY__SAFETYLOGIC__NOT_NULL_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Distributed/QueryRunner.h"
#include "Viatra/Query/Plan/DistSearchPlanExecutor.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Safetylogic/NotNullFrame_0.h"
#include "Viatra/Query/Safetylogic/NotNullMatch.h"
#include "Viatra/Query/Safetylogic/NotNullQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {

template<typename>class RootedNotNull;
		
template<class ModelRoot>
class NotNullMatcher {
	using QueryRunnerT = ::Viatra::Query::Distributed::QueryRunner<RootedNotNull<ModelRoot>>;
public:
	NotNullMatcher(
	const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context, QueryRunnerT * queryRunner) 
		: _model(model), _context(context), _queryRunner(queryRunner) {
	}
	std::unordered_set<NotNullMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<NotNullMatch> matches;
	
		{
			auto sp = NotNullQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<NotNullFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				NotNullMatch match;
			
				match.Old = static_cast<::railRoadModel::IRailRoadElement*>(frame._0);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
		void continue_0(NotNullFrame_0& frame, int startOpIndex, NotNullMatchSet& results, std::map<int, NotNullFrame_0Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = NotNullQuerySpecification<ModelRoot>::get_plan_unbound__0(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<NotNullFrame_0>(sp, *_context, 0, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				NotNullMatch match;
			
				match.Old = static_cast<::railRoadModel::IRailRoadElement*>(frame._0);
			
				results.insert(match);
			}
		
		}
		
		
	NotNullMatchSet continueExec(std::string strFrameVector, int bodyID, int startOpIndex){
		switch(bodyID){
			case 0: {
				NotNullMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, NotNullFrame_0Vector> frameVectors;
				
				// For each frame
				NotNullFrame_0Vector::ParseFromStringCallback( strFrameVector, _model, [&](NotNullFrame_0& frame){
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
					NotNullFrame_0Vector	vector;
					vector.push_back(NotNullFrame_0{});
					ret[0] = vector.SerializeAsString();
				}	
				return ret;
			}
	std::unordered_set<NotNullMatch> matches_Old(::railRoadModel::IRailRoadElement* Old) const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<NotNullMatch> matches;
	
		{
			auto sp = NotNullQuerySpecification<ModelRoot>::get_plan_Old__0(_model);
			NotNullFrame_0 frame;
			frame._0 = Old;
			
			auto unprepared_exec = SearchPlanExecutor<NotNullFrame_0>(sp, *_context);
			auto exec = unprepared_exec.prepare(frame);
			
			
			for (auto&& frame : exec) {
				NotNullMatch match;
			
				match.Old = static_cast<::railRoadModel::IRailRoadElement*>(frame._0);
			
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

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__NOT_NULL_MATCHER_H_ */
