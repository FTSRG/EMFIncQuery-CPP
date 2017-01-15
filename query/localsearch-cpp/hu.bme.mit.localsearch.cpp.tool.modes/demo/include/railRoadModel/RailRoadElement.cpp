#include "RailRoadElement.h"

#include "railRoadModel/Point.h"

#include <algorithm>

namespace railRoadModel {

std::list<RailRoadElement*> RailRoadElement::_instances;

RailRoadElement::RailRoadElement()
 {
	_instances.push_back(this);
}

RailRoadElement::~RailRoadElement() {
	_instances.remove(this);
}

} /* namespace railRoadModel */
