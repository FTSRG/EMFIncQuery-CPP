#include "Folyekony.h"


#include <algorithm>

namespace factory {

std::list<Folyekony*> Folyekony::_instances;

Folyekony::Folyekony() {
	_instances.push_back(this);
}

Folyekony::~Folyekony() {
	_instances.remove(this);
}

} /* namespace factory */
