#ifndef PLATFORMMODEL_CAMERA_H_
#define PLATFORMMODEL_CAMERA_H_

#include "PlatformModel_decl.h"
#include "RailRoadModel_decl.h"


#include <string>
#include <list>
#include <vector>

namespace PlatformModel {


class Camera  {
public:
	Camera();
	virtual ~Camera();
	static std::list<Camera*> _instances;
	static const unsigned short type_id = 0;

	virtual unsigned short get_type_id() const {
		return type_id;
	}


	std::vector< ::RailRoadModel::Segment* > responsibleFor;
};

} /* namespace PlatformModel */

#endif /*  PLATFORMMODEL_CAMERA_H_ */
