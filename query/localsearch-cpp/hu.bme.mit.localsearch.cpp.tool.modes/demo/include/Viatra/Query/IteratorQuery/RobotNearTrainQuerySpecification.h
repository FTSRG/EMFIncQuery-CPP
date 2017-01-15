#ifndef VIATRA__QUERY__ITERATOR_QUERY__ROBOT_NEAR_TRAIN_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__ITERATOR_QUERY__ROBOT_NEAR_TRAIN_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/IteratorQuery/IteratorQueryQueryGroup.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace IteratorQuery {

template<class ModelRoot>
class RobotNearTrainMatcher;

template<class ModelRoot>
class RobotNearTrainQuerySpecification {
public:
	using Matcher = RobotNearTrainMatcher<ModelRoot>;

	using QueryGroup = IteratorQueryQueryGroup;


};

} /* namespace IteratorQuery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__ITERATOR_QUERY__ROBOT_NEAR_TRAIN_QUERY_SPECIFICATION_H_ */
