#ifndef VIATRA__QUERY__CPSQUERY__MULTIPLE_TRANSITIONS_WITH_SAME_ACTION_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__MULTIPLE_TRANSITIONS_WITH_SAME_ACTION_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/MultipleTransitionsWithSameActionFrame_0.h"
#include "Viatra/Query/Cpsquery/MultipleTransitionsWithSameActionMatch.h"
#include "Viatra/Query/Cpsquery/MultipleTransitionsWithSameActionQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class MultipleTransitionsWithSameActionMatcher {
public:
	MultipleTransitionsWithSameActionMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<MultipleTransitionsWithSameActionMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<MultipleTransitionsWithSameActionMatch> matches;
	
		{
			auto sp = MultipleTransitionsWithSameActionQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<MultipleTransitionsWithSameActionFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				MultipleTransitionsWithSameActionMatch match;
			
				match.action = static_cast<::std::string>(frame._1);
				match.state = static_cast<::cyberPhysicalSystem::State*>(frame._0);
			
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


#endif /*  VIATRA__QUERY__CPSQUERY__MULTIPLE_TRANSITIONS_WITH_SAME_ACTION_MATCHER_H_ */
