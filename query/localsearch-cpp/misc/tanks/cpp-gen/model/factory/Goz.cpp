#include "Goz.h"


#include <algorithm>

namespace factory {

std::list<IGoz*> LocalGoz::_instances__x__x__x__x__x__x__x;





LocalGoz::LocalGoz(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, IHalmazallapot(id, true)
	, IGoz(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalGoz::~LocalGoz() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		
void LocalGoz::set_ID(int newVal) {
	_ID = newVal;				
}
int LocalGoz::ID() {
	return _ID;
}





RemoteGoz::RemoteGoz(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, IHalmazallapot(id, false)
, IGoz(id, true)
{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemoteGoz::~RemoteGoz() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}

void RemoteGoz::set_ID(int newVal) {
	throw "Unimplemented feature of Remote Class";			
}
int RemoteGoz::ID() {
	throw "Unimplemented feature of Remote Class";	
}




} /* namespace factory */
