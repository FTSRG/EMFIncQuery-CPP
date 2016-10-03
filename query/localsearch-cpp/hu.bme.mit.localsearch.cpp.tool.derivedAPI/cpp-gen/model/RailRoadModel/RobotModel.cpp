#include "RobotModel.h"

#include "RailRoadModel/Robot.h"
#include "RailRoadModel/RobotPart.h"

#include <algorithm>

namespace RailRoadModel {

std::list<IRobotModel*> LocalRobotModel::_instances__x__x__x__x__x__x__x;





LocalRobotModel::LocalRobotModel(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, IRobotModel(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalRobotModel::~LocalRobotModel() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		

void LocalRobotModel::set_robots(std::vector< ::RailRoadModel::IRobot* > newVal) {
	_robots = newVal;				
}
const std::vector< ::RailRoadModel::IRobot* >& LocalRobotModel::robots() const  {
	return _robots;
}

void LocalRobotModel::set_robotparts(std::vector< ::RailRoadModel::IRobotPart* > newVal) {
	_robotparts = newVal;				
}
const std::vector< ::RailRoadModel::IRobotPart* >& LocalRobotModel::robotparts() const  {
	return _robotparts;
}




RemoteRobotModel::RemoteRobotModel(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, IRobotModel(id, true)
{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemoteRobotModel::~RemoteRobotModel() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}


void RemoteRobotModel::set_robots(std::vector< ::RailRoadModel::IRobot* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::RailRoadModel::IRobot* >& RemoteRobotModel::robots() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteRobotModel::set_robotparts(std::vector< ::RailRoadModel::IRobotPart* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::RailRoadModel::IRobotPart* >& RemoteRobotModel::robotparts() const {
	throw "Unimplemented feature of Remote Class";	
}



} /* namespace RailRoadModel */
