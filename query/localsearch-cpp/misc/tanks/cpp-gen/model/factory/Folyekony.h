#ifndef FACTORY_FOLYEKONY_H_
#define FACTORY_FOLYEKONY_H_

#include "factory_decl.h"

#include "factory/Halmazallapot.h"

#include <string>
#include <list>
#include <vector>

namespace factory {


class Folyekony : public Halmazallapot {
public:
	Folyekony();
	virtual ~Folyekony();
	static std::list<Folyekony*> _instances;
	static const unsigned short type_id = 4;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

				
};

} /* namespace factory */

#endif /*  FACTORY_FOLYEKONY_H_ */
