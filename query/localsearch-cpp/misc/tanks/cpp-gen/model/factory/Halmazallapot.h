#ifndef FACTORY_HALMAZALLAPOT_H_
#define FACTORY_HALMAZALLAPOT_H_

#include "factory_decl.h"


#include <string>
#include <list>
#include <vector>

namespace factory {


class Halmazallapot  {
public:
	Halmazallapot();
	virtual ~Halmazallapot();
	static std::list<Halmazallapot*> _instances;
	static const unsigned short type_id = 3;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	int ID = 0;
				
};

} /* namespace factory */

#endif /*  FACTORY_HALMAZALLAPOT_H_ */
