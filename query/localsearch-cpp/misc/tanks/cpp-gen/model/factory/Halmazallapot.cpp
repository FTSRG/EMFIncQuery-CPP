#include "Halmazallapot.h"


#include <algorithm>

namespace factory {

std::list<Halmazallapot*> Halmazallapot::_instances;

Halmazallapot::Halmazallapot() {
	_instances.push_back(this);
}

Halmazallapot::~Halmazallapot() {
	_instances.remove(this);
}

} /* namespace factory */
