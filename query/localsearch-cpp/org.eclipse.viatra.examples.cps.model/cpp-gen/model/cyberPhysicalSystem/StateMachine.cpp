#include "StateMachine.h"

#include "cyberPhysicalSystem/State.h"

#include <algorithm>

namespace cyberPhysicalSystem {

std::list<StateMachine*> StateMachine::_instances;

StateMachine::StateMachine()
: initial(nullptr) {
	_instances.push_back(this);
}

StateMachine::~StateMachine() {
	_instances.remove(this);
}

} /* namespace cyberPhysicalSystem */
