#ifndef FACTORY_HALMAZALLAPOT_H_
#define FACTORY_HALMAZALLAPOT_H_

#include "factory_decl.h"


#include <string>
#include <list>
#include <vector>

#include <Viatra/Query/Model/ModelElement.h>
#include <Viatra/Query/Model/RemoteElement.h>
#include <Viatra/Query/Model/LocalElement.h>
#include <Viatra/Query/Model/IModelElemService.h>

namespace factory {

class IHalmazallapot;
class RemoteHalmazallapot;
class LocalHalmazallapot;


class IHalmazallapot : 
	public virtual Viatra::Query::Model::ModelElement
{
public:
	using RemoteImplementation = RemoteHalmazallapot;
	using LocalImplementation = LocalHalmazallapot;
	IHalmazallapot(Viatra::Query::Model::id_t id, bool present)
		: ModelElement(id, present)
	{}

	virtual ~IHalmazallapot() {}
	static constexpr unsigned short type_id = 6;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	virtual void set_ID(int newVal) = 0;
	virtual int ID() = 0;
	
};


class RemoteHalmazallapot : 
	public Viatra::Query::Model::RemoteElement, 
	public IHalmazallapot
{
public:
	RemoteHalmazallapot(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteHalmazallapot();

	void set_ID(int newVal) override;
	int ID() override;
	
};

class LocalHalmazallapot : 
	public virtual Viatra::Query::Model::LocalElement, 
	public IHalmazallapot
{
private:
	static std::list<IHalmazallapot*> _instances__x__x__x__x__x__x__x;
			
	int _ID = 0;
	
	
public:
	LocalHalmazallapot(Viatra::Query::Model::id_t id);
	virtual ~LocalHalmazallapot();
	static const unsigned short type_id = 7;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}
	
	inline static std::list<IHalmazallapot*> Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	void set_ID(int newVal) override;
	int ID() override;

	
};

} /* namespace factory */

#endif /*  FACTORY_HALMAZALLAPOT_H_ */
