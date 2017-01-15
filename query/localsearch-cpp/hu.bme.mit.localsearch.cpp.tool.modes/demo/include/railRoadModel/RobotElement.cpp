#include "RobotElement.h"


#include <algorithm>

namespace railRoadModel {

std::list<RobotElement*> RobotElement::_instances;

RobotElement::RobotElement() {
	_instances.push_back(this);
}

RobotElement::~RobotElement() {
	_instances.remove(this);
}

} /* namespace railRoadModel */
