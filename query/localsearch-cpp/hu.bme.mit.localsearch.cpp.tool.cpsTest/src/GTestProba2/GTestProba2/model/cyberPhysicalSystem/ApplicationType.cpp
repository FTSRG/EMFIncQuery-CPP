#include "ApplicationType.h"

#include "cyberPhysicalSystem/ResourceRequirement.h"
#include "cyberPhysicalSystem/CyberPhysicalSystem.h"
#include "cyberPhysicalSystem/ApplicationInstance.h"
#include "cyberPhysicalSystem/StateMachine.h"

#include <algorithm>

namespace cyberPhysicalSystem {

std::list<ApplicationType*> ApplicationType::_instances;

ApplicationType::ApplicationType()
: cps(NULL),behavior(NULL) {
	_instances.push_back(this);
}

ApplicationType::~ApplicationType() {
	_instances.remove(this);
}

} /* namespace cyberPhysicalSystem */
