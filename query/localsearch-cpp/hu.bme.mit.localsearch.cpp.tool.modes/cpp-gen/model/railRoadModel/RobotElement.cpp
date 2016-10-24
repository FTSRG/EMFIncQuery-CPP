#include "RobotElement.h"


#include <algorithm>

namespace railRoadModel {

std::list<IRobotElement*> LocalRobotElement::_instances__x__x__x__x__x__x__x;





LocalRobotElement::LocalRobotElement(Viatra::Query::Model::id_t id)
	: Viatra::Query::Model::ModelElement(id, true)
	, Viatra::Query::Model::LocalElement(id)
	, IRobotElement(id, true)
{
	_instances__x__x__x__x__x__x__x.push_back(this);
}

LocalRobotElement::~LocalRobotElement() {
	_instances__x__x__x__x__x__x__x.remove(this);
}
		
void LocalRobotElement::set_id(int newVal) {
	_id = newVal;				
}
int LocalRobotElement::get_id() const {
	return _id;
}





RemoteRobotElement::RemoteRobotElement(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv)
: Viatra::Query::Model::ModelElement(id, false)
, Viatra::Query::Model::RemoteElement(id)
, IRobotElement(id, true)
{
	//_instances__x__x__x__x__x__x__x.push_back(this);
}

RemoteRobotElement::~RemoteRobotElement() {
	//_instances__x__x__x__x__x__x__x.remove(this);
}

void RemoteRobotElement::set_id(int newVal) {
	throw "Unimplemented feature of Remote Class";			
}
int RemoteRobotElement::get_id() const {
	throw "Unimplemented feature of Remote Class";	
}




} /* namespace railRoadModel */
