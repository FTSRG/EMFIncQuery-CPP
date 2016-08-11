#ifndef VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__APP_INSTANCES_WITH_ALLOCATION_MATCHER_H_
#define VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__APP_INSTANCES_WITH_ALLOCATION_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/CpsModelViewerCommon/AppInstancesWithAllocationFrame_0.h"
#include "Viatra/Query/CpsModelViewerCommon/AppInstancesWithAllocationMatch.h"
#include "Viatra/Query/CpsModelViewerCommon/AppInstancesWithAllocationQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace CpsModelViewerCommon {

template<class ModelRoot>
class AppInstancesWithAllocationMatcher {
public:
	AppInstancesWithAllocationMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<AppInstancesWithAllocationMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<AppInstancesWithAllocationMatch> matches;
	
		{
			auto sp = AppInstancesWithAllocationQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<AppInstancesWithAllocationFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				AppInstancesWithAllocationMatch match;
			
				match.app = static_cast<::cyberPhysicalSystem::ApplicationInstance*>(frame._0);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
	std::unordered_set<AppInstancesWithAllocationMatch> matches(::cyberPhysicalSystem::ApplicationInstance* app) const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<AppInstancesWithAllocationMatch> matches;
	
		{
			auto sp = AppInstancesWithAllocationQuerySpecification<ModelRoot>::get_plan_app__0(_model);
			AppInstancesWithAllocationFrame_0 frame;
			frame._0 = app;
			
			auto exec = SearchPlanExecutor<AppInstancesWithAllocationFrame_0>(sp, *_context).prepare(frame);
			
			
			for (auto&& frame : exec) {
				AppInstancesWithAllocationMatch match;
			
				match.app = static_cast<::cyberPhysicalSystem::ApplicationInstance*>(frame._0);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
	
private:
	const ModelRoot* _model;
	const ::Viatra::Query::Matcher::ISearchContext* _context;
};

} /* namespace CpsModelViewerCommon */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__APP_INSTANCES_WITH_ALLOCATION_MATCHER_H_ */
