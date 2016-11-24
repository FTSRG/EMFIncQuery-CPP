#ifndef RAILROADMODEL_STATE_H_
#define RAILROADMODEL_STATE_H_

#include "railRoadModel_decl.h"


#include <string>
#include <list>
#include <vector>

#include <Viatra/Query/Model/ModelElement.h>
#include <Viatra/Query/Model/RemoteElement.h>
#include <Viatra/Query/Model/LocalElement.h>
#include <Viatra/Query/Model/IModelElemService.h>

namespace railRoadModel {

class IState;
class RemoteState;
class LocalState;


class IState : 
	public virtual Viatra::Query::Model::ModelElement
{
public:
	using RemoteImplementation = RemoteState;
	using LocalImplementation = LocalState;
	IState(Viatra::Query::Model::id_t id, bool present)
		: ModelElement(id, present)
	{}

	virtual ~IState() {}
	static constexpr unsigned short type_id = 9;
				
	static constexpr unsigned short get_static_type_id() {
		return type_id;
	}
	
	unsigned short get_type_id() override {
		return type_id;
	}

	virtual void set_id(int newVal) = 0;
	virtual int get_id() const = 0;
	
};


class RemoteState : 
	public Viatra::Query::Model::RemoteElement, 
	public IState
{
public:
	RemoteState(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteState();
	
	unsigned short get_type_id() override {
		return IState::type_id;
	}

	void set_id(int newVal) override;
	int get_id() const override;
	
};

class LocalState : 
	public virtual Viatra::Query::Model::LocalElement, 
	public IState
{
private:
	static std::list<IState*> _instances__x__x__x__x__x__x__x;
			
	int _id = 0;
	
	
public:
	LocalState(Viatra::Query::Model::id_t id);
	
	unsigned short get_type_id() override {
		return IState::type_id;
	}

				
	virtual ~LocalState();
	inline static std::list<IState*>& Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	void set_id(int newVal) override;
	int get_id() const override;

	
};

} /* namespace railRoadModel */

#endif /*  RAILROADMODEL_STATE_H_ */
