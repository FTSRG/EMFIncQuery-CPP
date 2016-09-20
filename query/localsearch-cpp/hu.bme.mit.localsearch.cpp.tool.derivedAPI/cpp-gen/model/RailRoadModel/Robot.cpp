#include "Robot.h"

#include "RailRoadModel/RobotPart.h"

#include <algorithm>

namespace RailRoadModel {

std::list<IRobot*> LocalRobot::_instances__x__x__x__x__x__x__x;



		
LocalRobot::LocalRobot(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, IRobotElement(id, true)
	, IRobot(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalRobot::~LocalRobot() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		
void LocalRobot::set_id(int newVal) {
	_id = newVal;				
}
int LocalRobot::id() {
	return _id;
}


void LocalRobot::set_parts(std::vector< ::RailRoadModel::RobotPart* > newVal) {
	_parts = newVal;				
}
std::vector< ::RailRoadModel::RobotPart* > LocalRobot::parts() {
	return _parts;
}

void LocalRobot::set_position(::RailRoadModel::Point* newVal) {
	_position = newVal;				
}
::RailRoadModel::Point* LocalRobot::position() {
	return _position;
}


		
RemoteRobot::RemoteRobot(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, IRobotElement(id, false)
, IRobot(id, true)
	{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemoteRobot::~RemoteRobot() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}

void RemoteRobot::set_id(int newVal) {
	throw "Unimplemented feature of Remote Class";			
}
int RemoteRobot::id() {
	throw "Unimplemented feature of Remote Class";	
}


void RemoteRobot::set_parts(std::vector< ::RailRoadModel::RobotPart* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
std::vector< ::RailRoadModel::RobotPart* > RemoteRobot::parts() {
	throw "Unimplemented feature of Remote Class";	
}
void RemoteRobot::set_position(::RailRoadModel::Point* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::RailRoadModel::Point* RemoteRobot::position() {
	throw "Unimplemented feature of Remote Class";	
}


} /* namespace RailRoadModel */
