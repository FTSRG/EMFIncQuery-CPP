#include "SN.h"

#include "arch/SN.h"

#include <algorithm>

namespace arch {

std::list<ISN*> LocalSN::_instances__x__x__x__x__x__x__x;





LocalSN::LocalSN(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, INode(id, true)
	, ISN(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalSN::~LocalSN() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		
void LocalSN::set_name(::std::string newVal) {
	_name = newVal;				
}
::std::string LocalSN::get_name() const {
	return _name;
}


void LocalSN::set_link(std::vector< ::arch::ISN* > newVal) {
	_link = newVal;				
}
const std::vector< ::arch::ISN* >& LocalSN::get_link() const  {
	return _link;
}




RemoteSN::RemoteSN(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, INode(id, false)
, ISN(id, true)
{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemoteSN::~RemoteSN() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}

void RemoteSN::set_name(::std::string newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::std::string RemoteSN::get_name() const {
	throw "Unimplemented feature of Remote Class";	
}


void RemoteSN::set_link(std::vector< ::arch::ISN* > newVal) {
	throw "Unimplemented feature of Remote Class";			
}
const std::vector< ::arch::ISN* >& RemoteSN::get_link() const {
	throw "Unimplemented feature of Remote Class";	
}



} /* namespace arch */
