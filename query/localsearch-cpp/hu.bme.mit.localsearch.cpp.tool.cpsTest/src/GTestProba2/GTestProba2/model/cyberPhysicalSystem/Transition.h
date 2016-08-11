#ifndef CYBERPHYSICALSYSTEM_TRANSITION_H_
#define CYBERPHYSICALSYSTEM_TRANSITION_H_

#include "cyberPhysicalSystem_decl.h"

#include "cyberPhysicalSystem/Identifiable.h"

#include <string>
#include <list>
#include <vector>

namespace cyberPhysicalSystem {


class Transition : public Identifiable {
public:
	Transition();
	virtual ~Transition();
	static std::list<Transition*> _instances;
	static const unsigned short type_id = 11;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	::std::string action = "";
	
	::cyberPhysicalSystem::State* targetState = nullptr;
};

} /* namespace cyberPhysicalSystem */

#endif /*  CYBERPHYSICALSYSTEM_TRANSITION_H_ */
