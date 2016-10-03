#include "EDataType.h"


#include <algorithm>

namespace ecore {

std::list<EDataType*> EDataType::_instances;

EDataType::EDataType() {
	_instances.push_back(this);
}

EDataType::~EDataType() {
	_instances.remove(this);
}

} /* namespace ecore */
