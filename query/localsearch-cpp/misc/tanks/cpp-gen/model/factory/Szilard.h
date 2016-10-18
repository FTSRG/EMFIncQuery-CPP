#ifndef FACTORY_SZILARD_H_
#define FACTORY_SZILARD_H_

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

class ISzilard;
class RemoteSzilard;
class LocalSzilard;


class ISzilard : 
	public virtual IHalmazallapot,
	public virtual Viatra::Query::Model::ModelElement
{
public:
	using RemoteImplementation = RemoteSzilard;
	using LocalImplementation = LocalSzilard;
	ISzilard(Viatra::Query::Model::id_t id, bool present)
		: ModelElement(id, present)
		, IHalmazallapot(id, present)
	{}

	virtual ~ISzilard() {}
	static constexpr unsigned short type_id = 12;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	
};


class RemoteSzilard : 
	public Viatra::Query::Model::RemoteElement, 
	public ISzilard
{
public:
	RemoteSzilard(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteSzilard();

	void set_ID(int newVal) override;
	int ID() override;
	
};

class LocalSzilard : 
	public virtual Viatra::Query::Model::LocalElement, 
	public ISzilard
{
private:
	static std::list<ISzilard*> _instances__x__x__x__x__x__x__x;
			
	int _ID = 0;
	
	
public:
	LocalSzilard(Viatra::Query::Model::id_t id);
	virtual ~LocalSzilard();
	static const unsigned short type_id = 13;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}
	
	inline static std::list<ISzilard*> Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	void set_ID(int newVal) override;
	int ID() override;

	
};

} /* namespace factory */

#endif /*  FACTORY_SZILARD_H_ */
