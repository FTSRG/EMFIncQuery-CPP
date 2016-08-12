#ifndef VIATRA__QUERY__CPSQUERY__NOT_ALLOCATED_BUT_RUNNING_MATCH_H_
#define VIATRA__QUERY__CPSQUERY__NOT_ALLOCATED_BUT_RUNNING_MATCH_H_

		
#include "cyberPhysicalSystem/ApplicationInstance.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

struct NotAllocatedButRunningMatch {
	
	::cyberPhysicalSystem::ApplicationInstance* app;
	
	bool operator==(const NotAllocatedButRunningMatch& other) const {
		return 
			app == other.app
		;
	}
	
};		

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Cpsquery::NotAllocatedButRunningMatch> {
	unsigned operator()(const ::Viatra::Query::Cpsquery::NotAllocatedButRunningMatch& match) const {
		return 
					std::hash<decltype(match.app)>()(match.app)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__CPSQUERY__NOT_ALLOCATED_BUT_RUNNING_MATCH_H_ */
