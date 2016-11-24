#ifndef VIATRA__QUERY__SNCL_RUNTIME__PCONNECTED_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__SNCL_RUNTIME__PCONNECTED_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Sncl_runtime/LinkedMatcher.h"
#include "Viatra/Query/Sncl_runtime/PconnectedFrame_0.h"
#include "Viatra/Query/Sncl_runtime/PconnectedFrame_1.h"
#include "Viatra/Query/Sncl_runtime/PconnectedMatch.h"
#include "Viatra/Query/Sncl_runtime/Sncl_runtimeQueryGroup.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

template<class ModelRoot>
class PconnectedMatcher;

template<class ModelRoot>
class PconnectedQuerySpecification {
public:
	using Matcher = PconnectedMatcher<ModelRoot>;
	using Match = PconnectedMatch;
	using QueryGroup = Sncl_runtimeQueryGroup;
						
	static ::Viatra::Query::Plan::SearchPlan<PconnectedFrame_0> get_plan_C1__0(const ModelRoot* model, std::map<int,PconnectedFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<PconnectedFrame_0> sp;
		
		LinkedMatcher<ModelRoot> matcher_952816656(model,  Sncl_runtimeQueryGroup::instance()->context());
		
		sp.add_operation(create_InstanceOfCheck(&PconnectedFrame_0::_0, ::arch::ICL::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<PconnectedFrame_0>(2, subFrames, &PconnectedFrame_0::_0));
		sp.add_operation(create_NavigateSingleAssociation(&PconnectedFrame_0::_0, &PconnectedFrame_0::_2, &::arch::ICL::get_cnn));
		sp.add_operation(create_GlobalIterateOverInstances<PconnectedFrame_0>(4, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&PconnectedFrame_0::_1, ::arch::ICL::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<PconnectedFrame_0>(6, subFrames, &PconnectedFrame_0::_1));
		sp.add_operation(create_NavigateSingleAssociation(&PconnectedFrame_0::_1, &PconnectedFrame_0::_3, &::arch::ICL::get_cnn));
		sp.add_operation(create_InstanceOfCheck(&PconnectedFrame_0::_1, ::arch::ICL::get_static_type_id()));
		sp.add_operation(create_TransitiveClosureCheck(matcher_952816656, &PconnectedFrame_0::_2, &PconnectedFrame_0::_3, &LinkedMatch::S2));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<PconnectedFrame_1> get_plan_C1__1(const ModelRoot* model, std::map<int,PconnectedFrame_1Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<PconnectedFrame_1> sp;
		
		
		sp.add_operation(create_InstanceOfCheck(&PconnectedFrame_1::_0, ::arch::ICL::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<PconnectedFrame_1>(2, subFrames, &PconnectedFrame_1::_0));
		sp.add_operation(create_NavigateSingleAssociation(&PconnectedFrame_1::_0, &PconnectedFrame_1::_2, &::arch::ICL::get_cnn));
		sp.add_operation(create_InstanceOfCheck(&PconnectedFrame_1::_2, ::arch::ISN::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<PconnectedFrame_1>(5, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&PconnectedFrame_1::_1, ::arch::ICL::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<PconnectedFrame_1>(7, subFrames, &PconnectedFrame_1::_1));
		sp.add_operation(create_SingleAssociationCheck(&PconnectedFrame_1::_1, &PconnectedFrame_1::_2, &::arch::ICL::get_cnn));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<PconnectedFrame_0> get_plan_unbound__0(const ModelRoot* model, std::map<int,PconnectedFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<PconnectedFrame_0> sp;
		
		
		sp.add_operation(create_GlobalIterateOverInstances<PconnectedFrame_0>(1, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&PconnectedFrame_0::_0, ::arch::ICL::get_static_type_id(), model));
		sp.add_operation(create_GlobalIterateOverInstances<PconnectedFrame_0>(3, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&PconnectedFrame_0::_1, ::arch::ICL::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<PconnectedFrame_0>(5, subFrames, &PconnectedFrame_0::_1));
		sp.add_operation(create_NavigateSingleAssociation(&PconnectedFrame_0::_1, &PconnectedFrame_0::_2, &::arch::ICL::get_cnn));
		sp.add_operation(create_InstanceOfCheck(&PconnectedFrame_0::_2, ::arch::ISN::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<PconnectedFrame_0>(8, subFrames, &PconnectedFrame_0::_0));
		sp.add_operation(create_SingleAssociationCheck(&PconnectedFrame_0::_0, &PconnectedFrame_0::_2, &::arch::ICL::get_cnn));
		sp.add_operation(create_InstanceOfCheck(&PconnectedFrame_0::_1, ::arch::ICL::get_static_type_id()));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<PconnectedFrame_1> get_plan_unbound__1(const ModelRoot* model, std::map<int,PconnectedFrame_1Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<PconnectedFrame_1> sp;
		
		LinkedMatcher<ModelRoot> matcher_2112211521(model,  Sncl_runtimeQueryGroup::instance()->context());
		
		sp.add_operation(create_GlobalIterateOverInstances<PconnectedFrame_1>(1, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&PconnectedFrame_1::_0, ::arch::ICL::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<PconnectedFrame_1>(3, subFrames, &PconnectedFrame_1::_0));
		sp.add_operation(create_NavigateSingleAssociation(&PconnectedFrame_1::_0, &PconnectedFrame_1::_2, &::arch::ICL::get_cnn));
		sp.add_operation(create_InstanceOfCheck(&PconnectedFrame_1::_0, ::arch::ICL::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<PconnectedFrame_1>(6, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&PconnectedFrame_1::_1, ::arch::ICL::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<PconnectedFrame_1>(8, subFrames, &PconnectedFrame_1::_1));
		sp.add_operation(create_NavigateSingleAssociation(&PconnectedFrame_1::_1, &PconnectedFrame_1::_3, &::arch::ICL::get_cnn));
		sp.add_operation(create_InstanceOfCheck(&PconnectedFrame_1::_1, ::arch::ICL::get_static_type_id()));
		sp.add_operation(create_TransitiveClosureCheck(matcher_2112211521, &PconnectedFrame_1::_2, &PconnectedFrame_1::_3, &LinkedMatch::S2));
		
		return sp;
	}

};

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__PCONNECTED_QUERY_SPECIFICATION_H_ */
