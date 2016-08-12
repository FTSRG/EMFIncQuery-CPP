#ifndef VIATRA__QUERY__CPSQUERY__MULTIPLE_TRANSITIONS_WITH_SAME_ACTION_MATCH_H_
#define VIATRA__QUERY__CPSQUERY__MULTIPLE_TRANSITIONS_WITH_SAME_ACTION_MATCH_H_

#include <string>
		
#include "cyberPhysicalSystem/State.h"
#include "cyberPhysicalSystem/Transition.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

struct MultipleTransitionsWithSameActionMatch {
	
	::std::string action;
	::cyberPhysicalSystem::State* state;
	
	bool operator==(const MultipleTransitionsWithSameActionMatch& other) const {
		return 
			action == other.action&&
			state == other.state
		;
	}
	
};		

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Cpsquery::MultipleTransitionsWithSameActionMatch> {
	unsigned operator()(const ::Viatra::Query::Cpsquery::MultipleTransitionsWithSameActionMatch& match) const {
		return 
					std::hash<decltype(match.action)>()(match.action)^
					std::hash<decltype(match.state)>()(match.state)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__CPSQUERY__MULTIPLE_TRANSITIONS_WITH_SAME_ACTION_MATCH_H_ */
