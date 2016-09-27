#ifndef VIATRA__QUERY__CPSQUERY__APP_TYPE_INSTANCE_AND_HOST_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__APP_TYPE_INSTANCE_AND_HOST_MATCHER_H_

#include <type_traits>
#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/AppTypeInstanceAndHostMatch.h"
#include "Viatra/Query/Cpsquery/AppTypeInstanceAndHostQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Util/IsNull.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class AppTypeInstanceAndHostMatcher {
public:
	AppTypeInstanceAndHostMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<AppTypeInstanceAndHostMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<AppTypeInstanceAndHostMatch> matches;
	
		{
			auto _classHelper = &_context->get_class_helper();		
			for(auto&& appInstance : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::ApplicationInstance>::type, ModelRoot>::instances(_model))) {
				if(_classHelper->is_super_type(appInstance->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
					auto appInstance_0 = appInstance;
					if(!::Viatra::Query::Util::IsNull<decltype(appInstance_0->type)>::check(appInstance_0->type)) {
						auto app = appInstance_0->type;
						if(!::Viatra::Query::Util::IsNull<decltype(appInstance_0->allocatedTo)>::check(appInstance_0->allocatedTo)) {
							auto hostInstance = appInstance_0->allocatedTo;
							::Viatra::Query::Cpsquery::AppTypeInstanceAndHostMatch match;
							match.app = static_cast<::cyberPhysicalSystem::ApplicationType*>(app);
							match.appInstance = static_cast<::cyberPhysicalSystem::ApplicationInstance*>(appInstance_0);
							match.hostInstance = static_cast<::cyberPhysicalSystem::HostInstance*>(hostInstance);
							
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


#endif /*  VIATRA__QUERY__CPSQUERY__APP_TYPE_INSTANCE_AND_HOST_MATCHER_H_ */
