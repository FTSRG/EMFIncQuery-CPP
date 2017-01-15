#include "Train.h"

#include "railRoadModel/RailRoadElement.h"

#include <algorithm>

namespace railRoadModel {

std::list<Train*> Train::_instances;

Train::Train()
: currentlyOn(nullptr),previouslyOn(nullptr) {
	_instances.push_back(this);
}

Train::~Train() {
	_instances.remove(this);
}

} /* namespace railRoadModel */
