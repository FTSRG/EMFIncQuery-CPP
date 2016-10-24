#include "Robot.h"

#include "railRoadModel/RobotPart.h"

#include <algorithm>

namespace railRoadModel {

std::list<IRobot*> LocalRobot::_instances__x__x__x__x__x__x__x;





LocalRobot::LocalRobot(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, IRobot(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalRobot::~LocalRobot() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		

void LocalRobot::set_robotParts(std::vector< ::railRoadModel::IRobotPart* > newVal) {
	_robotParts = newVal;				
}
const std::vector< ::railRoadModel::IRobotPart* >& LocalRobot::get_robotParts() const  {
	return _robotParts;
}




RemoteRobot::RemoteRobot(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, IRobot(id, true)
{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemoteRobot::~RemoteRobot() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}


void RemoteRobot::set_robotParts(std::vector< ::railRoadModel::IRobotPart* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::railRoadModel::IRobotPart* >& RemoteRobot::get_robotParts() const {
	throw "Unimplemented feature of Remote Class";	
}



} /* namespace railRoadModel */
