#include "Train.h"

#include "RailRoadModel/RailRoadElement.h"

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
		
void LocalTrain::set_x(double newVal) {
	x = newVal;				
}
double LocalTrain::x() const {
	return x;
}

void LocalTrain::set_y(double newVal) {
	y = newVal;				
}
double LocalTrain::y() const {
	return y;
}

void LocalTrain::set_id(int newVal) {
	id = newVal;				
}
int LocalTrain::id() const {
	return id;
}


void LocalTrain::set_currentlyOn(::RailRoadModel::IRailRoadElement* newVal) {
	currentlyOn = newVal;				
}
::RailRoadModel::IRailRoadElement* LocalTrain::currentlyOn() const  {
	return currentlyOn;
}

void LocalTrain::set_previouslyOn(::RailRoadModel::IRailRoadElement* newVal) {
	previouslyOn = newVal;				
}
::RailRoadModel::IRailRoadElement* LocalTrain::previouslyOn() const  {
	return previouslyOn;
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
double RemoteTrain::x() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteTrain::set_y(double newVal) {
	throw "Unimplemented feature of Remote Class";			
}
double RemoteTrain::y() const {
	throw "Unimplemented feature of Remote Class";	
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



} /* namespace RailRoadModel */
