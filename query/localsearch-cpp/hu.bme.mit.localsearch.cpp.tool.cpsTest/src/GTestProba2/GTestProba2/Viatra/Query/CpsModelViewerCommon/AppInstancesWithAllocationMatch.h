#ifndef VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__APP_INSTANCES_WITH_ALLOCATION_MATCH_H_
#define VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__APP_INSTANCES_WITH_ALLOCATION_MATCH_H_

		
#include "cyberPhysicalSystem/ApplicationInstance.h"
#include "cyberPhysicalSystem/HostInstance.h"

namespace Viatra {
namespace Query {
namespace CpsModelViewerCommon {

struct AppInstancesWithAllocationMatch {
	
	::cyberPhysicalSystem::ApplicationInstance* app;
	
	bool operator==(const AppInstancesWithAllocationMatch& other) const {
		return 
			app == other.app
		;
	}
	
};		

} /* namespace CpsModelViewerCommon */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::CpsModelViewerCommon::AppInstancesWithAllocationMatch> {
	unsigned operator()(const ::Viatra::Query::CpsModelViewerCommon::AppInstancesWithAllocationMatch& match) const {
		return 
			std::hash<decltype(match.app)>()(match.app)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__APP_INSTANCES_WITH_ALLOCATION_MATCH_H_ */
