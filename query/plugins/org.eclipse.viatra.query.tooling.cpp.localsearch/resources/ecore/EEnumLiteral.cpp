#include "EEnumLiteral.h"

#include "../ecore/EEnum.h"

#include <algorithm>

namespace ecore {

std::list<EEnumLiteral*> EEnumLiteral::_instances;

EEnumLiteral::EEnumLiteral()
: eEnum(nullptr) {
	_instances.push_back(this);
}

EEnumLiteral::~EEnumLiteral() {
	_instances.remove(this);
}

} /* namespace ecore */
