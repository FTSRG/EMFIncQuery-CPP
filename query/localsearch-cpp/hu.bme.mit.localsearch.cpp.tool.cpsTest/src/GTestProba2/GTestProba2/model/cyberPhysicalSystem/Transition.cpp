#include "Transition.h"

#include "cyberPhysicalSystem/State.h"

#include <algorithm>

namespace cyberPhysicalSystem {

std::list<Transition*> Transition::_instances;

Transition::Transition()
: targetState(NULL) {
	_instances.push_back(this);
}

Transition::~Transition() {
	_instances.remove(this);
}

} /* namespace cyberPhysicalSystem */
