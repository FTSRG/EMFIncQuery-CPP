#ifndef VIATRA__QUERY__CPSQUERY__NODE_IP_OF_HOST_MATCH_H_
#define VIATRA__QUERY__CPSQUERY__NODE_IP_OF_HOST_MATCH_H_

#include <string>
		
#include "cyberPhysicalSystem/HostInstance.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

struct NodeIpOfHostMatch {
	
	::cyberPhysicalSystem::HostInstance* host;
	::std::string ip;
	
	bool operator==(const NodeIpOfHostMatch& other) const {
		return 
			host == other.host&&
			ip == other.ip
		;
	}
	
};		

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Cpsquery::NodeIpOfHostMatch> {
	size_t operator()(const ::Viatra::Query::Cpsquery::NodeIpOfHostMatch& match) const {
		return 
					std::hash<decltype(match.host)>()(match.host)^
					std::hash<decltype(match.ip)>()(match.ip)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__CPSQUERY__NODE_IP_OF_HOST_MATCH_H_ */
