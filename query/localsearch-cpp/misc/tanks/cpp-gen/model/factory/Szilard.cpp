#include "Szilard.h"


#include <algorithm>

namespace factory {

std::list<Szilard*> Szilard::_instances;

Szilard::Szilard() {
	_instances.push_back(this);
}

Szilard::~Szilard() {
	_instances.remove(this);
}

} /* namespace factory */
