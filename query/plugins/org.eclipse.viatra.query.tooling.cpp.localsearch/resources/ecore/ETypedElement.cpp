#include "ETypedElement.h"

#include "../ecore/EClassifier.h"
#include "../ecore/EGenericType.h"

#include <algorithm>

namespace ecore {

std::list<ETypedElement*> ETypedElement::_instances;

ETypedElement::ETypedElement()
: eType(nullptr),eGenericType(nullptr) {
	_instances.push_back(this);
}

ETypedElement::~ETypedElement() {
	_instances.remove(this);
}

} /* namespace ecore */
