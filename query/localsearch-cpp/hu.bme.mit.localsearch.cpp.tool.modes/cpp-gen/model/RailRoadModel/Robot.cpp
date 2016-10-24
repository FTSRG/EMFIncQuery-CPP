#include "Robot.h"

#include "RailRoadModel/RobotPart.h"

#include <algorithm>

namespace RailRoadModel {

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
		

void LocalRobot::set_robotParts(std::vector< ::RailRoadModel::IRobotPart* > newVal) {
	robotParts = newVal;				
}
const std::vector< ::RailRoadModel::IRobotPart* >& LocalRobot::robotParts() const  {
	return robotParts;
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


void RemoteRobot::set_robotParts(std::vector< ::RailRoadModel::IRobotPart* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::RailRoadModel::IRobotPart* >& RemoteRobot::robotParts() const {
	throw "Unimplemented feature of Remote Class";	
}



} /* namespace RailRoadModel */
