#ifndef PLATFORMMODEL_NODE_H_
#define PLATFORMMODEL_NODE_H_

#include "PlatformModel_decl.h"
#include "RailRoadModel_decl.h"

#include <string>
#include <list>
#include <vector>

namespace PlatformModel {


class Node  {
public:
	Node();
	virtual ~Node();
	static std::list<Node*> _instances;
	static const unsigned short type_id = 0;

	virtual unsigned short get_type_id() const {
		return type_id;
	}

	int id = 0;
	std::vector< int> responsibleFor;

	std::vector< ::RailRoadModel::Segment* > executes;
	std::vector< ::RailRoadModel::Train* > derivedExecutes;
};

} /* namespace PlatformModel */

#endif /*  PLATFORMMODEL_NODE_H_ */
