#ifndef FACTORY_FOLYEKONY_H_
#define FACTORY_FOLYEKONY_H_

#include "factory_decl.h"

#include "factory/Halmazallapot.h"

#include <string>
#include <list>
#include <vector>

#include <Viatra/Query/Model/ModelElement.h>
#include <Viatra/Query/Model/RemoteElement.h>
#include <Viatra/Query/Model/LocalElement.h>
#include <Viatra/Query/Model/IModelElemService.h>

namespace factory {

class IFolyekony;
class RemoteFolyekony;
class LocalFolyekony;


class IFolyekony : 
	public virtual IHalmazallapot,
	public virtual Viatra::Query::Model::ModelElement
{
public:
	using RemoteImplementation = RemoteFolyekony;
	using LocalImplementation = LocalFolyekony;
	IFolyekony(Viatra::Query::Model::id_t id, bool present)
		: ModelElement(id, present)
		, IHalmazallapot(id, present)
	{}

	virtual ~IFolyekony() {}
	static constexpr unsigned short type_id = 8;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	
};


class RemoteFolyekony : 
	public Viatra::Query::Model::RemoteElement, 
	public IFolyekony
{
public:
	RemoteFolyekony(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteFolyekony();

	void set_ID(int newVal) override;
	int ID() override;
	
};

class LocalFolyekony : 
	public virtual Viatra::Query::Model::LocalElement, 
	public IFolyekony
{
private:
	static std::list<IFolyekony*> _instances__x__x__x__x__x__x__x;
			
	int _ID = 0;
	
	
public:
	LocalFolyekony(Viatra::Query::Model::id_t id);
	virtual ~LocalFolyekony();
	static const unsigned short type_id = 9;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}
	
	inline static std::list<IFolyekony*> Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	void set_ID(int newVal) override;
	int ID() override;

	
};

} /* namespace factory */

#endif /*  FACTORY_FOLYEKONY_H_ */
