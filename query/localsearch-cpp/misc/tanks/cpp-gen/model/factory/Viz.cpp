#include "Viz.h"


#include <algorithm>

namespace factory {

std::list<IViz*> LocalViz::_instances__x__x__x__x__x__x__x;





LocalViz::LocalViz(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, IAnyag(id, true)
	, IViz(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalViz::~LocalViz() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		




RemoteViz::RemoteViz(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, IAnyag(id, false)
, IViz(id, true)
{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemoteViz::~RemoteViz() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}




} /* namespace factory */
