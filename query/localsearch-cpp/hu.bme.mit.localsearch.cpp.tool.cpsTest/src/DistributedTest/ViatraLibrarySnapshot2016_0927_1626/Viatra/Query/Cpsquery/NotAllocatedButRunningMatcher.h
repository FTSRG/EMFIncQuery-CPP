#ifndef VIATRA__QUERY__CPSQUERY__NOT_ALLOCATED_BUT_RUNNING_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__NOT_ALLOCATED_BUT_RUNNING_MATCHER_H_

#include <type_traits>
#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/AllocatedApplicationMatcher.h"
#include "Viatra/Query/Cpsquery/NotAllocatedButRunningMatch.h"
#include "Viatra/Query/Cpsquery/NotAllocatedButRunningQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Util/IsNull.h"

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
			auto _classHelper = &_context->get_class_helper();		
			AllocatedApplicationMatcher<ModelRoot> matcher_2015792323(_model,  _context);
			auto _0 = ::cyberPhysicalSystem::AppState::Running;
			for(auto&& app : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::ApplicationInstance>::type, ModelRoot>::instances(_model))) {
				if(_classHelper->is_super_type(app->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
					auto app_0 = app;
					if(app_0->state == _0) {
						if(matcher_2015792323.matches(app_0).size() == 0) {
							::Viatra::Query::Cpsquery::NotAllocatedButRunningMatch match;
							match.app = static_cast<::cyberPhysicalSystem::ApplicationInstance*>(app_0);
							
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


#endif /*  VIATRA__QUERY__CPSQUERY__NOT_ALLOCATED_BUT_RUNNING_MATCHER_H_ */
