#ifndef VIATRA__QUERY__CPSQUERY__IDENTIFIABLE_ID_MATCH_H_
#define VIATRA__QUERY__CPSQUERY__IDENTIFIABLE_ID_MATCH_H_

#include <string>
		
#include "cyberPhysicalSystem/Identifiable.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

struct IdentifiableIdMatch {
	
	::cyberPhysicalSystem::Identifiable* identifiable;
	::std::string id;
	
	bool operator==(const IdentifiableIdMatch& other) const {
		return 
			identifiable == other.identifiable&&
			id == other.id
		;
	}
	
};		

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Cpsquery::IdentifiableIdMatch> {
	size_t operator()(const ::Viatra::Query::Cpsquery::IdentifiableIdMatch& match) const {
		return 
					std::hash<decltype(match.identifiable)>()(match.identifiable)^
					std::hash<decltype(match.id)>()(match.id)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__CPSQUERY__IDENTIFIABLE_ID_MATCH_H_ */
