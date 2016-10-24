#ifndef VIATRA__QUERY__DEPLOYMENT__DEPLOYMENT_QUERY_GROUP_H_
#define VIATRA__QUERY__DEPLOYMENT__DEPLOYMENT_QUERY_GROUP_H_

		
#include "PlatformModel/Node.h"
#include "RailRoadModel/Point.h"
#include "RailRoadModel/RailRoadElement.h"
#include "RailRoadModel/RailRoadModel.h"
#include "RailRoadModel/Robot.h"
#include "RailRoadModel/RobotElement.h"
#include "RailRoadModel/RobotModel.h"
#include "RailRoadModel/RobotPart.h"
#include "RailRoadModel/Segment.h"
#include "RailRoadModel/Train.h"
#include "Viatra/Query/Matcher/ClassHelper.h"
#include "Viatra/Query/Matcher/ISearchContext.h"
#include "Viatra/Query/Matcher/ModelIndex.h"

namespace Viatra {
namespace Query {
namespace Deployment {

class DeploymentQueryGroup{
public:
	static DeploymentQueryGroup* instance() {
		static DeploymentQueryGroup instance;
		return &instance;
	}

	const ::Viatra::Query::Matcher::ISearchContext* context() const {
		return &_isc;
	}

private:
	DeploymentQueryGroup()
		: _isc{ ::Viatra::Query::Matcher::ClassHelper::builder()
					.forClass(::PlatformModel::INode::type_id).noSuper()
					.forClass(::RailRoadModel::ITrain::type_id).noSuper()
					.forClass(::RailRoadModel::IRailRoadElement::type_id).noSuper()
					.forClass(::RailRoadModel::IPoint::type_id).noSuper()
					.forClass(::RailRoadModel::IRailRoadModel::type_id).noSuper()
					.forClass(::RailRoadModel::ISegment::type_id).setSuper(::RailRoadModel::IRailRoadElement::type_id)
					.forClass(::RailRoadModel::IRobotElement::type_id).noSuper()
					.forClass(::RailRoadModel::IRobot::type_id).setSuper(::RailRoadModel::IRobotElement::type_id)
					.forClass(::RailRoadModel::IRobotPart::type_id).setSuper(::RailRoadModel::IRobotElement::type_id)
					.forClass(::RailRoadModel::IRobotModel::type_id).noSuper()
					.build() } {
	}

	::Viatra::Query::Matcher::ISearchContext _isc;
};

} /* namespace Deployment */
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

#endif /*  VIATRA__QUERY__DEPLOYMENT__DEPLOYMENT_QUERY_GROUP_H_ */
