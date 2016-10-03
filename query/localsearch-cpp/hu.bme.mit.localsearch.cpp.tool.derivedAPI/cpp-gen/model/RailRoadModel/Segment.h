#ifndef RAILROADMODEL_SEGMENT_H_
#define RAILROADMODEL_SEGMENT_H_

#include "RailRoadModel_decl.h"

#include "RailRoadModel/RailRoadElement.h"

#include <string>
#include <list>
#include <vector>

#include <Viatra/Query/Model/ModelElement.h>
#include <Viatra/Query/Model/RemoteElement.h>
#include <Viatra/Query/Model/LocalElement.h>
#include <Viatra/Query/Model/IModelElemService.h>

namespace RailRoadModel {

class ISegment;
class RemoteSegment;
class LocalSegment;


class ISegment : 
	public virtual IRailRoadElement,
	public virtual Viatra::Query::Model::ModelElement
{
public:
	using RemoteImplementation = RemoteSegment;
	using LocalImplementation = LocalSegment;

	ISegment(Viatra::Query::Model::id_t id, bool present)
		: ModelElement(id, present)
		, IRailRoadElement(id, present)
	{}

	virtual ~ISegment() {}
	static constexpr unsigned short type_id = 8;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	virtual void set_isEnabled(bool newVal) = 0;
	virtual bool isEnabled() = 0;

				
	virtual void set_connectedTo(std::vector< ::RailRoadModel::RailRoadElement* > newVal) = 0;
	virtual std::vector< ::RailRoadModel::RailRoadElement* > connectedTo() = 0;
};
	


class RemoteSegment : 
													public Viatra::Query::Model::RemoteElement, 
	public ISegment
{
public:
	RemoteSegment(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteSegment();

	void set_isEnabled(bool newVal) override;
	bool isEnabled() override;
	void set_id(int newVal) override;
	int id() override;
	
				
	void set_connectedTo(std::vector< ::RailRoadModel::RailRoadElement* > newVal) override;
	std::vector< ::RailRoadModel::RailRoadElement* > connectedTo() override;
	void set_points(std::vector< ::RailRoadModel::Point* > newVal) override;
	std::vector< ::RailRoadModel::Point* > points() override;
};
	

class LocalSegment : 
													public virtual Viatra::Query::Model::LocalElement, 
	public ISegment
{
private:
	static std::list<ISegment*> _instances__x__x__x__x__x__x__x;
			
	bool _isEnabled = false;
	int _id = 0;
				
	std::vector< ::RailRoadModel::RailRoadElement* > _connectedTo;
	std::vector< ::RailRoadModel::Point* > _points;
	
public:
	LocalSegment(Viatra::Query::Model::id_t id);
	virtual ~LocalSegment();
	static const unsigned short type_id = 9;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}
	
	inline static std::list<ISegment*> Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	void set_isEnabled(bool newVal) override;
	bool isEnabled() override;

	void set_id(int newVal) override;
	int id() override;

				
	void set_connectedTo(std::vector< ::RailRoadModel::RailRoadElement* > newVal) override;
	std::vector< ::RailRoadModel::RailRoadElement* > connectedTo() override;
	
	void set_points(std::vector< ::RailRoadModel::Point* > newVal) override;
	std::vector< ::RailRoadModel::Point* > points() override;
	
};
	

} /* namespace RailRoadModel */

#endif /*  RAILROADMODEL_SEGMENT_H_ */
