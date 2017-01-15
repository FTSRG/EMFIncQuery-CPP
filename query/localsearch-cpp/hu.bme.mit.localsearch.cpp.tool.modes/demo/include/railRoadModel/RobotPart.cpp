#include "RobotPart.h"

#include "railRoadModel/Train.h"
#include "railRoadModel/Segment.h"

#include <algorithm>

namespace railRoadModel {

std::list<RobotPart*> RobotPart::_instances;

RobotPart::RobotPart()
 {
	_instances.push_back(this);
}

RobotPart::~RobotPart() {
	_instances.remove(this);
}

} /* namespace railRoadModel */
