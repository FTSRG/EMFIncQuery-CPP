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
	static constexpr unsigned short type_id = 1;
				
	static constexpr unsigned short get_static_type_id() {
		return type_id;
	}
	
	unsigned short get_type_id() override {
		return type_id;
	}

	virtual void set_id(int newVal) = 0;
	virtual int id() const = 0;
	
	virtual void set_points(std::vector< ::RailRoadModel::IPoint* > newVal) = 0;
	virtual const std::vector< ::RailRoadModel::IPoint* >& points() const = 0;
};


class RemoteRailRoadElement : 
	public Viatra::Query::Model::RemoteElement, 
	public IRailRoadElement
{
public:
	RemoteRailRoadElement(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteRailRoadElement();
	
	unsigned short get_type_id() override {
		return IRailRoadElement::type_id;
	}

	void set_id(int newVal) override;
	int id() const override;
	
	void set_points(std::vector< ::RailRoadModel::IPoint* > newVal) override;
	const std::vector< ::RailRoadModel::IPoint* >& points() const override;
};

class LocalRailRoadElement : 
	public virtual Viatra::Query::Model::LocalElement, 
	public IRailRoadElement
{
private:
	static std::list<IRailRoadElement*> _instances__x__x__x__x__x__x__x;
			
	int id = 0;
	
	std::vector< ::RailRoadModel::IPoint* > points;
	
public:
	LocalRailRoadElement(Viatra::Query::Model::id_t id);
	
	unsigned short get_type_id() override {
		return IRailRoadElement::type_id;
	}

				
	virtual ~LocalRailRoadElement();
	inline static std::list<IRailRoadElement*>& Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	void set_id(int newVal) override;
	int id() const override;

	
	void set_points(std::vector< ::RailRoadModel::IPoint* > newVal) override;
	const std::vector< ::RailRoadModel::IPoint* >& points() const override;
	
};

} /* namespace RailRoadModel */

#endif /*  RAILROADMODEL_RAILROADELEMENT_H_ */
