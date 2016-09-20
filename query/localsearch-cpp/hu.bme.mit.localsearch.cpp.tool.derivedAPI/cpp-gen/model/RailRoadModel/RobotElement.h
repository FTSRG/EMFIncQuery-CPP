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
	static constexpr unsigned short type_id = 10;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	virtual void set_id(int newVal) = 0;
	virtual int id() = 0;

				
	virtual void set_position(::RailRoadModel::Point* newVal) = 0;
	virtual ::RailRoadModel::Point* position() = 0;
};
	


class RemoteRobotElement : 
													public Viatra::Query::Model::RemoteElement, 
	public IRobotElement
{
public:
	RemoteRobotElement(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteRobotElement();

	void set_id(int newVal) override;
	int id() override;
	
				
	void set_position(::RailRoadModel::Point* newVal) override;
	::RailRoadModel::Point* position() override;
};
	

class LocalRobotElement : 
													public virtual Viatra::Query::Model::LocalElement, 
	public IRobotElement
{
private:
	static std::list<IRobotElement*> _instances__x__x__x__x__x__x__x;
			
	int _id = 0;
				
	::RailRoadModel::Point* _position = nullptr;
	
public:
	LocalRobotElement(Viatra::Query::Model::id_t id);
	virtual ~LocalRobotElement();
	static const unsigned short type_id = 11;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}
	
	inline static std::list<IRobotElement*> Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	void set_id(int newVal) override;
	int id() override;

				
	void set_position(::RailRoadModel::Point* newVal) override;
	::RailRoadModel::Point* position() override;
	
};
	

} /* namespace RailRoadModel */

#endif /*  RAILROADMODEL_ROBOTELEMENT_H_ */
