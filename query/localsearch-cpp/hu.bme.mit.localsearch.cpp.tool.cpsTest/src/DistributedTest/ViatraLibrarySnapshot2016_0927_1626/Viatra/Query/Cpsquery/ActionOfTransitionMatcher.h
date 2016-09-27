#ifndef VIATRA__QUERY__CPSQUERY__ACTION_OF_TRANSITION_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__ACTION_OF_TRANSITION_MATCHER_H_

#include <type_traits>
#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/ActionOfTransitionMatch.h"
#include "Viatra/Query/Cpsquery/ActionOfTransitionQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Util/IsNull.h"

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
			auto _classHelper = &_context->get_class_helper();		
			for(auto&& transition : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::Transition>::type, ModelRoot>::instances(_model))) {
				if(!::Viatra::Query::Util::IsNull<decltype(transition->action)>::check(transition->action)) {
					auto action = transition->action;
					if(_classHelper->is_super_type(transition->get_type_id(), ::cyberPhysicalSystem::Transition::type_id)) {
						auto transition_0 = transition;
						::Viatra::Query::Cpsquery::ActionOfTransitionMatch match;
						match.transition = static_cast<::cyberPhysicalSystem::Transition*>(transition_0);
						match.action = static_cast<::std::string>(action);
						
						matches.insert(match);
					}
				}
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
