#include "Operational.h"


#include <algorithm>

namespace RailRoadModel {

std::list<IOperational*> LocalOperational::_instances__x__x__x__x__x__x__x;





LocalOperational::LocalOperational(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, IState(id, true)
	, IOperational(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalOperational::~LocalOperational() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		
void LocalOperational::set_id(int newVal) {
	id = newVal;				
}
int LocalOperational::id() const {
	return id;
}





RemoteOperational::RemoteOperational(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, IState(id, false)
, IOperational(id, true)
{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemoteOperational::~RemoteOperational() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}

void RemoteOperational::set_id(int newVal) {
	throw "Unimplemented feature of Remote Class";			
}
int RemoteOperational::id() const {
	throw "Unimplemented feature of Remote Class";	
}




} /* namespace RailRoadModel */
