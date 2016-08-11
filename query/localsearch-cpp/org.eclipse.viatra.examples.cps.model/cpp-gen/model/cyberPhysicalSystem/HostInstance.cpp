#include "HostInstance.h"

#include "cyberPhysicalSystem/ApplicationInstance.h"
#include "cyberPhysicalSystem/HostInstance.h"

#include <algorithm>

namespace cyberPhysicalSystem {

std::list<HostInstance*> HostInstance::_instances;

HostInstance::HostInstance()
 {
	_instances.push_back(this);
}

HostInstance::~HostInstance() {
	_instances.remove(this);
}

} /* namespace cyberPhysicalSystem */
