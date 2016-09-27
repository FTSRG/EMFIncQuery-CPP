#ifndef VIATRA__QUERY__CPSQUERY__NODE_IP_IS_NOT_UNIQUE_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPSQUERY__NODE_IP_IS_NOT_UNIQUE_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/Cpsquery/CpsqueryQueryGroup.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class NodeIpIsNotUniqueMatcher;

template<class ModelRoot>
class NodeIpIsNotUniqueQuerySpecification {
public:
	using Matcher = NodeIpIsNotUniqueMatcher<ModelRoot>;

	using QueryGroup = CpsqueryQueryGroup;


};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__NODE_IP_IS_NOT_UNIQUE_QUERY_SPECIFICATION_H_ */
