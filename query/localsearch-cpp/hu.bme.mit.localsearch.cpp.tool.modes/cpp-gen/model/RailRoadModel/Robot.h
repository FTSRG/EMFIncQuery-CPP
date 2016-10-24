#ifndef RAILROADMODEL_ROBOT_H_
#define RAILROADMODEL_ROBOT_H_

#include "RailRoadModel_decl.h"


#include <string>
#include <list>
#include <vector>

#include <Viatra/Query/Model/ModelElement.h>
#include <Viatra/Query/Model/RemoteElement.h>
#include <Viatra/Query/Model/LocalElement.h>
#include <Viatra/Query/Model/IModelElemService.h>

namespace RailRoadModel {

class IRobot;
class RemoteRobot;
class LocalRobot;


class IRobot : 
	public virtual Viatra::Query::Model::ModelElement
{
public:
	using RemoteImplementation = RemoteRobot;
	using LocalImplementation = LocalRobot;
	IRobot(Viatra::Query::Model::id_t id, bool present)
		: ModelElement(id, present)
	{}

	virtual ~IRobot() {}
	static constexpr unsigned short type_id = 12;
				
	static constexpr unsigned short get_static_type_id() {
		return type_id;
	}
	
	unsigned short get_type_id() override {
		return type_id;
	}

	
	virtual void set_robotParts(std::vector< ::RailRoadModel::IRobotPart* > newVal) = 0;
	virtual const std::vector< ::RailRoadModel::IRobotPart* >& robotParts() const = 0;
};


class RemoteRobot : 
	public Viatra::Query::Model::RemoteElement, 
	public IRobot
{
public:
	RemoteRobot(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteRobot();
	
	unsigned short get_type_id() override {
		return IRobot::type_id;
	}

	
	void set_robotParts(std::vector< ::RailRoadModel::IRobotPart* > newVal) override;
	const std::vector< ::RailRoadModel::IRobotPart* >& robotParts() const override;
};

class LocalRobot : 
	public virtual Viatra::Query::Model::LocalElement, 
	public IRobot
{
private:
	static std::list<IRobot*> _instances__x__x__x__x__x__x__x;
			
	
	std::vector< ::RailRoadModel::IRobotPart* > robotParts;
	
public:
	LocalRobot(Viatra::Query::Model::id_t id);
	
	unsigned short get_type_id() override {
		return IRobot::type_id;
	}

				
	virtual ~LocalRobot();
	inline static std::list<IRobot*>& Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	
	void set_robotParts(std::vector< ::RailRoadModel::IRobotPart* > newVal) override;
	const std::vector< ::RailRoadModel::IRobotPart* >& robotParts() const override;
	
};

} /* namespace RailRoadModel */

#endif /*  RAILROADMODEL_ROBOT_H_ */
