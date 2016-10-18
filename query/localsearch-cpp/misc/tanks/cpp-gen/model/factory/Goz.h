#ifndef FACTORY_GOZ_H_
#define FACTORY_GOZ_H_

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

class IGoz;
class RemoteGoz;
class LocalGoz;


class IGoz : 
	public virtual IHalmazallapot,
	public virtual Viatra::Query::Model::ModelElement
{
public:
	using RemoteImplementation = RemoteGoz;
	using LocalImplementation = LocalGoz;
	IGoz(Viatra::Query::Model::id_t id, bool present)
		: ModelElement(id, present)
		, IHalmazallapot(id, present)
	{}

	virtual ~IGoz() {}
	static constexpr unsigned short type_id = 10;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	
};


class RemoteGoz : 
	public Viatra::Query::Model::RemoteElement, 
	public IGoz
{
public:
	RemoteGoz(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteGoz();

	void set_ID(int newVal) override;
	int ID() override;
	
};

class LocalGoz : 
	public virtual Viatra::Query::Model::LocalElement, 
	public IGoz
{
private:
	static std::list<IGoz*> _instances__x__x__x__x__x__x__x;
			
	int _ID = 0;
	
	
public:
	LocalGoz(Viatra::Query::Model::id_t id);
	virtual ~LocalGoz();
	static const unsigned short type_id = 11;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}
	
	inline static std::list<IGoz*> Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	void set_ID(int newVal) override;
	int ID() override;

	
};

} /* namespace factory */

#endif /*  FACTORY_GOZ_H_ */
