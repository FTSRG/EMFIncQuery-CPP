#include "ETypeParameter.h"

#include "../ecore/EGenericType.h"

#include <algorithm>

namespace ecore {

std::list<ETypeParameter*> ETypeParameter::_instances;

ETypeParameter::ETypeParameter()
 {
	_instances.push_back(this);
}

ETypeParameter::~ETypeParameter() {
	_instances.remove(this);
}

} /* namespace ecore */
