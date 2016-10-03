#include "RobotPart.h"

#include "RailRoadModel/Train.h"
#include "RailRoadModel/Segment.h"

#include <algorithm>

namespace RailRoadModel {

std::list<IRobotPart*> LocalRobotPart::_instances__x__x__x__x__x__x__x;



		
LocalRobotPart::LocalRobotPart(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, IRobotElement(id, true)
	, IRobotPart(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalRobotPart::~LocalRobotPart() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		
void LocalRobotPart::set_isOperational(bool newVal) {
	_isOperational = newVal;				
}
bool LocalRobotPart::isOperational() {
	return _isOperational;
}

void LocalRobotPart::set_id(int newVal) {
	_id = newVal;				
}
int LocalRobotPart::id() {
	return _id;
}


void LocalRobotPart::set_nearBy(std::vector< ::RailRoadModel::Train* > newVal) {
	_nearBy = newVal;				
}
std::vector< ::RailRoadModel::Train* > LocalRobotPart::nearBy() {
	return _nearBy;
}

void LocalRobotPart::set_refSegment(::RailRoadModel::Segment* newVal) {
	_refSegment = newVal;				
}
::RailRoadModel::Segment* LocalRobotPart::refSegment() {
	return _refSegment;
}

void LocalRobotPart::set_position(::RailRoadModel::Point* newVal) {
	_position = newVal;				
}
::RailRoadModel::Point* LocalRobotPart::position() {
	return _position;
}


		
RemoteRobotPart::RemoteRobotPart(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, IRobotElement(id, false)
, IRobotPart(id, true)
	{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemoteRobotPart::~RemoteRobotPart() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}

void RemoteRobotPart::set_isOperational(bool newVal) {
	throw "Unimplemented feature of Remote Class";			
}
bool RemoteRobotPart::isOperational() {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteRobotPart::set_id(int newVal) {
	throw "Unimplemented feature of Remote Class";			
}
int RemoteRobotPart::id() {
	throw "Unimplemented feature of Remote Class";	
}


void RemoteRobotPart::set_nearBy(std::vector< ::RailRoadModel::Train* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
std::vector< ::RailRoadModel::Train* > RemoteRobotPart::nearBy() {
	throw "Unimplemented feature of Remote Class";	
}
void RemoteRobotPart::set_refSegment(::RailRoadModel::Segment* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::RailRoadModel::Segment* RemoteRobotPart::refSegment() {
	throw "Unimplemented feature of Remote Class";	
}
void RemoteRobotPart::set_position(::RailRoadModel::Point* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::RailRoadModel::Point* RemoteRobotPart::position() {
	throw "Unimplemented feature of Remote Class";	
}


} /* namespace RailRoadModel */
