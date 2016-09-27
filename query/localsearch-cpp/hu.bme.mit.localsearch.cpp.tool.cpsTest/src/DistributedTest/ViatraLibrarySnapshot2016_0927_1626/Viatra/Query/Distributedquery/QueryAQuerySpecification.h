#ifndef VIATRA__QUERY__DISTRIBUTEDQUERY__QUERY_A_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__DISTRIBUTEDQUERY__QUERY_A_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/Distributedquery/DistributedqueryQueryGroup.h"
#include "Viatra/Query/Distributedquery/QueryAFrame_0.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Distributedquery {

template<class ModelRoot>
class QueryAMatcher;

template<class ModelRoot>
class QueryAQuerySpecification {
public:
	using Matcher = QueryAMatcher<ModelRoot>;

	using QueryGroup = DistributedqueryQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<QueryAFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<QueryAFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&QueryAFrame_0::_0, ::cyberPhysicalSystem::IHostInstance::get_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&QueryAFrame_0::_0, ::cyberPhysicalSystem::IHostInstance::get_type_id()));
		sp.add_operation(create_IterateOverInstances(&QueryAFrame_0::_5, ::cyberPhysicalSystem::IApplicationInstance::get_type_id(), model));
		sp.add_operation(create_NavigateSingleAssociation(&QueryAFrame_0::_5, &QueryAFrame_0::_1, &::cyberPhysicalSystem::IApplicationInstance::dbPassword));
		sp.add_operation(create_InstanceOfCheck(&QueryAFrame_0::_5, ::cyberPhysicalSystem::IApplicationInstance::get_type_id()));
		sp.add_operation(create_InstanceOfCheck(&QueryAFrame_0::_5, ::cyberPhysicalSystem::IApplicationInstance::get_type_id()));
		sp.add_operation(create_InstanceOfCheck(&QueryAFrame_0::_5, ::cyberPhysicalSystem::IApplicationInstance::get_type_id()));
		sp.add_operation(create_SingleAssociationCheck(&QueryAFrame_0::_5, &QueryAFrame_0::_0, &::cyberPhysicalSystem::IApplicationInstance::allocatedTo));
		sp.add_operation(create_IterateOverInstances(&QueryAFrame_0::_4, ::cyberPhysicalSystem::IApplicationInstance::get_type_id(), model));
		sp.add_operation(create_NavigateSingleAssociation(&QueryAFrame_0::_4, &QueryAFrame_0::_3, &::cyberPhysicalSystem::IApplicationInstance::allocatedTo));
		sp.add_operation(create_MultiAssociationCheck(&QueryAFrame_0::_0, &QueryAFrame_0::_3, &::cyberPhysicalSystem::IHostInstance::communicateWith));
		sp.add_operation(create_InstanceOfCheck(&QueryAFrame_0::_4, ::cyberPhysicalSystem::IApplicationInstance::get_type_id()));
		sp.add_operation(create_NavigateSingleAssociation(&QueryAFrame_0::_5, &QueryAFrame_0::_2, &::cyberPhysicalSystem::IApplicationInstance::state));
		
		return sp;
	}

};

} /* namespace Distributedquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DISTRIBUTEDQUERY__QUERY_A_QUERY_SPECIFICATION_H_ */
