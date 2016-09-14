#include "Node.h"

#include "RailRoadModel/Segment.h"
#include "RailRoadModel/Train.h"

#include <algorithm>

namespace PlatformModel {

std::list<Node*> Node::_instances;

Node::Node()
 {
	_instances.push_back(this);
}

Node::~Node() {
	_instances.remove(this);
}

} /* namespace PlatformModel */
