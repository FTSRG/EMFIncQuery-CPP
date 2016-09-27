#ifndef VIATRA__QUERY__CPSQUERY__STATE_TRANSITION_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__STATE_TRANSITION_MATCHER_H_

#include <type_traits>
#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/StateTransitionMatch.h"
#include "Viatra/Query/Cpsquery/StateTransitionQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Util/IsNull.h"

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
			auto _classHelper = &_context->get_class_helper();		
			if(_classHelper->is_super_type(source->get_type_id(), ::cyberPhysicalSystem::State::type_id)) {
				auto source_0 = source;
				auto& data = source_0->outgoingTransitions;
				if(std::find(data.begin(), data.end(), transition) != data.end()) {
					if(_classHelper->is_super_type(transition->get_type_id(), ::cyberPhysicalSystem::Transition::type_id)) {
						auto transition_0 = transition;
						if(!::Viatra::Query::Util::IsNull<decltype(transition_0->targetState)>::check(transition_0->targetState)) {
							auto target = transition_0->targetState;
							::Viatra::Query::Cpsquery::StateTransitionMatch match;
							match.source = static_cast<::cyberPhysicalSystem::State*>(source_0);
							match.transition = static_cast<::cyberPhysicalSystem::Transition*>(transition_0);
							match.target = static_cast<::cyberPhysicalSystem::State*>(target);
							
							matches.insert(match);
						}
					}
				}
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
			auto _classHelper = &_context->get_class_helper();		
			for(auto&& source : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::State>::type, ModelRoot>::instances(_model))) {
				for(auto&& transition : source->outgoingTransitions) {
					if(_classHelper->is_super_type(source->get_type_id(), ::cyberPhysicalSystem::State::type_id)) {
						auto source_0 = source;
						if(_classHelper->is_super_type(transition->get_type_id(), ::cyberPhysicalSystem::Transition::type_id)) {
							auto transition_0 = transition;
							if(!::Viatra::Query::Util::IsNull<decltype(transition_0->targetState)>::check(transition_0->targetState)) {
								auto target = transition_0->targetState;
								::Viatra::Query::Cpsquery::StateTransitionMatch match;
								match.source = static_cast<::cyberPhysicalSystem::State*>(source_0);
								match.transition = static_cast<::cyberPhysicalSystem::Transition*>(transition_0);
								match.target = static_cast<::cyberPhysicalSystem::State*>(target);
								
								matches.insert(match);
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


#endif /*  VIATRA__QUERY__CPSQUERY__STATE_TRANSITION_MATCHER_H_ */
