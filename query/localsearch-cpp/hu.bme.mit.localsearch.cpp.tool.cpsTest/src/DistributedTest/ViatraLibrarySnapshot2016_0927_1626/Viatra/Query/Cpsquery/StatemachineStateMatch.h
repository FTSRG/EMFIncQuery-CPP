#ifndef VIATRA__QUERY__CPSQUERY__STATEMACHINE_STATE_MATCH_H_
#define VIATRA__QUERY__CPSQUERY__STATEMACHINE_STATE_MATCH_H_

		
#include "cyberPhysicalSystem/State.h"
#include "cyberPhysicalSystem/StateMachine.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

struct StatemachineStateMatch {
	
	::cyberPhysicalSystem::StateMachine* statemachine;
	::cyberPhysicalSystem::State* state;
	
	bool operator==(const StatemachineStateMatch& other) const {
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

template<> struct hash<::Viatra::Query::Cpsquery::StatemachineStateMatch> {
	size_t operator()(const ::Viatra::Query::Cpsquery::StatemachineStateMatch& match) const {
		return 
					std::hash<decltype(match.statemachine)>()(match.statemachine)^
					std::hash<decltype(match.state)>()(match.state)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__CPSQUERY__STATEMACHINE_STATE_MATCH_H_ */
