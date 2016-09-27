#ifndef VIATRA__QUERY__CPSQUERY__REACHABLE_APP_INSTANCE_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__REACHABLE_APP_INSTANCE_MATCHER_H_

#include <type_traits>
#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/HostCommunicationMatcher.h"
#include "Viatra/Query/Cpsquery/ReachableAppInstanceMatch.h"
#include "Viatra/Query/Cpsquery/ReachableAppInstanceQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Util/IsNull.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class ReachableAppInstanceMatcher {
public:
	ReachableAppInstanceMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<ReachableAppInstanceMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<ReachableAppInstanceMatch> matches;
	
		{
			auto _classHelper = &_context->get_class_helper();		
			for(auto&& appTypeInstanceAndHost_1__hostInstance : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::HostInstance>::type, ModelRoot>::instances(_model))) {
				if(_classHelper->is_super_type(appTypeInstanceAndHost_1__hostInstance->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
					auto appTypeInstanceAndHost_1__hostInstance_0 = appTypeInstanceAndHost_1__hostInstance;
					if(_classHelper->is_super_type(appTypeInstanceAndHost_1__hostInstance_0->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
						auto appTypeInstanceAndHost_1__hostInstance_1 = appTypeInstanceAndHost_1__hostInstance_0;
						for(auto&& appTypeInstanceAndHost_1__appInstance : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::ApplicationInstance>::type, ModelRoot>::instances(_model))) {
							if(!::Viatra::Query::Util::IsNull<decltype(appTypeInstanceAndHost_1__appInstance->type)>::check(appTypeInstanceAndHost_1__appInstance->type)) {
								auto appTypeInstanceAndHost_1__app = appTypeInstanceAndHost_1__appInstance->type;
								if(_classHelper->is_super_type(appTypeInstanceAndHost_1__appInstance->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
									auto appTypeInstanceAndHost_1__appInstance_0 = appTypeInstanceAndHost_1__appInstance;
									if(_classHelper->is_super_type(appTypeInstanceAndHost_1__appInstance_0->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
										auto appTypeInstanceAndHost_1__appInstance_1 = appTypeInstanceAndHost_1__appInstance_0;
										if(appTypeInstanceAndHost_1__appInstance_1->allocatedTo == appTypeInstanceAndHost_1__hostInstance_1) {
											if(_classHelper->is_super_type(appTypeInstanceAndHost_1__app->get_type_id(), ::cyberPhysicalSystem::ApplicationType::type_id)) {
												auto appTypeInstanceAndHost_1__app_0 = appTypeInstanceAndHost_1__app;
												if(_classHelper->is_super_type(appTypeInstanceAndHost_1__appInstance_1->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
													auto appTypeInstanceAndHost_1__appInstance_2 = appTypeInstanceAndHost_1__appInstance_1;
													::Viatra::Query::Cpsquery::ReachableAppInstanceMatch match;
													match.app = static_cast<::cyberPhysicalSystem::ApplicationType*>(appTypeInstanceAndHost_1__app_0);
													match.appInstance = static_cast<::cyberPhysicalSystem::ApplicationInstance*>(appTypeInstanceAndHost_1__appInstance_2);
													match.sourceHostInstance = static_cast<::cyberPhysicalSystem::HostInstance*>(appTypeInstanceAndHost_1__hostInstance_1);
													
													matches.insert(match);
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		
		{
			auto _classHelper = &_context->get_class_helper();		
			HostCommunicationMatcher<ModelRoot> matcher_1662597579(_model,  _context);
			for(auto&& reachableHosts_0__source : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::HostInstance>::type, ModelRoot>::instances(_model))) {
				if(_classHelper->is_super_type(reachableHosts_0__source->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
					auto reachableHosts_0__source_0 = reachableHosts_0__source;
					for(auto&& appTypeInstanceAndHost_1__hostInstance : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::HostInstance>::type, ModelRoot>::instances(_model))) {
						if(transitive_closure_check(matcher_1662597579, &HostCommunicationMatch::toHost, reachableHosts_0__source_0, appTypeInstanceAndHost_1__hostInstance)) {
							for(auto&& appTypeInstanceAndHost_1__appInstance : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::ApplicationInstance>::type, ModelRoot>::instances(_model))) {
								if(!::Viatra::Query::Util::IsNull<decltype(appTypeInstanceAndHost_1__appInstance->type)>::check(appTypeInstanceAndHost_1__appInstance->type)) {
									auto appTypeInstanceAndHost_1__app = appTypeInstanceAndHost_1__appInstance->type;
									if(_classHelper->is_super_type(appTypeInstanceAndHost_1__appInstance->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
										auto appTypeInstanceAndHost_1__appInstance_0 = appTypeInstanceAndHost_1__appInstance;
										if(_classHelper->is_super_type(appTypeInstanceAndHost_1__appInstance_0->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
											auto appTypeInstanceAndHost_1__appInstance_1 = appTypeInstanceAndHost_1__appInstance_0;
											if(appTypeInstanceAndHost_1__appInstance_1->allocatedTo == appTypeInstanceAndHost_1__hostInstance) {
												if(_classHelper->is_super_type(appTypeInstanceAndHost_1__app->get_type_id(), ::cyberPhysicalSystem::ApplicationType::type_id)) {
													auto appTypeInstanceAndHost_1__app_0 = appTypeInstanceAndHost_1__app;
													if(_classHelper->is_super_type(appTypeInstanceAndHost_1__appInstance_1->get_type_id(), ::cyberPhysicalSystem::ApplicationInstance::type_id)) {
														auto appTypeInstanceAndHost_1__appInstance_2 = appTypeInstanceAndHost_1__appInstance_1;
														::Viatra::Query::Cpsquery::ReachableAppInstanceMatch match;
														match.sourceHostInstance = static_cast<::cyberPhysicalSystem::HostInstance*>(reachableHosts_0__source_0);
														match.app = static_cast<::cyberPhysicalSystem::ApplicationType*>(appTypeInstanceAndHost_1__app_0);
														match.appInstance = static_cast<::cyberPhysicalSystem::ApplicationInstance*>(appTypeInstanceAndHost_1__appInstance_2);
														
														matches.insert(match);
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		
	
		return matches;
	}
	
private:
	template<class NavigationMatcher, class SrcType, class TrgType, class NavigationMatch, class NavigationTrgType>
	bool transitive_closure_check(NavigationMatcher matcher, NavigationTrgType NavigationMatch::* trgMember, SrcType src, TrgType trg) const;
	const ModelRoot* _model;
	const ::Viatra::Query::Matcher::ISearchContext* _context;
};

template<class ModelRoot>
template<class NavigationMatcher, class SrcType, class TrgType, class NavigationMatch, class NavigationTrgType>
inline bool ReachableAppInstanceMatcher<ModelRoot>::transitive_closure_check(NavigationMatcher matcher, NavigationTrgType NavigationMatch::* trgMember, SrcType src, TrgType trg) const {
	std::unordered_set<SrcType> sourcesToEvaluate; 
	sourcesToEvaluate.insert(src);
	std::unordered_set<SrcType> sourceEvaluated; 

	do{
		auto it = sourcesToEvaluate.begin();
		auto currentSrc = *it;
		sourcesToEvaluate.erase(it);
		sourceEvaluated.insert(currentSrc);

		auto matches = matcher.matches(currentSrc);
		for(auto& match : matches)
		{
			auto foundTarget = match.*trgMember;

			if(trg == foundTarget) return true;
			else if( sourceEvaluated.count(foundTarget) == 0)
				sourcesToEvaluate.insert(foundTarget);
		}
	} while(!sourcesToEvaluate.empty());
	return false;
}

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__REACHABLE_APP_INSTANCE_MATCHER_H_ */
