#ifndef RAILROADMODEL_ROBOTPART_H_
#define RAILROADMODEL_ROBOTPART_H_

#include "../RailRoadModel_decl.h"

#include "../RailRoadModel/RobotElement.h"

#include <string>
#include <list>
#include <vector>

namespace RailRoadModel {


class RobotPart : public RobotElement {
public:
	RobotPart();
	virtual ~RobotPart();
	static std::list<RobotPart*> _instances;
	static const unsigned short type_id = 7;

	virtual unsigned short get_type_id() const {
		return type_id;
	}

	bool isOperational = false;

	std::vector< ::RailRoadModel::Train* > nearBy;
};

} /* namespace RailRoadModel */

#endif /*  RAILROADMODEL_ROBOTPART_H_ */
