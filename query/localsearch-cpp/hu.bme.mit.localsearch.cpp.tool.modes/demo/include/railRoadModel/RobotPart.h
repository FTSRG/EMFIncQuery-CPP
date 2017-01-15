#ifndef RAILROADMODEL_ROBOTPART_H_
#define RAILROADMODEL_ROBOTPART_H_

#include "railRoadModel_decl.h"

#include "railRoadModel/RobotElement.h"

#include <string>
#include <list>
#include <vector>

namespace railRoadModel {


class RobotPart : public RobotElement {
public:
	RobotPart();
	virtual ~RobotPart();
	static std::list<RobotPart*> _instances;
	static const unsigned short type_id = 7;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

				
	std::vector< ::railRoadModel::Train* > close;
	std::vector< ::railRoadModel::Segment* > refSegment;
	std::vector< ::railRoadModel::Train* > veryClose;
};

} /* namespace railRoadModel */

#endif /*  RAILROADMODEL_ROBOTPART_H_ */
