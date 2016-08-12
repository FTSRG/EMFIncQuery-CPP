#ifndef VIATRA__QUERY__CPSQUERY__ID_IS_NOT_UNIQUE_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPSQUERY__ID_IS_NOT_UNIQUE_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/Cpsquery/CpsqueryQueryGroup.h"
#include "Viatra/Query/Cpsquery/IdIsNotUniqueFrame_0.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class IdIsNotUniqueMatcher;

template<class ModelRoot>
class IdIsNotUniqueQuerySpecification {
public:
	using Matcher = IdIsNotUniqueMatcher<ModelRoot>;

	using QueryGroup = CpsqueryQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<IdIsNotUniqueFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<IdIsNotUniqueFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&IdIsNotUniqueFrame_0::_2, ::cyberPhysicalSystem::Identifiable::type_id, model));
		sp.add_operation(create_NavigateSingleAssociation(&IdIsNotUniqueFrame_0::_2, &IdIsNotUniqueFrame_0::_1, &::cyberPhysicalSystem::Identifiable::identifier));
		sp.add_operation(create_InstanceOfCheck(&IdIsNotUniqueFrame_0::_2, ::cyberPhysicalSystem::Identifiable::type_id));
		sp.add_operation(create_IterateOverInstances(&IdIsNotUniqueFrame_0::_0, ::cyberPhysicalSystem::Identifiable::type_id, model));
		sp.add_operation(create_SingleAssociationCheck(&IdIsNotUniqueFrame_0::_0, &IdIsNotUniqueFrame_0::_1, &::cyberPhysicalSystem::Identifiable::identifier));
		sp.add_operation(create_InequalityCheck(&IdIsNotUniqueFrame_0::_0, &IdIsNotUniqueFrame_0::_2));
		
		return sp;
	}

};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__ID_IS_NOT_UNIQUE_QUERY_SPECIFICATION_H_ */
