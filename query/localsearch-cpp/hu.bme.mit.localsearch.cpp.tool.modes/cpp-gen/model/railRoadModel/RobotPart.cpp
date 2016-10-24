#include "RobotPart.h"

#include "railRoadModel/Train.h"
#include "railRoadModel/Segment.h"

#include <algorithm>

namespace railRoadModel {

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
	_id = newVal;				
}
int LocalRobotPart::get_id() const {
	return _id;
}


void LocalRobotPart::set_nearBy(std::vector< ::railRoadModel::ITrain* > newVal) {
	_nearBy = newVal;				
}
const std::vector< ::railRoadModel::ITrain* >& LocalRobotPart::get_nearBy() const  {
	return _nearBy;
}

void LocalRobotPart::set_refSegment(std::vector< ::railRoadModel::ISegment* > newVal) {
	_refSegment = newVal;				
}
const std::vector< ::railRoadModel::ISegment* >& LocalRobotPart::get_refSegment() const  {
	return _refSegment;
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
int RemoteRobotPart::get_id() const {
	throw "Unimplemented feature of Remote Class";	
}


void RemoteRobotPart::set_nearBy(std::vector< ::railRoadModel::ITrain* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::railRoadModel::ITrain* >& RemoteRobotPart::get_nearBy() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteRobotPart::set_refSegment(std::vector< ::railRoadModel::ISegment* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::railRoadModel::ISegment* >& RemoteRobotPart::get_refSegment() const {
	throw "Unimplemented feature of Remote Class";	
}



} /* namespace railRoadModel */
