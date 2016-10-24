#include "RailRoadElement.h"

#include "RailRoadModel/Point.h"

#include <algorithm>

namespace RailRoadModel {

std::list<IRailRoadElement*> LocalRailRoadElement::_instances__x__x__x__x__x__x__x;





LocalRailRoadElement::LocalRailRoadElement(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, IRailRoadElement(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalRailRoadElement::~LocalRailRoadElement() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		
void LocalRailRoadElement::set_id(int newVal) {
	id = newVal;				
}
int LocalRailRoadElement::id() const {
	return id;
}


void LocalRailRoadElement::set_points(std::vector< ::RailRoadModel::IPoint* > newVal) {
	points = newVal;				
}
const std::vector< ::RailRoadModel::IPoint* >& LocalRailRoadElement::points() const  {
	return points;
}




RemoteRailRoadElement::RemoteRailRoadElement(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, IRailRoadElement(id, true)
{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemoteRailRoadElement::~RemoteRailRoadElement() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}

void RemoteRailRoadElement::set_id(int newVal) {
	throw "Unimplemented feature of Remote Class";			
}
int RemoteRailRoadElement::id() const {
	throw "Unimplemented feature of Remote Class";	
}


void RemoteRailRoadElement::set_points(std::vector< ::RailRoadModel::IPoint* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::RailRoadModel::IPoint* >& RemoteRailRoadElement::points() const {
	throw "Unimplemented feature of Remote Class";	
}



} /* namespace RailRoadModel */
