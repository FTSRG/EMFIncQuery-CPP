#ifndef ECORE_ESTRUCTURALFEATURE_H_
#define ECORE_ESTRUCTURALFEATURE_H_

#include "../ecore_decl.h"

#include "../ecore/ETypedElement.h"

#include <string>
#include <list>
#include <vector>

namespace ecore {


class EStructuralFeature : public ETypedElement {
public:
	EStructuralFeature();
	virtual ~EStructuralFeature();
	static std::list<EStructuralFeature*> _instances;
	static const unsigned short type_id = 15;

	virtual unsigned short get_type_id() const {
		return type_id;
	}

	bool changeable = false;
	//bool volatile = false; !!!!C++ keyword
	bool transient = false;
	::std::string defaultValueLiteral = "";
	//EJavaObject defaultValue = ;
	bool unsettable = false;
	bool derived = false;

	::ecore::EClass* eContainingClass = nullptr;
};

} /* namespace ecore */

#endif /*  ECORE_ESTRUCTURALFEATURE_H_ */
