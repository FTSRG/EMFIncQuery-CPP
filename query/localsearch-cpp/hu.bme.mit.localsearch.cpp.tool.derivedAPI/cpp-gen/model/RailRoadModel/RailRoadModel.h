#ifndef RAILROADMODEL_RAILROADMODEL_H_
#define RAILROADMODEL_RAILROADMODEL_H_

#include "../RailRoadModel_decl.h"


#include <string>
#include <list>
#include <vector>

namespace RailRoadModel {


class RailRoadModel  {
public:
	RailRoadModel();
	virtual ~RailRoadModel();
	static std::list<RailRoadModel*> _instances;
	static const unsigned short type_id = 3;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

				
	std::vector< ::RailRoadModel::RailRoadElement* > sections;
	std::vector< ::RailRoadModel::Train* > trains;
};

} /* namespace RailRoadModel */

#endif /*  RAILROADMODEL_RAILROADMODEL_H_ */
