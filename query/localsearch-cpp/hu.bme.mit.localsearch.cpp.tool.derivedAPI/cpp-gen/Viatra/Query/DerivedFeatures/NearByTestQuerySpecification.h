#ifndef VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_TEST_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_TEST_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/DerivedFeatures/DerivedFeaturesQueryGroup.h"
#include "Viatra/Query/DerivedFeatures/NearByTestFrame_0.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace DerivedFeatures {

template<class ModelRoot>
class NearByTestMatcher;

template<class ModelRoot>
class NearByTestQuerySpecification {
public:
	using Matcher = NearByTestMatcher<ModelRoot>;

	using QueryGroup = DerivedFeaturesQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<NearByTestFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<NearByTestFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&NearByTestFrame_0::_0, ::RailRoadModel::RobotPart::type_id, model));
		sp.add_operation(create_NavigateMultiAssociation(&NearByTestFrame_0::_0, &NearByTestFrame_0::_1, &::RailRoadModel::RobotPart::nearBy));
		sp.add_operation(create_InstanceOfCheck(&NearByTestFrame_0::_0, ::RailRoadModel::RobotPart::type_id));
		
		return sp;
	}

};

} /* namespace DerivedFeatures */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_TEST_QUERY_SPECIFICATION_H_ */
