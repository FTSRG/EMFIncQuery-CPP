#ifndef RAILROADMODEL_ROBOTMODEL_H_
#define RAILROADMODEL_ROBOTMODEL_H_

#include "railRoadModel_decl.h"


#include <string>
#include <list>
#include <vector>

namespace railRoadModel {


class RobotModel  {
public:
	RobotModel();
	virtual ~RobotModel();
	static std::list<RobotModel*> _instances;
	static const unsigned short type_id = 10;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

				
	std::vector< ::railRoadModel::Robot* > robots;
};

} /* namespace railRoadModel */

#endif /*  RAILROADMODEL_ROBOTMODEL_H_ */
