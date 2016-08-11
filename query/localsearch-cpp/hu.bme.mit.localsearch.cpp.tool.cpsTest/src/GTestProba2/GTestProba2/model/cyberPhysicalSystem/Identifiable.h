#ifndef CYBERPHYSICALSYSTEM_IDENTIFIABLE_H_
#define CYBERPHYSICALSYSTEM_IDENTIFIABLE_H_

#include "cyberPhysicalSystem_decl.h"


#include <string>
#include <list>
#include <vector>

namespace cyberPhysicalSystem {


class Identifiable  {
public:
	Identifiable();
	virtual ~Identifiable();
	static std::list<Identifiable*> _instances;
	static const unsigned short type_id = 0;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	::std::string identifier = "";
	
};

} /* namespace cyberPhysicalSystem */

#endif /*  CYBERPHYSICALSYSTEM_IDENTIFIABLE_H_ */
