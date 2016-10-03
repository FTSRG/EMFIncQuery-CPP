#ifndef RAILROADMODEL_ROBOTPART_H_
#define RAILROADMODEL_ROBOTPART_H_

#include "RailRoadModel_decl.h"

#include "RailRoadModel/RobotElement.h"

#include <string>
#include <list>
#include <vector>

#include <Viatra/Query/Model/ModelElement.h>
#include <Viatra/Query/Model/RemoteElement.h>
#include <Viatra/Query/Model/LocalElement.h>
#include <Viatra/Query/Model/IModelElemService.h>

namespace RailRoadModel {

class IRobotPart;
class RemoteRobotPart;
class LocalRobotPart;


class IRobotPart : 
	public virtual IRobotElement,
	public virtual Viatra::Query::Model::ModelElement
{
public:
	using RemoteImplementation = RemoteRobotPart;
	using LocalImplementation = LocalRobotPart;
	IRobotPart(Viatra::Query::Model::id_t id, bool present)
		: ModelElement(id, present)
		, IRobotElement(id, present)
	{}

	virtual ~IRobotPart() {}
	static constexpr unsigned short type_id = 7;
				
	static constexpr unsigned short get_type_id() {
		return type_id;
	}

	virtual void set_isOperational(bool newVal) = 0;
	virtual bool isOperational() const = 0;
	
	virtual void set_nearBy(std::vector< ::RailRoadModel::ITrain* > newVal) = 0;
	virtual const std::vector< ::RailRoadModel::ITrain* >& nearBy() const = 0;
	virtual void set_refSegment(::RailRoadModel::ISegment* newVal) = 0;
	virtual ::RailRoadModel::ISegment* refSegment() const = 0;
};


class RemoteRobotPart : 
	public Viatra::Query::Model::RemoteElement, 
	public IRobotPart
{
public:
	RemoteRobotPart(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteRobotPart();

	void set_isOperational(bool newVal) override;
	bool isOperational() const override;
	void set_id(int newVal) override;
	int id() const override;
	
	void set_nearBy(std::vector< ::RailRoadModel::ITrain* > newVal) override;
	const std::vector< ::RailRoadModel::ITrain* >& nearBy() const override;
	void set_refSegment(::RailRoadModel::ISegment* newVal) override;
	::RailRoadModel::ISegment* refSegment() const override;
	void set_position(::RailRoadModel::IPoint* newVal) override;
	::RailRoadModel::IPoint* position() const override;
};

class LocalRobotPart : 
	public virtual Viatra::Query::Model::LocalElement, 
	public IRobotPart
{
private:
	static std::list<IRobotPart*> _instances__x__x__x__x__x__x__x;
			
	bool _isOperational = false;
	int _id = 0;
	
	std::vector< ::RailRoadModel::ITrain* > _nearBy;
	::RailRoadModel::ISegment* _refSegment = nullptr;
	::RailRoadModel::IPoint* _position = nullptr;
	
public:
	LocalRobotPart(Viatra::Query::Model::id_t id);
	virtual ~LocalRobotPart();
	inline static std::list<IRobotPart*>& Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	void set_isOperational(bool newVal) override;
	bool isOperational() const override;

	void set_id(int newVal) override;
	int id() const override;

	
	void set_nearBy(std::vector< ::RailRoadModel::ITrain* > newVal) override;
	const std::vector< ::RailRoadModel::ITrain* >& nearBy() const override;
	
	void set_refSegment(::RailRoadModel::ISegment* newVal) override;
	::RailRoadModel::ISegment* refSegment() const override;
	
	void set_position(::RailRoadModel::IPoint* newVal) override;
	::RailRoadModel::IPoint* position() const override;
	
};

} /* namespace RailRoadModel */

#endif /*  RAILROADMODEL_ROBOTPART_H_ */
