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
int LocalTrain::id() const {
	return _id;
}


void LocalTrain::set_currentlyOn(::RailRoadModel::IRailRoadElement* newVal) {
	_currentlyOn = newVal;				
}
::RailRoadModel::IRailRoadElement* LocalTrain::currentlyOn() const  {
	return _currentlyOn;
}

void LocalTrain::set_previouslyOn(::RailRoadModel::IRailRoadElement* newVal) {
	_previouslyOn = newVal;				
}
::RailRoadModel::IRailRoadElement* LocalTrain::previouslyOn() const  {
	return _previouslyOn;
}

void LocalTrain::set_point(::RailRoadModel::IPoint* newVal) {
	_point = newVal;				
}
::RailRoadModel::IPoint* LocalTrain::point() const  {
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
int RemoteTrain::id() const {
	throw "Unimplemented feature of Remote Class";	
}


void RemoteTrain::set_currentlyOn(::RailRoadModel::IRailRoadElement* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::RailRoadModel::IRailRoadElement* RemoteTrain::currentlyOn() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteTrain::set_previouslyOn(::RailRoadModel::IRailRoadElement* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::RailRoadModel::IRailRoadElement* RemoteTrain::previouslyOn() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteTrain::set_point(::RailRoadModel::IPoint* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::RailRoadModel::IPoint* RemoteTrain::point() const {
	throw "Unimplemented feature of Remote Class";	
}



} /* namespace RailRoadModel */
