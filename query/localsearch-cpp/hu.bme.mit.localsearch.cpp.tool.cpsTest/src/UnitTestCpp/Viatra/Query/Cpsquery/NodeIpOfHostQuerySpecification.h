#ifndef VIATRA__QUERY__CPSQUERY__NODE_IP_OF_HOST_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPSQUERY__NODE_IP_OF_HOST_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/Cpsquery/CpsqueryQueryGroup.h"
#include "Viatra/Query/Cpsquery/NodeIpOfHostFrame_0.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class NodeIpOfHostMatcher;

template<class ModelRoot>
class NodeIpOfHostQuerySpecification {
public:
	using Matcher = NodeIpOfHostMatcher<ModelRoot>;

	using QueryGroup = CpsqueryQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<NodeIpOfHostFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<NodeIpOfHostFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&NodeIpOfHostFrame_0::_0, ::cyberPhysicalSystem::HostInstance::type_id, model));
		sp.add_operation(create_NavigateSingleAssociation(&NodeIpOfHostFrame_0::_0, &NodeIpOfHostFrame_0::_1, &::cyberPhysicalSystem::HostInstance::nodeIp));
		sp.add_operation(create_InstanceOfCheck(&NodeIpOfHostFrame_0::_0, ::cyberPhysicalSystem::HostInstance::type_id));
		
		return sp;
	}

};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__NODE_IP_OF_HOST_QUERY_SPECIFICATION_H_ */
