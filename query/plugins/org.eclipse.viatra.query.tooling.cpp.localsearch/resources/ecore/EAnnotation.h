#ifndef ECORE_EANNOTATION_H_
#define ECORE_EANNOTATION_H_

#include "../ecore_decl.h"

#include "../ecore/EModelElement.h"

#include <string>
#include <list>
#include <vector>

namespace ecore {


class EAnnotation : public EModelElement {
public:
	EAnnotation();
	virtual ~EAnnotation();
	static std::list<EAnnotation*> _instances;
	static const unsigned short type_id = 1;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	::std::string source = "";
				
	std::vector< ::ecore::EStringToStringMapEntry* > details;
	::ecore::EModelElement* eModelElement = nullptr;
	std::vector< ::ecore::EObject* > contents;
	std::vector< ::ecore::EObject* > references;
};

} /* namespace ecore */

#endif /*  ECORE_EANNOTATION_H_ */
