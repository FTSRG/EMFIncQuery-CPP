#ifndef VIATRA__QUERY__CPSQUERY__NOT_ALLOCATED_BUT_RUNNING_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPSQUERY__NOT_ALLOCATED_BUT_RUNNING_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/Cpsquery/CpsqueryQueryGroup.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class NotAllocatedButRunningMatcher;

template<class ModelRoot>
class NotAllocatedButRunningQuerySpecification {
public:
	using Matcher = NotAllocatedButRunningMatcher<ModelRoot>;

	using QueryGroup = CpsqueryQueryGroup;


};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__NOT_ALLOCATED_BUT_RUNNING_QUERY_SPECIFICATION_H_ */
