#ifndef VIATRA__QUERY__DERIVED_FEATURES__ASSIGNED_TO_CAMERA_MATCHER_H_
#define VIATRA__QUERY__DERIVED_FEATURES__ASSIGNED_TO_CAMERA_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/DerivedFeatures/AssignedToCameraFrame_0.h"
#include "Viatra/Query/DerivedFeatures/AssignedToCameraMatch.h"
#include "Viatra/Query/DerivedFeatures/AssignedToCameraQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace DerivedFeatures {

template<class ModelRoot>
class AssignedToCameraMatcher {
public:
	AssignedToCameraMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}
	std::unordered_set<AssignedToCameraMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<AssignedToCameraMatch> matches;
	
		{
			auto sp = AssignedToCameraQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<AssignedToCameraFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				AssignedToCameraMatch match;
			
				match.cam = static_cast<::PlatformModel::Camera*>(frame._0);
				match.seg = static_cast<::RailRoadModel::Segment*>(frame._1);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
	std::unordered_set<AssignedToCameraMatch> matches(::RailRoadModel::Segment* seg) const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<AssignedToCameraMatch> matches;
	
		{
			auto sp = AssignedToCameraQuerySpecification<ModelRoot>::get_plan_seg__0(_model);
			AssignedToCameraFrame_0 frame;
			frame._1 = seg;
			
			auto exec = SearchPlanExecutor<AssignedToCameraFrame_0>(sp, *_context).prepare(frame);
			
			
			for (auto&& frame : exec) {
				AssignedToCameraMatch match;
			
				match.cam = static_cast<::PlatformModel::Camera*>(frame._0);
				match.seg = static_cast<::RailRoadModel::Segment*>(frame._1);
			
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


#endif /*  VIATRA__QUERY__DERIVED_FEATURES__ASSIGNED_TO_CAMERA_MATCHER_H_ */
