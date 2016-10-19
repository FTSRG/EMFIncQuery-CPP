#ifndef FACTORY_SZILARD_H_
#define FACTORY_SZILARD_H_

#include "factory_decl.h"

#include "factory/Halmazallapot.h"

#include <string>
#include <list>
#include <vector>

namespace factory {


class Szilard : public Halmazallapot {
public:
	Szilard();
	virtual ~Szilard();
	static std::list<Szilard*> _instances;
	static const unsigned short type_id = 6;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

				
};

} /* namespace factory */

#endif /*  FACTORY_SZILARD_H_ */
