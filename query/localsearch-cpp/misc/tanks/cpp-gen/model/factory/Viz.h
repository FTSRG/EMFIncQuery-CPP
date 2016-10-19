#ifndef FACTORY_VIZ_H_
#define FACTORY_VIZ_H_

#include "factory_decl.h"

#include "factory/Anyag.h"

#include <string>
#include <list>
#include <vector>

namespace factory {


class Viz : public Anyag {
public:
	Viz();
	virtual ~Viz();
	static std::list<Viz*> _instances;
	static const unsigned short type_id = 2;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

				
};

} /* namespace factory */

#endif /*  FACTORY_VIZ_H_ */
