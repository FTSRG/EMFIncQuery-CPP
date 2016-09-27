#ifndef VIATRA__QUERY__CPSQUERY__TRANSITION_WITHOUT_TARGET_STATE_MATCH_H_
#define VIATRA__QUERY__CPSQUERY__TRANSITION_WITHOUT_TARGET_STATE_MATCH_H_

		
#include "cyberPhysicalSystem/State.h"
#include "cyberPhysicalSystem/Transition.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

struct TransitionWithoutTargetStateMatch {
	
	::cyberPhysicalSystem::Transition* transition;
	
	bool operator==(const TransitionWithoutTargetStateMatch& other) const {
		return 
			transition == other.transition
		;
	}
	
};		

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Cpsquery::TransitionWithoutTargetStateMatch> {
	size_t operator()(const ::Viatra::Query::Cpsquery::TransitionWithoutTargetStateMatch& match) const {
		return 
					std::hash<decltype(match.transition)>()(match.transition)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__CPSQUERY__TRANSITION_WITHOUT_TARGET_STATE_MATCH_H_ */
