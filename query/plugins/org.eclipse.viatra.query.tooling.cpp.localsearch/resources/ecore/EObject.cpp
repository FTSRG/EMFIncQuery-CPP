#include "EObject.h"


#include <algorithm>

namespace ecore {

std::list<EObject*> EObject::_instances;

EObject::EObject() {
	_instances.push_back(this);
}

EObject::~EObject() {
	_instances.remove(this);
}

} /* namespace ecore */
