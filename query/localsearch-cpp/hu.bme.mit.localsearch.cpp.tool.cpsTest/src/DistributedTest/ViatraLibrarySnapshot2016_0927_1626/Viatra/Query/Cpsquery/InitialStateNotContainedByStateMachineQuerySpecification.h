#ifndef VIATRA__QUERY__CPSQUERY__INITIAL_STATE_NOT_CONTAINED_BY_STATE_MACHINE_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPSQUERY__INITIAL_STATE_NOT_CONTAINED_BY_STATE_MACHINE_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/Cpsquery/CpsqueryQueryGroup.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class InitialStateNotContainedByStateMachineMatcher;

template<class ModelRoot>
class InitialStateNotContainedByStateMachineQuerySpecification {
public:
	using Matcher = InitialStateNotContainedByStateMachineMatcher<ModelRoot>;

	using QueryGroup = CpsqueryQueryGroup;


};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__INITIAL_STATE_NOT_CONTAINED_BY_STATE_MACHINE_QUERY_SPECIFICATION_H_ */
