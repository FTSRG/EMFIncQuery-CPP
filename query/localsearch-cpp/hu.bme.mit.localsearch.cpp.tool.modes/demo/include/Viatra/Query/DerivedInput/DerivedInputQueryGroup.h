#ifndef VIATRA__QUERY__DERIVED_INPUT__DERIVED_INPUT_QUERY_GROUP_H_
#define VIATRA__QUERY__DERIVED_INPUT__DERIVED_INPUT_QUERY_GROUP_H_

		
#include "Viatra/Query/Matcher/ClassHelper.h"
#include "Viatra/Query/Matcher/ISearchContext.h"
#include "Viatra/Query/Matcher/ModelIndex.h"
#include "railRoadModel/Path.h"
#include "railRoadModel/Point.h"
#include "railRoadModel/RailRoadElement.h"
#include "railRoadModel/RailRoadModel.h"
#include "railRoadModel/Robot.h"
#include "railRoadModel/RobotElement.h"
#include "railRoadModel/RobotModel.h"
#include "railRoadModel/RobotPart.h"
#include "railRoadModel/Segment.h"
#include "railRoadModel/Train.h"
#include "railRoadModel/Turnout.h"

namespace Viatra {
namespace Query {
namespace DerivedInput {

class DerivedInputQueryGroup{
public:
	static DerivedInputQueryGroup* instance() {
		static DerivedInputQueryGroup instance;
		return &instance;
	}

	const ::Viatra::Query::Matcher::ISearchContext* context() const {
		return &_isc;
	}

private:
	DerivedInputQueryGroup()
		: _isc{ ::Viatra::Query::Matcher::ClassHelper::builder()
					.forClass(::railRoadModel::Train::type_id).noSuper()
					.forClass(::railRoadModel::RailRoadElement::type_id).noSuper()
					.forClass(::railRoadModel::Turnout::type_id).setSuper(::railRoadModel::RailRoadElement::type_id)
					.forClass(::railRoadModel::Point::type_id).noSuper()
					.forClass(::railRoadModel::RailRoadModel::type_id).noSuper()
					.forClass(::railRoadModel::Segment::type_id).setSuper(::railRoadModel::RailRoadElement::type_id)
					.forClass(::railRoadModel::Path::type_id).noSuper()
					.forClass(::railRoadModel::RobotPart::type_id).setSuper(::railRoadModel::RobotElement::type_id)
					.forClass(::railRoadModel::RobotElement::type_id).noSuper()
					.forClass(::railRoadModel::Robot::type_id).noSuper()
					.forClass(::railRoadModel::RobotModel::type_id).noSuper()
					.build() } {
	}

	::Viatra::Query::Matcher::ISearchContext _isc;
};

} /* namespace DerivedInput */
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

#endif /*  VIATRA__QUERY__DERIVED_INPUT__DERIVED_INPUT_QUERY_GROUP_H_ */
