#ifndef ECORE_EDATATYPE_H_
#define ECORE_EDATATYPE_H_

#include "../ecore_decl.h"

#include "../ecore/EClassifier.h"

#include <string>
#include <list>
#include <vector>

namespace ecore {


class EDataType : public EClassifier {
public:
	EDataType();
	virtual ~EDataType();
	static std::list<EDataType*> _instances;
	static const unsigned short type_id = 4;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	bool serializable = false;
				
};

} /* namespace ecore */

#endif /*  ECORE_EDATATYPE_H_ */
