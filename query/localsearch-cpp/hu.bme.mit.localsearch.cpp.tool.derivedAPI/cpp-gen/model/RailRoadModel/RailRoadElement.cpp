#include "RailRoadElement.h"

#include "../RailRoadModel/Point.h"

#include <algorithm>

namespace RailRoadModel {

std::list<RailRoadElement*> RailRoadElement::_instances;

RailRoadElement::RailRoadElement()
 {
	_instances.push_back(this);
}

RailRoadElement::~RailRoadElement() {
	_instances.remove(this);
}

} /* namespace RailRoadModel */
