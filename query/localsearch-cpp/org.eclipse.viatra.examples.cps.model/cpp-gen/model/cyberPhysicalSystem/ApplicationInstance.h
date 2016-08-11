#ifndef CYBERPHYSICALSYSTEM_APPLICATIONINSTANCE_H_
#define CYBERPHYSICALSYSTEM_APPLICATIONINSTANCE_H_

#include "cyberPhysicalSystem_decl.h"

#include "cyberPhysicalSystem/Identifiable.h"

#include <string>
#include <list>
#include <vector>

namespace cyberPhysicalSystem {


class ApplicationInstance : public Identifiable {
public:
	ApplicationInstance();
	virtual ~ApplicationInstance();
	static std::list<ApplicationInstance*> _instances;
	static const unsigned short type_id = 6;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	::cyberPhysicalSystem::AppState state = ::cyberPhysicalSystem::AppState::Running;
	::std::string dbUser = "";
	::std::string dbPassword = "";
::cyberPhysicalSystem::HostInstance* allocatedTo = nullptr;
std::vector< ::cyberPhysicalSystem::ApplicationInstance*> dependOn;
::cyberPhysicalSystem::ApplicationType* type = nullptr;
};

} /* namespace cyberPhysicalSystem */

#endif /*  CYBERPHYSICALSYSTEM_APPLICATIONINSTANCE_H_ */
