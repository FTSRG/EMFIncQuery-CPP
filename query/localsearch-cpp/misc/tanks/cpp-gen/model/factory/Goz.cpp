#include "Goz.h"


#include <algorithm>

namespace factory {

std::list<Goz*> Goz::_instances;

Goz::Goz() {
	_instances.push_back(this);
}

Goz::~Goz() {
	_instances.remove(this);
}

} /* namespace factory */
