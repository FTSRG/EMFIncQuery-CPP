#ifndef ARCH_CL_H_
#define ARCH_CL_H_

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

class ICL;
class RemoteCL;
class LocalCL;


class ICL : 
	public virtual INode,
	public virtual Viatra::Query::Model::ModelElement
{
public:
	using RemoteImplementation = RemoteCL;
	using LocalImplementation = LocalCL;
	ICL(Viatra::Query::Model::id_t id, bool present)
		: ModelElement(id, present)
		, INode(id, present)
	{}

	virtual ~ICL() {}
	static constexpr unsigned short type_id = 2;
				
	static constexpr unsigned short get_static_type_id() {
		return type_id;
	}
	
	unsigned short get_type_id() override {
		return type_id;
	}

	virtual void set_countReachableSN(int newVal) = 0;
	virtual int get_countReachableSN() const = 0;
	
	virtual void set_cnn(::arch::ISN* newVal) = 0;
	virtual ::arch::ISN* get_cnn() const = 0;
};


class RemoteCL : 
	public Viatra::Query::Model::RemoteElement, 
	public ICL
{
public:
	RemoteCL(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteCL();
	
	unsigned short get_type_id() override {
		return ICL::type_id;
	}

	void set_countReachableSN(int newVal) override;
	int get_countReachableSN() const override;
	void set_name(::std::string newVal) override;
	::std::string get_name() const override;
	
	void set_cnn(::arch::ISN* newVal) override;
	::arch::ISN* get_cnn() const override;
};

class LocalCL : 
	public virtual Viatra::Query::Model::LocalElement, 
	public ICL
{
private:
	static std::list<ICL*> _instances__x__x__x__x__x__x__x;
			
	int _countReachableSN = 0;
	::std::string _name = "";
	
	::arch::ISN* _cnn = nullptr;
	
public:
	LocalCL(Viatra::Query::Model::id_t id);
	
	unsigned short get_type_id() override {
		return ICL::type_id;
	}

				
	virtual ~LocalCL();
	inline static std::list<ICL*>& Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	void set_countReachableSN(int newVal) override;
	int get_countReachableSN() const override;

	void set_name(::std::string newVal) override;
	::std::string get_name() const override;

	
	void set_cnn(::arch::ISN* newVal) override;
	::arch::ISN* get_cnn() const override;
	
};

} /* namespace arch */

#endif /*  ARCH_CL_H_ */
