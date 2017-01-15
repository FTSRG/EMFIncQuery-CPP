#include "Point.h"


#include <algorithm>

namespace railRoadModel {

std::list<Point*> Point::_instances;

Point::Point() {
	_instances.push_back(this);
}

Point::~Point() {
	_instances.remove(this);
}

} /* namespace railRoadModel */
