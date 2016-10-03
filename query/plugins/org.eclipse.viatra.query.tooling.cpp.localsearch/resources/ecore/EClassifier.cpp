#include "EClassifier.h"

#include "../ecore/EPackage.h"
#include "../ecore/ETypeParameter.h"

#include <algorithm>

namespace ecore {

std::list<EClassifier*> EClassifier::_instances;

EClassifier::EClassifier()
: ePackage(nullptr) {
	_instances.push_back(this);
}

EClassifier::~EClassifier() {
	_instances.remove(this);
}

} /* namespace ecore */
