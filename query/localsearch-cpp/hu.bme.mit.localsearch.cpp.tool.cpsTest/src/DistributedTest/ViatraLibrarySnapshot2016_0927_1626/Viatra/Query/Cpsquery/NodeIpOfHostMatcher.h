#ifndef VIATRA__QUERY__CPSQUERY__NODE_IP_OF_HOST_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__NODE_IP_OF_HOST_MATCHER_H_

#include <type_traits>
#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/NodeIpOfHostMatch.h"
#include "Viatra/Query/Cpsquery/NodeIpOfHostQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Util/IsNull.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class NodeIpOfHostMatcher {
public:
	NodeIpOfHostMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<NodeIpOfHostMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<NodeIpOfHostMatch> matches;
	
		{
			auto _classHelper = &_context->get_class_helper();		
			for(auto&& host : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::HostInstance>::type, ModelRoot>::instances(_model))) {
				if(!::Viatra::Query::Util::IsNull<decltype(host->nodeIp)>::check(host->nodeIp)) {
					auto ip = host->nodeIp;
					if(_classHelper->is_super_type(host->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
						auto host_0 = host;
						::Viatra::Query::Cpsquery::NodeIpOfHostMatch match;
						match.host = static_cast<::cyberPhysicalSystem::HostInstance*>(host_0);
						match.ip = static_cast<::std::string>(ip);
						
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


#endif /*  VIATRA__QUERY__CPSQUERY__NODE_IP_OF_HOST_MATCHER_H_ */
