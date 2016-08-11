#ifndef VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__CONNECT_APP_AND_HOST_MATCH_H_
#define VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__CONNECT_APP_AND_HOST_MATCH_H_

		
#include "cyberPhysicalSystem/ApplicationInstance.h"
#include "cyberPhysicalSystem/HostInstance.h"

namespace Viatra {
namespace Query {
namespace CpsModelViewerCommon {

struct ConnectAppAndHostMatch {
	
	::cyberPhysicalSystem::ApplicationInstance* app;
	::cyberPhysicalSystem::HostInstance* host;
	
	bool operator==(const ConnectAppAndHostMatch& other) const {
		return 
			app == other.app&&
			host == other.host
		;
	}
	
};		

} /* namespace CpsModelViewerCommon */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::CpsModelViewerCommon::ConnectAppAndHostMatch> {
	unsigned operator()(const ::Viatra::Query::CpsModelViewerCommon::ConnectAppAndHostMatch& match) const {
		return 
			std::hash<decltype(match.app)>()(match.app)^
			std::hash<decltype(match.host)>()(match.host)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__CPS_MODEL_VIEWER_COMMON__CONNECT_APP_AND_HOST_MATCH_H_ */
