#include "RailRoadModel.h"

#include "railRoadModel/RailRoadElement.h"
#include "railRoadModel/Train.h"
#include "railRoadModel/Path.h"

#include <algorithm>

namespace railRoadModel {

std::list<RailRoadModel*> RailRoadModel::_instances;

RailRoadModel::RailRoadModel()
 {
	_instances.push_back(this);
}

RailRoadModel::~RailRoadModel() {
	_instances.remove(this);
}

} /* namespace railRoadModel */
