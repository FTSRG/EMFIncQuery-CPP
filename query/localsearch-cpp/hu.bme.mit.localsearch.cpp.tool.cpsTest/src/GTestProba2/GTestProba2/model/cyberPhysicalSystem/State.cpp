#include "State.h"

#include "cyberPhysicalSystem/Transition.h"

#include <algorithm>

namespace cyberPhysicalSystem {

std::list<State*> State::_instances;

State::State()
 {
	_instances.push_back(this);
}

State::~State() {
	_instances.remove(this);
}

} /* namespace cyberPhysicalSystem */
