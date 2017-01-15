#ifndef RAILROADMODEL_ROBOT_H_
#define RAILROADMODEL_ROBOT_H_

#include "railRoadModel_decl.h"


#include <string>
#include <list>
#include <vector>

namespace railRoadModel {


class Robot  {
public:
	Robot();
	virtual ~Robot();
	static std::list<Robot*> _instances;
	static const unsigned short type_id = 9;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

				
	std::vector< ::railRoadModel::RobotPart* > robotParts;
};

} /* namespace railRoadModel */

#endif /*  RAILROADMODEL_ROBOT_H_ */
