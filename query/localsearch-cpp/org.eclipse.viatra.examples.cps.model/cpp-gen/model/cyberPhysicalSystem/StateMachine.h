#ifndef CYBERPHYSICALSYSTEM_STATEMACHINE_H_
#define CYBERPHYSICALSYSTEM_STATEMACHINE_H_

#include "cyberPhysicalSystem_decl.h"

#include "cyberPhysicalSystem/Identifiable.h"

#include <string>
#include <list>
#include <vector>

namespace cyberPhysicalSystem {


class StateMachine : public Identifiable {
public:
	StateMachine();
	virtual ~StateMachine();
	static std::list<StateMachine*> _instances;
	static const unsigned short type_id = 9;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

std::vector< ::cyberPhysicalSystem::State*> states;
::cyberPhysicalSystem::State* initial = nullptr;
};

} /* namespace cyberPhysicalSystem */

#endif /*  CYBERPHYSICALSYSTEM_STATEMACHINE_H_ */
