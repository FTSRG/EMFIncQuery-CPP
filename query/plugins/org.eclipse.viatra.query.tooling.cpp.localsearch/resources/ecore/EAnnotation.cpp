#include "EAnnotation.h"

#include "../ecore/EStringToStringMapEntry.h"
#include "../ecore/EModelElement.h"
#include "../ecore/EObject.h"

#include <algorithm>

namespace ecore {

std::list<EAnnotation*> EAnnotation::_instances;

EAnnotation::EAnnotation()
: eModelElement(nullptr) {
	_instances.push_back(this);
}

EAnnotation::~EAnnotation() {
	_instances.remove(this);
}

} /* namespace ecore */
