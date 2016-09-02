#include "EOperation.h"

#include "../ecore/EClass.h"
#include "../ecore/ETypeParameter.h"
#include "../ecore/EParameter.h"
#include "../ecore/EClassifier.h"
#include "../ecore/EGenericType.h"

#include <algorithm>

namespace ecore {

std::list<EOperation*> EOperation::_instances;

EOperation::EOperation()
: eContainingClass(nullptr) {
	_instances.push_back(this);
}

EOperation::~EOperation() {
	_instances.remove(this);
}

} /* namespace ecore */
