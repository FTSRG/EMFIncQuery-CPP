#ifndef RAILROADMODEL_ROBOTELEMENT_H_
#define RAILROADMODEL_ROBOTELEMENT_H_

#include "../RailRoadModel_decl.h"


#include <string>
#include <list>
#include <vector>

namespace RailRoadModel {


class RobotElement  {
public:
	RobotElement();
	virtual ~RobotElement();
	static std::list<RobotElement*> _instances;
	static const unsigned short type_id = 5;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	int id = 0;
				
	::RailRoadModel::Point* position = nullptr;
};

} /* namespace RailRoadModel */

#endif /*  RAILROADMODEL_ROBOTELEMENT_H_ */
