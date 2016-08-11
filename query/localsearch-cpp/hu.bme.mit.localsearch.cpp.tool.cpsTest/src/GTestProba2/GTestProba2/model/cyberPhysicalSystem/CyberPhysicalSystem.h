#ifndef CYBERPHYSICALSYSTEM_CYBERPHYSICALSYSTEM_H_
#define CYBERPHYSICALSYSTEM_CYBERPHYSICALSYSTEM_H_

#include "cyberPhysicalSystem_decl.h"

#include "cyberPhysicalSystem/Identifiable.h"

#include <string>
#include <list>
#include <vector>

namespace cyberPhysicalSystem {


class CyberPhysicalSystem : public Identifiable {
public:
	CyberPhysicalSystem();
	virtual ~CyberPhysicalSystem();
	static std::list<CyberPhysicalSystem*> _instances;
	static const unsigned short type_id = 1;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	::std::string dbUrl = "";
	
	std::vector< ::cyberPhysicalSystem::ApplicationType*> appTypes;
	std::vector< ::cyberPhysicalSystem::Request*> requests;
	std::vector< ::cyberPhysicalSystem::HostType*> hostTypes;
};

} /* namespace cyberPhysicalSystem */

#endif /*  CYBERPHYSICALSYSTEM_CYBERPHYSICALSYSTEM_H_ */
