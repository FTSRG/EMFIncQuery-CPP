#ifndef VIATRA__QUERY__CPSQUERY__NODE_IP_IS_NOT_UNIQUE_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__NODE_IP_IS_NOT_UNIQUE_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/NodeIpIsNotUniqueFrame_0.h"
#include "Viatra/Query/Cpsquery/NodeIpIsNotUniqueMatch.h"
#include "Viatra/Query/Cpsquery/NodeIpIsNotUniqueQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class NodeIpIsNotUniqueMatcher {
public:
	NodeIpIsNotUniqueMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<NodeIpIsNotUniqueMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<NodeIpIsNotUniqueMatch> matches;
	
		{
			auto sp = NodeIpIsNotUniqueQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<NodeIpIsNotUniqueFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				NodeIpIsNotUniqueMatch match;
			
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

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__NODE_IP_IS_NOT_UNIQUE_MATCHER_H_ */
