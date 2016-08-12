#ifndef VIATRA__QUERY__CPSQUERY__INITIAL_STATE_NOT_CONTAINED_BY_STATE_MACHINE_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__INITIAL_STATE_NOT_CONTAINED_BY_STATE_MACHINE_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/InitialStateNotContainedByStateMachineFrame_0.h"
#include "Viatra/Query/Cpsquery/InitialStateNotContainedByStateMachineMatch.h"
#include "Viatra/Query/Cpsquery/InitialStateNotContainedByStateMachineQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"

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
			auto sp = InitialStateNotContainedByStateMachineQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<InitialStateNotContainedByStateMachineFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				InitialStateNotContainedByStateMachineMatch match;
			
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


#endif /*  VIATRA__QUERY__CPSQUERY__INITIAL_STATE_NOT_CONTAINED_BY_STATE_MACHINE_MATCHER_H_ */
