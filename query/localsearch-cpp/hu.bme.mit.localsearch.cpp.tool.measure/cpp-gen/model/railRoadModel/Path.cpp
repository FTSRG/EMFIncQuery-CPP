#include "Path.h"

#include "railRoadModel/RailRoadElement.h"

#include <algorithm>

namespace railRoadModel {

std::list<IPath*> LocalPath::_instances__x__x__x__x__x__x__x;





LocalPath::LocalPath(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, IPath(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalPath::~LocalPath() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		

void LocalPath::set_from(::railRoadModel::IRailRoadElement* newVal) {
	_from = newVal;				
}
::railRoadModel::IRailRoadElement* LocalPath::get_from() const  {
	return _from;
}

void LocalPath::set_via(::railRoadModel::IRailRoadElement* newVal) {
	_via = newVal;				
}
::railRoadModel::IRailRoadElement* LocalPath::get_via() const  {
	return _via;
}

void LocalPath::set_to(::railRoadModel::IRailRoadElement* newVal) {
	_to = newVal;				
}
::railRoadModel::IRailRoadElement* LocalPath::get_to() const  {
	return _to;
}




RemotePath::RemotePath(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, IPath(id, true)
{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemotePath::~RemotePath() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}


void RemotePath::set_from(::railRoadModel::IRailRoadElement* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::railRoadModel::IRailRoadElement* RemotePath::get_from() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemotePath::set_via(::railRoadModel::IRailRoadElement* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::railRoadModel::IRailRoadElement* RemotePath::get_via() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemotePath::set_to(::railRoadModel::IRailRoadElement* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::railRoadModel::IRailRoadElement* RemotePath::get_to() const {
	throw "Unimplemented feature of Remote Class";	
}



} /* namespace railRoadModel */
