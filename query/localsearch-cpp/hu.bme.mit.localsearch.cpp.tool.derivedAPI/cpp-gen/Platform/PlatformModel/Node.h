#ifndef PLATFORMMODEL_NODE_H_
#define PLATFORMMODEL_NODE_H_

#include "PlatformModel_decl.h"


#include <string>
#include <list>
#include <vector>

#include <Viatra/Query/Model/ModelElement.h>
#include <Viatra/Query/Model/RemoteElement.h>
#include <Viatra/Query/Model/LocalElement.h>
#include <Viatra/Query/Model/IModelElemService.h>

namespace PlatformModel {

class INode;
class RemoteNode;
class LocalNode;


class INode : 
	public virtual Viatra::Query::Model::ModelElement
{
public:
	using RemoteImplementation = RemoteNode;
	using LocalImplementation = LocalNode;
	INode(Viatra::Query::Model::id_t id, bool present)
		: ModelElement(id, present)
	{}

	virtual ~INode() {}
	static constexpr unsigned short type_id = 0;
				
	static constexpr unsigned short get_type_id() {
		return type_id;
	}

	virtual void set_id(int newVal) = 0;
	virtual int id() const = 0;
	virtual void set_responsibleFor(std::vector< int> newVal) = 0;
	virtual const std::vector< int>& responsibleFor() const = 0;
	
	virtual void set_executes(std::vector< ::RailRoadModel::ISegment* > newVal) = 0;
	virtual const std::vector< ::RailRoadModel::ISegment* >& executes() const = 0;
	virtual void set_derivedExecutes(std::vector< ::RailRoadModel::ITrain* > newVal) = 0;
	virtual const std::vector< ::RailRoadModel::ITrain* >& derivedExecutes() const = 0;
};


class RemoteNode : 
	public Viatra::Query::Model::RemoteElement, 
	public INode
{
public:
	RemoteNode(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteNode();

	void set_id(int newVal) override;
	int id() const override;
	void set_responsibleFor(std::vector< int> newVal) override;
	const std::vector< int>& responsibleFor() const override;
	
	void set_executes(std::vector< ::RailRoadModel::ISegment* > newVal) override;
	const std::vector< ::RailRoadModel::ISegment* >& executes() const override;
	void set_derivedExecutes(std::vector< ::RailRoadModel::ITrain* > newVal) override;
	const std::vector< ::RailRoadModel::ITrain* >& derivedExecutes() const override;
};

class LocalNode : 
	public virtual Viatra::Query::Model::LocalElement, 
	public INode
{
private:
	static std::list<INode*> _instances__x__x__x__x__x__x__x;
			
	int _id = 0;
	std::vector< int> _responsibleFor = 0;
	
	std::vector< ::RailRoadModel::ISegment* > _executes;
	std::vector< ::RailRoadModel::ITrain* > _derivedExecutes;
	
public:
	LocalNode(Viatra::Query::Model::id_t id);
	virtual ~LocalNode();
	inline static std::list<INode*>& Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	void set_id(int newVal) override;
	int id() const override;

	void set_responsibleFor(std::vector< int> newVal) override;
	const std::vector< int>& responsibleFor() const override;

	
	void set_executes(std::vector< ::RailRoadModel::ISegment* > newVal) override;
	const std::vector< ::RailRoadModel::ISegment* >& executes() const override;
	
	void set_derivedExecutes(std::vector< ::RailRoadModel::ITrain* > newVal) override;
	const std::vector< ::RailRoadModel::ITrain* >& derivedExecutes() const override;
	
};

} /* namespace PlatformModel */

#endif /*  PLATFORMMODEL_NODE_H_ */
