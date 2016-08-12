#ifndef VIATRA__QUERY__CPSQUERY__IDENTIFIABLE_ID_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPSQUERY__IDENTIFIABLE_ID_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/Cpsquery/CpsqueryQueryGroup.h"
#include "Viatra/Query/Cpsquery/IdentifiableIdFrame_0.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class IdentifiableIdMatcher;

template<class ModelRoot>
class IdentifiableIdQuerySpecification {
public:
	using Matcher = IdentifiableIdMatcher<ModelRoot>;

	using QueryGroup = CpsqueryQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<IdentifiableIdFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<IdentifiableIdFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&IdentifiableIdFrame_0::_0, ::cyberPhysicalSystem::Identifiable::type_id, model));
		sp.add_operation(create_NavigateSingleAssociation(&IdentifiableIdFrame_0::_0, &IdentifiableIdFrame_0::_1, &::cyberPhysicalSystem::Identifiable::identifier));
		sp.add_operation(create_InstanceOfCheck(&IdentifiableIdFrame_0::_0, ::cyberPhysicalSystem::Identifiable::type_id));
		
		return sp;
	}

};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__IDENTIFIABLE_ID_QUERY_SPECIFICATION_H_ */
