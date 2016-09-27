#ifndef VIATRA__QUERY__CPSQUERY__NODE_IP_IS_NOT_UNIQUE_MATCHER_H_
#define VIATRA__QUERY__CPSQUERY__NODE_IP_IS_NOT_UNIQUE_MATCHER_H_

#include <type_traits>
#include <unordered_set>
		
#include "Viatra/Query/Cpsquery/NodeIpIsNotUniqueMatch.h"
#include "Viatra/Query/Cpsquery/NodeIpIsNotUniqueQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Util/IsNull.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class NodeIpIsNotUniqueMatcher {
public:
	NodeIpIsNotUniqueMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<NodeIpIsNotUniqueMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<NodeIpIsNotUniqueMatch> matches;
	
		{
			auto _classHelper = &_context->get_class_helper();		
			for(auto&& nodeIpOfHost_0__host : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::HostInstance>::type, ModelRoot>::instances(_model))) {
				if(!::Viatra::Query::Util::IsNull<decltype(nodeIpOfHost_0__host->nodeIp)>::check(nodeIpOfHost_0__host->nodeIp)) {
					auto nodeIpOfHost_0__ip = nodeIpOfHost_0__host->nodeIp;
					if(_classHelper->is_super_type(nodeIpOfHost_0__host->get_type_id(), ::cyberPhysicalSystem::HostInstance::type_id)) {
						auto nodeIpOfHost_0__host_0 = nodeIpOfHost_0__host;
						for(auto&& nodeIpOfHost_1__host : (ModelIndex<std::remove_pointer<::cyberPhysicalSystem::HostInstance>::type, ModelRoot>::instances(_model))) {
							if(nodeIpOfHost_1__host->nodeIp == nodeIpOfHost_0__ip) {
								if(nodeIpOfHost_1__host != nodeIpOfHost_0__host_0){
									::Viatra::Query::Cpsquery::NodeIpIsNotUniqueMatch match;
									match.host = static_cast<::cyberPhysicalSystem::HostInstance*>(nodeIpOfHost_1__host);
									
									matches.insert(match);
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
	const ModelRoot* _model;
	const ::Viatra::Query::Matcher::ISearchContext* _context;
};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__NODE_IP_IS_NOT_UNIQUE_MATCHER_H_ */
