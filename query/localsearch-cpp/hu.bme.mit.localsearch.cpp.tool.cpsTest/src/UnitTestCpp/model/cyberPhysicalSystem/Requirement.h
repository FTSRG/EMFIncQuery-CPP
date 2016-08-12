#ifndef CYBERPHYSICALSYSTEM_REQUIREMENT_H_
#define CYBERPHYSICALSYSTEM_REQUIREMENT_H_

#include "cyberPhysicalSystem_decl.h"

#include "cyberPhysicalSystem/Identifiable.h"

#include <string>
#include <list>
#include <vector>

namespace cyberPhysicalSystem {


class Requirement : public Identifiable {
public:
	Requirement();
	virtual ~Requirement();
	static std::list<Requirement*> _instances;
	static const unsigned short type_id = 8;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	int count = 0;
::cyberPhysicalSystem::Request* request = nullptr;
::cyberPhysicalSystem::ApplicationType* type = nullptr;
std::vector< ::cyberPhysicalSystem::ApplicationInstance*> applications;
};

} /* namespace cyberPhysicalSystem */

#endif /*  CYBERPHYSICALSYSTEM_REQUIREMENT_H_ */
