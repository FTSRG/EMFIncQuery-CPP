#ifndef VIATRA__QUERY__CPSQUERY__ALLOCATED_APPLICATION_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__ALLOCATED_APPLICATION_MATCHER_H_

#include <type_traits>
#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/AllocatedApplicationMatch.h"
#include "Viatra/Query/Cpsquery/AllocatedApplicationQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Util/IsNull.h"

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
			auto _classHelper = &_context->get_class_helper();		
			if(_classHelper->is_super_type(app->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
				auto app_0 = app;
				if(_classHelper->is_super_type(app_0->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
					auto app_1 = app_0;
					if(!::Viatra::Query::Util::IsNull<decltype(app_1->allocatedTo)>::check(app_1->allocatedTo)) {
						auto _unnamed_0 = app_1->allocatedTo;
						::Viatra::Query::Cpsquery::AllocatedApplicationMatch match;
						match.app = static_cast<::cyberPhysicalSystem::ApplicationInstance*>(app_1);
						
						matches.insert(match);
					}
				}
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
			auto _classHelper = &_context->get_class_helper();		
			for(auto&& app : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::ApplicationInstance>::type, ModelRoot>::instances(_model))) {
				if(_classHelper->is_super_type(app->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
					auto app_0 = app;
					if(!::Viatra::Query::Util::IsNull<decltype(app_0->allocatedTo)>::check(app_0->allocatedTo)) {
						auto _unnamed_0 = app_0->allocatedTo;
						::Viatra::Query::Cpsquery::AllocatedApplicationMatch match;
						match.app = static_cast<::cyberPhysicalSystem::ApplicationInstance*>(app_0);
						
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


#endif /*  VIATRA__QUERY__CPSQUERY__ALLOCATED_APPLICATION_MATCHER_H_ */
