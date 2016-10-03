#ifndef RAILROADMODEL_RAILROADMODEL_H_
#define RAILROADMODEL_RAILROADMODEL_H_

#include "RailRoadModel_decl.h"


#include <string>
#include <list>
#include <vector>

#include <Viatra/Query/Model/ModelElement.h>
#include <Viatra/Query/Model/RemoteElement.h>
#include <Viatra/Query/Model/LocalElement.h>
#include <Viatra/Query/Model/IModelElemService.h>

namespace RailRoadModel {

class IRailRoadModel;
class RemoteRailRoadModel;
class LocalRailRoadModel;


class IRailRoadModel : 
	public virtual Viatra::Query::Model::ModelElement
{
public:
	using RemoteImplementation = RemoteRailRoadModel;
	using LocalImplementation = LocalRailRoadModel;
	IRailRoadModel(Viatra::Query::Model::id_t id, bool present)
		: ModelElement(id, present)
	{}

	virtual ~IRailRoadModel() {}
	static constexpr unsigned short type_id = 3;
				
	static constexpr unsigned short get_type_id() {
		return type_id;
	}

	
	virtual void set_sections(std::vector< ::RailRoadModel::IRailRoadElement* > newVal) = 0;
	virtual const std::vector< ::RailRoadModel::IRailRoadElement* >& sections() const = 0;
	virtual void set_trains(std::vector< ::RailRoadModel::ITrain* > newVal) = 0;
	virtual const std::vector< ::RailRoadModel::ITrain* >& trains() const = 0;
};


class RemoteRailRoadModel : 
	public Viatra::Query::Model::RemoteElement, 
	public IRailRoadModel
{
public:
	RemoteRailRoadModel(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteRailRoadModel();

	
	void set_sections(std::vector< ::RailRoadModel::IRailRoadElement* > newVal) override;
	const std::vector< ::RailRoadModel::IRailRoadElement* >& sections() const override;
	void set_trains(std::vector< ::RailRoadModel::ITrain* > newVal) override;
	const std::vector< ::RailRoadModel::ITrain* >& trains() const override;
};

class LocalRailRoadModel : 
	public virtual Viatra::Query::Model::LocalElement, 
	public IRailRoadModel
{
private:
	static std::list<IRailRoadModel*> _instances__x__x__x__x__x__x__x;
			
	
	std::vector< ::RailRoadModel::IRailRoadElement* > _sections;
	std::vector< ::RailRoadModel::ITrain* > _trains;
	
public:
	LocalRailRoadModel(Viatra::Query::Model::id_t id);
	virtual ~LocalRailRoadModel();
	inline static std::list<IRailRoadModel*>& Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	
	void set_sections(std::vector< ::RailRoadModel::IRailRoadElement* > newVal) override;
	const std::vector< ::RailRoadModel::IRailRoadElement* >& sections() const override;
	
	void set_trains(std::vector< ::RailRoadModel::ITrain* > newVal) override;
	const std::vector< ::RailRoadModel::ITrain* >& trains() const override;
	
};

} /* namespace RailRoadModel */

#endif /*  RAILROADMODEL_RAILROADMODEL_H_ */
