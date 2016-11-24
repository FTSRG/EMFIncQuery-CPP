#ifndef VIATRA__QUERY__SAFETYLOGIC__SHOULD_COLLIDE_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__SAFETYLOGIC__SHOULD_COLLIDE_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Safetylogic/SafetylogicQueryGroup.h"
#include "Viatra/Query/Safetylogic/ShouldCollideFrame_0.h"
#include "Viatra/Query/Safetylogic/ShouldCollideMatch.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {

template<class ModelRoot>
class ShouldCollideMatcher;

template<class ModelRoot>
class ShouldCollideQuerySpecification {
public:
	using Matcher = ShouldCollideMatcher<ModelRoot>;
	using Match = ShouldCollideMatch;
	using QueryGroup = SafetylogicQueryGroup;
						
	static ::Viatra::Query::Plan::SearchPlan<ShouldCollideFrame_0> get_plan_unbound__0(const ModelRoot* model, std::map<int,ShouldCollideFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<ShouldCollideFrame_0> sp;
		
		
		sp.add_operation(create_GlobalIterateOverInstances<ShouldCollideFrame_0>(1, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&ShouldCollideFrame_0::_0, ::railRoadModel::IRobotPart::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<ShouldCollideFrame_0>(3, subFrames, &ShouldCollideFrame_0::_0));
		sp.add_operation(create_NavigateMultiAssociation(&ShouldCollideFrame_0::_0, &ShouldCollideFrame_0::_1, &::railRoadModel::IRobotPart::get_nearBy));
		sp.add_operation(create_InstanceOfCheck(&ShouldCollideFrame_0::_0, ::railRoadModel::IRobotPart::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ShouldCollideFrame_0::_1, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&ShouldCollideFrame_0::_0, ::railRoadModel::IRobotPart::get_static_type_id()));
		
		return sp;
	}

};

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__SHOULD_COLLIDE_QUERY_SPECIFICATION_H_ */
