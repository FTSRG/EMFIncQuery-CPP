#ifndef VIATRA__QUERY__DEPLOYMENT__I_DERIVED_EXECUTES_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__DEPLOYMENT__I_DERIVED_EXECUTES_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/Deployment/DeploymentQueryGroup.h"
#include "Viatra/Query/Deployment/IDerivedExecutesFrame_0.h"
#include "Viatra/Query/Deployment/IDerivedExecutesFrame_1.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Deployment {

template<class ModelRoot>
class IDerivedExecutesMatcher;

template<class ModelRoot>
class IDerivedExecutesQuerySpecification {
public:
	using Matcher = IDerivedExecutesMatcher<ModelRoot>;

	using QueryGroup = DeploymentQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<IDerivedExecutesFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<IDerivedExecutesFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&IDerivedExecutesFrame_0::_0, ::PlatformModel::Node::type_id, model));
		sp.add_operation(create_InstanceOfCheck(&IDerivedExecutesFrame_0::_0, ::PlatformModel::Node::type_id));
		sp.add_operation(create_NavigateMultiAssociation(&IDerivedExecutesFrame_0::_0, &IDerivedExecutesFrame_0::_4, &::PlatformModel::Node::executes));
		sp.add_operation(create_NavigateSingleAssociation(&IDerivedExecutesFrame_0::_0, &IDerivedExecutesFrame_0::_1, &::PlatformModel::Node::id));
		sp.add_operation(create_IterateOverInstances(&IDerivedExecutesFrame_0::_2, ::RailRoadModel::Train::type_id, model));
		sp.add_operation(create_NavigateSingleAssociation(&IDerivedExecutesFrame_0::_2, &IDerivedExecutesFrame_0::_3, &::RailRoadModel::Train::id));
		sp.add_operation(create_InstanceOfCheck(&IDerivedExecutesFrame_0::_2, ::RailRoadModel::Train::type_id));
		sp.add_operation(create_SingleAssociationCheck(&IDerivedExecutesFrame_0::_2, &IDerivedExecutesFrame_0::_4, &::RailRoadModel::Train::currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&IDerivedExecutesFrame_0::_2, ::RailRoadModel::Train::type_id));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<IDerivedExecutesFrame_1> get_plan_unbound__1(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<IDerivedExecutesFrame_1> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&IDerivedExecutesFrame_1::_0, ::PlatformModel::Node::type_id, model));
		sp.add_operation(create_InstanceOfCheck(&IDerivedExecutesFrame_1::_0, ::PlatformModel::Node::type_id));
		sp.add_operation(create_NavigateSingleAssociation(&IDerivedExecutesFrame_1::_0, &IDerivedExecutesFrame_1::_1, &::PlatformModel::Node::id));
		sp.add_operation(create_IterateOverInstances(&IDerivedExecutesFrame_1::_5, ::RailRoadModel::Segment::type_id, model));
		sp.add_operation(create_NavigateMultiAssociation(&IDerivedExecutesFrame_1::_5, &IDerivedExecutesFrame_1::_4, &::RailRoadModel::Segment::connectedTo));
		sp.add_operation(create_MultiAssociationCheck(&IDerivedExecutesFrame_1::_0, &IDerivedExecutesFrame_1::_5, &::PlatformModel::Node::executes));
		sp.add_operation(create_InstanceOfCheck(&IDerivedExecutesFrame_1::_5, ::RailRoadModel::Segment::type_id));
		sp.add_operation(create_IterateOverInstances(&IDerivedExecutesFrame_1::_2, ::RailRoadModel::Train::type_id, model));
		sp.add_operation(create_NavigateSingleAssociation(&IDerivedExecutesFrame_1::_2, &IDerivedExecutesFrame_1::_3, &::RailRoadModel::Train::id));
		sp.add_operation(create_InstanceOfCheck(&IDerivedExecutesFrame_1::_2, ::RailRoadModel::Train::type_id));
		sp.add_operation(create_SingleAssociationCheck(&IDerivedExecutesFrame_1::_2, &IDerivedExecutesFrame_1::_4, &::RailRoadModel::Train::currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&IDerivedExecutesFrame_1::_2, ::RailRoadModel::Train::type_id));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<IDerivedExecutesFrame_0> get_plan_nodeID__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<IDerivedExecutesFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&IDerivedExecutesFrame_0::_0, ::PlatformModel::Node::type_id, model));
		sp.add_operation(create_InstanceOfCheck(&IDerivedExecutesFrame_0::_0, ::PlatformModel::Node::type_id));
		sp.add_operation(create_SingleAssociationCheck(&IDerivedExecutesFrame_0::_0, &IDerivedExecutesFrame_0::_1, &::PlatformModel::Node::id));
		sp.add_operation(create_NavigateMultiAssociation(&IDerivedExecutesFrame_0::_0, &IDerivedExecutesFrame_0::_4, &::PlatformModel::Node::executes));
		sp.add_operation(create_IterateOverInstances(&IDerivedExecutesFrame_0::_2, ::RailRoadModel::Train::type_id, model));
		sp.add_operation(create_NavigateSingleAssociation(&IDerivedExecutesFrame_0::_2, &IDerivedExecutesFrame_0::_3, &::RailRoadModel::Train::id));
		sp.add_operation(create_InstanceOfCheck(&IDerivedExecutesFrame_0::_2, ::RailRoadModel::Train::type_id));
		sp.add_operation(create_SingleAssociationCheck(&IDerivedExecutesFrame_0::_2, &IDerivedExecutesFrame_0::_4, &::RailRoadModel::Train::currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&IDerivedExecutesFrame_0::_2, ::RailRoadModel::Train::type_id));
		
		return sp;
	}
	static ::Viatra::Query::Plan::SearchPlan<IDerivedExecutesFrame_1> get_plan_nodeID__1(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<IDerivedExecutesFrame_1> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&IDerivedExecutesFrame_1::_0, ::PlatformModel::Node::type_id, model));
		sp.add_operation(create_InstanceOfCheck(&IDerivedExecutesFrame_1::_0, ::PlatformModel::Node::type_id));
		sp.add_operation(create_SingleAssociationCheck(&IDerivedExecutesFrame_1::_0, &IDerivedExecutesFrame_1::_1, &::PlatformModel::Node::id));
		sp.add_operation(create_IterateOverInstances(&IDerivedExecutesFrame_1::_5, ::RailRoadModel::Segment::type_id, model));
		sp.add_operation(create_NavigateMultiAssociation(&IDerivedExecutesFrame_1::_5, &IDerivedExecutesFrame_1::_4, &::RailRoadModel::Segment::connectedTo));
		sp.add_operation(create_MultiAssociationCheck(&IDerivedExecutesFrame_1::_0, &IDerivedExecutesFrame_1::_5, &::PlatformModel::Node::executes));
		sp.add_operation(create_InstanceOfCheck(&IDerivedExecutesFrame_1::_5, ::RailRoadModel::Segment::type_id));
		sp.add_operation(create_IterateOverInstances(&IDerivedExecutesFrame_1::_2, ::RailRoadModel::Train::type_id, model));
		sp.add_operation(create_NavigateSingleAssociation(&IDerivedExecutesFrame_1::_2, &IDerivedExecutesFrame_1::_3, &::RailRoadModel::Train::id));
		sp.add_operation(create_InstanceOfCheck(&IDerivedExecutesFrame_1::_2, ::RailRoadModel::Train::type_id));
		sp.add_operation(create_SingleAssociationCheck(&IDerivedExecutesFrame_1::_2, &IDerivedExecutesFrame_1::_4, &::RailRoadModel::Train::currentlyOn));
		sp.add_operation(create_InstanceOfCheck(&IDerivedExecutesFrame_1::_2, ::RailRoadModel::Train::type_id));
		
		return sp;
	}

};

} /* namespace Deployment */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DEPLOYMENT__I_DERIVED_EXECUTES_QUERY_SPECIFICATION_H_ */
