#include "Train.h"

#include "RailRoadModel/RailRoadElement.h"
#include "RailRoadModel/Point.h"

#include <algorithm>

namespace RailRoadModel {

std::list<ITrain*> LocalTrain::_instances__x__x__x__x__x__x__x;



		
LocalTrain::LocalTrain(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, ITrain(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalTrain::~LocalTrain() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		
void LocalTrain::set_id(int newVal) {
	_id = newVal;				
}
int LocalTrain::id() {
	return _id;
}


void LocalTrain::set_currentlyOn(::RailRoadModel::RailRoadElement* newVal) {
	_currentlyOn = newVal;				
}
::RailRoadModel::RailRoadElement* LocalTrain::currentlyOn() {
	return _currentlyOn;
}

void LocalTrain::set_previouslyOn(::RailRoadModel::RailRoadElement* newVal) {
	_previouslyOn = newVal;				
}
::RailRoadModel::RailRoadElement* LocalTrain::previouslyOn() {
	return _previouslyOn;
}

void LocalTrain::set_point(::RailRoadModel::Point* newVal) {
	_point = newVal;				
}
::RailRoadModel::Point* LocalTrain::point() {
	return _point;
}


		
RemoteTrain::RemoteTrain(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, ITrain(id, true)
	{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemoteTrain::~RemoteTrain() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}

void RemoteTrain::set_id(int newVal) {
	throw "Unimplemented feature of Remote Class";			
}
int RemoteTrain::id() {
	throw "Unimplemented feature of Remote Class";	
}


void RemoteTrain::set_currentlyOn(::RailRoadModel::RailRoadElement* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::RailRoadModel::RailRoadElement* RemoteTrain::currentlyOn() {
	throw "Unimplemented feature of Remote Class";	
}
void RemoteTrain::set_previouslyOn(::RailRoadModel::RailRoadElement* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::RailRoadModel::RailRoadElement* RemoteTrain::previouslyOn() {
	throw "Unimplemented feature of Remote Class";	
}
void RemoteTrain::set_point(::RailRoadModel::Point* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::RailRoadModel::Point* RemoteTrain::point() {
	throw "Unimplemented feature of Remote Class";	
}


} /* namespace RailRoadModel */
