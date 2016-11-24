#ifndef RAILROADMODEL_OPERATIONAL_H_
#define RAILROADMODEL_OPERATIONAL_H_

#include "railRoadModel_decl.h"

#include "railRoadModel/State.h"

#include <string>
#include <list>
#include <vector>

#include <Viatra/Query/Model/ModelElement.h>
#include <Viatra/Query/Model/RemoteElement.h>
#include <Viatra/Query/Model/LocalElement.h>
#include <Viatra/Query/Model/IModelElemService.h>

namespace railRoadModel {

class IOperational;
class RemoteOperational;
class LocalOperational;


class IOperational : 
	public virtual IState,
	public virtual Viatra::Query::Model::ModelElement
{
public:
	using RemoteImplementation = RemoteOperational;
	using LocalImplementation = LocalOperational;
	IOperational(Viatra::Query::Model::id_t id, bool present)
		: ModelElement(id, present)
		, IState(id, present)
	{}

	virtual ~IOperational() {}
	static constexpr unsigned short type_id = 11;
				
	static constexpr unsigned short get_static_type_id() {
		return type_id;
	}
	
	unsigned short get_type_id() override {
		return type_id;
	}

	
};


class RemoteOperational : 
	public Viatra::Query::Model::RemoteElement, 
	public IOperational
{
public:
	RemoteOperational(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteOperational();
	
	unsigned short get_type_id() override {
		return IOperational::type_id;
	}

	void set_id(int newVal) override;
	int get_id() const override;
	
};

class LocalOperational : 
	public virtual Viatra::Query::Model::LocalElement, 
	public IOperational
{
private:
	static std::list<IOperational*> _instances__x__x__x__x__x__x__x;
			
	int _id = 0;
	
	
public:
	LocalOperational(Viatra::Query::Model::id_t id);
	
	unsigned short get_type_id() override {
		return IOperational::type_id;
	}

				
	virtual ~LocalOperational();
	inline static std::list<IOperational*>& Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	void set_id(int newVal) override;
	int get_id() const override;

	
};

} /* namespace railRoadModel */

#endif /*  RAILROADMODEL_OPERATIONAL_H_ */
