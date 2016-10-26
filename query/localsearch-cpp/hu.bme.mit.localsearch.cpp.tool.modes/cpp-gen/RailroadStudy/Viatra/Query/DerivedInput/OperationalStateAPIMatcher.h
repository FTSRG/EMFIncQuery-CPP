#ifndef VIATRA__QUERY__DERIVED_INPUT__OPERATIONAL_STATE_A_P_I_MATCHER_H_
#define VIATRA__QUERY__DERIVED_INPUT__OPERATIONAL_STATE_A_P_I_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/DerivedInput/OperationalStateAPIFrame_0.h"
#include "Viatra/Query/DerivedInput/OperationalStateAPIMatch.h"
#include "Viatra/Query/DerivedInput/OperationalStateAPIQuerySpecification.h"
#include "Viatra/Query/Distributed/QueryRunner.h"
#include "Viatra/Query/Plan/DistSearchPlanExecutor.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace DerivedInput {

template<typename>class RootedOperationalStateAPI;
		
template<class ModelRoot>
class OperationalStateAPIMatcher {
	using QueryRunnerT = ::Viatra::Query::Distributed::QueryRunner<RootedOperationalStateAPI<ModelRoot>>;
public:
	OperationalStateAPIMatcher(
	const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context, QueryRunnerT * queryRunner) 
		: _model(model), _context(context), _queryRunner(queryRunner) {
	}
	std::unordered_set<OperationalStateAPIMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<OperationalStateAPIMatch> matches;
	
		{
			auto sp = OperationalStateAPIQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<OperationalStateAPIFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				OperationalStateAPIMatch match;
			
				match.turnout = static_cast<::railRoadModel::ITurnout*>(frame._0);
				match.turnoutID = static_cast<int>(frame._1);
				match.operational = static_cast<::railRoadModel::IOperational*>(frame._2);
				match.stateID = static_cast<int>(frame._3);
				match.turnoutTemp = static_cast<double>(frame._4);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
		void continue_0(OperationalStateAPIFrame_0& frame, int startOpIndex, OperationalStateAPIMatchSet& results, std::map<int, OperationalStateAPIFrame_0Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = OperationalStateAPIQuerySpecification<ModelRoot>::get_plan_unbound__0(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<OperationalStateAPIFrame_0>(sp, *_context, 0, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				OperationalStateAPIMatch match;
			
				match.turnout = static_cast<::railRoadModel::ITurnout*>(frame._0);
				match.turnoutID = static_cast<int>(frame._1);
				match.operational = static_cast<::railRoadModel::IOperational*>(frame._2);
				match.stateID = static_cast<int>(frame._3);
				match.turnoutTemp = static_cast<double>(frame._4);
			
				results.insert(match);
			}
		
		}
		
		
	OperationalStateAPIMatchSet continueExec(std::string strFrameVector, int bodyID, int startOpIndex){
		switch(bodyID){
			case 0: {
				OperationalStateAPIMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, OperationalStateAPIFrame_0Vector> frameVectors;
				
				// For each frame
				OperationalStateAPIFrame_0Vector::ParseFromStringCallback( strFrameVector, _model, [&](OperationalStateAPIFrame_0& frame){
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
					OperationalStateAPIFrame_0Vector	vector;
					vector.push_back(OperationalStateAPIFrame_0{});
					ret[0] = vector.SerializeAsString();
				}	
				return ret;
			}
	std::unordered_set<OperationalStateAPIMatch> matches_turnoutID_stateID_turnoutTemp(int turnoutID, int stateID, double turnoutTemp) const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<OperationalStateAPIMatch> matches;
	
		{
			auto sp = OperationalStateAPIQuerySpecification<ModelRoot>::get_plan_turnoutID_stateID_turnoutTemp__0(_model);
			OperationalStateAPIFrame_0 frame;
			frame._1 = turnoutID;
			frame._3 = stateID;
			frame._4 = turnoutTemp;
			
			auto unprepared_exec = SearchPlanExecutor<OperationalStateAPIFrame_0>(sp, *_context);
			auto exec = unprepared_exec.prepare(frame);
			
			
			for (auto&& frame : exec) {
				OperationalStateAPIMatch match;
			
				match.turnout = static_cast<::railRoadModel::ITurnout*>(frame._0);
				match.turnoutID = static_cast<int>(frame._1);
				match.operational = static_cast<::railRoadModel::IOperational*>(frame._2);
				match.stateID = static_cast<int>(frame._3);
				match.turnoutTemp = static_cast<double>(frame._4);
			
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

} /* namespace DerivedInput */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED_INPUT__OPERATIONAL_STATE_A_P_I_MATCHER_H_ */
