#ifndef RAILROADMODEL_PATH_H_
#define RAILROADMODEL_PATH_H_

#include "railRoadModel_decl.h"


#include <string>
#include <list>
#include <vector>

namespace railRoadModel {


class Path  {
public:
	Path();
	virtual ~Path();
	static std::list<Path*> _instances;
	static const unsigned short type_id = 6;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

				
	::railRoadModel::RailRoadElement* from = nullptr;
	::railRoadModel::RailRoadElement* via = nullptr;
	::railRoadModel::RailRoadElement* to = nullptr;
};

} /* namespace railRoadModel */

#endif /*  RAILROADMODEL_PATH_H_ */
