#include "Point.h"


#include <algorithm>

namespace railRoadModel {

std::list<IPoint*> LocalPoint::_instances__x__x__x__x__x__x__x;





LocalPoint::LocalPoint(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, IPoint(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalPoint::~LocalPoint() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		
void LocalPoint::set_x(double newVal) {
	_x = newVal;				
}
double LocalPoint::get_x() const {
	return _x;
}

void LocalPoint::set_y(double newVal) {
	_y = newVal;				
}
double LocalPoint::get_y() const {
	return _y;
}





RemotePoint::RemotePoint(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, IPoint(id, true)
{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemotePoint::~RemotePoint() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}

void RemotePoint::set_x(double newVal) {
	throw "Unimplemented feature of Remote Class";			
}
double RemotePoint::get_x() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemotePoint::set_y(double newVal) {
	throw "Unimplemented feature of Remote Class";			
}
double RemotePoint::get_y() const {
	throw "Unimplemented feature of Remote Class";	
}




} /* namespace railRoadModel */
