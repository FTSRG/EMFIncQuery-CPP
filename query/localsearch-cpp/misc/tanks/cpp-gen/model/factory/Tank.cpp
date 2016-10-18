#include "Tank.h"

#include "factory/Anyag.h"
#include "factory/Halmazallapot.h"

#include <algorithm>

namespace factory {

std::list<ITank*> LocalTank::_instances__x__x__x__x__x__x__x;





LocalTank::LocalTank(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, ITank(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalTank::~LocalTank() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		
void LocalTank::set_ID(int newVal) {
	_ID = newVal;				
}
int LocalTank::ID() {
	return _ID;
}


void LocalTank::set_tarol(::factory::Anyag* newVal) {
	_tarol = newVal;				
}
::factory::Anyag* LocalTank::tarol() {
	return _tarol;
}

void LocalTank::set_allapot(::factory::Halmazallapot* newVal) {
	_allapot = newVal;				
}
::factory::Halmazallapot* LocalTank::allapot() {
	return _allapot;
}




RemoteTank::RemoteTank(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, ITank(id, true)
{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemoteTank::~RemoteTank() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}

void RemoteTank::set_ID(int newVal) {
	throw "Unimplemented feature of Remote Class";			
}
int RemoteTank::ID() {
	throw "Unimplemented feature of Remote Class";	
}


void RemoteTank::set_tarol(::factory::Anyag* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::factory::Anyag* RemoteTank::tarol() {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteTank::set_allapot(::factory::Halmazallapot* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::factory::Halmazallapot* RemoteTank::allapot() {
	throw "Unimplemented feature of Remote Class";	
}



} /* namespace factory */
