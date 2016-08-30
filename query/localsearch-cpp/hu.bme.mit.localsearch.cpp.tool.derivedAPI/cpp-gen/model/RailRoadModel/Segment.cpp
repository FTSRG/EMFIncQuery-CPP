#include "Segment.h"

#include "../RailRoadModel/RailRoadElement.h"

#include <algorithm>

namespace RailRoadModel {

std::list<Segment*> Segment::_instances;

Segment::Segment()
 {
	_instances.push_back(this);
}

Segment::~Segment() {
	_instances.remove(this);
}

} /* namespace RailRoadModel */
