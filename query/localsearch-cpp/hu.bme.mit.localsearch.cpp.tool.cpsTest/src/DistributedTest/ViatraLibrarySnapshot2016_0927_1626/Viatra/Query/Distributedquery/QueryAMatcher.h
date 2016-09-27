#ifndef VIATRA__QUERY__DISTRIBUTEDQUERY__QUERY_A_MATCHER_H_
#define VIATRA__QUERY__DISTRIBUTEDQUERY__QUERY_A_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Distributedquery/QueryAFrame_0.h"
#include "Viatra/Query/Distributedquery/QueryAMatch.h"
#include "Viatra/Query/Distributedquery/QueryAQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace Distributedquery {

template<class ModelRoot>
class QueryAMatcher {
public:
	QueryAMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}
	std::unordered_set<QueryAMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<QueryAMatch> matches;
	
		{
			auto sp = QueryAQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<QueryAFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				QueryAMatch match;
			
				match.h1 = static_cast<::cyberPhysicalSystem::IHostInstance*>(frame._0);
				match.pw = static_cast<::std::string>(frame._1);
				match.state = static_cast<::cyberPhysicalSystem::AppState>(frame._2);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
	
private:
	const ModelRoot* _model;
	const ::Viatra::Query::Matcher::ISearchContext* _context;
};

} /* namespace Distributedquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DISTRIBUTEDQUERY__QUERY_A_MATCHER_H_ */
