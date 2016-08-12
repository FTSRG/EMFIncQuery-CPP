#ifndef VIATRA__QUERY__CPSQUERY__STATEMACHINE_STATE_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__STATEMACHINE_STATE_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/StatemachineStateFrame_0.h"
#include "Viatra/Query/Cpsquery/StatemachineStateMatch.h"
#include "Viatra/Query/Cpsquery/StatemachineStateQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"

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
			auto sp = StatemachineStateQuerySpecification<ModelRoot>::get_plan_statemachine_state__0(_model);
			StatemachineStateFrame_0 frame;
			frame._0 = statemachine;
			frame._1 = state;
			
			auto exec = SearchPlanExecutor<StatemachineStateFrame_0>(sp, *_context).prepare(frame);
			
			
			for (auto&& frame : exec) {
				StatemachineStateMatch match;
			
				match.statemachine = static_cast<::cyberPhysicalSystem::StateMachine*>(frame._0);
				match.state = static_cast<::cyberPhysicalSystem::State*>(frame._1);
			
				matches.insert(match);
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
			auto sp = StatemachineStateQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<StatemachineStateFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				StatemachineStateMatch match;
			
				match.statemachine = static_cast<::cyberPhysicalSystem::StateMachine*>(frame._0);
				match.state = static_cast<::cyberPhysicalSystem::State*>(frame._1);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
	std::unordered_set<StatemachineStateMatch> matches(::cyberPhysicalSystem::StateMachine* statemachine, ::cyberPhysicalSystem::State* state) const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<StatemachineStateMatch> matches;
	
		{
			auto sp = StatemachineStateQuerySpecification<ModelRoot>::get_plan_statemachine_state__0(_model);
			StatemachineStateFrame_0 frame;
			frame._0 = statemachine;
			frame._1 = state;
			
			auto exec = SearchPlanExecutor<StatemachineStateFrame_0>(sp, *_context).prepare(frame);
			
			
			for (auto&& frame : exec) {
				StatemachineStateMatch match;
			
				match.statemachine = static_cast<::cyberPhysicalSystem::StateMachine*>(frame._0);
				match.state = static_cast<::cyberPhysicalSystem::State*>(frame._1);
			
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


#endif /*  VIATRA__QUERY__CPSQUERY__STATEMACHINE_STATE_MATCHER_H_ */
