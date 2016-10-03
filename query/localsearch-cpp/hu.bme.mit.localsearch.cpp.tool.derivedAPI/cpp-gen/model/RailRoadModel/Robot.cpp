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
int LocalRobot::id() const {
	return _id;
}


void LocalRobot::set_parts(std::vector< ::RailRoadModel::IRobotPart* > newVal) {
	_parts = newVal;				
}
const std::vector< ::RailRoadModel::IRobotPart* >& LocalRobot::parts() const  {
	return _parts;
}

void LocalRobot::set_position(::RailRoadModel::IPoint* newVal) {
	_position = newVal;				
}
::RailRoadModel::IPoint* LocalRobot::position() const  {
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
int RemoteRobot::id() const {
	throw "Unimplemented feature of Remote Class";	
}


void RemoteRobot::set_parts(std::vector< ::RailRoadModel::IRobotPart* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::RailRoadModel::IRobotPart* >& RemoteRobot::parts() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteRobot::set_position(::RailRoadModel::IPoint* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::RailRoadModel::IPoint* RemoteRobot::position() const {
	throw "Unimplemented feature of Remote Class";	
}



} /* namespace RailRoadModel */
