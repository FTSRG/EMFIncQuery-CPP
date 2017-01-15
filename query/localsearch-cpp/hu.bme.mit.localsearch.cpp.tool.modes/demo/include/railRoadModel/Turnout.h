#ifndef RAILROADMODEL_TURNOUT_H_
#define RAILROADMODEL_TURNOUT_H_

#include "railRoadModel_decl.h"

#include "railRoadModel/RailRoadElement.h"

#include <string>
#include <list>
#include <vector>

namespace railRoadModel {


class Turnout : public RailRoadElement {
public:
	Turnout();
	virtual ~Turnout();
	static std::list<Turnout*> _instances;
	static const unsigned short type_id = 2;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	bool currentlyDivergent = false;
	::railRoadModel::State currentState = ::railRoadModel::State::Operational;
				
	::railRoadModel::RailRoadElement* top = nullptr;
	::railRoadModel::RailRoadElement* straight = nullptr;
	::railRoadModel::RailRoadElement* divergent = nullptr;
};

} /* namespace railRoadModel */

#endif /*  RAILROADMODEL_TURNOUT_H_ */
