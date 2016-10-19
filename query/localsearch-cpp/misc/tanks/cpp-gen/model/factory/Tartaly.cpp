#include "Tartaly.h"

#include "factory/Anyag.h"
#include "factory/Halmazallapot.h"

#include <algorithm>

namespace factory {

std::list<Tartaly*> Tartaly::_instances;

Tartaly::Tartaly()
: tarol(nullptr),allapot(nullptr) {
	_instances.push_back(this);
}

Tartaly::~Tartaly() {
	_instances.remove(this);
}

} /* namespace factory */
