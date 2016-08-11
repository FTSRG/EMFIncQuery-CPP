#ifndef VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__ALL_HOST_INSTANCES_MATCHER_H_
#define VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__ALL_HOST_INSTANCES_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/CpsModelViewerCommon/AllHostInstancesFrame_0.h"
#include "Viatra/Query/CpsModelViewerCommon/AllHostInstancesMatch.h"
#include "Viatra/Query/CpsModelViewerCommon/AllHostInstancesQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace CpsModelViewerCommon {

template<class ModelRoot>
class AllHostInstancesMatcher {
public:
	AllHostInstancesMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<AllHostInstancesMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<AllHostInstancesMatch> matches;
	
		{
			auto sp = AllHostInstancesQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<AllHostInstancesFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				AllHostInstancesMatch match;
			
				match.host = static_cast<::cyberPhysicalSystem::HostInstance*>(frame._0);
			
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


#endif /*  VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__ALL_HOST_INSTANCES_MATCHER_H_ */
