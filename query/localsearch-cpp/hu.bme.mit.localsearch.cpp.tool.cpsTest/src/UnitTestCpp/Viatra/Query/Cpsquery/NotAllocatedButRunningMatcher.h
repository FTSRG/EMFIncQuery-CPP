#ifndef VIATRA__QUERY__CPSQUERY__NOT_ALLOCATED_BUT_RUNNING_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__NOT_ALLOCATED_BUT_RUNNING_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/NotAllocatedButRunningFrame_0.h"
#include "Viatra/Query/Cpsquery/NotAllocatedButRunningMatch.h"
#include "Viatra/Query/Cpsquery/NotAllocatedButRunningQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class NotAllocatedButRunningMatcher {
public:
	NotAllocatedButRunningMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<NotAllocatedButRunningMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<NotAllocatedButRunningMatch> matches;
	
		{
			auto sp = NotAllocatedButRunningQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<NotAllocatedButRunningFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				NotAllocatedButRunningMatch match;
			
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


#endif /*  VIATRA__QUERY__CPSQUERY__NOT_ALLOCATED_BUT_RUNNING_MATCHER_H_ */
