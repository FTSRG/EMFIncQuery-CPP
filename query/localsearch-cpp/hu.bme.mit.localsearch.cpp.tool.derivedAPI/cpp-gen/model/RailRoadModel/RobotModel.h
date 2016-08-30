#ifndef RAILROADMODEL_ROBOTMODEL_H_
#define RAILROADMODEL_ROBOTMODEL_H_

#include "../RailRoadModel_decl.h"


#include <string>
#include <list>
#include <vector>

namespace RailRoadModel {


class RobotModel  {
public:
	RobotModel();
	virtual ~RobotModel();
	static std::list<RobotModel*> _instances;
	static const unsigned short type_id = 8;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

				
	std::vector< ::RailRoadModel::Robot* > robots;
	std::vector< ::RailRoadModel::RobotPart* > robotparts;
};

} /* namespace RailRoadModel */

#endif /*  RAILROADMODEL_ROBOTMODEL_H_ */
