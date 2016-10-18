#ifndef FACTORY_VIZ_H_
#define FACTORY_VIZ_H_

#include "factory_decl.h"

#include "factory/Anyag.h"

#include <string>
#include <list>
#include <vector>

#include <Viatra/Query/Model/ModelElement.h>
#include <Viatra/Query/Model/RemoteElement.h>
#include <Viatra/Query/Model/LocalElement.h>
#include <Viatra/Query/Model/IModelElemService.h>

namespace factory {

class IViz;
class RemoteViz;
class LocalViz;


class IViz : 
	public virtual IAnyag,
	public virtual Viatra::Query::Model::ModelElement
{
public:
	using RemoteImplementation = RemoteViz;
	using LocalImplementation = LocalViz;
	IViz(Viatra::Query::Model::id_t id, bool present)
		: ModelElement(id, present)
		, IAnyag(id, present)
	{}

	virtual ~IViz() {}
	static constexpr unsigned short type_id = 4;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	
};


class RemoteViz : 
	public Viatra::Query::Model::RemoteElement, 
	public IViz
{
public:
	RemoteViz(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteViz();

	
};

class LocalViz : 
	public virtual Viatra::Query::Model::LocalElement, 
	public IViz
{
private:
	static std::list<IViz*> _instances__x__x__x__x__x__x__x;
			
	
	
public:
	LocalViz(Viatra::Query::Model::id_t id);
	virtual ~LocalViz();
	static const unsigned short type_id = 5;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}
	
	inline static std::list<IViz*> Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	
};

} /* namespace factory */

#endif /*  FACTORY_VIZ_H_ */
