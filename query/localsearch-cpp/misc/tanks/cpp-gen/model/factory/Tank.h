#ifndef FACTORY_TANK_H_
#define FACTORY_TANK_H_

#include "factory_decl.h"


#include <string>
#include <list>
#include <vector>

#include <Viatra/Query/Model/ModelElement.h>
#include <Viatra/Query/Model/RemoteElement.h>
#include <Viatra/Query/Model/LocalElement.h>
#include <Viatra/Query/Model/IModelElemService.h>

namespace factory {

class ITank;
class RemoteTank;
class LocalTank;


class ITank : 
	public virtual Viatra::Query::Model::ModelElement
{
public:
	using RemoteImplementation = RemoteTank;
	using LocalImplementation = LocalTank;
	ITank(Viatra::Query::Model::id_t id, bool present)
		: ModelElement(id, present)
	{}

	virtual ~ITank() {}
	static constexpr unsigned short type_id = 0;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}

	virtual void set_ID(int newVal) = 0;
	virtual int ID() = 0;
	
	virtual void set_tarol(::factory::Anyag* newVal) = 0;
	virtual ::factory::Anyag* tarol() = 0;
	virtual void set_allapot(::factory::Halmazallapot* newVal) = 0;
	virtual ::factory::Halmazallapot* allapot() = 0;
};


class RemoteTank : 
	public Viatra::Query::Model::RemoteElement, 
	public ITank
{
public:
	RemoteTank(Viatra::Query::Model::id_t id, Viatra::Query::Model::IModelElemService* serv);
	
	virtual ~RemoteTank();

	void set_ID(int newVal) override;
	int ID() override;
	
	void set_tarol(::factory::Anyag* newVal) override;
	::factory::Anyag* tarol() override;
	void set_allapot(::factory::Halmazallapot* newVal) override;
	::factory::Halmazallapot* allapot() override;
};

class LocalTank : 
	public virtual Viatra::Query::Model::LocalElement, 
	public ITank
{
private:
	static std::list<ITank*> _instances__x__x__x__x__x__x__x;
			
	int _ID = 0;
	
	::factory::Anyag* _tarol = nullptr;
	::factory::Halmazallapot* _allapot = nullptr;
	
public:
	LocalTank(Viatra::Query::Model::id_t id);
	virtual ~LocalTank();
	static const unsigned short type_id = 1;
	
	virtual unsigned short get_type_id() const {
		return type_id;
	}
	
	inline static std::list<ITank*> Instances()
	{
		return _instances__x__x__x__x__x__x__x;				
	}

	void set_ID(int newVal) override;
	int ID() override;

	
	void set_tarol(::factory::Anyag* newVal) override;
	::factory::Anyag* tarol() override;
	
	void set_allapot(::factory::Halmazallapot* newVal) override;
	::factory::Halmazallapot* allapot() override;
	
};

} /* namespace factory */

#endif /*  FACTORY_TANK_H_ */
