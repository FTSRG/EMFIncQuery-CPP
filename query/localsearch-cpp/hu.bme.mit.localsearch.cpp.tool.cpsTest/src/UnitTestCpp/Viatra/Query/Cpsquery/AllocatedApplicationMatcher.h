#ifndef VIATRA__QUERY__CPSQUERY__ALLOCATED_APPLICATION_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__ALLOCATED_APPLICATION_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/AllocatedApplicationFrame_0.h"
#include "Viatra/Query/Cpsquery/AllocatedApplicationMatch.h"
#include "Viatra/Query/Cpsquery/AllocatedApplicationQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class AllocatedApplicationMatcher {
public:
	AllocatedApplicationMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<AllocatedApplicationMatch> matches(::cyberPhysicalSystem::ApplicationInstance* app) const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<AllocatedApplicationMatch> matches;
	
		{
			auto sp = AllocatedApplicationQuerySpecification<ModelRoot>::get_plan_app__0(_model);
			AllocatedApplicationFrame_0 frame;
			frame._0 = app;
			
			auto exec = SearchPlanExecutor<AllocatedApplicationFrame_0>(sp, *_context).prepare(frame);
			
			
			for (auto&& frame : exec) {
				AllocatedApplicationMatch match;
			
				match.app = static_cast<::cyberPhysicalSystem::ApplicationInstance*>(frame._0);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
	std::unordered_set<AllocatedApplicationMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<AllocatedApplicationMatch> matches;
	
		{
			auto sp = AllocatedApplicationQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<AllocatedApplicationFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				AllocatedApplicationMatch match;
			
				match.app = static_cast<::cyberPhysicalSystem::ApplicationInstance*>(frame._0);
			
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


#endif /*  VIATRA__QUERY__CPSQUERY__ALLOCATED_APPLICATION_MATCHER_H_ */
