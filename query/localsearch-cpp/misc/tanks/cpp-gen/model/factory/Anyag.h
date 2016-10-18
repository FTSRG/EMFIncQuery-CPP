#ifndef FACTORY_ANYAG_H_
#define FACTORY_ANYAG_H_

#include "factory_decl.h"


#include <string>
#include <list>
#include <vector>

#include <Viatra/Query/Model/ModelElement.h>
#include <Viatra/Query/Model/RemoteElement.h>
#include <Viatra/Query/Model/LocalElement.h>
#include <Viatra/Query/Model/IModelElemService.h>

namespace factory {

class IAnyag;
class RemoteAnyag;
class LocalAnyag;


class IAnyag : 
	public virtual Viatra::Query::Model::ModelElement
{
public:
	using RemoteImplementation = RemoteAnyag;
	using LocalImplementation = LocalAnyag;
	IAnyag(Viatra::Query::Model::id_t id, bool present)
		: ModelElement(id, present)
	{}

	virtual ~IAnyag() {}
	static constexpr unsigned short type_id = 2;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	
};


class RemoteAnyag : 
	public Viatra::Query::Model::RemoteElement, 
	public IAnyag
{
public:
	RemoteAnyag(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteAnyag();

	
};

class LocalAnyag : 
	public virtual Viatra::Query::Model::LocalElement, 
	public IAnyag
{
private:
	static std::list<IAnyag*> _instances__x__x__x__x__x__x__x;
			
	
	
public:
	LocalAnyag(Viatra::Query::Model::id_t id);
	virtual ~LocalAnyag();
	static const unsigned short type_id = 3;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}
	
	inline static std::list<IAnyag*> Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	
};

} /* namespace factory */

#endif /*  FACTORY_ANYAG_H_ */
