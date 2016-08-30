#ifndef RAILROADMODEL_SEGMENT_H_
#define RAILROADMODEL_SEGMENT_H_

#include "../RailRoadModel_decl.h"

#include "../RailRoadModel/RailRoadElement.h"

#include <string>
#include <list>
#include <vector>

namespace RailRoadModel {


class Segment : public RailRoadElement {
public:
	Segment();
	virtual ~Segment();
	static std::list<Segment*> _instances;
	static const unsigned short type_id = 4;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	bool isEnabled = false;
				
	std::vector< ::RailRoadModel::RailRoadElement* > connectedTo;
};

} /* namespace RailRoadModel */

#endif /*  RAILROADMODEL_SEGMENT_H_ */
