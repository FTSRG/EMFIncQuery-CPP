#include "EStructuralFeature.h"

#include "../ecore/EClass.h"

#include <algorithm>

namespace ecore {

std::list<EStructuralFeature*> EStructuralFeature::_instances;

EStructuralFeature::EStructuralFeature()
: eContainingClass(nullptr) {
	_instances.push_back(this);
}

EStructuralFeature::~EStructuralFeature() {
	_instances.remove(this);
}

} /* namespace ecore */
