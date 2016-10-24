#ifndef RAILROADMODEL_ROBOTMODEL_H_
#define RAILROADMODEL_ROBOTMODEL_H_

#include "RailRoadModel_decl.h"


#include <string>
#include <list>
#include <vector>

#include <Viatra/Query/Model/ModelElement.h>
#include <Viatra/Query/Model/RemoteElement.h>
#include <Viatra/Query/Model/LocalElement.h>
#include <Viatra/Query/Model/IModelElemService.h>

namespace RailRoadModel {

class IRobotModel;
class RemoteRobotModel;
class LocalRobotModel;


class IRobotModel : 
	public virtual Viatra::Query::Model::ModelElement
{
public:
	using RemoteImplementation = RemoteRobotModel;
	using LocalImplementation = LocalRobotModel;
	IRobotModel(Viatra::Query::Model::id_t id, bool present)
		: ModelElement(id, present)
	{}

	virtual ~IRobotModel() {}
	static constexpr unsigned short type_id = 13;
				
	static constexpr unsigned short get_static_type_id() {
		return type_id;
	}
	
	unsigned short get_type_id() override {
		return type_id;
	}

	
	virtual void set_robots(std::vector< ::RailRoadModel::IRobot* > newVal) = 0;
	virtual const std::vector< ::RailRoadModel::IRobot* >& robots() const = 0;
};


class RemoteRobotModel : 
	public Viatra::Query::Model::RemoteElement, 
	public IRobotModel
{
public:
	RemoteRobotModel(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteRobotModel();
	
	unsigned short get_type_id() override {
		return IRobotModel::type_id;
	}

	
	void set_robots(std::vector< ::RailRoadModel::IRobot* > newVal) override;
	const std::vector< ::RailRoadModel::IRobot* >& robots() const override;
};

class LocalRobotModel : 
	public virtual Viatra::Query::Model::LocalElement, 
	public IRobotModel
{
private:
	static std::list<IRobotModel*> _instances__x__x__x__x__x__x__x;
			
	
	std::vector< ::RailRoadModel::IRobot* > robots;
	
public:
	LocalRobotModel(Viatra::Query::Model::id_t id);
	
	unsigned short get_type_id() override {
		return IRobotModel::type_id;
	}

				
	virtual ~LocalRobotModel();
	inline static std::list<IRobotModel*>& Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	
	void set_robots(std::vector< ::RailRoadModel::IRobot* > newVal) override;
	const std::vector< ::RailRoadModel::IRobot* >& robots() const override;
	
};

} /* namespace RailRoadModel */

#endif /*  RAILROADMODEL_ROBOTMODEL_H_ */
