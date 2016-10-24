#include "Node.h"

#include "RailRoadModel/Segment.h"
#include "RailRoadModel/Train.h"

#include <algorithm>

namespace PlatformModel {

std::list<INode*> LocalNode::_instances__x__x__x__x__x__x__x;





LocalNode::LocalNode(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, INode(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalNode::~LocalNode() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		
void LocalNode::set_id(int newVal) {
	_id = newVal;				
}
int LocalNode::id() const {
	return _id;
}

void LocalNode::set_responsibleFor(std::vector< int> newVal) {
	_responsibleFor = newVal;				
}
const std::vector< int>& LocalNode::responsibleFor() const {
	return _responsibleFor;
}


void LocalNode::set_executes(std::vector< ::RailRoadModel::ISegment* > newVal) {
	_executes = newVal;				
}
const std::vector< ::RailRoadModel::ISegment* >& LocalNode::executes() const  {
	return _executes;
}

void LocalNode::set_derivedExecutes(std::vector< ::RailRoadModel::ITrain* > newVal) {
	_derivedExecutes = newVal;				
}
const std::vector< ::RailRoadModel::ITrain* >& LocalNode::derivedExecutes() const  {
	return _derivedExecutes;
}




RemoteNode::RemoteNode(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, INode(id, true)
{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemoteNode::~RemoteNode() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}

void RemoteNode::set_id(int newVal) {
	throw "Unimplemented feature of Remote Class";			
}
int RemoteNode::id() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteNode::set_responsibleFor(std::vector< int> newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< int>& RemoteNode::responsibleFor() const {
	throw "Unimplemented feature of Remote Class";	
}


void RemoteNode::set_executes(std::vector< ::RailRoadModel::ISegment* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::RailRoadModel::ISegment* >& RemoteNode::executes() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteNode::set_derivedExecutes(std::vector< ::RailRoadModel::ITrain* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::RailRoadModel::ITrain* >& RemoteNode::derivedExecutes() const {
	throw "Unimplemented feature of Remote Class";	
}



} /* namespace PlatformModel */
