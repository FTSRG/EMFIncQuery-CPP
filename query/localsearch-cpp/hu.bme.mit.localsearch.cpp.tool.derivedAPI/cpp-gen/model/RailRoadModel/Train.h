#ifndef RAILROADMODEL_TRAIN_H_
#define RAILROADMODEL_TRAIN_H_

#include "../RailRoadModel_decl.h"


#include <string>
#include <list>
#include <vector>

namespace RailRoadModel {


class Train  {
public:
	Train();
	virtual ~Train();
	static std::list<Train*> _instances;
	static const unsigned short type_id = 0;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	int id = 0;
				
	::RailRoadModel::RailRoadElement* currentlyOn = nullptr;
	::RailRoadModel::RailRoadElement* previouslyOn = nullptr;
	::RailRoadModel::Point* point = nullptr;
};

} /* namespace RailRoadModel */

#endif /*  RAILROADMODEL_TRAIN_H_ */
