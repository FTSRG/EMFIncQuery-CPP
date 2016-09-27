#ifndef VIATRA__QUERY__CPSQUERY__STATEMACHINE_STATE_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__STATEMACHINE_STATE_MATCHER_H_

#include <type_traits>
#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/StatemachineStateMatch.h"
#include "Viatra/Query/Cpsquery/StatemachineStateQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Util/IsNull.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class StatemachineStateMatcher {
public:
	StatemachineStateMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<StatemachineStateMatch> matches(::cyberPhysicalSystem::StateMachine* statemachine, ::cyberPhysicalSystem::State* state) const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<StatemachineStateMatch> matches;
	
		{
			auto _classHelper = &_context->get_class_helper();		
			if(_classHelper->is_super_type(statemachine->get_type_id(), ::cyberPhysicalSystem::StateMachine::type_id)) {
				auto statemachine_0 = statemachine;
				auto& data = statemachine_0->states;
				if(std::find(data.begin(), data.end(), state) != data.end()) {
					::Viatra::Query::Cpsquery::StatemachineStateMatch match;
					match.statemachine = static_cast<::cyberPhysicalSystem::StateMachine*>(statemachine_0);
					match.state = static_cast<::cyberPhysicalSystem::State*>(state);
					
					matches.insert(match);
				}
			}
		}
		
	
		return matches;
	}
	std::unordered_set<StatemachineStateMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<StatemachineStateMatch> matches;
	
		{
			auto _classHelper = &_context->get_class_helper();		
			for(auto&& statemachine : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::StateMachine>::type, ModelRoot>::instances(_model))) {
				for(auto&& state : statemachine->states) {
					if(_classHelper->is_super_type(statemachine->get_type_id(), ::cyberPhysicalSystem::StateMachine::type_id)) {
						auto statemachine_0 = statemachine;
						::Viatra::Query::Cpsquery::StatemachineStateMatch match;
						match.statemachine = static_cast<::cyberPhysicalSystem::StateMachine*>(statemachine_0);
						match.state = static_cast<::cyberPhysicalSystem::State*>(state);
						
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


#endif /*  VIATRA__QUERY__CPSQUERY__STATEMACHINE_STATE_MATCHER_H_ */
