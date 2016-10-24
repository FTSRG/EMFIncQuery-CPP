#include "Turnout.h"

#include "RailRoadModel/RailRoadElement.h"
#include "RailRoadModel/State.h"

#include <algorithm>

namespace RailRoadModel {

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
		
void LocalTurnout::set_currentlyDivergent( newVal) {
	currentlyDivergent = newVal;				
}
 LocalTurnout::currentlyDivergent() const {
	return currentlyDivergent;
}

void LocalTurnout::set_id(int newVal) {
	id = newVal;				
}
int LocalTurnout::id() const {
	return id;
}


void LocalTurnout::set_top(::RailRoadModel::IRailRoadElement* newVal) {
	top = newVal;				
}
::RailRoadModel::IRailRoadElement* LocalTurnout::top() const  {
	return top;
}

void LocalTurnout::set_straight(::RailRoadModel::IRailRoadElement* newVal) {
	straight = newVal;				
}
::RailRoadModel::IRailRoadElement* LocalTurnout::straight() const  {
	return straight;
}

void LocalTurnout::set_divergent(::RailRoadModel::IRailRoadElement* newVal) {
	divergent = newVal;				
}
::RailRoadModel::IRailRoadElement* LocalTurnout::divergent() const  {
	return divergent;
}

void LocalTurnout::set_currentState(::RailRoadModel::IState* newVal) {
	currentState = newVal;				
}
::RailRoadModel::IState* LocalTurnout::currentState() const  {
	return currentState;
}

void LocalTurnout::set_points(std::vector< ::RailRoadModel::IPoint* > newVal) {
	points = newVal;				
}
const std::vector< ::RailRoadModel::IPoint* >& LocalTurnout::points() const  {
	return points;
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

void RemoteTurnout::set_currentlyDivergent( newVal) {
	throw "Unimplemented feature of Remote Class";			
}
 RemoteTurnout::currentlyDivergent() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteTurnout::set_id(int newVal) {
	throw "Unimplemented feature of Remote Class";			
}
int RemoteTurnout::id() const {
	throw "Unimplemented feature of Remote Class";	
}


void RemoteTurnout::set_top(::RailRoadModel::IRailRoadElement* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::RailRoadModel::IRailRoadElement* RemoteTurnout::top() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteTurnout::set_straight(::RailRoadModel::IRailRoadElement* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::RailRoadModel::IRailRoadElement* RemoteTurnout::straight() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteTurnout::set_divergent(::RailRoadModel::IRailRoadElement* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::RailRoadModel::IRailRoadElement* RemoteTurnout::divergent() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteTurnout::set_currentState(::RailRoadModel::IState* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::RailRoadModel::IState* RemoteTurnout::currentState() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteTurnout::set_points(std::vector< ::RailRoadModel::IPoint* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::RailRoadModel::IPoint* >& RemoteTurnout::points() const {
	throw "Unimplemented feature of Remote Class";	
}



} /* namespace RailRoadModel */
