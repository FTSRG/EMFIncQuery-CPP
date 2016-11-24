#ifndef VIATRA__QUERY__SNCL_RUNTIME__LINKED_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__SNCL_RUNTIME__LINKED_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Sncl_runtime/LinkedFrame_0.h"
#include "Viatra/Query/Sncl_runtime/LinkedFrame_1.h"
#include "Viatra/Query/Sncl_runtime/LinkedMatch.h"
#include "Viatra/Query/Sncl_runtime/Sncl_runtimeQueryGroup.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

template<class ModelRoot>
class LinkedMatcher;

template<class ModelRoot>
class LinkedQuerySpecification {
public:
	using Matcher = LinkedMatcher<ModelRoot>;
	using Match = LinkedMatch;
	using QueryGroup = Sncl_runtimeQueryGroup;
						
	static ::Viatra::Query::Plan::SearchPlan<LinkedFrame_0> get_plan_S1__0(const ModelRoot* model, std::map<int,LinkedFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<LinkedFrame_0> sp;
		
		
		sp.add_operation(create_InstanceOfCheck(&LinkedFrame_0::_0, ::arch::ISN::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<LinkedFrame_0>(2, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&LinkedFrame_0::_1, ::arch::ISN::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<LinkedFrame_0>(4, subFrames, &LinkedFrame_0::_1));
		sp.add_operation(create_MultiAssociationCheck(&LinkedFrame_0::_1, &LinkedFrame_0::_0, &::arch::ISN::get_link));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<LinkedFrame_1> get_plan_S1__1(const ModelRoot* model, std::map<int,LinkedFrame_1Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<LinkedFrame_1> sp;
		
		
		sp.add_operation(create_InstanceOfCheck(&LinkedFrame_1::_0, ::arch::ISN::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<LinkedFrame_1>(2, subFrames, &LinkedFrame_1::_0));
		sp.add_operation(create_NavigateMultiAssociation(&LinkedFrame_1::_0, &LinkedFrame_1::_1, &::arch::ISN::get_link));
		sp.add_operation(create_InstanceOfCheck(&LinkedFrame_1::_1, ::arch::ISN::get_static_type_id()));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<LinkedFrame_0> get_plan_unbound__0(const ModelRoot* model, std::map<int,LinkedFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<LinkedFrame_0> sp;
		
		
		sp.add_operation(create_GlobalIterateOverInstances<LinkedFrame_0>(1, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&LinkedFrame_0::_1, ::arch::ISN::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<LinkedFrame_0>(3, subFrames, &LinkedFrame_0::_1));
		sp.add_operation(create_NavigateMultiAssociation(&LinkedFrame_0::_1, &LinkedFrame_0::_0, &::arch::ISN::get_link));
		sp.add_operation(create_InstanceOfCheck(&LinkedFrame_0::_0, ::arch::ISN::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&LinkedFrame_0::_1, ::arch::ISN::get_static_type_id()));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<LinkedFrame_1> get_plan_unbound__1(const ModelRoot* model, std::map<int,LinkedFrame_1Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<LinkedFrame_1> sp;
		
		
		sp.add_operation(create_GlobalIterateOverInstances<LinkedFrame_1>(1, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&LinkedFrame_1::_0, ::arch::ISN::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<LinkedFrame_1>(3, subFrames, &LinkedFrame_1::_0));
		sp.add_operation(create_NavigateMultiAssociation(&LinkedFrame_1::_0, &LinkedFrame_1::_1, &::arch::ISN::get_link));
		sp.add_operation(create_InstanceOfCheck(&LinkedFrame_1::_1, ::arch::ISN::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&LinkedFrame_1::_0, ::arch::ISN::get_static_type_id()));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<LinkedFrame_0> get_plan_S1_S2__0(const ModelRoot* model, std::map<int,LinkedFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<LinkedFrame_0> sp;
		
		
		sp.add_operation(create_InstanceOfCheck(&LinkedFrame_0::_1, ::arch::ISN::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&LinkedFrame_0::_0, ::arch::ISN::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<LinkedFrame_0>(3, subFrames, &LinkedFrame_0::_0));
		sp.add_operation(create_MultiAssociationCheck(&LinkedFrame_0::_0, &LinkedFrame_0::_1, &::arch::ISN::get_link));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<LinkedFrame_1> get_plan_S1_S2__1(const ModelRoot* model, std::map<int,LinkedFrame_1Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<LinkedFrame_1> sp;
		
		
		sp.add_operation(create_InstanceOfCheck(&LinkedFrame_1::_0, ::arch::ISN::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&LinkedFrame_1::_1, ::arch::ISN::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<LinkedFrame_1>(3, subFrames, &LinkedFrame_1::_1));
		sp.add_operation(create_MultiAssociationCheck(&LinkedFrame_1::_1, &LinkedFrame_1::_0, &::arch::ISN::get_link));
		
		return sp;
	}

};

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__LINKED_QUERY_SPECIFICATION_H_ */
