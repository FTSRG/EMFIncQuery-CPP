#ifndef ECORE_EENUM_H_
#define ECORE_EENUM_H_

#include "../ecore_decl.h"

#include "../ecore/EDataType.h"

#include <string>
#include <list>
#include <vector>

namespace ecore {


class EEnum : public EDataType {
public:
	EEnum();
	virtual ~EEnum();
	static std::list<EEnum*> _instances;
	static const unsigned short type_id = 5;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

				
	std::vector< ::ecore::EEnumLiteral* > eLiterals;
};

} /* namespace ecore */

#endif /*  ECORE_EENUM_H_ */
