#ifndef VIATRA__QUERY__CPSQUERY__TRANSITION_WITHOUT_TARGET_STATE_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__TRANSITION_WITHOUT_TARGET_STATE_MATCHER_H_

#include <type_traits>
#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/StateTransitionMatcher.h"
#include "Viatra/Query/Cpsquery/TransitionWithoutTargetStateMatch.h"
#include "Viatra/Query/Cpsquery/TransitionWithoutTargetStateQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Util/IsNull.h"

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
			auto _classHelper = &_context->get_class_helper();		
			StateTransitionMatcher<ModelRoot> matcher_1159908148(_model,  _context);
			for(auto&& source : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::State>::type, ModelRoot>::instances(_model))) {
				for(auto&& transition : source->outgoingTransitions) {
					if(_classHelper->is_super_type(source->get_type_id(), ::cyberPhysicalSystem::State::type_id)) {
						auto source_0 = source;
						if(matcher_1159908148.matches(source_0, transition).size() == 0) {
							::Viatra::Query::Cpsquery::TransitionWithoutTargetStateMatch match;
							match.transition = static_cast<::cyberPhysicalSystem::Transition*>(transition);
							
							matches.insert(match);
						}
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


#endif /*  VIATRA__QUERY__CPSQUERY__TRANSITION_WITHOUT_TARGET_STATE_MATCHER_H_ */
