#ifndef VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__ALL_HOST_INSTANCES_MATCH_H_
#define VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__ALL_HOST_INSTANCES_MATCH_H_

		
#include "cyberPhysicalSystem/HostInstance.h"

namespace Viatra {
namespace Query {
namespace CpsModelViewerCommon {

struct AllHostInstancesMatch {
	
	::cyberPhysicalSystem::HostInstance* host;
	
	bool operator==(const AllHostInstancesMatch& other) const {
		return 
			host == other.host
		;
	}
	
};		

} /* namespace CpsModelViewerCommon */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::CpsModelViewerCommon::AllHostInstancesMatch> {
	unsigned operator()(const ::Viatra::Query::CpsModelViewerCommon::AllHostInstancesMatch& match) const {
		return 
			std::hash<decltype(match.host)>()(match.host)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__ALL_HOST_INSTANCES_MATCH_H_ */
