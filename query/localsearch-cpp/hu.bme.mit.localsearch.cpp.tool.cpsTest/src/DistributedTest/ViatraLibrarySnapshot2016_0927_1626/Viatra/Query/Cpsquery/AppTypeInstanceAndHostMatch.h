#ifndef VIATRA__QUERY__CPSQUERY__APP_TYPE_INSTANCE_AND_HOST_MATCH_H_
#define VIATRA__QUERY__CPSQUERY__APP_TYPE_INSTANCE_AND_HOST_MATCH_H_

		
#include "cyberPhysicalSystem/ApplicationInstance.h"
#include "cyberPhysicalSystem/ApplicationType.h"
#include "cyberPhysicalSystem/HostInstance.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

struct AppTypeInstanceAndHostMatch {
	
	::cyberPhysicalSystem::ApplicationType* app;
	::cyberPhysicalSystem::ApplicationInstance* appInstance;
	::cyberPhysicalSystem::HostInstance* hostInstance;
	
	bool operator==(const AppTypeInstanceAndHostMatch& other) const {
		return 
			app == other.app&&
			appInstance == other.appInstance&&
			hostInstance == other.hostInstance
		;
	}
	
};		

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Cpsquery::AppTypeInstanceAndHostMatch> {
	size_t operator()(const ::Viatra::Query::Cpsquery::AppTypeInstanceAndHostMatch& match) const {
		return 
					std::hash<decltype(match.app)>()(match.app)^
					std::hash<decltype(match.appInstance)>()(match.appInstance)^
					std::hash<decltype(match.hostInstance)>()(match.hostInstance)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__CPSQUERY__APP_TYPE_INSTANCE_AND_HOST_MATCH_H_ */
