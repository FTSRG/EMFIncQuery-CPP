#ifndef VIATRA__QUERY__CPSQUERY__INITIAL_STATE_NOT_CONTAINED_BY_STATE_MACHINE_MATCH_H_
#define VIATRA__QUERY__CPSQUERY__INITIAL_STATE_NOT_CONTAINED_BY_STATE_MACHINE_MATCH_H_

		
#include "cyberPhysicalSystem/State.h"
#include "cyberPhysicalSystem/StateMachine.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

struct InitialStateNotContainedByStateMachineMatch {
	
	::cyberPhysicalSystem::StateMachine* statemachine;
	::cyberPhysicalSystem::State* state;
	
	bool operator==(const InitialStateNotContainedByStateMachineMatch& other) const {
		return 
			statemachine == other.statemachine&&
			state == other.state
		;
	}
	
};		

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Cpsquery::InitialStateNotContainedByStateMachineMatch> {
	size_t operator()(const ::Viatra::Query::Cpsquery::InitialStateNotContainedByStateMachineMatch& match) const {
		return 
					std::hash<decltype(match.statemachine)>()(match.statemachine)^
					std::hash<decltype(match.state)>()(match.state)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__CPSQUERY__INITIAL_STATE_NOT_CONTAINED_BY_STATE_MACHINE_MATCH_H_ */
