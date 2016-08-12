#ifndef VIATRA__QUERY__CPSQUERY__NOT_ALLOCATED_BUT_RUNNING_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPSQUERY__NOT_ALLOCATED_BUT_RUNNING_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/Cpsquery/AllocatedApplicationMatcher.h"
#include "Viatra/Query/Cpsquery/CpsqueryQueryGroup.h"
#include "Viatra/Query/Cpsquery/NotAllocatedButRunningFrame_0.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class NotAllocatedButRunningMatcher;

template<class ModelRoot>
class NotAllocatedButRunningQuerySpecification {
public:
	using Matcher = NotAllocatedButRunningMatcher<ModelRoot>;

	using QueryGroup = CpsqueryQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<NotAllocatedButRunningFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<NotAllocatedButRunningFrame_0> sp;
		
		AllocatedApplicationMatcher<ModelRoot> matcher_1513934283(model,  CpsqueryQueryGroup::instance()->context());
		
		sp.add_operation(create_ConstantValueExtend(&NotAllocatedButRunningFrame_0::_1, ::cyberPhysicalSystem::AppState::Running));
		sp.add_operation(create_IterateOverInstances(&NotAllocatedButRunningFrame_0::_0, ::cyberPhysicalSystem::ApplicationInstance::type_id, model));
		sp.add_operation(create_InstanceOfCheck(&NotAllocatedButRunningFrame_0::_0, ::cyberPhysicalSystem::ApplicationInstance::type_id));
		sp.add_operation(create_SingleAssociationCheck(&NotAllocatedButRunningFrame_0::_0, &NotAllocatedButRunningFrame_0::_1, &::cyberPhysicalSystem::ApplicationInstance::state));
		sp.add_operation(create_NACOperation<NotAllocatedButRunningFrame_0>(matcher_1513934283, &NotAllocatedButRunningFrame_0::_0));
		
		return sp;
	}

};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__NOT_ALLOCATED_BUT_RUNNING_QUERY_SPECIFICATION_H_ */
