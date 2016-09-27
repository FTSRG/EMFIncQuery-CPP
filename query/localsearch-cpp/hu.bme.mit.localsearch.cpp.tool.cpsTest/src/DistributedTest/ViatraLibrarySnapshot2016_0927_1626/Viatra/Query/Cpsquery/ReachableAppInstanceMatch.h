#ifndef VIATRA__QUERY__CPSQUERY__REACHABLE_APP_INSTANCE_MATCH_H_
#define VIATRA__QUERY__CPSQUERY__REACHABLE_APP_INSTANCE_MATCH_H_

		
#include "cyberPhysicalSystem/ApplicationInstance.h"
#include "cyberPhysicalSystem/ApplicationType.h"
#include "cyberPhysicalSystem/HostInstance.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

struct ReachableAppInstanceMatch {
	
	::cyberPhysicalSystem::ApplicationType* app;
	::cyberPhysicalSystem::ApplicationInstance* appInstance;
	::cyberPhysicalSystem::HostInstance* sourceHostInstance;
	
	bool operator==(const ReachableAppInstanceMatch& other) const {
		return 
			app == other.app&&
			appInstance == other.appInstance&&
			sourceHostInstance == other.sourceHostInstance
		;
	}
	
};		

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Cpsquery::ReachableAppInstanceMatch> {
	size_t operator()(const ::Viatra::Query::Cpsquery::ReachableAppInstanceMatch& match) const {
		return 
					std::hash<decltype(match.app)>()(match.app)^
					std::hash<decltype(match.appInstance)>()(match.appInstance)^
					std::hash<decltype(match.sourceHostInstance)>()(match.sourceHostInstance)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__CPSQUERY__REACHABLE_APP_INSTANCE_MATCH_H_ */
