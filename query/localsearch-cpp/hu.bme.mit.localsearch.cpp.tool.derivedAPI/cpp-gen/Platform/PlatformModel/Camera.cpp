#include "Camera.h"

#include "RailRoadModel/Segment.h"

#include <algorithm>

namespace PlatformModel {

std::list<Camera*> Camera::_instances;

Camera::Camera()
 {
	_instances.push_back(this);
}

Camera::~Camera() {
	_instances.remove(this);
}

} /* namespace PlatformModel */
