#include "RobotModel.h"

#include "railRoadModel/Robot.h"

#include <algorithm>

namespace railRoadModel {

std::list<RobotModel*> RobotModel::_instances;

RobotModel::RobotModel()
 {
	_instances.push_back(this);
}

RobotModel::~RobotModel() {
	_instances.remove(this);
}

} /* namespace railRoadModel */
