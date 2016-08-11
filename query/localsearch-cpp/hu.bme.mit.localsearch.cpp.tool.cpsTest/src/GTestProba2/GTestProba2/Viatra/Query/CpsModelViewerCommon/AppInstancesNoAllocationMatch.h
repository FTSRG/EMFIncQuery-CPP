#ifndef VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__APP_INSTANCES_NO_ALLOCATION_MATCH_H_
#define VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__APP_INSTANCES_NO_ALLOCATION_MATCH_H_

		
#include "cyberPhysicalSystem/ApplicationInstance.h"

namespace Viatra {
namespace Query {
namespace CpsModelViewerCommon {

struct AppInstancesNoAllocationMatch {
	
	::cyberPhysicalSystem::ApplicationInstance* app;
	
	bool operator==(const AppInstancesNoAllocationMatch& other) const {
		return 
			app == other.app
		;
	}
	
};		

} /* namespace CpsModelViewerCommon */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::CpsModelViewerCommon::AppInstancesNoAllocationMatch> {
	unsigned operator()(const ::Viatra::Query::CpsModelViewerCommon::AppInstancesNoAllocationMatch& match) const {
		return 
			std::hash<decltype(match.app)>()(match.app)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__APP_INSTANCES_NO_ALLOCATION_MATCH_H_ */
