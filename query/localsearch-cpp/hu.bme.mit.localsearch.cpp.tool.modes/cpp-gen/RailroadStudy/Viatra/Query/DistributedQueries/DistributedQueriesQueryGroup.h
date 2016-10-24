#ifndef VIATRA__QUERY__DISTRIBUTED_QUERIES__DISTRIBUTED_QUERIES_QUERY_GROUP_H_
#define VIATRA__QUERY__DISTRIBUTED_QUERIES__DISTRIBUTED_QUERIES_QUERY_GROUP_H_

		
#include "Viatra/Query/Matcher/ClassHelper.h"
#include "Viatra/Query/Matcher/ISearchContext.h"
#include "Viatra/Query/Matcher/ModelIndex.h"
#include "railRoadModel/Frozen.h"
#include "railRoadModel/Operational.h"
#include "railRoadModel/Path.h"
#include "railRoadModel/Point.h"
#include "railRoadModel/RailRoadElement.h"
#include "railRoadModel/RailRoadModel.h"
#include "railRoadModel/Robot.h"
#include "railRoadModel/RobotElement.h"
#include "railRoadModel/RobotModel.h"
#include "railRoadModel/RobotPart.h"
#include "railRoadModel/Segment.h"
#include "railRoadModel/State.h"
#include "railRoadModel/Train.h"
#include "railRoadModel/Turnout.h"

namespace Viatra {
namespace Query {
namespace DistributedQueries {

class DistributedQueriesQueryGroup{
public:
	static DistributedQueriesQueryGroup* instance() {
		static DistributedQueriesQueryGroup instance;
		return &instance;
	}

	const ::Viatra::Query::Matcher::ISearchContext* context() const {
		return &_isc;
	}

private:
	DistributedQueriesQueryGroup()
		: _isc{ ::Viatra::Query::Matcher::ClassHelper::builder()
					.forClass(::railRoadModel::ITrain::type_id).noSuper()
					.forClass(::railRoadModel::IRailRoadElement::type_id).noSuper()
					.forClass(::railRoadModel::ITurnout::type_id).setSuper(::railRoadModel::IRailRoadElement::type_id)
					.forClass(::railRoadModel::IPoint::type_id).noSuper()
					.forClass(::railRoadModel::IRailRoadModel::type_id).noSuper()
					.forClass(::railRoadModel::ISegment::type_id).setSuper(::railRoadModel::IRailRoadElement::type_id)
					.forClass(::railRoadModel::IPath::type_id).noSuper()
					.forClass(::railRoadModel::IRobotPart::type_id).setSuper(::railRoadModel::IRobotElement::type_id)
					.forClass(::railRoadModel::IRobotElement::type_id).noSuper()
					.forClass(::railRoadModel::IState::type_id).noSuper()
					.forClass(::railRoadModel::IFrozen::type_id).setSuper(::railRoadModel::IState::type_id)
					.forClass(::railRoadModel::IOperational::type_id).setSuper(::railRoadModel::IState::type_id)
					.forClass(::railRoadModel::IRobot::type_id).noSuper()
					.forClass(::railRoadModel::IRobotModel::type_id).noSuper()
					.build() } {
	}

	::Viatra::Query::Matcher::ISearchContext _isc;
};

} /* namespace DistributedQueries */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DISTRIBUTED_QUERIES__DISTRIBUTED_QUERIES_QUERY_GROUP_H_ */
