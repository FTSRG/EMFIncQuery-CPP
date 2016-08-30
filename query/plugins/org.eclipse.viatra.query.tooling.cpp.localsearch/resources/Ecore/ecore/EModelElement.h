#ifndef ECORE_EMODELELEMENT_H_
#define ECORE_EMODELELEMENT_H_

#include "../ecore_decl.h"


#include <string>
#include <list>
#include <vector>

namespace ecore {


class EModelElement  {
public:
	EModelElement();
	virtual ~EModelElement();
	static std::list<EModelElement*> _instances;
	static const unsigned short type_id = 8;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

				
	std::vector< ::ecore::EAnnotation* > eAnnotations;
};

} /* namespace ecore */

#endif /*  ECORE_EMODELELEMENT_H_ */
