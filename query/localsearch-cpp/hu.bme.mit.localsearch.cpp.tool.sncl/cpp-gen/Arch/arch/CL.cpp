#include "CL.h"

#include "arch/SN.h"

#include <algorithm>

namespace arch {

std::list<ICL*> LocalCL::_instances__x__x__x__x__x__x__x;





LocalCL::LocalCL(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, INode(id, true)
	, ICL(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalCL::~LocalCL() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		
void LocalCL::set_countReachableSN(int newVal) {
	_countReachableSN = newVal;				
}
int LocalCL::get_countReachableSN() const {
	return _countReachableSN;
}

void LocalCL::set_name(::std::string newVal) {
	_name = newVal;				
}
::std::string LocalCL::get_name() const {
	return _name;
}


void LocalCL::set_cnn(::arch::ISN* newVal) {
	_cnn = newVal;				
}
::arch::ISN* LocalCL::get_cnn() const  {
	return _cnn;
}




RemoteCL::RemoteCL(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, INode(id, false)
, ICL(id, true)
{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemoteCL::~RemoteCL() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}

void RemoteCL::set_countReachableSN(int newVal) {
	throw "Unimplemented feature of Remote Class";			
}
int RemoteCL::get_countReachableSN() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemoteCL::set_name(::std::string newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::std::string RemoteCL::get_name() const {
	throw "Unimplemented feature of Remote Class";	
}


void RemoteCL::set_cnn(::arch::ISN* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::arch::ISN* RemoteCL::get_cnn() const {
	throw "Unimplemented feature of Remote Class";	
}



} /* namespace arch */
