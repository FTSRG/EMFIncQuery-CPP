#ifndef RAILROADMODEL_TRAIN_H_
#define RAILROADMODEL_TRAIN_H_

#include "railRoadModel_decl.h"


#include <string>
#include <list>
#include <vector>

#include <Viatra/Query/Model/ModelElement.h>
#include <Viatra/Query/Model/RemoteElement.h>
#include <Viatra/Query/Model/LocalElement.h>
#include <Viatra/Query/Model/IModelElemService.h>

namespace railRoadModel {

class ITrain;
class RemoteTrain;
class LocalTrain;


class ITrain : 
	public virtual Viatra::Query::Model::ModelElement
{
public:
	using RemoteImplementation = RemoteTrain;
	using LocalImplementation = LocalTrain;
	ITrain(Viatra::Query::Model::id_t id, bool present)
		: ModelElement(id, present)
	{}

	virtual ~ITrain() {}
	static constexpr unsigned short type_id = 0;
				
	static constexpr unsigned short get_static_type_id() {
		return type_id;
	}
	
	unsigned short get_type_id() override {
		return type_id;
	}

	virtual void set_x(double newVal) = 0;
	virtual double get_x() const = 0;
	virtual void set_y(double newVal) = 0;
	virtual double get_y() const = 0;
	virtual void set_id(int newVal) = 0;
	virtual int get_id() const = 0;
	
	virtual void set_currentlyOn(::railRoadModel::IRailRoadElement* newVal) = 0;
	virtual ::railRoadModel::IRailRoadElement* get_currentlyOn() const = 0;
	virtual void set_previouslyOn(::railRoadModel::IRailRoadElement* newVal) = 0;
	virtual ::railRoadModel::IRailRoadElement* get_previouslyOn() const = 0;
};


class RemoteTrain : 
	public Viatra::Query::Model::RemoteElement, 
	public ITrain
{
public:
	RemoteTrain(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteTrain();
	
	unsigned short get_type_id() override {
		return ITrain::type_id;
	}

	void set_x(double newVal) override;
	double get_x() const override;
	void set_y(double newVal) override;
	double get_y() const override;
	void set_id(int newVal) override;
	int get_id() const override;
	
	void set_currentlyOn(::railRoadModel::IRailRoadElement* newVal) override;
	::railRoadModel::IRailRoadElement* get_currentlyOn() const override;
	void set_previouslyOn(::railRoadModel::IRailRoadElement* newVal) override;
	::railRoadModel::IRailRoadElement* get_previouslyOn() const override;
};

class LocalTrain : 
	public virtual Viatra::Query::Model::LocalElement, 
	public ITrain
{
private:
	static std::list<ITrain*> _instances__x__x__x__x__x__x__x;
			
	double _x = 0.0;
	double _y = 0.0;
	int _id = 0;
	
	::railRoadModel::IRailRoadElement* _currentlyOn = nullptr;
	::railRoadModel::IRailRoadElement* _previouslyOn = nullptr;
	
public:
	LocalTrain(Viatra::Query::Model::id_t id);
	
	unsigned short get_type_id() override {
		return ITrain::type_id;
	}

				
	virtual ~LocalTrain();
	inline static std::list<ITrain*>& Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	void set_x(double newVal) override;
	double get_x() const override;

	void set_y(double newVal) override;
	double get_y() const override;

	void set_id(int newVal) override;
	int get_id() const override;

	
	void set_currentlyOn(::railRoadModel::IRailRoadElement* newVal) override;
	::railRoadModel::IRailRoadElement* get_currentlyOn() const override;
	
	void set_previouslyOn(::railRoadModel::IRailRoadElement* newVal) override;
	::railRoadModel::IRailRoadElement* get_previouslyOn() const override;
	
};

} /* namespace railRoadModel */

#endif /*  RAILROADMODEL_TRAIN_H_ */
