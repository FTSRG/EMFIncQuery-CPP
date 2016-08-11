#ifndef CYBERPHYSICALSYSTEM_REQUEST_H_
#define CYBERPHYSICALSYSTEM_REQUEST_H_

#include "cyberPhysicalSystem_decl.h"

#include "cyberPhysicalSystem/Identifiable.h"

#include <string>
#include <list>
#include <vector>

namespace cyberPhysicalSystem {


class Request : public Identifiable {
public:
	Request();
	virtual ~Request();
	static std::list<Request*> _instances;
	static const unsigned short type_id = 7;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	
	std::vector< ::cyberPhysicalSystem::Requirement*> requirements;
};

} /* namespace cyberPhysicalSystem */

#endif /*  CYBERPHYSICALSYSTEM_REQUEST_H_ */
