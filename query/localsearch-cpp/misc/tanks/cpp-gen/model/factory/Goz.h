#ifndef FACTORY_GOZ_H_
#define FACTORY_GOZ_H_

#include "factory_decl.h"

#include "factory/Halmazallapot.h"

#include <string>
#include <list>
#include <vector>

namespace factory {


class Goz : public Halmazallapot {
public:
	Goz();
	virtual ~Goz();
	static std::list<Goz*> _instances;
	static const unsigned short type_id = 5;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

				
};

} /* namespace factory */

#endif /*  FACTORY_GOZ_H_ */
