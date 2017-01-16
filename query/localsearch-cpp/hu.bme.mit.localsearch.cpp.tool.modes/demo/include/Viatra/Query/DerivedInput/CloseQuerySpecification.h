#ifndef VIATRA__QUERY__DERIVED_INPUT__CLOSE_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__DERIVED_INPUT__CLOSE_QUERY_SPECIFICATION_H_

		
#include "Viatra/Query/DerivedInput/DerivedInputQueryGroup.h"
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace DerivedInput {

template<class ModelRoot>
class CloseMatcher;

template<class ModelRoot>
class CloseQuerySpecification {
public:
	using Matcher = CloseMatcher<ModelRoot>;

	using QueryGroup = DerivedInputQueryGroup;


};

} /* namespace DerivedInput */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED_INPUT__CLOSE_QUERY_SPECIFICATION_H_ */
