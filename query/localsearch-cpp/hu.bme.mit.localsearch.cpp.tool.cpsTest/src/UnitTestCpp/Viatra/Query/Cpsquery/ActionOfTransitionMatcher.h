#ifndef VIATRA__QUERY__CPSQUERY__ACTION_OF_TRANSITION_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__ACTION_OF_TRANSITION_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/ActionOfTransitionFrame_0.h"
#include "Viatra/Query/Cpsquery/ActionOfTransitionMatch.h"
#include "Viatra/Query/Cpsquery/ActionOfTransitionQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class ActionOfTransitionMatcher {
public:
	ActionOfTransitionMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<ActionOfTransitionMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<ActionOfTransitionMatch> matches;
	
		{
			auto sp = ActionOfTransitionQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<ActionOfTransitionFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				ActionOfTransitionMatch match;
			
				match.transition = static_cast<::cyberPhysicalSystem::Transition*>(frame._0);
				match.action = static_cast<::std::string>(frame._1);
			
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


#endif /*  VIATRA__QUERY__CPSQUERY__ACTION_OF_TRANSITION_MATCHER_H_ */
