#include "Frozen.h"


#include <algorithm>

namespace RailRoadModel {

std::list<IFrozen*> LocalFrozen::_instances__x__x__x__x__x__x__x;





LocalFrozen::LocalFrozen(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, IState(id, true)
	, IFrozen(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalFrozen::~LocalFrozen() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		
void LocalFrozen::set_id(int newVal) {
	id = newVal;				
}
int LocalFrozen::id() const {
	return id;
}





RemoteFrozen::RemoteFrozen(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, IState(id, false)
, IFrozen(id, true)
{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemoteFrozen::~RemoteFrozen() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}

void RemoteFrozen::set_id(int newVal) {
	throw "Unimplemented feature of Remote Class";			
}
int RemoteFrozen::id() const {
	throw "Unimplemented feature of Remote Class";	
}




} /* namespace RailRoadModel */
