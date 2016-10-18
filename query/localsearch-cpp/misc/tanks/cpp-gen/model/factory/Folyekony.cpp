#include "Folyekony.h"


#include <algorithm>

namespace factory {

std::list<IFolyekony*> LocalFolyekony::_instances__x__x__x__x__x__x__x;





LocalFolyekony::LocalFolyekony(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, IHalmazallapot(id, true)
	, IFolyekony(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalFolyekony::~LocalFolyekony() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		
void LocalFolyekony::set_ID(int newVal) {
	_ID = newVal;				
}
int LocalFolyekony::ID() {
	return _ID;
}





RemoteFolyekony::RemoteFolyekony(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, IHalmazallapot(id, false)
, IFolyekony(id, true)
{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemoteFolyekony::~RemoteFolyekony() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}

void RemoteFolyekony::set_ID(int newVal) {
	throw "Unimplemented feature of Remote Class";			
}
int RemoteFolyekony::ID() {
	throw "Unimplemented feature of Remote Class";	
}




} /* namespace factory */
