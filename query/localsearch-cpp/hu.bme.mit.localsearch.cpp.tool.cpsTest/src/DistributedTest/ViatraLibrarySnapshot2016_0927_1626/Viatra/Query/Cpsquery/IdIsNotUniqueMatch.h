#ifndef VIATRA__QUERY__CPSQUERY__ID_IS_NOT_UNIQUE_MATCH_H_
#define VIATRA__QUERY__CPSQUERY__ID_IS_NOT_UNIQUE_MATCH_H_

#include <string>
		
#include "cyberPhysicalSystem/Identifiable.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

struct IdIsNotUniqueMatch {
	
	::cyberPhysicalSystem::Identifiable* identifiable;
	
	bool operator==(const IdIsNotUniqueMatch& other) const {
		return 
			identifiable == other.identifiable
		;
	}
	
};		

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Cpsquery::IdIsNotUniqueMatch> {
	size_t operator()(const ::Viatra::Query::Cpsquery::IdIsNotUniqueMatch& match) const {
		return 
					std::hash<decltype(match.identifiable)>()(match.identifiable)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__CPSQUERY__ID_IS_NOT_UNIQUE_MATCH_H_ */
