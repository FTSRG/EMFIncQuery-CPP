#ifndef RAILROADMODEL_TURNOUT_H_
#define RAILROADMODEL_TURNOUT_H_

#include "RailRoadModel_decl.h"

#include "RailRoadModel/RailRoadElement.h"

#include <string>
#include <list>
#include <vector>

#include <Viatra/Query/Model/ModelElement.h>
#include <Viatra/Query/Model/RemoteElement.h>
#include <Viatra/Query/Model/LocalElement.h>
#include <Viatra/Query/Model/IModelElemService.h>

namespace RailRoadModel {

class ITurnout;
class RemoteTurnout;
class LocalTurnout;


class ITurnout : 
	public virtual IRailRoadElement,
	public virtual Viatra::Query::Model::ModelElement
{
public:
	using RemoteImplementation = RemoteTurnout;
	using LocalImplementation = LocalTurnout;
	ITurnout(Viatra::Query::Model::id_t id, bool present)
		: ModelElement(id, present)
		, IRailRoadElement(id, present)
	{}

	virtual ~ITurnout() {}
	static constexpr unsigned short type_id = 2;
				
	static constexpr unsigned short get_static_type_id() {
		return type_id;
	}
	
	unsigned short get_type_id() override {
		return type_id;
	}

	virtual void set_currentlyDivergent( newVal) = 0;
	virtual  currentlyDivergent() const = 0;
	
	virtual void set_top(::RailRoadModel::IRailRoadElement* newVal) = 0;
	virtual ::RailRoadModel::IRailRoadElement* top() const = 0;
	virtual void set_straight(::RailRoadModel::IRailRoadElement* newVal) = 0;
	virtual ::RailRoadModel::IRailRoadElement* straight() const = 0;
	virtual void set_divergent(::RailRoadModel::IRailRoadElement* newVal) = 0;
	virtual ::RailRoadModel::IRailRoadElement* divergent() const = 0;
	virtual void set_currentState(::RailRoadModel::IState* newVal) = 0;
	virtual ::RailRoadModel::IState* currentState() const = 0;
};


class RemoteTurnout : 
	public Viatra::Query::Model::RemoteElement, 
	public ITurnout
{
public:
	RemoteTurnout(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteTurnout();
	
	unsigned short get_type_id() override {
		return ITurnout::type_id;
	}

	void set_currentlyDivergent( newVal) override;
	 currentlyDivergent() const override;
	void set_id(int newVal) override;
	int id() const override;
	
	void set_top(::RailRoadModel::IRailRoadElement* newVal) override;
	::RailRoadModel::IRailRoadElement* top() const override;
	void set_straight(::RailRoadModel::IRailRoadElement* newVal) override;
	::RailRoadModel::IRailRoadElement* straight() const override;
	void set_divergent(::RailRoadModel::IRailRoadElement* newVal) override;
	::RailRoadModel::IRailRoadElement* divergent() const override;
	void set_currentState(::RailRoadModel::IState* newVal) override;
	::RailRoadModel::IState* currentState() const override;
	void set_points(std::vector< ::RailRoadModel::IPoint* > newVal) override;
	const std::vector< ::RailRoadModel::IPoint* >& points() const override;
};

class LocalTurnout : 
	public virtual Viatra::Query::Model::LocalElement, 
	public ITurnout
{
private:
	static std::list<ITurnout*> _instances__x__x__x__x__x__x__x;
			
	 currentlyDivergent = ;
	int id = 0;
	
	::RailRoadModel::IRailRoadElement* top = nullptr;
	::RailRoadModel::IRailRoadElement* straight = nullptr;
	::RailRoadModel::IRailRoadElement* divergent = nullptr;
	::RailRoadModel::IState* currentState = nullptr;
	std::vector< ::RailRoadModel::IPoint* > points;
	
public:
	LocalTurnout(Viatra::Query::Model::id_t id);
	
	unsigned short get_type_id() override {
		return ITurnout::type_id;
	}

				
	virtual ~LocalTurnout();
	inline static std::list<ITurnout*>& Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	void set_currentlyDivergent( newVal) override;
	 currentlyDivergent() const override;

	void set_id(int newVal) override;
	int id() const override;

	
	void set_top(::RailRoadModel::IRailRoadElement* newVal) override;
	::RailRoadModel::IRailRoadElement* top() const override;
	
	void set_straight(::RailRoadModel::IRailRoadElement* newVal) override;
	::RailRoadModel::IRailRoadElement* straight() const override;
	
	void set_divergent(::RailRoadModel::IRailRoadElement* newVal) override;
	::RailRoadModel::IRailRoadElement* divergent() const override;
	
	void set_currentState(::RailRoadModel::IState* newVal) override;
	::RailRoadModel::IState* currentState() const override;
	
	void set_points(std::vector< ::RailRoadModel::IPoint* > newVal) override;
	const std::vector< ::RailRoadModel::IPoint* >& points() const override;
	
};

} /* namespace RailRoadModel */

#endif /*  RAILROADMODEL_TURNOUT_H_ */
