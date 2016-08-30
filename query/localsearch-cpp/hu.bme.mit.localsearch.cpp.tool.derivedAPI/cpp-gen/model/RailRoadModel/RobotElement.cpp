#include "RobotElement.h"

#include "../RailRoadModel/Point.h"

#include <algorithm>

namespace RailRoadModel {

std::list<RobotElement*> RobotElement::_instances;

RobotElement::RobotElement()
: position(nullptr) {
	_instances.push_back(this);
}

RobotElement::~RobotElement() {
	_instances.remove(this);
}

} /* namespace RailRoadModel */
