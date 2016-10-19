#ifndef FACTORY_ANYAG_H_
#define FACTORY_ANYAG_H_

#include "factory_decl.h"


#include <string>
#include <list>
#include <vector>

namespace factory {


class Anyag  {
public:
	Anyag();
	virtual ~Anyag();
	static std::list<Anyag*> _instances;
	static const unsigned short type_id = 1;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

				
};

} /* namespace factory */

#endif /*  FACTORY_ANYAG_H_ */
