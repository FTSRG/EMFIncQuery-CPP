#ifndef RAILROADMODEL_RAILROADMODEL_H_
#define RAILROADMODEL_RAILROADMODEL_H_

#include "railRoadModel_decl.h"


#include <string>
#include <list>
#include <vector>

namespace railRoadModel {


class RailRoadModel  {
public:
	RailRoadModel();
	virtual ~RailRoadModel();
	static std::list<RailRoadModel*> _instances;
	static const unsigned short type_id = 4;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

				
	std::vector< ::railRoadModel::RailRoadElement* > segments;
	std::vector< ::railRoadModel::Train* > trains;
	std::vector< ::railRoadModel::Path* > paths;
};

} /* namespace railRoadModel */

#endif /*  RAILROADMODEL_RAILROADMODEL_H_ */
