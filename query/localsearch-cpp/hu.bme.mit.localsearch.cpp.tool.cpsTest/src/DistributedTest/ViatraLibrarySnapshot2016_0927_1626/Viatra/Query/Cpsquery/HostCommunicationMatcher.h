#ifndef VIATRA__QUERY__CPSQUERY__HOST_COMMUNICATION_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__HOST_COMMUNICATION_MATCHER_H_

#include <type_traits>
#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/HostCommunicationMatch.h"
#include "Viatra/Query/Cpsquery/HostCommunicationQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Util/IsNull.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class HostCommunicationMatcher {
public:
	HostCommunicationMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<HostCommunicationMatch> matches(::cyberPhysicalSystem::HostInstance* fromHost, ::cyberPhysicalSystem::HostInstance* toHost) const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<HostCommunicationMatch> matches;
	
		{
			auto _classHelper = &_context->get_class_helper();		
			if(_classHelper->is_super_type(fromHost->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
				auto fromHost_0 = fromHost;
				auto& data = fromHost_0->communicateWith;
				if(std::find(data.begin(), data.end(), toHost) != data.end()) {
					::Viatra::Query::Cpsquery::HostCommunicationMatch match;
					match.fromHost = static_cast<::cyberPhysicalSystem::HostInstance*>(fromHost_0);
					match.toHost = static_cast<::cyberPhysicalSystem::HostInstance*>(toHost);
					
					matches.insert(match);
				}
			}
		}
		
	
		return matches;
	}
	std::unordered_set<HostCommunicationMatch> matches(::cyberPhysicalSystem::HostInstance* toHost, ::cyberPhysicalSystem::HostInstance* fromHost) const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<HostCommunicationMatch> matches;
	
		{
			auto _classHelper = &_context->get_class_helper();		
			if(_classHelper->is_super_type(fromHost->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
				auto fromHost_0 = fromHost;
				auto& data = fromHost_0->communicateWith;
				if(std::find(data.begin(), data.end(), toHost) != data.end()) {
					::Viatra::Query::Cpsquery::HostCommunicationMatch match;
					match.fromHost = static_cast<::cyberPhysicalSystem::HostInstance*>(fromHost_0);
					match.toHost = static_cast<::cyberPhysicalSystem::HostInstance*>(toHost);
					
					matches.insert(match);
				}
			}
		}
		
	
		return matches;
	}
	std::unordered_set<HostCommunicationMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<HostCommunicationMatch> matches;
	
		{
			auto _classHelper = &_context->get_class_helper();		
			for(auto&& fromHost : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::HostInstance>::type, ModelRoot>::instances(_model))) {
				for(auto&& toHost : fromHost->communicateWith) {
					if(_classHelper->is_super_type(fromHost->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
						auto fromHost_0 = fromHost;
						::Viatra::Query::Cpsquery::HostCommunicationMatch match;
						match.fromHost = static_cast<::cyberPhysicalSystem::HostInstance*>(fromHost_0);
						match.toHost = static_cast<::cyberPhysicalSystem::HostInstance*>(toHost);
						
						matches.insert(match);
					}
				}
			}
		}
		
	
		return matches;
	}
	std::unordered_set<HostCommunicationMatch> matches(::cyberPhysicalSystem::HostInstance* fromHost) const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<HostCommunicationMatch> matches;
	
		{
			auto _classHelper = &_context->get_class_helper();		
			if(_classHelper->is_super_type(fromHost->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
				auto fromHost_0 = fromHost;
				for(auto&& toHost : fromHost_0->communicateWith) {
					::Viatra::Query::Cpsquery::HostCommunicationMatch match;
					match.fromHost = static_cast<::cyberPhysicalSystem::HostInstance*>(fromHost_0);
					match.toHost = static_cast<::cyberPhysicalSystem::HostInstance*>(toHost);
					
					matches.insert(match);
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


#endif /*  VIATRA__QUERY__CPSQUERY__HOST_COMMUNICATION_MATCHER_H_ */
