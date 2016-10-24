#ifndef RAILROADMODEL_FROZEN_H_
#define RAILROADMODEL_FROZEN_H_

#include "RailRoadModel_decl.h"

#include "RailRoadModel/State.h"

#include <string>
#include <list>
#include <vector>

#include <Viatra/Query/Model/ModelElement.h>
#include <Viatra/Query/Model/RemoteElement.h>
#include <Viatra/Query/Model/LocalElement.h>
#include <Viatra/Query/Model/IModelElemService.h>

namespace RailRoadModel {

class IFrozen;
class RemoteFrozen;
class LocalFrozen;


class IFrozen : 
	public virtual IState,
	public virtual Viatra::Query::Model::ModelElement
{
public:
	using RemoteImplementation = RemoteFrozen;
	using LocalImplementation = LocalFrozen;
	IFrozen(Viatra::Query::Model::id_t id, bool present)
		: ModelElement(id, present)
		, IState(id, present)
	{}

	virtual ~IFrozen() {}
	static constexpr unsigned short type_id = 10;
				
	static constexpr unsigned short get_static_type_id() {
		return type_id;
	}
	
	unsigned short get_type_id() override {
		return type_id;
	}

	
};


class RemoteFrozen : 
	public Viatra::Query::Model::RemoteElement, 
	public IFrozen
{
public:
	RemoteFrozen(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteFrozen();
	
	unsigned short get_type_id() override {
		return IFrozen::type_id;
	}

	void set_id(int newVal) override;
	int id() const override;
	
};

class LocalFrozen : 
	public virtual Viatra::Query::Model::LocalElement, 
	public IFrozen
{
private:
	static std::list<IFrozen*> _instances__x__x__x__x__x__x__x;
			
	int id = 0;
	
	
public:
	LocalFrozen(Viatra::Query::Model::id_t id);
	
	unsigned short get_type_id() override {
		return IFrozen::type_id;
	}

				
	virtual ~LocalFrozen();
	inline static std::list<IFrozen*>& Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	void set_id(int newVal) override;
	int id() const override;

	
};

} /* namespace RailRoadModel */

#endif /*  RAILROADMODEL_FROZEN_H_ */
