#include "Requirement.h"

#include "cyberPhysicalSystem/Request.h"
#include "cyberPhysicalSystem/ApplicationType.h"
#include "cyberPhysicalSystem/ApplicationInstance.h"

#include <algorithm>

namespace cyberPhysicalSystem {

std::list<Requirement*> Requirement::_instances;

Requirement::Requirement()
: request(nullptr),type(nullptr) {
	_instances.push_back(this);
}

Requirement::~Requirement() {
	_instances.remove(this);
}

} /* namespace cyberPhysicalSystem */
