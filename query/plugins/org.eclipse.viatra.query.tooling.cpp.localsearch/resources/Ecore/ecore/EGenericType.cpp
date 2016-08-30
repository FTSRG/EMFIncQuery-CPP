#include "EGenericType.h"

#include "../ecore/EGenericType.h"
#include "../ecore/EClassifier.h"
#include "../ecore/ETypeParameter.h"

#include <algorithm>

namespace ecore {

std::list<EGenericType*> EGenericType::_instances;

EGenericType::EGenericType()
: eUpperBound(nullptr),eRawType(nullptr),eLowerBound(nullptr),eTypeParameter(nullptr),eClassifier(nullptr) {
	_instances.push_back(this);
}

EGenericType::~EGenericType() {
	_instances.remove(this);
}

} /* namespace ecore */
