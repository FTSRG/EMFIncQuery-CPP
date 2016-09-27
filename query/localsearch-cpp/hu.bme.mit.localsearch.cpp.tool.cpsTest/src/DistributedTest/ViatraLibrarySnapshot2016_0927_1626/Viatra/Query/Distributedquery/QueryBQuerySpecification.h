#ifndef VIATRA__QUERY__DISTRIBUTEDQUERY__QUERY_B_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__DISTRIBUTEDQUERY__QUERY_B_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/Distributedquery/DistributedqueryQueryGroup.h"
#include "Viatra/Query/Distributedquery/QueryBFrame_0.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Distributedquery {

template<class ModelRoot>
class QueryBMatcher;

template<class ModelRoot>
class QueryBQuerySpecification {
public:
	using Matcher = QueryBMatcher<ModelRoot>;

	using QueryGroup = DistributedqueryQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<QueryBFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<QueryBFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&QueryBFrame_0::_0, ::cyberPhysicalSystem::IApplicationInstance::get_type_id(), model));
		sp.add_operation(create_NavigateSingleAssociation(&QueryBFrame_0::_0, &QueryBFrame_0::_1, &::cyberPhysicalSystem::IApplicationInstance::allocatedTo));
		sp.add_operation(create_InstanceOfCheck(&QueryBFrame_0::_0, ::cyberPhysicalSystem::IApplicationInstance::get_type_id()));
		
		return sp;
	}

};

} /* namespace Distributedquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DISTRIBUTEDQUERY__QUERY_B_QUERY_SPECIFICATION_H_ */
