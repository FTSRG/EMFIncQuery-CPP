#include "Anyag.h"


#include <algorithm>

namespace factory {

std::list<IAnyag*> LocalAnyag::_instances__x__x__x__x__x__x__x;





LocalAnyag::LocalAnyag(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, IAnyag(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalAnyag::~LocalAnyag() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		




RemoteAnyag::RemoteAnyag(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, IAnyag(id, true)
{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemoteAnyag::~RemoteAnyag() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}




} /* namespace factory */
