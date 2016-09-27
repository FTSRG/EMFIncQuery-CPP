#ifndef VIATRA__QUERY__CPSQUERY__INITIAL_STATE_NOT_CONTAINED_BY_STATE_MACHINE_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__INITIAL_STATE_NOT_CONTAINED_BY_STATE_MACHINE_MATCHER_H_

#include <type_traits>
#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/InitialStateNotContainedByStateMachineMatch.h"
#include "Viatra/Query/Cpsquery/InitialStateNotContainedByStateMachineQuerySpecification.h"
#include "Viatra/Query/Cpsquery/StatemachineStateMatcher.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Util/IsNull.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class InitialStateNotContainedByStateMachineMatcher {
public:
	InitialStateNotContainedByStateMachineMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<InitialStateNotContainedByStateMachineMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<InitialStateNotContainedByStateMachineMatch> matches;
	
		{
			auto _classHelper = &_context->get_class_helper();		
			StatemachineStateMatcher<ModelRoot> matcher_548604577(_model,  _context);
			for(auto&& statemachine : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::StateMachine>::type, ModelRoot>::instances(_model))) {
				if(!::Viatra::Query::Util::IsNull<decltype(statemachine->initial)>::check(statemachine->initial)) {
					auto state = statemachine->initial;
					if(_classHelper->is_super_type(statemachine->get_type_id(), ::cyberPhysicalSystem::StateMachine::type_id)) {
						auto statemachine_0 = statemachine;
						if(matcher_548604577.matches(statemachine_0, state).size() == 0) {
							::Viatra::Query::Cpsquery::InitialStateNotContainedByStateMachineMatch match;
							match.statemachine = static_cast<::cyberPhysicalSystem::StateMachine*>(statemachine_0);
							match.state = static_cast<::cyberPhysicalSystem::State*>(state);
							
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


#endif /*  VIATRA__QUERY__CPSQUERY__INITIAL_STATE_NOT_CONTAINED_BY_STATE_MACHINE_MATCHER_H_ */
