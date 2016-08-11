#ifndef CYBERPHYSICALSYSTEM_STATE_H_
#define CYBERPHYSICALSYSTEM_STATE_H_

#include "cyberPhysicalSystem_decl.h"

#include "cyberPhysicalSystem/Identifiable.h"

#include <string>
#include <list>
#include <vector>

namespace cyberPhysicalSystem {


class State : public Identifiable {
public:
	State();
	virtual ~State();
	static std::list<State*> _instances;
	static const unsigned short type_id = 10;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	
	std::vector< ::cyberPhysicalSystem::Transition*> outgoingTransitions;
};

} /* namespace cyberPhysicalSystem */

#endif /*  CYBERPHYSICALSYSTEM_STATE_H_ */
