#include "RobotModel.h"

#include "railRoadModel/Robot.h"

#include <algorithm>

namespace railRoadModel {

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
		

void LocalRobotModel::set_robots(std::vector< ::railRoadModel::IRobot* > newVal) {
	_robots = newVal;				
}
const std::vector< ::railRoadModel::IRobot* >& LocalRobotModel::get_robots() const  {
	return _robots;
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


void RemoteRobotModel::set_robots(std::vector< ::railRoadModel::IRobot* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::railRoadModel::IRobot* >& RemoteRobotModel::get_robots() const {
	throw "Unimplemented feature of Remote Class";	
}



} /* namespace railRoadModel */
