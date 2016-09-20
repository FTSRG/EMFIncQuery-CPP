#include "Segment.h"

#include "RailRoadModel/RailRoadElement.h"

#include <algorithm>

namespace RailRoadModel {

std::list<ISegment*> LocalSegment::_instances__x__x__x__x__x__x__x;



		
LocalSegment::LocalSegment(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, IRailRoadElement(id, true)
	, ISegment(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalSegment::~LocalSegment() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		
void LocalSegment::set_isEnabled(bool newVal) {
	_isEnabled = newVal;				
}
bool LocalSegment::isEnabled() {
	return _isEnabled;
}

void LocalSegment::set_id(int newVal) {
	_id = newVal;				
}
int LocalSegment::id() {
	return _id;
}


void LocalSegment::set_connectedTo(std::vector< ::RailRoadModel::RailRoadElement* > newVal) {
	_connectedTo = newVal;				
}
std::vector< ::RailRoadModel::RailRoadElement* > LocalSegment::connectedTo() {
	return _connectedTo;
}

void LocalSegment::set_points(std::vector< ::RailRoadModel::Point* > newVal) {
	_points = newVal;				
}
std::vector< ::RailRoadModel::Point* > LocalSegment::points() {
	return _points;
}


		
RemoteSegment::RemoteSegment(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, IRailRoadElement(id, false)
, ISegment(id, true)
	{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemoteSegment::~RemoteSegment() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}

void RemoteSegment::set_isEnabled(bool newVal) {
	throw "Unimplemented feature of Remote Class";			
}
bool RemoteSegment::isEnabled() {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteSegment::set_id(int newVal) {
	throw "Unimplemented feature of Remote Class";			
}
int RemoteSegment::id() {
	throw "Unimplemented feature of Remote Class";	
}


void RemoteSegment::set_connectedTo(std::vector< ::RailRoadModel::RailRoadElement* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
std::vector< ::RailRoadModel::RailRoadElement* > RemoteSegment::connectedTo() {
	throw "Unimplemented feature of Remote Class";	
}
void RemoteSegment::set_points(std::vector< ::RailRoadModel::Point* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
std::vector< ::RailRoadModel::Point* > RemoteSegment::points() {
	throw "Unimplemented feature of Remote Class";	
}


} /* namespace RailRoadModel */
