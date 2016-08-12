#ifndef VIATRA__QUERY__CPSQUERY__ACTION_OF_TRANSITION_MATCH_H_
#define VIATRA__QUERY__CPSQUERY__ACTION_OF_TRANSITION_MATCH_H_

#include <string>
		
#include "cyberPhysicalSystem/Transition.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

struct ActionOfTransitionMatch {
	
	::cyberPhysicalSystem::Transition* transition;
	::std::string action;
	
	bool operator==(const ActionOfTransitionMatch& other) const {
		return 
			transition == other.transition&&
			action == other.action
		;
	}
	
};		

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Cpsquery::ActionOfTransitionMatch> {
	unsigned operator()(const ::Viatra::Query::Cpsquery::ActionOfTransitionMatch& match) const {
		return 
					std::hash<decltype(match.transition)>()(match.transition)^
					std::hash<decltype(match.action)>()(match.action)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__CPSQUERY__ACTION_OF_TRANSITION_MATCH_H_ */
