#include "Turnout.h"

#include "railRoadModel/RailRoadElement.h"

#include <algorithm>

namespace railRoadModel {

std::list<Turnout*> Turnout::_instances;

Turnout::Turnout()
: top(nullptr),straight(nullptr),divergent(nullptr) {
	_instances.push_back(this);
}

Turnout::~Turnout() {
	_instances.remove(this);
}

} /* namespace railRoadModel */
