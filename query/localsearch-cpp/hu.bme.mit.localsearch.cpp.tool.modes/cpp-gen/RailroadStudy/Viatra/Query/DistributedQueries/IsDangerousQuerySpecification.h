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
		sp.add_operation(create_LocalIterateOverInstances(&IsDangerousFrame_0::_1, ::railRoadModel::ITurnout::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<IsDangerousFrame_0>(3, subFrames, &IsDangerousFrame_0::_1));
		sp.add_operation(create_NavigateSingleAssociation(&IsDangerousFrame_0::_1, &IsDangerousFrame_0::_3, &::railRoadModel::ITurnout::get_currentState));
		sp.add_operation(create_InstanceOfCheck(&IsDangerousFrame_0::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&IsDangerousFrame_0::_3, ::railRoadModel::IFrozen::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&IsDangerousFrame_0::_1, ::railRoadModel::ITurnout::get_static_type_id()));
		sp.add_operation(create_GlobalIterateOverInstances<IsDangerousFrame_0>(8, subFrames));
		sp.add_operation(create_LocalIterateOverInstances(&IsDangerousFrame_0::_2, ::railRoadModel::ITrain::get_static_type_id(), model));
		sp.add_operation(create_DistributeIfNotPresent<IsDangerousFrame_0>(10, subFrames, &IsDangerousFrame_0::_2));
		sp.add_operation(create_NavigateSingleAssociation(&IsDangerousFrame_0::_2, &IsDangerousFrame_0::_0, &::railRoadModel::ITrain::get_currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&IsDangerousFrame_0::_2, ::railRoadModel::ITrain::get_static_type_id()));
		sp.add_operation(create_InstanceOfCheck(&IsDangerousFrame_0::_0, ::railRoadModel::ISegment::get_static_type_id()));
		sp.add_operation(create_DistributeIfNotPresent<IsDangerousFrame_0>(14, subFrames, &IsDangerousFrame_0::_0));
		sp.add_operation(create_MultiAssociationCheck(&IsDangerousFrame_0::_0, &IsDangerousFrame_0::_1, &::railRoadModel::ISegment::get_connectedTo));
		
		return sp;
	}

};

} /* namespace DistributedQueries */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DISTRIBUTED_QUERIES__IS_DANGEROUS_QUERY_SPECIFICATION_H_ */
