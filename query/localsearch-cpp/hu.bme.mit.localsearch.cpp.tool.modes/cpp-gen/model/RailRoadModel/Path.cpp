#include "Path.h"

#include "RailRoadModel/RailRoadElement.h"

#include <algorithm>

namespace RailRoadModel {

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
		

void LocalPath::set_from(::RailRoadModel::IRailRoadElement* newVal) {
	from = newVal;				
}
::RailRoadModel::IRailRoadElement* LocalPath::from() const  {
	return from;
}

void LocalPath::set_via(::RailRoadModel::IRailRoadElement* newVal) {
	via = newVal;				
}
::RailRoadModel::IRailRoadElement* LocalPath::via() const  {
	return via;
}

void LocalPath::set_to(::RailRoadModel::IRailRoadElement* newVal) {
	to = newVal;				
}
::RailRoadModel::IRailRoadElement* LocalPath::to() const  {
	return to;
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


void RemotePath::set_from(::RailRoadModel::IRailRoadElement* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::RailRoadModel::IRailRoadElement* RemotePath::from() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemotePath::set_via(::RailRoadModel::IRailRoadElement* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::RailRoadModel::IRailRoadElement* RemotePath::via() const {
	throw "Unimplemented feature of Remote Class";	
}

void RemotePath::set_to(::RailRoadModel::IRailRoadElement* newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::RailRoadModel::IRailRoadElement* RemotePath::to() const {
	throw "Unimplemented feature of Remote Class";	
}



} /* namespace RailRoadModel */
