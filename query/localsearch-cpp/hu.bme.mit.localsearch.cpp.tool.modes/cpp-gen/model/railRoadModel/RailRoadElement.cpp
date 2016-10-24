#include "RailRoadElement.h"

#include "railRoadModel/Point.h"

#include <algorithm>

namespace railRoadModel {

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
int LocalRailRoadElement::get_id() const {
	return _id;
}


void LocalRailRoadElement::set_points(std::vector< ::railRoadModel::IPoint* > newVal) {
	_points = newVal;				
}
const std::vector< ::railRoadModel::IPoint* >& LocalRailRoadElement::get_points() const  {
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
int RemoteRailRoadElement::get_id() const {
	throw "Unimplemented feature of Remote Class";	
}


void RemoteRailRoadElement::set_points(std::vector< ::railRoadModel::IPoint* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::railRoadModel::IPoint* >& RemoteRailRoadElement::get_points() const {
	throw "Unimplemented feature of Remote Class";	
}



} /* namespace railRoadModel */
