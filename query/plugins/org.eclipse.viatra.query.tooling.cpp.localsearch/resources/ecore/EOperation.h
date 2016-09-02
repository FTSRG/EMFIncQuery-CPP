#ifndef ECORE_EOPERATION_H_
#define ECORE_EOPERATION_H_

#include "../ecore_decl.h"

#include "../ecore/ETypedElement.h"

#include <string>
#include <list>
#include <vector>

namespace ecore {


class EOperation : public ETypedElement {
public:
	EOperation();
	virtual ~EOperation();
	static std::list<EOperation*> _instances;
	static const unsigned short type_id = 11;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

				
	::ecore::EClass* eContainingClass = nullptr;
	std::vector< ::ecore::ETypeParameter* > eTypeParameters;
	std::vector< ::ecore::EParameter* > eParameters;
	std::vector< ::ecore::EClassifier* > eExceptions;
	std::vector< ::ecore::EGenericType* > eGenericExceptions;
};

} /* namespace ecore */

#endif /*  ECORE_EOPERATION_H_ */
