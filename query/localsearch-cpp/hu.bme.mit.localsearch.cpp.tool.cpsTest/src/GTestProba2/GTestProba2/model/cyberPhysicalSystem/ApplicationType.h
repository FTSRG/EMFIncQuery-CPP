#ifndef CYBERPHYSICALSYSTEM_APPLICATIONTYPE_H_
#define CYBERPHYSICALSYSTEM_APPLICATIONTYPE_H_

#include "cyberPhysicalSystem_decl.h"

#include "cyberPhysicalSystem/Identifiable.h"

#include <string>
#include <list>
#include <vector>

namespace cyberPhysicalSystem {


class ApplicationType : public Identifiable {
public:
	ApplicationType();
	virtual ~ApplicationType();
	static std::list<ApplicationType*> _instances;
	static const unsigned short type_id = 2;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	::std::string exeFileLocation = "";
	::std::string exeType = "";
	::std::string zipFileUrl = "";
	
	std::vector< ::cyberPhysicalSystem::ResourceRequirement*> requirements;
	::cyberPhysicalSystem::CyberPhysicalSystem* cps = nullptr;
	std::vector< ::cyberPhysicalSystem::ApplicationInstance*> instances;
	::cyberPhysicalSystem::StateMachine* behavior = nullptr;
};

} /* namespace cyberPhysicalSystem */

#endif /*  CYBERPHYSICALSYSTEM_APPLICATIONTYPE_H_ */
