#include "EClass.h"

#include "../ecore/EClass.h"
#include "../ecore/EOperation.h"
#include "../ecore/EAttribute.h"
#include "../ecore/EReference.h"
#include "../ecore/EStructuralFeature.h"
#include "../ecore/EGenericType.h"

#include <algorithm>

namespace ecore {

std::list<EClass*> EClass::_instances;

EClass::EClass()
: eIDAttribute(nullptr) {
	_instances.push_back(this);
}

EClass::~EClass() {
	_instances.remove(this);
}

} /* namespace ecore */
