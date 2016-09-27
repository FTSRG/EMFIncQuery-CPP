#ifndef VIATRA__QUERY__CPSQUERY__ALLOCATED_APPLICATION_MATCH_H_
#define VIATRA__QUERY__CPSQUERY__ALLOCATED_APPLICATION_MATCH_H_

		
#include "cyberPhysicalSystem/ApplicationInstance.h"
#include "cyberPhysicalSystem/HostInstance.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

struct AllocatedApplicationMatch {
	
	::cyberPhysicalSystem::ApplicationInstance* app;
	
	bool operator==(const AllocatedApplicationMatch& other) const {
		return 
			app == other.app
		;
	}
	
};		

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Cpsquery::AllocatedApplicationMatch> {
	size_t operator()(const ::Viatra::Query::Cpsquery::AllocatedApplicationMatch& match) const {
		return 
					std::hash<decltype(match.app)>()(match.app)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__CPSQUERY__ALLOCATED_APPLICATION_MATCH_H_ */
