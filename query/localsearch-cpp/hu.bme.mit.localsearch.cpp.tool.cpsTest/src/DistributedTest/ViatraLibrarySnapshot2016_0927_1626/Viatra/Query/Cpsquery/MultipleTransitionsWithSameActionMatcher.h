#ifndef VIATRA__QUERY__CPSQUERY__MULTIPLE_TRANSITIONS_WITH_SAME_ACTION_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__MULTIPLE_TRANSITIONS_WITH_SAME_ACTION_MATCHER_H_

#include <type_traits>
#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/MultipleTransitionsWithSameActionMatch.h"
#include "Viatra/Query/Cpsquery/MultipleTransitionsWithSameActionQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Util/IsNull.h"

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
			auto _classHelper = &_context->get_class_helper();		
			for(auto&& state : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::State>::type, ModelRoot>::instances(_model))) {
				if(_classHelper->is_super_type(state->get_type_id(), ::cyberPhysicalSystem::State::type_id)) {
					auto state_0 = state;
					for(auto&& actionOfTransition_1__transition : state_0->outgoingTransitions) {
						if(_classHelper->is_super_type(actionOfTransition_1__transition->get_type_id(), ::cyberPhysicalSystem::Transition::type_id)) {
							auto actionOfTransition_1__transition_0 = actionOfTransition_1__transition;
							for(auto&& actionOfTransition_0__transition : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::Transition>::type, ModelRoot>::instances(_model))) {
								if(!::Viatra::Query::Util::IsNull<decltype(actionOfTransition_0__transition->action)>::check(actionOfTransition_0__transition->action)) {
									auto actionOfTransition_0__action = actionOfTransition_0__transition->action;
									if(_classHelper->is_super_type(actionOfTransition_0__transition->get_type_id(), ::cyberPhysicalSystem::Transition::type_id)) {
										auto actionOfTransition_0__transition_0 = actionOfTransition_0__transition;
										if(actionOfTransition_1__transition_0->action == actionOfTransition_0__action) {
											auto& data = state_0->outgoingTransitions;
											if(std::find(data.begin(), data.end(), actionOfTransition_0__transition_0) != data.end()) {
												if(actionOfTransition_1__transition_0 != actionOfTransition_0__transition_0){
													::Viatra::Query::Cpsquery::MultipleTransitionsWithSameActionMatch match;
													match.action = static_cast<::std::string>(actionOfTransition_0__action);
													match.state = static_cast<::cyberPhysicalSystem::State*>(state_0);
													
													matches.insert(match);
												}
											}
										}
									}
								}
							}
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


#endif /*  VIATRA__QUERY__CPSQUERY__MULTIPLE_TRANSITIONS_WITH_SAME_ACTION_MATCHER_H_ */
