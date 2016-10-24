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
		
void LocalRobotPart::set_id(int newVal) {
	id = newVal;				
}
int LocalRobotPart::id() const {
	return id;
}


void LocalRobotPart::set_nearBy(std::vector< ::RailRoadModel::ITrain* > newVal) {
	nearBy = newVal;				
}
const std::vector< ::RailRoadModel::ITrain* >& LocalRobotPart::nearBy() const  {
	return nearBy;
}

void LocalRobotPart::set_refSegment(std::vector< ::RailRoadModel::ISegment* > newVal) {
	refSegment = newVal;				
}
const std::vector< ::RailRoadModel::ISegment* >& LocalRobotPart::refSegment() const  {
	return refSegment;
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

void RemoteRobotPart::set_id(int newVal) {
	throw "Unimplemented feature of Remote Class";			
}
int RemoteRobotPart::id() const {
	throw "Unimplemented feature of Remote Class";	
}


void RemoteRobotPart::set_nearBy(std::vector< ::RailRoadModel::ITrain* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::RailRoadModel::ITrain* >& RemoteRobotPart::nearBy() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteRobotPart::set_refSegment(std::vector< ::RailRoadModel::ISegment* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::RailRoadModel::ISegment* >& RemoteRobotPart::refSegment() const {
	throw "Unimplemented feature of Remote Class";	
}



} /* namespace RailRoadModel */
