#include "Node.h"


#include <algorithm>

namespace arch {

std::list<INode*> LocalNode::_instances__x__x__x__x__x__x__x;





LocalNode::LocalNode(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, INode(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalNode::~LocalNode() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		
void LocalNode::set_name(::std::string newVal) {
	_name = newVal;				
}
::std::string LocalNode::get_name() const {
	return _name;
}





RemoteNode::RemoteNode(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, INode(id, true)
{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemoteNode::~RemoteNode() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}

void RemoteNode::set_name(::std::string newVal) {
	throw "Unimplemented feature of Remote Class";			
}
::std::string RemoteNode::get_name() const {
	throw "Unimplemented feature of Remote Class";	
}




} /* namespace arch */
