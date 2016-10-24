#ifndef RAILROADMODEL_TURNOUT_H_
#define RAILROADMODEL_TURNOUT_H_

#include "railRoadModel_decl.h"

#include "railRoadModel/RailRoadElement.h"

#include <string>
#include <list>
#include <vector>

#include <Viatra/Query/Model/ModelElement.h>
#include <Viatra/Query/Model/RemoteElement.h>
#include <Viatra/Query/Model/LocalElement.h>
#include <Viatra/Query/Model/IModelElemService.h>

namespace railRoadModel {

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

	virtual void set_currentlyDivergent(bool newVal) = 0;
	virtual bool get_currentlyDivergent() const = 0;
	
	virtual void set_top(::railRoadModel::IRailRoadElement* newVal) = 0;
	virtual ::railRoadModel::IRailRoadElement* get_top() const = 0;
	virtual void set_straight(::railRoadModel::IRailRoadElement* newVal) = 0;
	virtual ::railRoadModel::IRailRoadElement* get_straight() const = 0;
	virtual void set_divergent(::railRoadModel::IRailRoadElement* newVal) = 0;
	virtual ::railRoadModel::IRailRoadElement* get_divergent() const = 0;
	virtual void set_currentState(::railRoadModel::IState* newVal) = 0;
	virtual ::railRoadModel::IState* get_currentState() const = 0;
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

	void set_currentlyDivergent(bool newVal) override;
	bool get_currentlyDivergent() const override;
	void set_id(int newVal) override;
	int get_id() const override;
	
	void set_top(::railRoadModel::IRailRoadElement* newVal) override;
	::railRoadModel::IRailRoadElement* get_top() const override;
	void set_straight(::railRoadModel::IRailRoadElement* newVal) override;
	::railRoadModel::IRailRoadElement* get_straight() const override;
	void set_divergent(::railRoadModel::IRailRoadElement* newVal) override;
	::railRoadModel::IRailRoadElement* get_divergent() const override;
	void set_currentState(::railRoadModel::IState* newVal) override;
	::railRoadModel::IState* get_currentState() const override;
	void set_points(std::vector< ::railRoadModel::IPoint* > newVal) override;
	const std::vector< ::railRoadModel::IPoint* >& get_points() const override;
};

class LocalTurnout : 
	public virtual Viatra::Query::Model::LocalElement, 
	public ITurnout
{
private:
	static std::list<ITurnout*> _instances__x__x__x__x__x__x__x;
			
	bool _currentlyDivergent = false;
	int _id = 0;
	
	::railRoadModel::IRailRoadElement* _top = nullptr;
	::railRoadModel::IRailRoadElement* _straight = nullptr;
	::railRoadModel::IRailRoadElement* _divergent = nullptr;
	::railRoadModel::IState* _currentState = nullptr;
	std::vector< ::railRoadModel::IPoint* > _points;
	
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

	void set_currentlyDivergent(bool newVal) override;
	bool get_currentlyDivergent() const override;

	void set_id(int newVal) override;
	int get_id() const override;

	
	void set_top(::railRoadModel::IRailRoadElement* newVal) override;
	::railRoadModel::IRailRoadElement* get_top() const override;
	
	void set_straight(::railRoadModel::IRailRoadElement* newVal) override;
	::railRoadModel::IRailRoadElement* get_straight() const override;
	
	void set_divergent(::railRoadModel::IRailRoadElement* newVal) override;
	::railRoadModel::IRailRoadElement* get_divergent() const override;
	
	void set_currentState(::railRoadModel::IState* newVal) override;
	::railRoadModel::IState* get_currentState() const override;
	
	void set_points(std::vector< ::railRoadModel::IPoint* > newVal) override;
	const std::vector< ::railRoadModel::IPoint* >& get_points() const override;
	
};

} /* namespace railRoadModel */

#endif /*  RAILROADMODEL_TURNOUT_H_ */
