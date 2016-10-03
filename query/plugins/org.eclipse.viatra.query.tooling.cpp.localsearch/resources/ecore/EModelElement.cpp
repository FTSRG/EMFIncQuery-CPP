#include "EModelElement.h"

#include "../ecore/EAnnotation.h"

#include <algorithm>

namespace ecore {

std::list<EModelElement*> EModelElement::_instances;

EModelElement::EModelElement()
 {
	_instances.push_back(this);
}

EModelElement::~EModelElement() {
	_instances.remove(this);
}

} /* namespace ecore */
