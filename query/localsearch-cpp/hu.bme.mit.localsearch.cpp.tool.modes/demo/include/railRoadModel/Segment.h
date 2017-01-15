#ifndef RAILROADMODEL_SEGMENT_H_
#define RAILROADMODEL_SEGMENT_H_

#include "railRoadModel_decl.h"

#include "railRoadModel/RailRoadElement.h"

#include <string>
#include <list>
#include <vector>

namespace railRoadModel {


class Segment : public RailRoadElement {
public:
	Segment();
	virtual ~Segment();
	static std::list<Segment*> _instances;
	static const unsigned short type_id = 5;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	bool isEnabled = false;
				
	std::vector< ::railRoadModel::RailRoadElement* > connectedTo;
};

} /* namespace railRoadModel */

#endif /*  RAILROADMODEL_SEGMENT_H_ */
