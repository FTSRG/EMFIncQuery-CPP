#include "Robot.h"

#include "railRoadModel/RobotPart.h"

#include <algorithm>

namespace railRoadModel {

std::list<Robot*> Robot::_instances;

Robot::Robot()
 {
	_instances.push_back(this);
}

Robot::~Robot() {
	_instances.remove(this);
}

} /* namespace railRoadModel */
