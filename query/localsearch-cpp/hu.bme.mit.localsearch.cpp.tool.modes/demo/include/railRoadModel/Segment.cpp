#include "Segment.h"

#include "railRoadModel/RailRoadElement.h"

#include <algorithm>

namespace railRoadModel {

std::list<Segment*> Segment::_instances;

Segment::Segment()
 {
	_instances.push_back(this);
}

Segment::~Segment() {
	_instances.remove(this);
}

} /* namespace railRoadModel */
