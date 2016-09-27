#ifndef VIATRA__QUERY__CPSQUERY__REACHABLE_HOSTS_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__REACHABLE_HOSTS_MATCHER_H_

#include <type_traits>
#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/HostCommunicationMatcher.h"
#include "Viatra/Query/Cpsquery/ReachableHostsMatch.h"
#include "Viatra/Query/Cpsquery/ReachableHostsQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Util/IsNull.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class ReachableHostsMatcher {
public:
	ReachableHostsMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<ReachableHostsMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<ReachableHostsMatch> matches;
	
		{
			auto _classHelper = &_context->get_class_helper();		
			HostCommunicationMatcher<ModelRoot> matcher_1846559069(_model,  _context);
			for(auto&& source : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::HostInstance>::type, ModelRoot>::instances(_model))) {
				for(auto&& target : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::HostInstance>::type, ModelRoot>::instances(_model))) {
					if(transitive_closure_check(matcher_1846559069, &HostCommunicationMatch::toHost, source, target)) {
						::Viatra::Query::Cpsquery::ReachableHostsMatch match;
						match.source = static_cast<::cyberPhysicalSystem::HostInstance*>(source);
						match.target = static_cast<::cyberPhysicalSystem::HostInstance*>(target);
						
						matches.insert(match);
					}
				}
			}
		}
		
		{
			auto _classHelper = &_context->get_class_helper();		
			for(auto&& target : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::HostInstance>::type, ModelRoot>::instances(_model))) {
				if(_classHelper->is_super_type(target->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
					auto target_0 = target;
					::Viatra::Query::Cpsquery::ReachableHostsMatch match;
					match.source = static_cast<::cyberPhysicalSystem::HostInstance*>(target_0);
					match.target = static_cast<::cyberPhysicalSystem::HostInstance*>(target_0);
					
					matches.insert(match);
				}
			}
		}
		
	
		return matches;
	}
	std::unordered_set<ReachableHostsMatch> matches(::cyberPhysicalSystem::HostInstance* source) const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<ReachableHostsMatch> matches;
	
		{
			auto _classHelper = &_context->get_class_helper();		
			HostCommunicationMatcher<ModelRoot> matcher_142104618(_model,  _context);
			if(_classHelper->is_super_type(source->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
				auto source_0 = source;
				for(auto&& target : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::HostInstance>::type, ModelRoot>::instances(_model))) {
					if(transitive_closure_check(matcher_142104618, &HostCommunicationMatch::toHost, source_0, target)) {
						::Viatra::Query::Cpsquery::ReachableHostsMatch match;
						match.source = static_cast<::cyberPhysicalSystem::HostInstance*>(source_0);
						match.target = static_cast<::cyberPhysicalSystem::HostInstance*>(target);
						
						matches.insert(match);
					}
				}
			}
		}
		
		{
			auto _classHelper = &_context->get_class_helper();		
			if(_classHelper->is_super_type(target->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
				auto target_0 = target;
				if(_classHelper->is_super_type(target_0->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
					auto target_1 = target_0;
					::Viatra::Query::Cpsquery::ReachableHostsMatch match;
					match.source = static_cast<::cyberPhysicalSystem::HostInstance*>(target_1);
					match.target = static_cast<::cyberPhysicalSystem::HostInstance*>(target_1);
					
					matches.insert(match);
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
inline bool ReachableHostsMatcher<ModelRoot>::transitive_closure_check(NavigationMatcher matcher, NavigationTrgType NavigationMatch::* trgMember, SrcType src, TrgType trg) const {
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


#endif /*  VIATRA__QUERY__CPSQUERY__REACHABLE_HOSTS_MATCHER_H_ */
