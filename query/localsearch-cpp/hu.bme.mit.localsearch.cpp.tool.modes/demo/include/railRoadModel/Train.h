#ifndef RAILROADMODEL_TRAIN_H_
#define RAILROADMODEL_TRAIN_H_

#include "railRoadModel_decl.h"


#include <string>
#include <list>
#include <vector>

namespace railRoadModel {


class Train  {
public:
	Train();
	virtual ~Train();
	static std::list<Train*> _instances;
	static const unsigned short type_id = 0;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	double x = 0.0;
	double y = 0.0;
	int id = 0;
				
	::railRoadModel::RailRoadElement* currentlyOn = nullptr;
	::railRoadModel::RailRoadElement* previouslyOn = nullptr;
};

} /* namespace railRoadModel */

#endif /*  RAILROADMODEL_TRAIN_H_ */
