#ifndef RAILROADMODEL_POINT_H_
#define RAILROADMODEL_POINT_H_

#include "railRoadModel_decl.h"


#include <string>
#include <list>
#include <vector>

namespace railRoadModel {


class Point  {
public:
	Point();
	virtual ~Point();
	static std::list<Point*> _instances;
	static const unsigned short type_id = 3;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	double x = 0.0;
	double y = 0.0;
				
};

} /* namespace railRoadModel */

#endif /*  RAILROADMODEL_POINT_H_ */
