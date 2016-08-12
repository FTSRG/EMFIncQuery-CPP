#ifndef VIATRA__QUERY__CPSQUERY__STATE_TRANSITION_MATCH_H_
#define VIATRA__QUERY__CPSQUERY__STATE_TRANSITION_MATCH_H_

		
#include "cyberPhysicalSystem/State.h"
#include "cyberPhysicalSystem/Transition.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

struct StateTransitionMatch {
	
	::cyberPhysicalSystem::State* source;
	::cyberPhysicalSystem::Transition* transition;
	::cyberPhysicalSystem::State* target;
	
	bool operator==(const StateTransitionMatch& other) const {
		return 
			source == other.source&&
			transition == other.transition&&
			target == other.target
		;
	}
	
};		

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Cpsquery::StateTransitionMatch> {
	unsigned operator()(const ::Viatra::Query::Cpsquery::StateTransitionMatch& match) const {
		return 
					std::hash<decltype(match.source)>()(match.source)^
					std::hash<decltype(match.transition)>()(match.transition)^
					std::hash<decltype(match.target)>()(match.target)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__CPSQUERY__STATE_TRANSITION_MATCH_H_ */
