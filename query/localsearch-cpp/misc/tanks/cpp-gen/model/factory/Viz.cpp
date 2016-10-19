#include "Viz.h"


#include <algorithm>

namespace factory {

std::list<Viz*> Viz::_instances;

Viz::Viz() {
	_instances.push_back(this);
}

Viz::~Viz() {
	_instances.remove(this);
}

} /* namespace factory */
