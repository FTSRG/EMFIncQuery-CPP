#ifndef RAILROADMODEL_TRAIN_H_
#define RAILROADMODEL_TRAIN_H_

#include "RailRoadModel_decl.h"


#include <string>
#include <list>
#include <vector>

#include <Viatra/Query/Model/ModelElement.h>
#include <Viatra/Query/Model/RemoteElement.h>
#include <Viatra/Query/Model/LocalElement.h>
#include <Viatra/Query/Model/IModelElemService.h>

namespace RailRoadModel {

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
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	virtual void set_id(int newVal) = 0;
	virtual int id() = 0;

				
	virtual void set_currentlyOn(::RailRoadModel::RailRoadElement* newVal) = 0;
	virtual ::RailRoadModel::RailRoadElement* currentlyOn() = 0;
	virtual void set_previouslyOn(::RailRoadModel::RailRoadElement* newVal) = 0;
	virtual ::RailRoadModel::RailRoadElement* previouslyOn() = 0;
	virtual void set_point(::RailRoadModel::Point* newVal) = 0;
	virtual ::RailRoadModel::Point* point() = 0;
};
	


class RemoteTrain : 
													public Viatra::Query::Model::RemoteElement, 
	public ITrain
{
public:
	RemoteTrain(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteTrain();

	void set_id(int newVal) override;
	int id() override;
	
				
	void set_currentlyOn(::RailRoadModel::RailRoadElement* newVal) override;
	::RailRoadModel::RailRoadElement* currentlyOn() override;
	void set_previouslyOn(::RailRoadModel::RailRoadElement* newVal) override;
	::RailRoadModel::RailRoadElement* previouslyOn() override;
	void set_point(::RailRoadModel::Point* newVal) override;
	::RailRoadModel::Point* point() override;
};
	

class LocalTrain : 
													public virtual Viatra::Query::Model::LocalElement, 
	public ITrain
{
private:
	static std::list<ITrain*> _instances__x__x__x__x__x__x__x;
			
	int _id = 0;
				
	::RailRoadModel::RailRoadElement* _currentlyOn = nullptr;
	::RailRoadModel::RailRoadElement* _previouslyOn = nullptr;
	::RailRoadModel::Point* _point = nullptr;
	
public:
	LocalTrain(Viatra::Query::Model::id_t id);
	virtual ~LocalTrain();
	static const unsigned short type_id = 1;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}
	
	inline static std::list<ITrain*> Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	void set_id(int newVal) override;
	int id() override;

				
	void set_currentlyOn(::RailRoadModel::RailRoadElement* newVal) override;
	::RailRoadModel::RailRoadElement* currentlyOn() override;
	
	void set_previouslyOn(::RailRoadModel::RailRoadElement* newVal) override;
	::RailRoadModel::RailRoadElement* previouslyOn() override;
	
	void set_point(::RailRoadModel::Point* newVal) override;
	::RailRoadModel::Point* point() override;
	
};
	

} /* namespace RailRoadModel */

#endif /*  RAILROADMODEL_TRAIN_H_ */
