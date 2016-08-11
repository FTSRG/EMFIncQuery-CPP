#include "Identifiable.h"


#include <algorithm>

namespace cyberPhysicalSystem {

std::list<Identifiable*> Identifiable::_instances;

Identifiable::Identifiable() {
	_instances.push_back(this);
}

Identifiable::~Identifiable() {
	_instances.remove(this);
}

} /* namespace cyberPhysicalSystem */
