#ifndef RAILROADMODEL_PATH_H_
#define RAILROADMODEL_PATH_H_

#include "RailRoadModel_decl.h"


#include <string>
#include <list>
#include <vector>

#include <Viatra/Query/Model/ModelElement.h>
#include <Viatra/Query/Model/RemoteElement.h>
#include <Viatra/Query/Model/LocalElement.h>
#include <Viatra/Query/Model/IModelElemService.h>

namespace RailRoadModel {

class IPath;
class RemotePath;
class LocalPath;


class IPath : 
	public virtual Viatra::Query::Model::ModelElement
{
public:
	using RemoteImplementation = RemotePath;
	using LocalImplementation = LocalPath;
	IPath(Viatra::Query::Model::id_t id, bool present)
		: ModelElement(id, present)
	{}

	virtual ~IPath() {}
	static constexpr unsigned short type_id = 6;
				
	static constexpr unsigned short get_static_type_id() {
		return type_id;
	}
	
	unsigned short get_type_id() override {
		return type_id;
	}

	
	virtual void set_from(::RailRoadModel::IRailRoadElement* newVal) = 0;
	virtual ::RailRoadModel::IRailRoadElement* from() const = 0;
	virtual void set_via(::RailRoadModel::IRailRoadElement* newVal) = 0;
	virtual ::RailRoadModel::IRailRoadElement* via() const = 0;
	virtual void set_to(::RailRoadModel::IRailRoadElement* newVal) = 0;
	virtual ::RailRoadModel::IRailRoadElement* to() const = 0;
};


class RemotePath : 
	public Viatra::Query::Model::RemoteElement, 
	public IPath
{
public:
	RemotePath(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemotePath();
	
	unsigned short get_type_id() override {
		return IPath::type_id;
	}

	
	void set_from(::RailRoadModel::IRailRoadElement* newVal) override;
	::RailRoadModel::IRailRoadElement* from() const override;
	void set_via(::RailRoadModel::IRailRoadElement* newVal) override;
	::RailRoadModel::IRailRoadElement* via() const override;
	void set_to(::RailRoadModel::IRailRoadElement* newVal) override;
	::RailRoadModel::IRailRoadElement* to() const override;
};

class LocalPath : 
	public virtual Viatra::Query::Model::LocalElement, 
	public IPath
{
private:
	static std::list<IPath*> _instances__x__x__x__x__x__x__x;
			
	
	::RailRoadModel::IRailRoadElement* from = nullptr;
	::RailRoadModel::IRailRoadElement* via = nullptr;
	::RailRoadModel::IRailRoadElement* to = nullptr;
	
public:
	LocalPath(Viatra::Query::Model::id_t id);
	
	unsigned short get_type_id() override {
		return IPath::type_id;
	}

				
	virtual ~LocalPath();
	inline static std::list<IPath*>& Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	
	void set_from(::RailRoadModel::IRailRoadElement* newVal) override;
	::RailRoadModel::IRailRoadElement* from() const override;
	
	void set_via(::RailRoadModel::IRailRoadElement* newVal) override;
	::RailRoadModel::IRailRoadElement* via() const override;
	
	void set_to(::RailRoadModel::IRailRoadElement* newVal) override;
	::RailRoadModel::IRailRoadElement* to() const override;
	
};

} /* namespace RailRoadModel */

#endif /*  RAILROADMODEL_PATH_H_ */
