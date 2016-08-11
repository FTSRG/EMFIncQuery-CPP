#include "ResourceRequirement.h"

#include "cyberPhysicalSystem/HostType.h"

#include <algorithm>

namespace cyberPhysicalSystem {

std::list<ResourceRequirement*> ResourceRequirement::_instances;

ResourceRequirement::ResourceRequirement()
: type(nullptr) {
	_instances.push_back(this);
}

ResourceRequirement::~ResourceRequirement() {
	_instances.remove(this);
}

} /* namespace cyberPhysicalSystem */
