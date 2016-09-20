#ifndef RAILROADMODEL_RAILROADELEMENT_H_
#define RAILROADMODEL_RAILROADELEMENT_H_

#include "RailRoadModel_decl.h"


#include <string>
#include <list>
#include <vector>

#include <Viatra/Query/Model/ModelElement.h>
#include <Viatra/Query/Model/RemoteElement.h>
#include <Viatra/Query/Model/LocalElement.h>
#include <Viatra/Query/Model/IModelElemService.h>

namespace RailRoadModel {

class IRailRoadElement;
class RemoteRailRoadElement;
class LocalRailRoadElement;


class IRailRoadElement : 
	public virtual Viatra::Query::Model::ModelElement
{
public:
	using RemoteImplementation = RemoteRailRoadElement;
	using LocalImplementation = LocalRailRoadElement;

	IRailRoadElement(Viatra::Query::Model::id_t id, bool present)
		: ModelElement(id, present)
	{}

	virtual ~IRailRoadElement() {}
	static constexpr unsigned short type_id = 2;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	virtual void set_id(int newVal) = 0;
	virtual int id() = 0;

				
	virtual void set_points(std::vector< ::RailRoadModel::Point* > newVal) = 0;
	virtual std::vector< ::RailRoadModel::Point* > points() = 0;
};
	


class RemoteRailRoadElement : 
													public Viatra::Query::Model::RemoteElement, 
	public IRailRoadElement
{
public:
	RemoteRailRoadElement(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteRailRoadElement();

	void set_id(int newVal) override;
	int id() override;
	
				
	void set_points(std::vector< ::RailRoadModel::Point* > newVal) override;
	std::vector< ::RailRoadModel::Point* > points() override;
};
	

class LocalRailRoadElement : 
													public virtual Viatra::Query::Model::LocalElement, 
	public IRailRoadElement
{
private:
	static std::list<IRailRoadElement*> _instances__x__x__x__x__x__x__x;
			
	int _id = 0;
				
	std::vector< ::RailRoadModel::Point* > _points;
	
public:
	LocalRailRoadElement(Viatra::Query::Model::id_t id);
	virtual ~LocalRailRoadElement();
	static const unsigned short type_id = 3;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}
	
	inline static std::list<IRailRoadElement*> Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	void set_id(int newVal) override;
	int id() override;

				
	void set_points(std::vector< ::RailRoadModel::Point* > newVal) override;
	std::vector< ::RailRoadModel::Point* > points() override;
	
};
	

} /* namespace RailRoadModel */

#endif /*  RAILROADMODEL_RAILROADELEMENT_H_ */
