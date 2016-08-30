#ifndef RAILROADMODEL_POINT_H_
#define RAILROADMODEL_POINT_H_

#include "../RailRoadModel_decl.h"


#include <string>
#include <list>
#include <vector>

namespace RailRoadModel {


class Point  {
public:
	Point();
	virtual ~Point();
	static std::list<Point*> _instances;
	static const unsigned short type_id = 2;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
				
};

} /* namespace RailRoadModel */

#endif /*  RAILROADMODEL_POINT_H_ */
