#include "Segment.h"

#include "railRoadModel/RailRoadElement.h"

#include <algorithm>

namespace railRoadModel {

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
bool LocalSegment::get_isEnabled() const {
	return _isEnabled;
}

void LocalSegment::set_id(int newVal) {
	_id = newVal;				
}
int LocalSegment::get_id() const {
	return _id;
}


void LocalSegment::set_connectedTo(std::vector< ::railRoadModel::IRailRoadElement* > newVal) {
	_connectedTo = newVal;				
}
const std::vector< ::railRoadModel::IRailRoadElement* >& LocalSegment::get_connectedTo() const  {
	return _connectedTo;
}

void LocalSegment::set_points(std::vector< ::railRoadModel::IPoint* > newVal) {
	_points = newVal;				
}
const std::vector< ::railRoadModel::IPoint* >& LocalSegment::get_points() const  {
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
bool RemoteSegment::get_isEnabled() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteSegment::set_id(int newVal) {
	throw "Unimplemented feature of Remote Class";			
}
int RemoteSegment::get_id() const {
	throw "Unimplemented feature of Remote Class";	
}


void RemoteSegment::set_connectedTo(std::vector< ::railRoadModel::IRailRoadElement* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::railRoadModel::IRailRoadElement* >& RemoteSegment::get_connectedTo() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteSegment::set_points(std::vector< ::railRoadModel::IPoint* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::railRoadModel::IPoint* >& RemoteSegment::get_points() const {
	throw "Unimplemented feature of Remote Class";	
}



} /* namespace railRoadModel */
