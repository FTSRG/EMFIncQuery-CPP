#ifndef VIATRA__QUERY__DERIVED_FEATURES__REF_SEG_MATCHER_H_
#define VIATRA__QUERY__DERIVED_FEATURES__REF_SEG_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/DerivedFeatures/RefSegFrame_0.h"
#include "Viatra/Query/DerivedFeatures/RefSegMatch.h"
#include "Viatra/Query/DerivedFeatures/RefSegQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace DerivedFeatures {

template<class ModelRoot>
class RefSegMatcher {
public:
	RefSegMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}
	std::unordered_set<RefSegMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<RefSegMatch> matches;
	
		{
			auto sp = RefSegQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<RefSegFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				RefSegMatch match;
			
				match.robotPart = static_cast<::RailRoadModel::IRobotPart*>(frame._0);
				match.robotPartID = static_cast<int>(frame._1);
				match.segment = static_cast<::RailRoadModel::ISegment*>(frame._2);
				match.segmentID = static_cast<int>(frame._3);
				match.robX = static_cast<double>(frame._4);
				match.robY = static_cast<double>(frame._5);
				match.robZ = static_cast<double>(frame._6);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
	std::unordered_set<RefSegMatch> matches(int robotPartID, double robX, double robY, double robZ) const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<RefSegMatch> matches;
	
		{
			auto sp = RefSegQuerySpecification<ModelRoot>::get_plan_robotPartID_robX_robY_robZ__0(_model);
			RefSegFrame_0 frame;
			frame._1 = robotPartID;
			frame._4 = robX;
			frame._5 = robY;
			frame._6 = robZ;
			
			auto exec = SearchPlanExecutor<RefSegFrame_0>(sp, *_context).prepare(frame);
			
			
			for (auto&& frame : exec) {
				RefSegMatch match;
			
				match.robotPart = static_cast<::RailRoadModel::IRobotPart*>(frame._0);
				match.robotPartID = static_cast<int>(frame._1);
				match.segment = static_cast<::RailRoadModel::ISegment*>(frame._2);
				match.segmentID = static_cast<int>(frame._3);
				match.robX = static_cast<double>(frame._4);
				match.robY = static_cast<double>(frame._5);
				match.robZ = static_cast<double>(frame._6);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
	
private:
	const ModelRoot* _model;
	const ::Viatra::Query::Matcher::ISearchContext* _context;
};

} /* namespace DerivedFeatures */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED_FEATURES__REF_SEG_MATCHER_H_ */
