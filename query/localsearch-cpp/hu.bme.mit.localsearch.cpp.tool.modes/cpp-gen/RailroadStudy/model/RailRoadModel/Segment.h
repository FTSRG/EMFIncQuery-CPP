#ifndef RAILROADMODEL_SEGMENT_H_
#define RAILROADMODEL_SEGMENT_H_

#include "railRoadModel_decl.h"

#include "railRoadModel/RailRoadElement.h"

#include <string>
#include <list>
#include <vector>

#include <Viatra/Query/Model/ModelElement.h>
#include <Viatra/Query/Model/RemoteElement.h>
#include <Viatra/Query/Model/LocalElement.h>
#include <Viatra/Query/Model/IModelElemService.h>

namespace railRoadModel {

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
	static constexpr unsigned short type_id = 5;
				
	static constexpr unsigned short get_static_type_id() {
		return type_id;
	}
	
	unsigned short get_type_id() override {
		return type_id;
	}

	virtual void set_isEnabled(bool newVal) = 0;
	virtual bool get_isEnabled() const = 0;
	
	virtual void set_connectedTo(std::vector< ::railRoadModel::IRailRoadElement* > newVal) = 0;
	virtual const std::vector< ::railRoadModel::IRailRoadElement* >& get_connectedTo() const = 0;
};


class RemoteSegment : 
	public Viatra::Query::Model::RemoteElement, 
	public ISegment
{
public:
	RemoteSegment(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteSegment();
	
	unsigned short get_type_id() override {
		return ISegment::type_id;
	}

	void set_isEnabled(bool newVal) override;
	bool get_isEnabled() const override;
	void set_id(int newVal) override;
	int get_id() const override;
	
	void set_connectedTo(std::vector< ::railRoadModel::IRailRoadElement* > newVal) override;
	const std::vector< ::railRoadModel::IRailRoadElement* >& get_connectedTo() const override;
	void set_points(std::vector< ::railRoadModel::IPoint* > newVal) override;
	const std::vector< ::railRoadModel::IPoint* >& get_points() const override;
};

class LocalSegment : 
	public virtual Viatra::Query::Model::LocalElement, 
	public ISegment
{
private:
	static std::list<ISegment*> _instances__x__x__x__x__x__x__x;
			
	bool _isEnabled = false;
	int _id = 0;
	
	std::vector< ::railRoadModel::IRailRoadElement* > _connectedTo;
	std::vector< ::railRoadModel::IPoint* > _points;
	
public:
	LocalSegment(Viatra::Query::Model::id_t id);
	
	unsigned short get_type_id() override {
		return ISegment::type_id;
	}

				
	virtual ~LocalSegment();
	inline static std::list<ISegment*>& Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	void set_isEnabled(bool newVal) override;
	bool get_isEnabled() const override;

	void set_id(int newVal) override;
	int get_id() const override;

	
	void set_connectedTo(std::vector< ::railRoadModel::IRailRoadElement* > newVal) override;
	const std::vector< ::railRoadModel::IRailRoadElement* >& get_connectedTo() const override;
	
	void set_points(std::vector< ::railRoadModel::IPoint* > newVal) override;
	const std::vector< ::railRoadModel::IPoint* >& get_points() const override;
	
};

} /* namespace railRoadModel */

#endif /*  RAILROADMODEL_SEGMENT_H_ */
