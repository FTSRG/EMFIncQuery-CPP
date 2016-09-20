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
		

void LocalRailRoadModel::set_sections(std::vector< ::RailRoadModel::RailRoadElement* > newVal) {
	_sections = newVal;				
}
std::vector< ::RailRoadModel::RailRoadElement* > LocalRailRoadModel::sections() {
	return _sections;
}

void LocalRailRoadModel::set_trains(std::vector< ::RailRoadModel::Train* > newVal) {
	_trains = newVal;				
}
std::vector< ::RailRoadModel::Train* > LocalRailRoadModel::trains() {
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


void RemoteRailRoadModel::set_sections(std::vector< ::RailRoadModel::RailRoadElement* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
std::vector< ::RailRoadModel::RailRoadElement* > RemoteRailRoadModel::sections() {
	throw "Unimplemented feature of Remote Class";	
}
void RemoteRailRoadModel::set_trains(std::vector< ::RailRoadModel::Train* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
std::vector< ::RailRoadModel::Train* > RemoteRailRoadModel::trains() {
	throw "Unimplemented feature of Remote Class";	
}


} /* namespace RailRoadModel */
