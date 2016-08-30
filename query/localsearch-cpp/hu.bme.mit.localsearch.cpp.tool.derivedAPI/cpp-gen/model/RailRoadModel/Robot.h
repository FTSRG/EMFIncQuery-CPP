#ifndef RAILROADMODEL_ROBOT_H_
#define RAILROADMODEL_ROBOT_H_

#include "../RailRoadModel_decl.h"

#include "../RailRoadModel/RobotElement.h"

#include <string>
#include <list>
#include <vector>

namespace RailRoadModel {


class Robot : public RobotElement {
public:
	Robot();
	virtual ~Robot();
	static std::list<Robot*> _instances;
	static const unsigned short type_id = 6;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

				
	std::vector< ::RailRoadModel::RobotPart* > parts;
};

} /* namespace RailRoadModel */

#endif /*  RAILROADMODEL_ROBOT_H_ */
