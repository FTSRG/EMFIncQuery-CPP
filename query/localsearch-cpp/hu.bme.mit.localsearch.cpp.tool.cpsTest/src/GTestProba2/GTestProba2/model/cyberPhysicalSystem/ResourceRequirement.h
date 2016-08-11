#ifndef CYBERPHYSICALSYSTEM_RESOURCEREQUIREMENT_H_
#define CYBERPHYSICALSYSTEM_RESOURCEREQUIREMENT_H_

#include "cyberPhysicalSystem_decl.h"

#include "cyberPhysicalSystem/Identifiable.h"

#include <string>
#include <list>
#include <vector>

namespace cyberPhysicalSystem {


class ResourceRequirement : public Identifiable {
public:
	ResourceRequirement();
	virtual ~ResourceRequirement();
	static std::list<ResourceRequirement*> _instances;
	static const unsigned short type_id = 4;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	int requiredCpu = 0;
	int requiredRam = 0;
	int requiredHdd = 0;
	
	::cyberPhysicalSystem::HostType* type = nullptr;
};

} /* namespace cyberPhysicalSystem */

#endif /*  CYBERPHYSICALSYSTEM_RESOURCEREQUIREMENT_H_ */
