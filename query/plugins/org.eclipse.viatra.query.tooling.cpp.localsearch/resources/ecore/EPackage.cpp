#include "EPackage.h"

#include "../ecore/EFactory.h"
#include "../ecore/EClassifier.h"
#include "../ecore/EPackage.h"

#include <algorithm>

namespace ecore {

std::list<EPackage*> EPackage::_instances;

EPackage::EPackage()
: eFactoryInstance(nullptr),eSuperPackage(nullptr) {
	_instances.push_back(this);
}

EPackage::~EPackage() {
	_instances.remove(this);
}

} /* namespace ecore */
