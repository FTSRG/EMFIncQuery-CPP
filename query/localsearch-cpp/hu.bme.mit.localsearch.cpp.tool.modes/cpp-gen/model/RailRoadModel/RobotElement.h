#ifndef RAILROADMODEL_ROBOTELEMENT_H_
#define RAILROADMODEL_ROBOTELEMENT_H_

#include "RailRoadModel_decl.h"


#include <string>
#include <list>
#include <vector>

#include <Viatra/Query/Model/ModelElement.h>
#include <Viatra/Query/Model/RemoteElement.h>
#include <Viatra/Query/Model/LocalElement.h>
#include <Viatra/Query/Model/IModelElemService.h>

namespace RailRoadModel {

class IRobotElement;
class RemoteRobotElement;
class LocalRobotElement;


class IRobotElement : 
	public virtual Viatra::Query::Model::ModelElement
{
public:
	using RemoteImplementation = RemoteRobotElement;
	using LocalImplementation = LocalRobotElement;
	IRobotElement(Viatra::Query::Model::id_t id, bool present)
		: ModelElement(id, present)
	{}

	virtual ~IRobotElement() {}
	static constexpr unsigned short type_id = 8;
				
	static constexpr unsigned short get_static_type_id() {
		return type_id;
	}
	
	unsigned short get_type_id() override {
		return type_id;
	}

	virtual void set_id(int newVal) = 0;
	virtual int id() const = 0;
	
};


class RemoteRobotElement : 
	public Viatra::Query::Model::RemoteElement, 
	public IRobotElement
{
public:
	RemoteRobotElement(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteRobotElement();
	
	unsigned short get_type_id() override {
		return IRobotElement::type_id;
	}

	void set_id(int newVal) override;
	int id() const override;
	
};

class LocalRobotElement : 
	public virtual Viatra::Query::Model::LocalElement, 
	public IRobotElement
{
private:
	static std::list<IRobotElement*> _instances__x__x__x__x__x__x__x;
			
	int id = 0;
	
	
public:
	LocalRobotElement(Viatra::Query::Model::id_t id);
	
	unsigned short get_type_id() override {
		return IRobotElement::type_id;
	}

				
	virtual ~LocalRobotElement();
	inline static std::list<IRobotElement*>& Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	void set_id(int newVal) override;
	int id() const override;

	
};

} /* namespace RailRoadModel */

#endif /*  RAILROADMODEL_ROBOTELEMENT_H_ */
