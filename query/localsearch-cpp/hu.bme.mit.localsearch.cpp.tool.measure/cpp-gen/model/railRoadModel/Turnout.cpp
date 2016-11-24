#include "Turnout.h"

#include "railRoadModel/RailRoadElement.h"
#include "railRoadModel/State.h"

#include <algorithm>

namespace railRoadModel {

std::list<ITurnout*> LocalTurnout::_instances__x__x__x__x__x__x__x;





LocalTurnout::LocalTurnout(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, IRailRoadElement(id, true)
	, ITurnout(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalTurnout::~LocalTurnout() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		
void LocalTurnout::set_currentlyDivergent(bool newVal) {
	_currentlyDivergent = newVal;				
}
bool LocalTurnout::get_currentlyDivergent() const {
	return _currentlyDivergent;
}

void LocalTurnout::set_id(int newVal) {
	_id = newVal;				
}
int LocalTurnout::get_id() const {
	return _id;
}


void LocalTurnout::set_top(::railRoadModel::IRailRoadElement* newVal) {
	_top = newVal;				
}
::railRoadModel::IRailRoadElement* LocalTurnout::get_top() const  {
	return _top;
}

void LocalTurnout::set_straight(::railRoadModel::IRailRoadElement* newVal) {
	_straight = newVal;				
}
::railRoadModel::IRailRoadElement* LocalTurnout::get_straight() const  {
	return _straight;
}

void LocalTurnout::set_divergent(::railRoadModel::IRailRoadElement* newVal) {
	_divergent = newVal;				
}
::railRoadModel::IRailRoadElement* LocalTurnout::get_divergent() const  {
	return _divergent;
}

void LocalTurnout::set_currentState(::railRoadModel::IState* newVal) {
	_currentState = newVal;				
}
::railRoadModel::IState* LocalTurnout::get_currentState() const  {
	return _currentState;
}

void LocalTurnout::set_points(std::vector< ::railRoadModel::IPoint* > newVal) {
	_points = newVal;				
}
const std::vector< ::railRoadModel::IPoint* >& LocalTurnout::get_points() const  {
	return _points;
}




RemoteTurnout::RemoteTurnout(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, IRailRoadElement(id, false)
, ITurnout(id, true)
{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemoteTurnout::~RemoteTurnout() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}

void RemoteTurnout::set_currentlyDivergent(bool newVal) {
	throw "Unimplemented feature of Remote Class";			
}
bool RemoteTurnout::get_currentlyDivergent() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteTurnout::set_id(int newVal) {
	throw "Unimplemented feature of Remote Class";			
}
int RemoteTurnout::get_id() const {
	throw "Unimplemented feature of Remote Class";	
}


void RemoteTurnout::set_top(::railRoadModel::IRailRoadElement* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::railRoadModel::IRailRoadElement* RemoteTurnout::get_top() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteTurnout::set_straight(::railRoadModel::IRailRoadElement* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::railRoadModel::IRailRoadElement* RemoteTurnout::get_straight() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteTurnout::set_divergent(::railRoadModel::IRailRoadElement* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::railRoadModel::IRailRoadElement* RemoteTurnout::get_divergent() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteTurnout::set_currentState(::railRoadModel::IState* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::railRoadModel::IState* RemoteTurnout::get_currentState() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteTurnout::set_points(std::vector< ::railRoadModel::IPoint* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::railRoadModel::IPoint* >& RemoteTurnout::get_points() const {
	throw "Unimplemented feature of Remote Class";	
}



} /* namespace railRoadModel */
