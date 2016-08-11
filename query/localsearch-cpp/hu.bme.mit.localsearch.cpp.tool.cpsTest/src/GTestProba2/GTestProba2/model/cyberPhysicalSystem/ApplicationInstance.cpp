#include "ApplicationInstance.h"

#include "cyberPhysicalSystem/HostInstance.h"
#include "cyberPhysicalSystem/ApplicationInstance.h"
#include "cyberPhysicalSystem/ApplicationType.h"

#include <algorithm>

namespace cyberPhysicalSystem {

std::list<ApplicationInstance*> ApplicationInstance::_instances;

ApplicationInstance::ApplicationInstance()
: allocatedTo(NULL),type(NULL) {
	_instances.push_back(this);
}

ApplicationInstance::~ApplicationInstance() {
	_instances.remove(this);
}

} /* namespace cyberPhysicalSystem */
