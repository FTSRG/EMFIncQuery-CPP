#ifndef ECORE_EENUMLITERAL_H_
#define ECORE_EENUMLITERAL_H_

#include "../ecore_decl.h"

#include "../ecore/ENamedElement.h"

#include <string>
#include <list>
#include <vector>

namespace ecore {


class EEnumLiteral : public ENamedElement {
public:
	EEnumLiteral();
	virtual ~EEnumLiteral();
	static std::list<EEnumLiteral*> _instances;
	static const unsigned short type_id = 6;

	virtual unsigned short get_type_id() const {
		return type_id;
	}

	int value = 0;
	//EEnumerator instance = ;
	::std::string literal = "";

	::ecore::EEnum* eEnum = nullptr;
};

} /* namespace ecore */

#endif /*  ECORE_EENUMLITERAL_H_ */
