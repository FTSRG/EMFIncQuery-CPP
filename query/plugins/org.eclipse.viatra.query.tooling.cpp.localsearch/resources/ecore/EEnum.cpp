#include "EEnum.h"

#include "../ecore/EEnumLiteral.h"

#include <algorithm>

namespace ecore {

std::list<EEnum*> EEnum::_instances;

EEnum::EEnum()
 {
	_instances.push_back(this);
}

EEnum::~EEnum() {
	_instances.remove(this);
}

} /* namespace ecore */
