#ifndef ECORE_EREFERENCE_H_
#define ECORE_EREFERENCE_H_

#include "../ecore_decl.h"

#include "../ecore/EStructuralFeature.h"

#include <string>
#include <list>
#include <vector>

namespace ecore {


class EReference : public EStructuralFeature {
public:
	EReference();
	virtual ~EReference();
	static std::list<EReference*> _instances;
	static const unsigned short type_id = 14;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	bool containment = false;
	bool container = false;
	bool resolveProxies = false;
				
	::ecore::EReference* eOpposite = nullptr;
	::ecore::EClass* eReferenceType = nullptr;
	std::vector< ::ecore::EAttribute* > eKeys;
};

} /* namespace ecore */

#endif /*  ECORE_EREFERENCE_H_ */
