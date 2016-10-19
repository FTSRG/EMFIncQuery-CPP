#ifndef VIATRA__QUERY__TEST__TEST_QUERY_GROUP_H_
#define VIATRA__QUERY__TEST__TEST_QUERY_GROUP_H_

		
#include "Viatra/Query/Matcher/ClassHelper.h"
#include "Viatra/Query/Matcher/ISearchContext.h"
#include "Viatra/Query/Matcher/ModelIndex.h"
#include "factory/Anyag.h"
#include "factory/Folyekony.h"
#include "factory/Goz.h"
#include "factory/Halmazallapot.h"
#include "factory/Szilard.h"
#include "factory/Tank.h"
#include "factory/Viz.h"

namespace Viatra {
namespace Query {
namespace Test {

class TestQueryGroup{
public:
	static TestQueryGroup* instance() {
		static TestQueryGroup instance;
		return &instance;
	}

	const ::Viatra::Query::Matcher::ISearchContext* context() const {
		return &_isc;
	}

private:
	TestQueryGroup()
		: _isc{ ::Viatra::Query::Matcher::ClassHelper::builder()
					.forClass(::factory::Tank::type_id).noSuper()
					.forClass(::factory::Anyag::type_id).noSuper()
					.forClass(::factory::Viz::type_id).setSuper(::factory::Anyag::type_id)
					.forClass(::factory::Halmazallapot::type_id).noSuper()
					.forClass(::factory::Folyekony::type_id).setSuper(::factory::Halmazallapot::type_id)
					.forClass(::factory::Goz::type_id).setSuper(::factory::Halmazallapot::type_id)
					.forClass(::factory::Szilard::type_id).setSuper(::factory::Halmazallapot::type_id)
					.build() } {
	}

	::Viatra::Query::Matcher::ISearchContext _isc;
};

} /* namespace Test */
} /* namespace Query */
} /* namespace Viatra */

namespace Viatra {
	namespace Query {
		
	class Any{
	private:
		class ContainerBase{
		public:
			virtual ~ContainerBase(){}
		};
		
		template<typename T>
		class Container : public ContainerBase{
		public:
			T data;
			Container(T const &modelRoot) : data(modelRoot) {}
		};
		
		ContainerBase* pdata;
	public:
		Any() :pdata(nullptr){}
		Any(Any const &to_copy) = delete;
		Any& operator(Any const& to_copy) = delete;
		~Any() { delete pdata; }
		
		//must implement T copy cstr properly
		template <typename T>
		void set(T const &modelRoot){
			ContainerBase *newpdata = new Container<T>(modelRoot);
			delete pdata;
			pdata = newpdata;
		}
		
		template <typename T>
		T& get(){
			return dynamic_cast<Container<T>&>(*pdata).data;
		}
		
		template <typename T>
		T const & get() const {
			return dynamic_cast<Container<T>&>(*pdata).data;
		}
	};

    struct ModelRoot
  	{
  		ModelRoot(){}

  		~ModelRoot(){}
  		
  		Any root;
  		
  	};

	template<typename T>
	struct ModelIndex<T, ModelRoot> {
		static const std::list<T*>& instances(const ModelRoot* modelRoot)
		{
			return T::_instances;
		}
	};
	}
}

#endif /*  VIATRA__QUERY__TEST__TEST_QUERY_GROUP_H_ */
