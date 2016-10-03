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
	_id = newVal;				
}
int LocalRailRoadElement::id() {
	return _id;
}


void LocalRailRoadElement::set_points(std::vector< ::RailRoadModel::Point* > newVal) {
	_points = newVal;				
}
std::vector< ::RailRoadModel::Point* > LocalRailRoadElement::points() {
	return _points;
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
int RemoteRailRoadElement::id() {
	throw "Unimplemented feature of Remote Class";	
}


void RemoteRailRoadElement::set_points(std::vector< ::RailRoadModel::Point* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
std::vector< ::RailRoadModel::Point* > RemoteRailRoadElement::points() {
	throw "Unimplemented feature of Remote Class";	
}


} /* namespace RailRoadModel */
