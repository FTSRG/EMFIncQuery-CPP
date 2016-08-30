#include "Robot.h"

#include "../RailRoadModel/RobotPart.h"

#include <algorithm>

namespace RailRoadModel {

std::list<Robot*> Robot::_instances;

Robot::Robot()
 {
	_instances.push_back(this);
}

Robot::~Robot() {
	_instances.remove(this);
}

} /* namespace RailRoadModel */
