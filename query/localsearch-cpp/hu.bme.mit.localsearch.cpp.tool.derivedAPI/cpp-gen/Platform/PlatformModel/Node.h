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
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	virtual void set_id(int newVal) = 0;
	virtual int id() = 0;

	virtual void set_responsibleFor(std::vector< int> newVal) = 0;
	virtual std::vector< int> responsibleFor() = 0;

				
	virtual void set_executes(std::vector< ::RailRoadModel::Segment* > newVal) = 0;
	virtual std::vector< ::RailRoadModel::Segment* > executes() = 0;
	virtual void set_derivedExecutes(std::vector< ::RailRoadModel::Train* > newVal) = 0;
	virtual std::vector< ::RailRoadModel::Train* > derivedExecutes() = 0;
};
	


class RemoteNode : 
													public Viatra::Query::Model::RemoteElement, 
	public INode
{
public:
	RemoteNode(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteNode();

	void set_id(int newVal) override;
	int id() override;
	void set_responsibleFor(std::vector< int> newVal) override;
	std::vector< int> responsibleFor() override;
	
				
	void set_executes(std::vector< ::RailRoadModel::Segment* > newVal) override;
	std::vector< ::RailRoadModel::Segment* > executes() override;
	void set_derivedExecutes(std::vector< ::RailRoadModel::Train* > newVal) override;
	std::vector< ::RailRoadModel::Train* > derivedExecutes() override;
};
	

class LocalNode : 
													public virtual Viatra::Query::Model::LocalElement, 
	public INode
{
private:
	static std::list<INode*> _instances__x__x__x__x__x__x__x;
			
	int _id = 0;
	std::vector< int> _responsibleFor = 0;
				
	std::vector< ::RailRoadModel::Segment* > _executes;
	std::vector< ::RailRoadModel::Train* > _derivedExecutes;
	
public:
	LocalNode(Viatra::Query::Model::id_t id);
	virtual ~LocalNode();
	static const unsigned short type_id = 1;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}
	
	inline static std::list<INode*> Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	void set_id(int newVal) override;
	int id() override;

	void set_responsibleFor(std::vector< int> newVal) override;
	std::vector< int> responsibleFor() override;

				
	void set_executes(std::vector< ::RailRoadModel::Segment* > newVal) override;
	std::vector< ::RailRoadModel::Segment* > executes() override;
	
	void set_derivedExecutes(std::vector< ::RailRoadModel::Train* > newVal) override;
	std::vector< ::RailRoadModel::Train* > derivedExecutes() override;
	
};
	

} /* namespace PlatformModel */

#endif /*  PLATFORMMODEL_NODE_H_ */
