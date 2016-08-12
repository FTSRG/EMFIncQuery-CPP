#ifndef VIATRA__QUERY__CPSQUERY__ALLOCATED_APPLICATION_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPSQUERY__ALLOCATED_APPLICATION_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/Cpsquery/AllocatedApplicationFrame_0.h"
#include "Viatra/Query/Cpsquery/CpsqueryQueryGroup.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class AllocatedApplicationMatcher;

template<class ModelRoot>
class AllocatedApplicationQuerySpecification {
public:
	using Matcher = AllocatedApplicationMatcher<ModelRoot>;

	using QueryGroup = CpsqueryQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<AllocatedApplicationFrame_0> get_plan_app__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<AllocatedApplicationFrame_0> sp;
		
		
		sp.add_operation(create_InstanceOfCheck(&AllocatedApplicationFrame_0::_0, ::cyberPhysicalSystem::ApplicationInstance::type_id));
		sp.add_operation(create_InstanceOfCheck(&AllocatedApplicationFrame_0::_0, ::cyberPhysicalSystem::ApplicationInstance::type_id));
		sp.add_operation(create_NavigateSingleAssociation(&AllocatedApplicationFrame_0::_0, &AllocatedApplicationFrame_0::_1, &::cyberPhysicalSystem::ApplicationInstance::allocatedTo));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<AllocatedApplicationFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<AllocatedApplicationFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&AllocatedApplicationFrame_0::_0, ::cyberPhysicalSystem::ApplicationInstance::type_id, model));
		sp.add_operation(create_InstanceOfCheck(&AllocatedApplicationFrame_0::_0, ::cyberPhysicalSystem::ApplicationInstance::type_id));
		sp.add_operation(create_NavigateSingleAssociation(&AllocatedApplicationFrame_0::_0, &AllocatedApplicationFrame_0::_1, &::cyberPhysicalSystem::ApplicationInstance::allocatedTo));
		
		return sp;
	}

};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__ALLOCATED_APPLICATION_QUERY_SPECIFICATION_H_ */
