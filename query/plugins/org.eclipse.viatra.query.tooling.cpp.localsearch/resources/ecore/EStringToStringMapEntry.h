#ifndef ECORE_ESTRINGTOSTRINGMAPENTRY_H_
#define ECORE_ESTRINGTOSTRINGMAPENTRY_H_

#include "../ecore_decl.h"


#include <string>
#include <list>
#include <vector>

namespace ecore {


class EStringToStringMapEntry  {
public:
	EStringToStringMapEntry();
	virtual ~EStringToStringMapEntry();
	static std::list<EStringToStringMapEntry*> _instances;
	static const unsigned short type_id = 17;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	::std::string key = "";
	::std::string value = "";
				
};

} /* namespace ecore */

#endif /*  ECORE_ESTRINGTOSTRINGMAPENTRY_H_ */
