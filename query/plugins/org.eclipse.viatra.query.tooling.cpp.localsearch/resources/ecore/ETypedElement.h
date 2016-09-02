#ifndef ECORE_ETYPEDELEMENT_H_
#define ECORE_ETYPEDELEMENT_H_

#include "../ecore_decl.h"

#include "../ecore/ENamedElement.h"

#include <string>
#include <list>
#include <vector>

namespace ecore {


class ETypedElement : public ENamedElement {
public:
	ETypedElement();
	virtual ~ETypedElement();
	static std::list<ETypedElement*> _instances;
	static const unsigned short type_id = 16;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	bool ordered = false;
	bool unique = false;
	int lowerBound = 0;
	int upperBound = 0;
	bool many = false;
	bool required = false;
				
	::ecore::EClassifier* eType = nullptr;
	::ecore::EGenericType* eGenericType = nullptr;
};

} /* namespace ecore */

#endif /*  ECORE_ETYPEDELEMENT_H_ */
