#ifndef FACTORY_TARTALY_H_
#define FACTORY_TARTALY_H_

#include "factory_decl.h"


#include <string>
#include <list>
#include <vector>

namespace factory {


class Tartaly  {
public:
	Tartaly();
	virtual ~Tartaly();
	static std::list<Tartaly*> _instances;
	static const unsigned short type_id = 0;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	int ID = 0;
				
	::factory::Anyag* tarol = nullptr;
	::factory::Halmazallapot* allapot = nullptr;
};

} /* namespace factory */

#endif /*  FACTORY_TARTALY_H_ */
