#include "EAttribute.h"

#include "../ecore/EDataType.h"

#include <algorithm>

namespace ecore {

std::list<EAttribute*> EAttribute::_instances;

EAttribute::EAttribute()
: eAttributeType(nullptr) {
	_instances.push_back(this);
}

EAttribute::~EAttribute() {
	_instances.remove(this);
}

} /* namespace ecore */
