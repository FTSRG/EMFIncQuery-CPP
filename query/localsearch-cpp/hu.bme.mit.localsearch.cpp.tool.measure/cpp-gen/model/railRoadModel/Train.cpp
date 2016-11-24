#include "Train.h"

#include "railRoadModel/RailRoadElement.h"

#include <algorithm>

namespace railRoadModel {

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
		
void LocalTrain::set_x(double newVal) {
	_x = newVal;				
}
double LocalTrain::get_x() const {
	return _x;
}

void LocalTrain::set_y(double newVal) {
	_y = newVal;				
}
double LocalTrain::get_y() const {
	return _y;
}

void LocalTrain::set_id(int newVal) {
	_id = newVal;				
}
int LocalTrain::get_id() const {
	return _id;
}


void LocalTrain::set_currentlyOn(::railRoadModel::IRailRoadElement* newVal) {
	_currentlyOn = newVal;				
}
::railRoadModel::IRailRoadElement* LocalTrain::get_currentlyOn() const  {
	return _currentlyOn;
}

void LocalTrain::set_previouslyOn(::railRoadModel::IRailRoadElement* newVal) {
	_previouslyOn = newVal;				
}
::railRoadModel::IRailRoadElement* LocalTrain::get_previouslyOn() const  {
	return _previouslyOn;
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

void RemoteTrain::set_x(double newVal) {
	throw "Unimplemented feature of Remote Class";			
}
double RemoteTrain::get_x() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteTrain::set_y(double newVal) {
	throw "Unimplemented feature of Remote Class";			
}
double RemoteTrain::get_y() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteTrain::set_id(int newVal) {
	throw "Unimplemented feature of Remote Class";			
}
int RemoteTrain::get_id() const {
	throw "Unimplemented feature of Remote Class";	
}


void RemoteTrain::set_currentlyOn(::railRoadModel::IRailRoadElement* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::railRoadModel::IRailRoadElement* RemoteTrain::get_currentlyOn() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteTrain::set_previouslyOn(::railRoadModel::IRailRoadElement* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::railRoadModel::IRailRoadElement* RemoteTrain::get_previouslyOn() const {
	throw "Unimplemented feature of Remote Class";	
}



} /* namespace railRoadModel */
