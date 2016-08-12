#include "CyberPhysicalSystem.h"

#include "cyberPhysicalSystem/ApplicationType.h"
#include "cyberPhysicalSystem/Request.h"
#include "cyberPhysicalSystem/HostType.h"

#include <algorithm>

namespace cyberPhysicalSystem {

std::list<CyberPhysicalSystem*> CyberPhysicalSystem::_instances;

CyberPhysicalSystem::CyberPhysicalSystem()
 {
	_instances.push_back(this);
}

CyberPhysicalSystem::~CyberPhysicalSystem() {
	_instances.remove(this);
}

} /* namespace cyberPhysicalSystem */
