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
					.forClass(::PlatformModel::Node::type_id).noSuper()
					.forClass(::RailRoadModel::Train::type_id).noSuper()
					.forClass(::RailRoadModel::RailRoadElement::type_id).noSuper()
					.forClass(::RailRoadModel::Point::type_id).noSuper()
					.forClass(::RailRoadModel::RailRoadModel::type_id).noSuper()
					.forClass(::RailRoadModel::Segment::type_id).setSuper(::RailRoadModel::RailRoadElement::type_id)
					.forClass(::RailRoadModel::RobotElement::type_id).noSuper()
					.forClass(::RailRoadModel::Robot::type_id).setSuper(::RailRoadModel::RobotElement::type_id)
					.forClass(::RailRoadModel::RobotPart::type_id).setSuper(::RailRoadModel::RobotElement::type_id)
					.forClass(::RailRoadModel::RobotModel::type_id).noSuper()
					.build() } {
	}

	::Viatra::Query::Matcher::ISearchContext _isc;
};

} /* namespace Deployment */
} /* namespace Query */
} /* namespace Viatra */

namespace Viatra {
	namespace Query {

    struct ModelRoot
  	{
  		ModelRoot(){}

  		~ModelRoot(){}
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
