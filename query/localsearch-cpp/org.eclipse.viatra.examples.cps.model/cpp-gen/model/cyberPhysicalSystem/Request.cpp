#include "Request.h"

#include "cyberPhysicalSystem/Requirement.h"

#include <algorithm>

namespace cyberPhysicalSystem {

std::list<Request*> Request::_instances;

Request::Request()
 {
	_instances.push_back(this);
}

Request::~Request() {
	_instances.remove(this);
}

} /* namespace cyberPhysicalSystem */
