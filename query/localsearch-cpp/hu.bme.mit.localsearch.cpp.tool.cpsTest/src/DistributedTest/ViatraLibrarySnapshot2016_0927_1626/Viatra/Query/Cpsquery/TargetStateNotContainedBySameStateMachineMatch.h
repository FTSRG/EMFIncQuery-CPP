#ifndef VIATRA__QUERY__CPSQUERY__TARGET_STATE_NOT_CONTAINED_BY_SAME_STATE_MACHINE_MATCH_H_
#define VIATRA__QUERY__CPSQUERY__TARGET_STATE_NOT_CONTAINED_BY_SAME_STATE_MACHINE_MATCH_H_

		
#include "cyberPhysicalSystem/State.h"
#include "cyberPhysicalSystem/StateMachine.h"
#include "cyberPhysicalSystem/Transition.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

struct TargetStateNotContainedBySameStateMachineMatch {
	
	::cyberPhysicalSystem::Transition* transition;
	::cyberPhysicalSystem::State* target;
	
	bool operator==(const TargetStateNotContainedBySameStateMachineMatch& other) const {
		return 
			transition == other.transition&&
			target == other.target
		;
	}
	
};		

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Cpsquery::TargetStateNotContainedBySameStateMachineMatch> {
	size_t operator()(const ::Viatra::Query::Cpsquery::TargetStateNotContainedBySameStateMachineMatch& match) const {
		return 
					std::hash<decltype(match.transition)>()(match.transition)^
					std::hash<decltype(match.target)>()(match.target)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__CPSQUERY__TARGET_STATE_NOT_CONTAINED_BY_SAME_STATE_MACHINE_MATCH_H_ */
