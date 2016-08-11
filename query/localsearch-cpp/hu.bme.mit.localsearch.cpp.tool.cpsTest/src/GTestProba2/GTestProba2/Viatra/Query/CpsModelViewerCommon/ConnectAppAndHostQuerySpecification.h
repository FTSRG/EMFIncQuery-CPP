#ifndef VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__CONNECT_APP_AND_HOST_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__CONNECT_APP_AND_HOST_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/CpsModelViewerCommon/ConnectAppAndHostFrame_0.h"
#include "Viatra/Query/CpsModelViewerCommon/CpsModelViewerCommonQueryGroup.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace CpsModelViewerCommon {

template<class ModelRoot>
class ConnectAppAndHostMatcher;

template<class ModelRoot>
class ConnectAppAndHostQuerySpecification {
public:
	using Matcher = ConnectAppAndHostMatcher<ModelRoot>;

	using QueryGroup = CpsModelViewerCommonQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<ConnectAppAndHostFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<ConnectAppAndHostFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&ConnectAppAndHostFrame_0::_0, ::cyberPhysicalSystem::ApplicationInstance::type_id, model));
		sp.add_operation(create_NavigateSingleAssociation(&ConnectAppAndHostFrame_0::_0, &ConnectAppAndHostFrame_0::_1, &::cyberPhysicalSystem::ApplicationInstance::allocatedTo));
		sp.add_operation(create_InstanceOfCheck(&ConnectAppAndHostFrame_0::_0, ::cyberPhysicalSystem::ApplicationInstance::type_id));
		
		return sp;
	}

};

} /* namespace CpsModelViewerCommon */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__CONNECT_APP_AND_HOST_QUERY_SPECIFICATION_H_ */
