#ifndef VIATRA__QUERY__CPSQUERY__REACHABLE_HOSTS_MATCH_H_
#define VIATRA__QUERY__CPSQUERY__REACHABLE_HOSTS_MATCH_H_

		
#include "cyberPhysicalSystem/HostInstance.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

struct ReachableHostsMatch {
	
	::cyberPhysicalSystem::HostInstance* source;
	::cyberPhysicalSystem::HostInstance* target;
	
	bool operator==(const ReachableHostsMatch& other) const {
		return 
			source == other.source&&
			target == other.target
		;
	}
	
};		

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Cpsquery::ReachableHostsMatch> {
	size_t operator()(const ::Viatra::Query::Cpsquery::ReachableHostsMatch& match) const {
		return 
					std::hash<decltype(match.source)>()(match.source)^
					std::hash<decltype(match.target)>()(match.target)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__CPSQUERY__REACHABLE_HOSTS_MATCH_H_ */
