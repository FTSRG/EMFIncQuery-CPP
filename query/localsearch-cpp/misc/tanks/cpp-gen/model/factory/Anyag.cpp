#include "Anyag.h"


#include <algorithm>

namespace factory {

std::list<Anyag*> Anyag::_instances;

Anyag::Anyag() {
	_instances.push_back(this);
}

Anyag::~Anyag() {
	_instances.remove(this);
}

} /* namespace factory */
