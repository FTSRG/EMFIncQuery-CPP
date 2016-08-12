#ifndef VIATRA__QUERY__CPSQUERY__TRANSITION_WITHOUT_TARGET_STATE_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__TRANSITION_WITHOUT_TARGET_STATE_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/TransitionWithoutTargetStateFrame_0.h"
#include "Viatra/Query/Cpsquery/TransitionWithoutTargetStateMatch.h"
#include "Viatra/Query/Cpsquery/TransitionWithoutTargetStateQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class TransitionWithoutTargetStateMatcher {
public:
	TransitionWithoutTargetStateMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<TransitionWithoutTargetStateMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<TransitionWithoutTargetStateMatch> matches;
	
		{
			auto sp = TransitionWithoutTargetStateQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<TransitionWithoutTargetStateFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TransitionWithoutTargetStateMatch match;
			
				match.transition = static_cast<::cyberPhysicalSystem::Transition*>(frame._0);
			
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


#endif /*  VIATRA__QUERY__CPSQUERY__TRANSITION_WITHOUT_TARGET_STATE_MATCHER_H_ */
