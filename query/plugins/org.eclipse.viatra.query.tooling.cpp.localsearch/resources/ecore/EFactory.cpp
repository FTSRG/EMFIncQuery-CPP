#include "EFactory.h"

#include "../ecore/EPackage.h"

#include <algorithm>

namespace ecore {

std::list<EFactory*> EFactory::_instances;

EFactory::EFactory()
: ePackage(nullptr) {
	_instances.push_back(this);
}

EFactory::~EFactory() {
	_instances.remove(this);
}

} /* namespace ecore */
