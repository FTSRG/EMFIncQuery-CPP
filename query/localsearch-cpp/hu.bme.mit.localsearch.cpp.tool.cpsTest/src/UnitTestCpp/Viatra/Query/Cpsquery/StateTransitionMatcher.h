#ifndef VIATRA__QUERY__CPSQUERY__STATE_TRANSITION_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__STATE_TRANSITION_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/StateTransitionFrame_0.h"
#include "Viatra/Query/Cpsquery/StateTransitionMatch.h"
#include "Viatra/Query/Cpsquery/StateTransitionQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class StateTransitionMatcher {
public:
	StateTransitionMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<StateTransitionMatch> matches(::cyberPhysicalSystem::State* source, ::cyberPhysicalSystem::Transition* transition) const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<StateTransitionMatch> matches;
	
		{
			auto sp = StateTransitionQuerySpecification<ModelRoot>::get_plan_source_transition__0(_model);
			StateTransitionFrame_0 frame;
			frame._0 = source;
			frame._1 = transition;
			
			auto exec = SearchPlanExecutor<StateTransitionFrame_0>(sp, *_context).prepare(frame);
			
			
			for (auto&& frame : exec) {
				StateTransitionMatch match;
			
				match.source = static_cast<::cyberPhysicalSystem::State*>(frame._0);
				match.transition = static_cast<::cyberPhysicalSystem::Transition*>(frame._1);
				match.target = static_cast<::cyberPhysicalSystem::State*>(frame._2);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
	std::unordered_set<StateTransitionMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<StateTransitionMatch> matches;
	
		{
			auto sp = StateTransitionQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<StateTransitionFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				StateTransitionMatch match;
			
				match.source = static_cast<::cyberPhysicalSystem::State*>(frame._0);
				match.transition = static_cast<::cyberPhysicalSystem::Transition*>(frame._1);
				match.target = static_cast<::cyberPhysicalSystem::State*>(frame._2);
			
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


#endif /*  VIATRA__QUERY__CPSQUERY__STATE_TRANSITION_MATCHER_H_ */
