#ifndef ECORE_EPACKAGE_H_
#define ECORE_EPACKAGE_H_

#include "../ecore_decl.h"

#include "../ecore/ENamedElement.h"

#include <string>
#include <list>
#include <vector>

namespace ecore {


class EPackage : public ENamedElement {
public:
	EPackage();
	virtual ~EPackage();
	static std::list<EPackage*> _instances;
	static const unsigned short type_id = 12;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	::std::string nsURI = "";
	::std::string nsPrefix = "";
				
	::ecore::EFactory* eFactoryInstance = nullptr;
	std::vector< ::ecore::EClassifier* > eClassifiers;
	std::vector< ::ecore::EPackage* > eSubpackages;
	::ecore::EPackage* eSuperPackage = nullptr;
};

} /* namespace ecore */

#endif /*  ECORE_EPACKAGE_H_ */
