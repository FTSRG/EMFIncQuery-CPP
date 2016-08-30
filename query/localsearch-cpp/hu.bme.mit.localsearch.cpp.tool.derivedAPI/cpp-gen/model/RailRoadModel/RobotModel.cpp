#include "RobotModel.h"

#include "../RailRoadModel/Robot.h"
#include "../RailRoadModel/RobotPart.h"

#include <algorithm>

namespace RailRoadModel {

std::list<RobotModel*> RobotModel::_instances;

RobotModel::RobotModel()
 {
	_instances.push_back(this);
}

RobotModel::~RobotModel() {
	_instances.remove(this);
}

} /* namespace RailRoadModel */
