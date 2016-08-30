#ifndef ECORE_EGENERICTYPE_H_
#define ECORE_EGENERICTYPE_H_

#include "../ecore_decl.h"


#include <string>
#include <list>
#include <vector>

namespace ecore {


class EGenericType  {
public:
	EGenericType();
	virtual ~EGenericType();
	static std::list<EGenericType*> _instances;
	static const unsigned short type_id = 18;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

				
	::ecore::EGenericType* eUpperBound = nullptr;
	std::vector< ::ecore::EGenericType* > eTypeArguments;
	::ecore::EClassifier* eRawType = nullptr;
	::ecore::EGenericType* eLowerBound = nullptr;
	::ecore::ETypeParameter* eTypeParameter = nullptr;
	::ecore::EClassifier* eClassifier = nullptr;
};

} /* namespace ecore */

#endif /*  ECORE_EGENERICTYPE_H_ */
