#include "State.h"


#include <algorithm>

namespace RailRoadModel {

std::list<IState*> LocalState::_instances__x__x__x__x__x__x__x;





LocalState::LocalState(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, IState(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalState::~LocalState() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		
void LocalState::set_id(int newVal) {
	id = newVal;				
}
int LocalState::id() const {
	return id;
}





RemoteState::RemoteState(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, IState(id, true)
{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemoteState::~RemoteState() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}

void RemoteState::set_id(int newVal) {
	throw "Unimplemented feature of Remote Class";			
}
int RemoteState::id() const {
	throw "Unimplemented feature of Remote Class";	
}




} /* namespace RailRoadModel */
