#ifndef VIATRA__QUERY__CPSQUERY__ID_IS_NOT_UNIQUE_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__ID_IS_NOT_UNIQUE_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/IdIsNotUniqueFrame_0.h"
#include "Viatra/Query/Cpsquery/IdIsNotUniqueMatch.h"
#include "Viatra/Query/Cpsquery/IdIsNotUniqueQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class IdIsNotUniqueMatcher {
public:
	IdIsNotUniqueMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<IdIsNotUniqueMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<IdIsNotUniqueMatch> matches;
	
		{
			auto sp = IdIsNotUniqueQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<IdIsNotUniqueFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				IdIsNotUniqueMatch match;
			
				match.identifiable = static_cast<::cyberPhysicalSystem::Identifiable*>(frame._0);
			
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


#endif /*  VIATRA__QUERY__CPSQUERY__ID_IS_NOT_UNIQUE_MATCHER_H_ */
