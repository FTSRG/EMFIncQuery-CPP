#include "ENamedElement.h"


#include <algorithm>

namespace ecore {

std::list<ENamedElement*> ENamedElement::_instances;

ENamedElement::ENamedElement() {
	_instances.push_back(this);
}

ENamedElement::~ENamedElement() {
	_instances.remove(this);
}

} /* namespace ecore */
