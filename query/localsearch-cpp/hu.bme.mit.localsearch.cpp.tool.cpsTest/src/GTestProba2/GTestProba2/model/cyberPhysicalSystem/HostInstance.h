#ifndef CYBERPHYSICALSYSTEM_HOSTINSTANCE_H_
#define CYBERPHYSICALSYSTEM_HOSTINSTANCE_H_

#include "cyberPhysicalSystem_decl.h"

#include "cyberPhysicalSystem/Identifiable.h"

#include <string>
#include <list>
#include <vector>

namespace cyberPhysicalSystem {


class HostInstance : public Identifiable {
public:
	HostInstance();
	virtual ~HostInstance();
	static std::list<HostInstance*> _instances;
	static const unsigned short type_id = 5;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	::std::string nodeIp = "";
	int availableCpu = 0;
	int availableRam = 0;
	int availableHdd = 0;
	int totalCpu = 0;
	int totalRam = 0;
	int totalHdd = 0;
	
	std::vector< ::cyberPhysicalSystem::ApplicationInstance*> applications;
	std::vector< ::cyberPhysicalSystem::HostInstance*> communicateWith;
};

} /* namespace cyberPhysicalSystem */

#endif /*  CYBERPHYSICALSYSTEM_HOSTINSTANCE_H_ */
