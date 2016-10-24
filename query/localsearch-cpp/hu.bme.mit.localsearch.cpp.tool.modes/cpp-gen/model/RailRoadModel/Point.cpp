#include "Point.h"


#include <algorithm>

namespace RailRoadModel {

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
	x = newVal;				
}
double LocalPoint::x() const {
	return x;
}

void LocalPoint::set_y(double newVal) {
	y = newVal;				
}
double LocalPoint::y() const {
	return y;
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
double RemotePoint::x() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemotePoint::set_y(double newVal) {
	throw "Unimplemented feature of Remote Class";			
}
double RemotePoint::y() const {
	throw "Unimplemented feature of Remote Class";	
}




} /* namespace RailRoadModel */
