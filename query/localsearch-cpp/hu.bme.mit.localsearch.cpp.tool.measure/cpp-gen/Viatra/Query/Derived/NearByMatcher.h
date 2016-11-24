#ifndef VIATRA__QUERY__DERIVED__NEAR_BY_MATCHER_H_
#define VIATRA__QUERY__DERIVED__NEAR_BY_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Derived/NearByFrame_0.h"
#include "Viatra/Query/Derived/NearByMatch.h"
#include "Viatra/Query/Derived/NearByQuerySpecification.h"
#include "Viatra/Query/Distributed/QueryRunner.h"
#include "Viatra/Query/Plan/DistSearchPlanExecutor.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace Derived {

template<typename>class RootedNearBy;
		
template<class ModelRoot>
class NearByMatcher {
	using QueryRunnerT = ::Viatra::Query::Distributed::QueryRunner<RootedNearBy<ModelRoot>>;
public:
	NearByMatcher(
	const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context, QueryRunnerT * queryRunner) 
		: _model(model), _context(context), _queryRunner(queryRunner) {
	}
	std::unordered_set<NearByMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<NearByMatch> matches;
	
		{
			auto sp = NearByQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<NearByFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				NearByMatch match;
			
				match.robotPart = static_cast<::railRoadModel::IRobotPart*>(frame._0);
				match.robotPartID = static_cast<int>(frame._1);
				match.train = static_cast<::railRoadModel::ITrain*>(frame._2);
				match.trainID = static_cast<int>(frame._3);
				match.segID = static_cast<int>(frame._4);
				match.robX = static_cast<double>(frame._5);
				match.robY = static_cast<double>(frame._6);
				match.robZ = static_cast<double>(frame._7);
				match.segX = static_cast<double>(frame._8);
				match.segY = static_cast<double>(frame._9);
				match.segZ = static_cast<double>(frame._10);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
		void continue_0(NearByFrame_0& frame, int startOpIndex, NearByMatchSet& results, std::map<int, NearByFrame_0Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = NearByQuerySpecification<ModelRoot>::get_plan_unbound__0(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<NearByFrame_0>(sp, *_context, 0, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				NearByMatch match;
			
				match.robotPart = static_cast<::railRoadModel::IRobotPart*>(frame._0);
				match.robotPartID = static_cast<int>(frame._1);
				match.train = static_cast<::railRoadModel::ITrain*>(frame._2);
				match.trainID = static_cast<int>(frame._3);
				match.segID = static_cast<int>(frame._4);
				match.robX = static_cast<double>(frame._5);
				match.robY = static_cast<double>(frame._6);
				match.robZ = static_cast<double>(frame._7);
				match.segX = static_cast<double>(frame._8);
				match.segY = static_cast<double>(frame._9);
				match.segZ = static_cast<double>(frame._10);
			
				results.insert(match);
			}
		
		}
		
		
	NearByMatchSet continueExec(std::string strFrameVector, int bodyID, int startOpIndex){
		switch(bodyID){
			case 0: {
				NearByMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, NearByFrame_0Vector> frameVectors;
				
				// For each frame
				NearByFrame_0Vector::ParseFromStringCallback( strFrameVector, _model, [&](NearByFrame_0& frame){
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
					NearByFrame_0Vector	vector;
					vector.push_back(NearByFrame_0{});
					ret[0] = vector.SerializeAsString();
				}	
				return ret;
			}
	std::unordered_set<NearByMatch> matches_robotPartID_trainID_segID_robX_robY_robZ_segX_segY_segZ(int robotPartID, int trainID, int segID, double robX, double robY, double robZ, double segX, double segY, double segZ) const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<NearByMatch> matches;
	
		{
			auto sp = NearByQuerySpecification<ModelRoot>::get_plan_robotPartID_trainID_segID_robX_robY_robZ_segX_segY_segZ__0(_model);
			NearByFrame_0 frame;
			frame._1 = robotPartID;
			frame._3 = trainID;
			frame._4 = segID;
			frame._5 = robX;
			frame._6 = robY;
			frame._7 = robZ;
			frame._8 = segX;
			frame._9 = segY;
			frame._10 = segZ;
			
			auto unprepared_exec = SearchPlanExecutor<NearByFrame_0>(sp, *_context);
			auto exec = unprepared_exec.prepare(frame);
			
			
			for (auto&& frame : exec) {
				NearByMatch match;
			
				match.robotPart = static_cast<::railRoadModel::IRobotPart*>(frame._0);
				match.robotPartID = static_cast<int>(frame._1);
				match.train = static_cast<::railRoadModel::ITrain*>(frame._2);
				match.trainID = static_cast<int>(frame._3);
				match.segID = static_cast<int>(frame._4);
				match.robX = static_cast<double>(frame._5);
				match.robY = static_cast<double>(frame._6);
				match.robZ = static_cast<double>(frame._7);
				match.segX = static_cast<double>(frame._8);
				match.segY = static_cast<double>(frame._9);
				match.segZ = static_cast<double>(frame._10);
			
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

} /* namespace Derived */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED__NEAR_BY_MATCHER_H_ */
