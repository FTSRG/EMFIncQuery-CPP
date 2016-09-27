#ifndef VIATRA__QUERY__DISTRIBUTEDQUERY__QUERY_B_MATCHER_H_
#define VIATRA__QUERY__DISTRIBUTEDQUERY__QUERY_B_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Distributedquery/QueryBFrame_0.h"
#include "Viatra/Query/Distributedquery/QueryBMatch.h"
#include "Viatra/Query/Distributedquery/QueryBQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace Distributedquery {

template<class ModelRoot>
class QueryBMatcher {
public:
	QueryBMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}
	std::unordered_set<QueryBMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<QueryBMatch> matches;
	
		{
			auto sp = QueryBQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<QueryBFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				QueryBMatch match;
			
				match.a1 = static_cast<::cyberPhysicalSystem::IApplicationInstance*>(frame._0);
				match.h1 = static_cast<::cyberPhysicalSystem::IHostInstance*>(frame._1);
			
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


#endif /*  VIATRA__QUERY__DISTRIBUTEDQUERY__QUERY_B_MATCHER_H_ */
