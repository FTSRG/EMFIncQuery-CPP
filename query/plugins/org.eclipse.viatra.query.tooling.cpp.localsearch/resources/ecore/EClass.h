#ifndef ECORE_ECLASS_H_
#define ECORE_ECLASS_H_

#include "../ecore_decl.h"

#include "../ecore/EClassifier.h"

#include <string>
#include <list>
#include <vector>

namespace ecore {


class EClass : public EClassifier {
public:
	EClass();
	virtual ~EClass();
	static std::list<EClass*> _instances;
	static const unsigned short type_id = 2;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	bool abstract = false;
	bool interface = false;
				
	std::vector< ::ecore::EClass* > eSuperTypes;
	std::vector< ::ecore::EOperation* > eOperations;
	std::vector< ::ecore::EAttribute* > eAllAttributes;
	std::vector< ::ecore::EReference* > eAllReferences;
	std::vector< ::ecore::EReference* > eReferences;
	std::vector< ::ecore::EAttribute* > eAttributes;
	std::vector< ::ecore::EReference* > eAllContainments;
	std::vector< ::ecore::EOperation* > eAllOperations;
	std::vector< ::ecore::EStructuralFeature* > eAllStructuralFeatures;
	std::vector< ::ecore::EClass* > eAllSuperTypes;
	::ecore::EAttribute* eIDAttribute = nullptr;
	std::vector< ::ecore::EStructuralFeature* > eStructuralFeatures;
	std::vector< ::ecore::EGenericType* > eGenericSuperTypes;
	std::vector< ::ecore::EGenericType* > eAllGenericSuperTypes;
};

} /* namespace ecore */

#endif /*  ECORE_ECLASS_H_ */
