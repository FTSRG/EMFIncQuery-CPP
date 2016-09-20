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
	static constexpr unsigned short type_id = 16;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

				
	virtual void set_robots(std::vector< ::RailRoadModel::Robot* > newVal) = 0;
	virtual std::vector< ::RailRoadModel::Robot* > robots() = 0;
	virtual void set_robotparts(std::vector< ::RailRoadModel::RobotPart* > newVal) = 0;
	virtual std::vector< ::RailRoadModel::RobotPart* > robotparts() = 0;
};
	


class RemoteRobotModel : 
													public Viatra::Query::Model::RemoteElement, 
	public IRobotModel
{
public:
	RemoteRobotModel(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteRobotModel();

	
				
	void set_robots(std::vector< ::RailRoadModel::Robot* > newVal) override;
	std::vector< ::RailRoadModel::Robot* > robots() override;
	void set_robotparts(std::vector< ::RailRoadModel::RobotPart* > newVal) override;
	std::vector< ::RailRoadModel::RobotPart* > robotparts() override;
};
	

class LocalRobotModel : 
													public virtual Viatra::Query::Model::LocalElement, 
	public IRobotModel
{
private:
	static std::list<IRobotModel*> _instances__x__x__x__x__x__x__x;
			
				
	std::vector< ::RailRoadModel::Robot* > _robots;
	std::vector< ::RailRoadModel::RobotPart* > _robotparts;
	
public:
	LocalRobotModel(Viatra::Query::Model::id_t id);
	virtual ~LocalRobotModel();
	static const unsigned short type_id = 17;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}
	
	inline static std::list<IRobotModel*> Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

				
	void set_robots(std::vector< ::RailRoadModel::Robot* > newVal) override;
	std::vector< ::RailRoadModel::Robot* > robots() override;
	
	void set_robotparts(std::vector< ::RailRoadModel::RobotPart* > newVal) override;
	std::vector< ::RailRoadModel::RobotPart* > robotparts() override;
	
};
	

} /* namespace RailRoadModel */

#endif /*  RAILROADMODEL_ROBOTMODEL_H_ */
