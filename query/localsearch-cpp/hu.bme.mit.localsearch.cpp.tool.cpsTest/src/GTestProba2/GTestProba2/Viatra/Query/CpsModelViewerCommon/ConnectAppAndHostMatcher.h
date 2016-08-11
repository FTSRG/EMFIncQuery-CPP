#ifndef VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__CONNECT_APP_AND_HOST_MATCHER_H_
#define VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__CONNECT_APP_AND_HOST_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/CpsModelViewerCommon/ConnectAppAndHostFrame_0.h"
#include "Viatra/Query/CpsModelViewerCommon/ConnectAppAndHostMatch.h"
#include "Viatra/Query/CpsModelViewerCommon/ConnectAppAndHostQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace CpsModelViewerCommon {

template<class ModelRoot>
class ConnectAppAndHostMatcher {
public:
	ConnectAppAndHostMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<ConnectAppAndHostMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<ConnectAppAndHostMatch> matches;
	
		{
			auto sp = ConnectAppAndHostQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<ConnectAppAndHostFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				ConnectAppAndHostMatch match;
			
				match.app = static_cast<::cyberPhysicalSystem::ApplicationInstance*>(frame._0);
				match.host = static_cast<::cyberPhysicalSystem::HostInstance*>(frame._1);
			
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


#endif /*  VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__CONNECT_APP_AND_HOST_MATCHER_H_ */
