#include "RobotModel.h"

#include "RailRoadModel/Robot.h"

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
	robots = newVal;				
}
const std::vector< ::RailRoadModel::IRobot* >& LocalRobotModel::robots() const  {
	return robots;
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



} /* namespace RailRoadModel */
