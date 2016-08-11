#ifndef CYBERPHYSICALSYSTEM_HOSTTYPE_H_
#define CYBERPHYSICALSYSTEM_HOSTTYPE_H_

#include "cyberPhysicalSystem_decl.h"

#include "cyberPhysicalSystem/Identifiable.h"

#include <string>
#include <list>
#include <vector>

namespace cyberPhysicalSystem {


class HostType : public Identifiable {
public:
	HostType();
	virtual ~HostType();
	static std::list<HostType*> _instances;
	static const unsigned short type_id = 3;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	int defaultCpu = 0;
	int defaultRam = 0;
	int defaultHdd = 0;
	
	::cyberPhysicalSystem::CyberPhysicalSystem* cps = nullptr;
	std::vector< ::cyberPhysicalSystem::HostInstance*> instances;
};

} /* namespace cyberPhysicalSystem */

#endif /*  CYBERPHYSICALSYSTEM_HOSTTYPE_H_ */
