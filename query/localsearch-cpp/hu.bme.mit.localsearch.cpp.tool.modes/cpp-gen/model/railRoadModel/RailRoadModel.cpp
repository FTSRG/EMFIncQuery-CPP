#include "RailRoadModel.h"

#include "railRoadModel/RailRoadElement.h"
#include "railRoadModel/Train.h"
#include "railRoadModel/Path.h"

#include <algorithm>

namespace railRoadModel {

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
		

void LocalRailRoadModel::set_segments(std::vector< ::railRoadModel::IRailRoadElement* > newVal) {
	_segments = newVal;				
}
const std::vector< ::railRoadModel::IRailRoadElement* >& LocalRailRoadModel::get_segments() const  {
	return _segments;
}

void LocalRailRoadModel::set_trains(std::vector< ::railRoadModel::ITrain* > newVal) {
	_trains = newVal;				
}
const std::vector< ::railRoadModel::ITrain* >& LocalRailRoadModel::get_trains() const  {
	return _trains;
}

void LocalRailRoadModel::set_paths(std::vector< ::railRoadModel::IPath* > newVal) {
	_paths = newVal;				
}
const std::vector< ::railRoadModel::IPath* >& LocalRailRoadModel::get_paths() const  {
	return _paths;
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


void RemoteRailRoadModel::set_segments(std::vector< ::railRoadModel::IRailRoadElement* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::railRoadModel::IRailRoadElement* >& RemoteRailRoadModel::get_segments() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteRailRoadModel::set_trains(std::vector< ::railRoadModel::ITrain* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::railRoadModel::ITrain* >& RemoteRailRoadModel::get_trains() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteRailRoadModel::set_paths(std::vector< ::railRoadModel::IPath* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::railRoadModel::IPath* >& RemoteRailRoadModel::get_paths() const {
	throw "Unimplemented feature of Remote Class";	
}



} /* namespace railRoadModel */
