#include "EStringToStringMapEntry.h"


#include <algorithm>

namespace ecore {

std::list<EStringToStringMapEntry*> EStringToStringMapEntry::_instances;

EStringToStringMapEntry::EStringToStringMapEntry() {
	_instances.push_back(this);
}

EStringToStringMapEntry::~EStringToStringMapEntry() {
	_instances.remove(this);
}

} /* namespace ecore */
