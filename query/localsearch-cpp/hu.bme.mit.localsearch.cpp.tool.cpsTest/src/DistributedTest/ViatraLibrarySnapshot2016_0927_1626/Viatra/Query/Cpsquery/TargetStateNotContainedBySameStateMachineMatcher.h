#ifndef VIATRA__QUERY__CPSQUERY__TARGET_STATE_NOT_CONTAINED_BY_SAME_STATE_MACHINE_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__TARGET_STATE_NOT_CONTAINED_BY_SAME_STATE_MACHINE_MATCHER_H_

#include <type_traits>
#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/StatemachineStateMatcher.h"
#include "Viatra/Query/Cpsquery/TargetStateNotContainedBySameStateMachineMatch.h"
#include "Viatra/Query/Cpsquery/TargetStateNotContainedBySameStateMachineQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Util/IsNull.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class TargetStateNotContainedBySameStateMachineMatcher {
public:
	TargetStateNotContainedBySameStateMachineMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<TargetStateNotContainedBySameStateMachineMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<TargetStateNotContainedBySameStateMachineMatch> matches;
	
		{
			auto _classHelper = &_context->get_class_helper();		
			StatemachineStateMatcher<ModelRoot> matcher_1115706993(_model,  _context);
			for(auto&& statemachineState_0__statemachine : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::StateMachine>::type, ModelRoot>::instances(_model))) {
				for(auto&& statemachineState_0__state : statemachineState_0__statemachine->states) {
					if(_classHelper->is_super_type(statemachineState_0__statemachine->get_type_id(), ::cyberPhysicalSystem::StateMachine::type_id)) {
						auto statemachineState_0__statemachine_0 = statemachineState_0__statemachine;
						if(_classHelper->is_super_type(statemachineState_0__state->get_type_id(), ::cyberPhysicalSystem::State::type_id)) {
							auto statemachineState_0__state_0 = statemachineState_0__state;
							for(auto&& stateTransition_1__transition : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::Transition>::type, ModelRoot>::instances(_model))) {
								if(!::Viatra::Query::Util::IsNull<decltype(stateTransition_1__transition->targetState)>::check(stateTransition_1__transition->targetState)) {
									auto stateTransition_1__target = stateTransition_1__transition->targetState;
									auto& data = statemachineState_0__state_0->outgoingTransitions;
									if(std::find(data.begin(), data.end(), stateTransition_1__transition) != data.end()) {
										if(_classHelper->is_super_type(stateTransition_1__transition->get_type_id(), ::cyberPhysicalSystem::Transition::type_id)) {
											auto stateTransition_1__transition_0 = stateTransition_1__transition;
											if(matcher_1115706993.matches(statemachineState_0__statemachine_0, stateTransition_1__target).size() == 0) {
												::Viatra::Query::Cpsquery::TargetStateNotContainedBySameStateMachineMatch match;
												match.transition = static_cast<::cyberPhysicalSystem::Transition*>(stateTransition_1__transition_0);
												match.target = static_cast<::cyberPhysicalSystem::State*>(stateTransition_1__target);
												
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
		
	
		return matches;
	}
	
private:
	const ModelRoot* _model;
	const ::Viatra::Query::Matcher::ISearchContext* _context;
};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__TARGET_STATE_NOT_CONTAINED_BY_SAME_STATE_MACHINE_MATCHER_H_ */
