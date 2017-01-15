#include "Path.h"

#include "railRoadModel/RailRoadElement.h"

#include <algorithm>

namespace railRoadModel {

std::list<Path*> Path::_instances;

Path::Path()
: from(nullptr),via(nullptr),to(nullptr) {
	_instances.push_back(this);
}

Path::~Path() {
	_instances.remove(this);
}

} /* namespace railRoadModel */
