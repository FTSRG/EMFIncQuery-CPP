#ifndef ECORE_ETYPEPARAMETER_H_
#define ECORE_ETYPEPARAMETER_H_

#include "../ecore_decl.h"

#include "../ecore/ENamedElement.h"

#include <string>
#include <list>
#include <vector>

namespace ecore {


class ETypeParameter : public ENamedElement {
public:
	ETypeParameter();
	virtual ~ETypeParameter();
	static std::list<ETypeParameter*> _instances;
	static const unsigned short type_id = 19;

	virtual unsigned short get_type_id() const {
		return type_id;
	}


	std::vector< ::ecore::EGenericType* > eBounds;
};

} /* namespace ecore */

#endif /*  ECORE_ETYPEPARAMETER_H_ */
