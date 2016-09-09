#ifndef VIATRA__QUERY__DERIVED_FEATURES__ASSIGNED_TO_CAMERA_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__DERIVED_FEATURES__ASSIGNED_TO_CAMERA_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/DerivedFeatures/AssignedToCameraFrame_0.h"
#include "Viatra/Query/DerivedFeatures/DerivedFeaturesQueryGroup.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace DerivedFeatures {

template<class ModelRoot>
class AssignedToCameraMatcher;

template<class ModelRoot>
class AssignedToCameraQuerySpecification {
public:
	using Matcher = AssignedToCameraMatcher<ModelRoot>;

	using QueryGroup = DerivedFeaturesQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<AssignedToCameraFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<AssignedToCameraFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&AssignedToCameraFrame_0::_0, ::PlatformModel::Camera::type_id, model));
		sp.add_operation(create_NavigateMultiAssociation(&AssignedToCameraFrame_0::_0, &AssignedToCameraFrame_0::_1, &::PlatformModel::Camera::responsibleFor));
		sp.add_operation(create_InstanceOfCheck(&AssignedToCameraFrame_0::_0, ::PlatformModel::Camera::type_id));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<AssignedToCameraFrame_0> get_plan_seg__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<AssignedToCameraFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&AssignedToCameraFrame_0::_0, ::PlatformModel::Camera::type_id, model));
		sp.add_operation(create_MultiAssociationCheck(&AssignedToCameraFrame_0::_0, &AssignedToCameraFrame_0::_1, &::PlatformModel::Camera::responsibleFor));
		
		return sp;
	}

};

} /* namespace DerivedFeatures */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED_FEATURES__ASSIGNED_TO_CAMERA_QUERY_SPECIFICATION_H_ */
