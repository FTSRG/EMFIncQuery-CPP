#ifndef ARCH_SN_H_
#define ARCH_SN_H_

#include "arch_decl.h"

#include "arch/Node.h"

#include <string>
#include <list>
#include <vector>

#include <Viatra/Query/Model/ModelElement.h>
#include <Viatra/Query/Model/RemoteElement.h>
#include <Viatra/Query/Model/LocalElement.h>
#include <Viatra/Query/Model/IModelElemService.h>

namespace arch {

class ISN;
class RemoteSN;
class LocalSN;


class ISN : 
	public virtual INode,
	public virtual Viatra::Query::Model::ModelElement
{
public:
	using RemoteImplementation = RemoteSN;
	using LocalImplementation = LocalSN;
	ISN(Viatra::Query::Model::id_t id, bool present)
		: ModelElement(id, present)
		, INode(id, present)
	{}

	virtual ~ISN() {}
	static constexpr unsigned short type_id = 1;
				
	static constexpr unsigned short get_static_type_id() {
		return type_id;
	}
	
	unsigned short get_type_id() override {
		return type_id;
	}

	
	virtual void set_link(std::vector< ::arch::ISN* > newVal) = 0;
	virtual const std::vector< ::arch::ISN* >& get_link() const = 0;
};


class RemoteSN : 
	public Viatra::Query::Model::RemoteElement, 
	public ISN
{
public:
	RemoteSN(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteSN();
	
	unsigned short get_type_id() override {
		return ISN::type_id;
	}

	void set_name(::std::string newVal) override;
	::std::string get_name() const override;
	
	void set_link(std::vector< ::arch::ISN* > newVal) override;
	const std::vector< ::arch::ISN* >& get_link() const override;
};

class LocalSN : 
	public virtual Viatra::Query::Model::LocalElement, 
	public ISN
{
private:
	static std::list<ISN*> _instances__x__x__x__x__x__x__x;
			
	::std::string _name = "";
	
	std::vector< ::arch::ISN* > _link;
	
public:
	LocalSN(Viatra::Query::Model::id_t id);
	
	unsigned short get_type_id() override {
		return ISN::type_id;
	}

				
	virtual ~LocalSN();
	inline static std::list<ISN*>& Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	void set_name(::std::string newVal) override;
	::std::string get_name() const override;

	
	void set_link(std::vector< ::arch::ISN* > newVal) override;
	const std::vector< ::arch::ISN* >& get_link() const override;
	
};

} /* namespace arch */

#endif /*  ARCH_SN_H_ */
