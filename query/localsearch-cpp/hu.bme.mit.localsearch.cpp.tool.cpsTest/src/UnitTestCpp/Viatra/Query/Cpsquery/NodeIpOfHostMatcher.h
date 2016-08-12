#ifndef VIATRA__QUERY__CPSQUERY__NODE_IP_OF_HOST_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__NODE_IP_OF_HOST_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/NodeIpOfHostFrame_0.h"
#include "Viatra/Query/Cpsquery/NodeIpOfHostMatch.h"
#include "Viatra/Query/Cpsquery/NodeIpOfHostQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class NodeIpOfHostMatcher {
public:
	NodeIpOfHostMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<NodeIpOfHostMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<NodeIpOfHostMatch> matches;
	
		{
			auto sp = NodeIpOfHostQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<NodeIpOfHostFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				NodeIpOfHostMatch match;
			
				match.host = static_cast<::cyberPhysicalSystem::HostInstance*>(frame._0);
				match.ip = static_cast<::std::string>(frame._1);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
	
private:
	const ModelRoot* _model;
	const ::Viatra::Query::Matcher::ISearchContext* _context;
};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__NODE_IP_OF_HOST_MATCHER_H_ */
