#include "RobotPart.h"

#include "../RailRoadModel/Train.h"

#include <algorithm>

namespace RailRoadModel {

std::list<RobotPart*> RobotPart::_instances;

RobotPart::RobotPart()
 {
	_instances.push_back(this);
}

RobotPart::~RobotPart() {
	_instances.remove(this);
}

} /* namespace RailRoadModel */
