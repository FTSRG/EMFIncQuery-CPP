#ifndef ECORE_EFACTORY_H_
#define ECORE_EFACTORY_H_

#include "../ecore_decl.h"

#include "../ecore/EModelElement.h"

#include <string>
#include <list>
#include <vector>

namespace ecore {


class EFactory : public EModelElement {
public:
	EFactory();
	virtual ~EFactory();
	static std::list<EFactory*> _instances;
	static const unsigned short type_id = 7;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

				
	::ecore::EPackage* ePackage = nullptr;
};

} /* namespace ecore */

#endif /*  ECORE_EFACTORY_H_ */
