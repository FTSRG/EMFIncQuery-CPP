#include "RailRoadModel.h"

#include "RailRoadModel/RailRoadElement.h"
#include "RailRoadModel/Train.h"
#include "RailRoadModel/Path.h"

#include <algorithm>

namespace RailRoadModel {

std::list<IRailRoadModel*> LocalRailRoadModel::_instances__x__x__x__x__x__x__x;





LocalRailRoadModel::LocalRailRoadModel(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, IRailRoadModel(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalRailRoadModel::~LocalRailRoadModel() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		

void LocalRailRoadModel::set_segments(std::vector< ::RailRoadModel::IRailRoadElement* > newVal) {
	segments = newVal;				
}
const std::vector< ::RailRoadModel::IRailRoadElement* >& LocalRailRoadModel::segments() const  {
	return segments;
}

void LocalRailRoadModel::set_trains(std::vector< ::RailRoadModel::ITrain* > newVal) {
	trains = newVal;				
}
const std::vector< ::RailRoadModel::ITrain* >& LocalRailRoadModel::trains() const  {
	return trains;
}

void LocalRailRoadModel::set_paths(std::vector< ::RailRoadModel::IPath* > newVal) {
	paths = newVal;				
}
const std::vector< ::RailRoadModel::IPath* >& LocalRailRoadModel::paths() const  {
	return paths;
}




RemoteRailRoadModel::RemoteRailRoadModel(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, IRailRoadModel(id, true)
{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemoteRailRoadModel::~RemoteRailRoadModel() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}


void RemoteRailRoadModel::set_segments(std::vector< ::RailRoadModel::IRailRoadElement* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::RailRoadModel::IRailRoadElement* >& RemoteRailRoadModel::segments() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteRailRoadModel::set_trains(std::vector< ::RailRoadModel::ITrain* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::RailRoadModel::ITrain* >& RemoteRailRoadModel::trains() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteRailRoadModel::set_paths(std::vector< ::RailRoadModel::IPath* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::RailRoadModel::IPath* >& RemoteRailRoadModel::paths() const {
	throw "Unimplemented feature of Remote Class";	
}



} /* namespace RailRoadModel */
