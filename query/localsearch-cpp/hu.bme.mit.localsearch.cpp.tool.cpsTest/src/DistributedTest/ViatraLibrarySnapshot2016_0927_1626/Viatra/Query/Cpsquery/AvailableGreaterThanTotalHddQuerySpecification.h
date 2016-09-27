#ifndef VIATRA__QUERY__CPSQUERY__AVAILABLE_GREATER_THAN_TOTAL_HDD_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPSQUERY__AVAILABLE_GREATER_THAN_TOTAL_HDD_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/Cpsquery/CpsqueryQueryGroup.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class AvailableGreaterThanTotalHddMatcher;

template<class ModelRoot>
class AvailableGreaterThanTotalHddQuerySpecification {
public:
	using Matcher = AvailableGreaterThanTotalHddMatcher<ModelRoot>;

	using QueryGroup = CpsqueryQueryGroup;


};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__AVAILABLE_GREATER_THAN_TOTAL_HDD_QUERY_SPECIFICATION_H_ */
