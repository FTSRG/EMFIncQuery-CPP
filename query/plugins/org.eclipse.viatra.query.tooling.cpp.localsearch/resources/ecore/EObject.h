#ifndef ECORE_EOBJECT_H_
#define ECORE_EOBJECT_H_

#include "../ecore_decl.h"


#include <string>
#include <list>
#include <vector>

namespace ecore {


class EObject  {
public:
	EObject();
	virtual ~EObject();
	static std::list<EObject*> _instances;
	static const unsigned short type_id = 10;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

				
};

} /* namespace ecore */

#endif /*  ECORE_EOBJECT_H_ */
