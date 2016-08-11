#include "HostType.h"

#include "cyberPhysicalSystem/CyberPhysicalSystem.h"
#include "cyberPhysicalSystem/HostInstance.h"

#include <algorithm>

namespace cyberPhysicalSystem {

std::list<HostType*> HostType::_instances;

HostType::HostType()
: cps(NULL) {
	_instances.push_back(this);
}

HostType::~HostType() {
	_instances.remove(this);
}

} /* namespace cyberPhysicalSystem */
