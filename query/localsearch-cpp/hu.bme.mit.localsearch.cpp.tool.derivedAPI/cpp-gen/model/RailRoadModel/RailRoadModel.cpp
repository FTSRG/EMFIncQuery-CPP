#include "RailRoadModel.h"

#include "RailRoadModel/RailRoadElement.h"
#include "RailRoadModel/Train.h"

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
		

void LocalRailRoadModel::set_sections(std::vector< ::RailRoadModel::IRailRoadElement* > newVal) {
	_sections = newVal;				
}
const std::vector< ::RailRoadModel::IRailRoadElement* >& LocalRailRoadModel::sections() const  {
	return _sections;
}

void LocalRailRoadModel::set_trains(std::vector< ::RailRoadModel::ITrain* > newVal) {
	_trains = newVal;				
}
const std::vector< ::RailRoadModel::ITrain* >& LocalRailRoadModel::trains() const  {
	return _trains;
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


void RemoteRailRoadModel::set_sections(std::vector< ::RailRoadModel::IRailRoadElement* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::RailRoadModel::IRailRoadElement* >& RemoteRailRoadModel::sections() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteRailRoadModel::set_trains(std::vector< ::RailRoadModel::ITrain* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::RailRoadModel::ITrain* >& RemoteRailRoadModel::trains() const {
	throw "Unimplemented feature of Remote Class";	
}



} /* namespace RailRoadModel */
