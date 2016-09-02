#ifndef ECORE_ENAMEDELEMENT_H_
#define ECORE_ENAMEDELEMENT_H_

#include "../ecore_decl.h"

#include "../ecore/EModelElement.h"

#include <string>
#include <list>
#include <vector>

namespace ecore {


class ENamedElement : public EModelElement {
public:
	ENamedElement();
	virtual ~ENamedElement();
	static std::list<ENamedElement*> _instances;
	static const unsigned short type_id = 9;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	::std::string name = "";
				
};

} /* namespace ecore */

#endif /*  ECORE_ENAMEDELEMENT_H_ */
