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
int LocalNode::id() {
	return _id;
}

void LocalNode::set_responsibleFor(std::vector< int> newVal) {
	_responsibleFor = newVal;				
}
std::vector< int> LocalNode::responsibleFor() {
	return _responsibleFor;
}


void LocalNode::set_executes(std::vector< ::RailRoadModel::Segment* > newVal) {
	_executes = newVal;				
}
std::vector< ::RailRoadModel::Segment* > LocalNode::executes() {
	return _executes;
}

void LocalNode::set_derivedExecutes(std::vector< ::RailRoadModel::Train* > newVal) {
	_derivedExecutes = newVal;				
}
std::vector< ::RailRoadModel::Train* > LocalNode::derivedExecutes() {
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
int RemoteNode::id() {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteNode::set_responsibleFor(std::vector< int> newVal) {
	throw "Unimplemented feature of Remote Class";			
}
std::vector< int> RemoteNode::responsibleFor() {
	throw "Unimplemented feature of Remote Class";	
}


void RemoteNode::set_executes(std::vector< ::RailRoadModel::Segment* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
std::vector< ::RailRoadModel::Segment* > RemoteNode::executes() {
	throw "Unimplemented feature of Remote Class";	
}
void RemoteNode::set_derivedExecutes(std::vector< ::RailRoadModel::Train* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
std::vector< ::RailRoadModel::Train* > RemoteNode::derivedExecutes() {
	throw "Unimplemented feature of Remote Class";	
}


} /* namespace PlatformModel */
