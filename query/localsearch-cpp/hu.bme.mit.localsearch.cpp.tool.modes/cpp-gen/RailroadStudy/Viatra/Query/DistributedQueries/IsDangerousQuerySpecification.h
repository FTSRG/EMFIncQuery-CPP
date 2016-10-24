#ifndef VIATRA__QUERY__DISTRIBUTED_QUERIES__IS_DANGEROUS_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__DISTRIBUTED_QUERIES__IS_DANGEROUS_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/DistributedQueries/DistributedQueriesQueryGroup.h"
#include "Viatra/Query/DistributedQueries/IsDangerousFrame_0.h"
#include "Viatra/Query/DistributedQueries/IsDangerousMatch.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace DistributedQueries {

template<class ModelRoot>
class IsDangerousMatcher;

template<class ModelRoot>
class IsDangerousQuerySpecification {
public:
	using Matcher = IsDangerousMatcher<ModelRoot>;
	using Match = IsDangerousMatch;
	using QueryGroup = DistributedQueriesQueryGroup;
						
	static ::Viatra::Query::Plan::SearchPlan<IsDangerousFrame_0> get_plan_unbound__0(const ModelRoot* model, std::map<int,IsDangerousFrame_0Vector>* subFrames = nullptr) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<IsDangerousFrame_0> sp;
		
		
		sp.add_operation(create_GlobalIterateOverInstances<IsDangerousFrame_0>(1, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&IsDangerousFrame_0::_0, ::railRoadModel::IRobotPart::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<IsDangerousFrame_0>(3, subFrames, &IsDangerousFrame_0::_0));
		sp.add_operation(create_NavigateMultiAssociation(&IsDangerousFrame_0::_0, &IsDangerousFrame_0::_1, &::railRoadModel::IRobotPart::nearBy));
		sp.add_operation(create_InstanceOfCheck(&IsDangerousFrame_0::_0, ::railRoadModel::IRobotPart::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&IsDangerousFrame_0::_1, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&IsDangerousFrame_0::_0, ::railRoadModel::IRobotPart::get_static_type_id()));
		
		return sp;
	}

};

} /* namespace DistributedQueries */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DISTRIBUTED_QUERIES__IS_DANGEROUS_QUERY_SPECIFICATION_H_ */
