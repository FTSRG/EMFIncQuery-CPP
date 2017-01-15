#ifndef VIATRA__QUERY__ITERATOR_QUERY__ROBOT_COLLIDE_WITH_TRAIN_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__ITERATOR_QUERY__ROBOT_COLLIDE_WITH_TRAIN_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/IteratorQuery/IteratorQueryQueryGroup.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace IteratorQuery {

template<class ModelRoot>
class RobotCollideWithTrainMatcher;

template<class ModelRoot>
class RobotCollideWithTrainQuerySpecification {
public:
	using Matcher = RobotCollideWithTrainMatcher<ModelRoot>;

	using QueryGroup = IteratorQueryQueryGroup;


};

} /* namespace IteratorQuery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__ITERATOR_QUERY__ROBOT_COLLIDE_WITH_TRAIN_QUERY_SPECIFICATION_H_ */
