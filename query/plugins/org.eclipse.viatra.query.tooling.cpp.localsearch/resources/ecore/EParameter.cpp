#include "EParameter.h"

#include "../ecore/EOperation.h"

#include <algorithm>

namespace ecore {

std::list<EParameter*> EParameter::_instances;

EParameter::EParameter()
: eOperation(nullptr) {
	_instances.push_back(this);
}

EParameter::~EParameter() {
	_instances.remove(this);
}

} /* namespace ecore */
