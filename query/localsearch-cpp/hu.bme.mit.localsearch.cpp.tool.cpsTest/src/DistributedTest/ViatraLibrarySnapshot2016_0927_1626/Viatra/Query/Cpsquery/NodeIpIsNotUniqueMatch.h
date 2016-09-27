#ifndef VIATRA__QUERY__CPSQUERY__NODE_IP_IS_NOT_UNIQUE_MATCH_H_
#define VIATRA__QUERY__CPSQUERY__NODE_IP_IS_NOT_UNIQUE_MATCH_H_

#include <string>
		
#include "cyberPhysicalSystem/HostInstance.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

struct NodeIpIsNotUniqueMatch {
	
	::cyberPhysicalSystem::HostInstance* host;
	
	bool operator==(const NodeIpIsNotUniqueMatch& other) const {
		return 
			host == other.host
		;
	}
	
};		

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Cpsquery::NodeIpIsNotUniqueMatch> {
	size_t operator()(const ::Viatra::Query::Cpsquery::NodeIpIsNotUniqueMatch& match) const {
		return 
					std::hash<decltype(match.host)>()(match.host)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__CPSQUERY__NODE_IP_IS_NOT_UNIQUE_MATCH_H_ */
