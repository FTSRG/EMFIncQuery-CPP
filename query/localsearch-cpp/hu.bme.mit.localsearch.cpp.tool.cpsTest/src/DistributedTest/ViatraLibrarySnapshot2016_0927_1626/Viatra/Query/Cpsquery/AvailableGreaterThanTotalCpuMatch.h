#ifndef VIATRA__QUERY__CPSQUERY__AVAILABLE_GREATER_THAN_TOTAL_CPU_MATCH_H_
#define VIATRA__QUERY__CPSQUERY__AVAILABLE_GREATER_THAN_TOTAL_CPU_MATCH_H_

		
#include "cyberPhysicalSystem/HostInstance.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

struct AvailableGreaterThanTotalCpuMatch {
	
	::cyberPhysicalSystem::HostInstance* host;
	
	bool operator==(const AvailableGreaterThanTotalCpuMatch& other) const {
		return 
			host == other.host
		;
	}
	
};		

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Cpsquery::AvailableGreaterThanTotalCpuMatch> {
	size_t operator()(const ::Viatra::Query::Cpsquery::AvailableGreaterThanTotalCpuMatch& match) const {
		return 
					std::hash<decltype(match.host)>()(match.host)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__CPSQUERY__AVAILABLE_GREATER_THAN_TOTAL_CPU_MATCH_H_ */
