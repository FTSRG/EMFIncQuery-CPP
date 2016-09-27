#ifndef VIATRA__QUERY__CPSQUERY__APP_TYPE_INSTANCE_AND_HOST_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__CPSQUERY__APP_TYPE_INSTANCE_AND_HOST_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/Cpsquery/CpsqueryQueryGroup.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Cpsquery {

template<class ModelRoot>
class AppTypeInstanceAndHostMatcher;

template<class ModelRoot>
class AppTypeInstanceAndHostQuerySpecification {
public:
	using Matcher = AppTypeInstanceAndHostMatcher<ModelRoot>;

	using QueryGroup = CpsqueryQueryGroup;


};

} /* namespace Cpsquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__CPSQUERY__APP_TYPE_INSTANCE_AND_HOST_QUERY_SPECIFICATION_H_ */
