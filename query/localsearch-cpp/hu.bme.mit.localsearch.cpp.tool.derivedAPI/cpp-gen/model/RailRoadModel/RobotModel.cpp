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
		

void LocalRobotModel::set_robots(std::vector< ::RailRoadModel::Robot* > newVal) {
	_robots = newVal;				
}
std::vector< ::RailRoadModel::Robot* > LocalRobotModel::robots() {
	return _robots;
}

void LocalRobotModel::set_robotparts(std::vector< ::RailRoadModel::RobotPart* > newVal) {
	_robotparts = newVal;				
}
std::vector< ::RailRoadModel::RobotPart* > LocalRobotModel::robotparts() {
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


void RemoteRobotModel::set_robots(std::vector< ::RailRoadModel::Robot* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
std::vector< ::RailRoadModel::Robot* > RemoteRobotModel::robots() {
	throw "Unimplemented feature of Remote Class";	
}
void RemoteRobotModel::set_robotparts(std::vector< ::RailRoadModel::RobotPart* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
std::vector< ::RailRoadModel::RobotPart* > RemoteRobotModel::robotparts() {
	throw "Unimplemented feature of Remote Class";	
}


} /* namespace RailRoadModel */
