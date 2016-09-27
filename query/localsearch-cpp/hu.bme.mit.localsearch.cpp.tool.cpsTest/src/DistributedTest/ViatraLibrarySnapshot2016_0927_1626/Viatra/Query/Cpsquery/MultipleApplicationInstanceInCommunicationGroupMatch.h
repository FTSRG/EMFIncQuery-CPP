#ifndef VIATRA__QUERY__CPSQUERY__MULTIPLE_APPLICATION_INSTANCE_IN_COMMUNICATION_GROUP_MATCH_H_
#define VIATRA__QUERY__CPSQUERY__MULTIPLE_APPLICATION_INSTANCE_IN_COMMUNICATION_GROUP_MATCH_H_

		
#include "cyberPhysicalSystem/ApplicationInstance.h"
#include "cyberPhysicalSystem/ApplicationType.h"
#include "cyberPhysicalSystem/HostInstance.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

struct MultipleApplicationInstanceInCommunicationGroupMatch {
	
	::cyberPhysicalSystem::HostInstance* sourceHostInstance;
	::cyberPhysicalSystem::ApplicationType* app;
	
	bool operator==(const MultipleApplicationInstanceInCommunicationGroupMatch& other) const {
		return 
			sourceHostInstance == other.sourceHostInstance&&
			app == other.app
		;
	}
	
};		

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Cpsquery::MultipleApplicationInstanceInCommunicationGroupMatch> {
	size_t operator()(const ::Viatra::Query::Cpsquery::MultipleApplicationInstanceInCommunicationGroupMatch& match) const {
		return 
					std::hash<decltype(match.sourceHostInstance)>()(match.sourceHostInstance)^
					std::hash<decltype(match.app)>()(match.app)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__CPSQUERY__MULTIPLE_APPLICATION_INSTANCE_IN_COMMUNICATION_GROUP_MATCH_H_ */
