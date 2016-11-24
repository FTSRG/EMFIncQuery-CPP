#ifndef VIATRA__QUERY__SAFETYLOGIC__NOT_NULL_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__SAFETYLOGIC__NOT_NULL_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Safetylogic/NotNullFrame_0.h"
#include "Viatra/Query/Safetylogic/NotNullMatch.h"
#include "Viatra/Query/Safetylogic/SafetylogicQueryGroup.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {

template<class ModelRoot>
class NotNullMatcher;

template<class ModelRoot>
class NotNullQuerySpecification {
public:
	using Matcher = NotNullMatcher<ModelRoot>;
	using Match = NotNullMatch;
	using QueryGroup = SafetylogicQueryGroup;
						
	static ::Viatra::Query::Plan::SearchPlan<NotNullFrame_0> get_plan_unbound__0(const ModelRoot* model, std::map<int,NotNullFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<NotNullFrame_0> sp;
		
		
		sp.add_operation(create_GlobalIterateOverInstances<NotNullFrame_0>(1, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&NotNullFrame_0::_0, ::railRoadModel::IRailRoadElement::get_static_type_id(), model));
		sp.add_operation(create_InstanceOfCheck(&NotNullFrame_0::_0, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<NotNullFrame_0> get_plan_Old__0(const ModelRoot* model, std::map<int,NotNullFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<NotNullFrame_0> sp;
		
		
		sp.add_operation(create_InstanceOfCheck(&NotNullFrame_0::_0, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&NotNullFrame_0::_0, ::railRoadModel::IRailRoadElement::get_static_type_id()));
		
		return sp;
	}

};

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__NOT_NULL_QUERY_SPECIFICATION_H_ */
