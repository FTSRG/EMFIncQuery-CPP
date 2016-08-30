#include "Train.h"

#include "../RailRoadModel/RailRoadElement.h"
#include "../RailRoadModel/Point.h"

#include <algorithm>

namespace RailRoadModel {

std::list<Train*> Train::_instances;

Train::Train()
: currentlyOn(nullptr),previouslyOn(nullptr),point(nullptr) {
	_instances.push_back(this);
}

Train::~Train() {
	_instances.remove(this);
}

} /* namespace RailRoadModel */
