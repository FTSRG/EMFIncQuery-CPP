#ifndef ECORE_EPARAMETER_H_
#define ECORE_EPARAMETER_H_

#include "../ecore_decl.h"

#include "../ecore/ETypedElement.h"

#include <string>
#include <list>
#include <vector>

namespace ecore {


class EParameter : public ETypedElement {
public:
	EParameter();
	virtual ~EParameter();
	static std::list<EParameter*> _instances;
	static const unsigned short type_id = 13;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

				
	::ecore::EOperation* eOperation = nullptr;
};

} /* namespace ecore */

#endif /*  ECORE_EPARAMETER_H_ */
