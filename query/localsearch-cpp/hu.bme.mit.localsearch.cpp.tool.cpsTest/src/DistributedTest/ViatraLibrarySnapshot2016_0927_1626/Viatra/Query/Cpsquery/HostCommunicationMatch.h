#ifndef VIATRA__QUERY__CPSQUERY__HOST_COMMUNICATION_MATCH_H_
#define VIATRA__QUERY__CPSQUERY__HOST_COMMUNICATION_MATCH_H_

		
#include "cyberPhysicalSystem/HostInstance.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

struct HostCommunicationMatch {
	
	::cyberPhysicalSystem::HostInstance* fromHost;
	::cyberPhysicalSystem::HostInstance* toHost;
	
	bool operator==(const HostCommunicationMatch& other) const {
		return 
			fromHost == other.fromHost&&
			toHost == other.toHost
		;
	}
	
};		

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Cpsquery::HostCommunicationMatch> {
	size_t operator()(const ::Viatra::Query::Cpsquery::HostCommunicationMatch& match) const {
		return 
					std::hash<decltype(match.fromHost)>()(match.fromHost)^
					std::hash<decltype(match.toHost)>()(match.toHost)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__CPSQUERY__HOST_COMMUNICATION_MATCH_H_ */
