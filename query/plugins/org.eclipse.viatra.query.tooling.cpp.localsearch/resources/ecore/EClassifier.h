#ifndef ECORE_ECLASSIFIER_H_
#define ECORE_ECLASSIFIER_H_

#include "../ecore_decl.h"

#include "../ecore/ENamedElement.h"

#include <string>
#include <list>
#include <vector>

namespace ecore {


class EClassifier : public ENamedElement {
public:
	EClassifier();
	virtual ~EClassifier();
	static std::list<EClassifier*> _instances;
	static const unsigned short type_id = 3;

	virtual unsigned short get_type_id() const {
		return type_id;
	}

	::std::string instanceClassName = "";
	//EJavaClass<?> instanceClass = ;
	//EJavaObject defaultValue = ;
	::std::string instanceTypeName = "";

	::ecore::EPackage* ePackage = nullptr;
	std::vector< ::ecore::ETypeParameter* > eTypeParameters;
};

} /* namespace ecore */

#endif /*  ECORE_ECLASSIFIER_H_ */
