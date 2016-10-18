#include "Szilard.h"


#include <algorithm>

namespace factory {

std::list<ISzilard*> LocalSzilard::_instances__x__x__x__x__x__x__x;





LocalSzilard::LocalSzilard(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, IHalmazallapot(id, true)
	, ISzilard(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalSzilard::~LocalSzilard() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		
void LocalSzilard::set_ID(int newVal) {
	_ID = newVal;				
}
int LocalSzilard::ID() {
	return _ID;
}





RemoteSzilard::RemoteSzilard(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, IHalmazallapot(id, false)
, ISzilard(id, true)
{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemoteSzilard::~RemoteSzilard() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}

void RemoteSzilard::set_ID(int newVal) {
	throw "Unimplemented feature of Remote Class";			
}
int RemoteSzilard::ID() {
	throw "Unimplemented feature of Remote Class";	
}




} /* namespace factory */
