#include "Halmazallapot.h"


#include <algorithm>

namespace factory {

std::list<IHalmazallapot*> LocalHalmazallapot::_instances__x__x__x__x__x__x__x;





LocalHalmazallapot::LocalHalmazallapot(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, IHalmazallapot(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalHalmazallapot::~LocalHalmazallapot() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		
void LocalHalmazallapot::set_ID(int newVal) {
	_ID = newVal;				
}
int LocalHalmazallapot::ID() {
	return _ID;
}





RemoteHalmazallapot::RemoteHalmazallapot(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, IHalmazallapot(id, true)
{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemoteHalmazallapot::~RemoteHalmazallapot() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}

void RemoteHalmazallapot::set_ID(int newVal) {
	throw "Unimplemented feature of Remote Class";			
}
int RemoteHalmazallapot::ID() {
	throw "Unimplemented feature of Remote Class";	
}




} /* namespace factory */
