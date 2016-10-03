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
bool LocalSegment::isEnabled() const {
	return _isEnabled;
}

void LocalSegment::set_id(int newVal) {
	_id = newVal;				
}
int LocalSegment::id() const {
	return _id;
}


void LocalSegment::set_connectedTo(std::vector< ::RailRoadModel::IRailRoadElement* > newVal) {
	_connectedTo = newVal;				
}
const std::vector< ::RailRoadModel::IRailRoadElement* >& LocalSegment::connectedTo() const  {
	return _connectedTo;
}

void LocalSegment::set_points(std::vector< ::RailRoadModel::IPoint* > newVal) {
	_points = newVal;				
}
const std::vector< ::RailRoadModel::IPoint* >& LocalSegment::points() const  {
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
bool RemoteSegment::isEnabled() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteSegment::set_id(int newVal) {
	throw "Unimplemented feature of Remote Class";			
}
int RemoteSegment::id() const {
	throw "Unimplemented feature of Remote Class";	
}


void RemoteSegment::set_connectedTo(std::vector< ::RailRoadModel::IRailRoadElement* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::RailRoadModel::IRailRoadElement* >& RemoteSegment::connectedTo() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteSegment::set_points(std::vector< ::RailRoadModel::IPoint* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::RailRoadModel::IPoint* >& RemoteSegment::points() const {
	throw "Unimplemented feature of Remote Class";	
}



} /* namespace RailRoadModel */
