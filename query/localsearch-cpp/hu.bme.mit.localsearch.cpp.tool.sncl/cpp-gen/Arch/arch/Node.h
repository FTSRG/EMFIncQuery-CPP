#ifndef ARCH_NODE_H_
#define ARCH_NODE_H_

#include "arch_decl.h"


#include <string>
#include <list>
#include <vector>

#include <Viatra/Query/Model/ModelElement.h>
#include <Viatra/Query/Model/RemoteElement.h>
#include <Viatra/Query/Model/LocalElement.h>
#include <Viatra/Query/Model/IModelElemService.h>

namespace arch {

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
				
	static constexpr unsigned short get_static_type_id() {
		return type_id;
	}
	
	unsigned short get_type_id() override {
		return type_id;
	}

	virtual void set_name(::std::string newVal) = 0;
	virtual ::std::string get_name() const = 0;
	
};


class RemoteNode : 
	public Viatra::Query::Model::RemoteElement, 
	public INode
{
public:
	RemoteNode(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteNode();
	
	unsigned short get_type_id() override {
		return INode::type_id;
	}

	void set_name(::std::string newVal) override;
	::std::string get_name() const override;
	
};

class LocalNode : 
	public virtual Viatra::Query::Model::LocalElement, 
	public INode
{
private:
	static std::list<INode*> _instances__x__x__x__x__x__x__x;
			
	::std::string _name = "";
	
	
public:
	LocalNode(Viatra::Query::Model::id_t id);
	
	unsigned short get_type_id() override {
		return INode::type_id;
	}

				
	virtual ~LocalNode();
	inline static std::list<INode*>& Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	void set_name(::std::string newVal) override;
	::std::string get_name() const override;

	
};

} /* namespace arch */

#endif /*  ARCH_NODE_H_ */
