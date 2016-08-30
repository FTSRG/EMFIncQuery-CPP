#include "RailRoadModel.h"

#include "../RailRoadModel/RailRoadElement.h"
#include "../RailRoadModel/Train.h"

#include <algorithm>

namespace RailRoadModel {

std::list<RailRoadModel*> RailRoadModel::_instances;

RailRoadModel::RailRoadModel()
 {
	_instances.push_back(this);
}

RailRoadModel::~RailRoadModel() {
	_instances.remove(this);
}

} /* namespace RailRoadModel */
