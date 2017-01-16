#ifndef VIATRA__QUERY__ITERATOR_QUERY__ROBOT_IS_SAFE_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__ITERATOR_QUERY__ROBOT_IS_SAFE_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/IteratorQuery/IteratorQueryQueryGroup.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace IteratorQuery {

template<class ModelRoot>
class RobotIsSafeMatcher;

template<class ModelRoot>
class RobotIsSafeQuerySpecification {
public:
	using Matcher = RobotIsSafeMatcher<ModelRoot>;

	using QueryGroup = IteratorQueryQueryGroup;


};

} /* namespace IteratorQuery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__ITERATOR_QUERY__ROBOT_IS_SAFE_QUERY_SPECIFICATION_H_ */
