#ifndef VIATRA__QUERY__CPSQUERY__NODE_IP_IS_NOT_UNIQUE_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPSQUERY__NODE_IP_IS_NOT_UNIQUE_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/Cpsquery/CpsqueryQueryGroup.h"
#include "Viatra/Query/Cpsquery/NodeIpIsNotUniqueFrame_0.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class NodeIpIsNotUniqueMatcher;

template<class ModelRoot>
class NodeIpIsNotUniqueQuerySpecification {
public:
	using Matcher = NodeIpIsNotUniqueMatcher<ModelRoot>;

	using QueryGroup = CpsqueryQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<NodeIpIsNotUniqueFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<NodeIpIsNotUniqueFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&NodeIpIsNotUniqueFrame_0::_0, ::cyberPhysicalSystem::HostInstance::type_id, model));
		sp.add_operation(create_NavigateSingleAssociation(&NodeIpIsNotUniqueFrame_0::_0, &NodeIpIsNotUniqueFrame_0::_2, &::cyberPhysicalSystem::HostInstance::nodeIp));
		sp.add_operation(create_InstanceOfCheck(&NodeIpIsNotUniqueFrame_0::_0, ::cyberPhysicalSystem::HostInstance::type_id));
		sp.add_operation(create_IterateOverInstances(&NodeIpIsNotUniqueFrame_0::_1, ::cyberPhysicalSystem::HostInstance::type_id, model));
		sp.add_operation(create_SingleAssociationCheck(&NodeIpIsNotUniqueFrame_0::_1, &NodeIpIsNotUniqueFrame_0::_2, &::cyberPhysicalSystem::HostInstance::nodeIp));
		sp.add_operation(create_InequalityCheck(&NodeIpIsNotUniqueFrame_0::_0, &NodeIpIsNotUniqueFrame_0::_1));
		
		return sp;
	}

};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__NODE_IP_IS_NOT_UNIQUE_QUERY_SPECIFICATION_H_ */
