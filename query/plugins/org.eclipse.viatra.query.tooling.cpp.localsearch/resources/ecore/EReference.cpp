#include "EReference.h"

#include "../ecore/EReference.h"
#include "../ecore/EClass.h"
#include "../ecore/EAttribute.h"

#include <algorithm>

namespace ecore {

std::list<EReference*> EReference::_instances;

EReference::EReference()
: eOpposite(nullptr),eReferenceType(nullptr) {
	_instances.push_back(this);
}

EReference::~EReference() {
	_instances.remove(this);
}

} /* namespace ecore */
