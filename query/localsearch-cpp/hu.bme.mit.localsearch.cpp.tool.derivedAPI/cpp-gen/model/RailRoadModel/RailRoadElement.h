#ifndef RAILROADMODEL_RAILROADELEMENT_H_
#define RAILROADMODEL_RAILROADELEMENT_H_

#include "../RailRoadModel_decl.h"


#include <string>
#include <list>
#include <vector>

namespace RailRoadModel {


class RailRoadElement  {
public:
	RailRoadElement();
	virtual ~RailRoadElement();
	static std::list<RailRoadElement*> _instances;
	static const unsigned short type_id = 1;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	int id = 0;
				
	std::vector< ::RailRoadModel::Point* > points;
};

} /* namespace RailRoadModel */

#endif /*  RAILROADMODEL_RAILROADELEMENT_H_ */
