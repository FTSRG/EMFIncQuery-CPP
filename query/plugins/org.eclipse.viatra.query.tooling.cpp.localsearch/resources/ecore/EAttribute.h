#ifndef ECORE_EATTRIBUTE_H_
#define ECORE_EATTRIBUTE_H_

#include "../ecore_decl.h"

#include "../ecore/EStructuralFeature.h"

#include <string>
#include <list>
#include <vector>

namespace ecore {


class EAttribute : public EStructuralFeature {
public:
	EAttribute();
	virtual ~EAttribute();
	static std::list<EAttribute*> _instances;
	static const unsigned short type_id = 0;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	bool iD = false;
				
	::ecore::EDataType* eAttributeType = nullptr;
};

} /* namespace ecore */

#endif /*  ECORE_EATTRIBUTE_H_ */
