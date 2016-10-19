#ifndef VIATRA__QUERY__TEST__TEST_QUERY_SPECIFICATION_H_
#define VIATRA__QUERY__TEST__TEST_QUERY_SPECIFICATION_H_

#include <cmath>
		
#include "Viatra/Query/Operations/AllOperations.h"
#include "Viatra/Query/Plan/SearchPlan.h"
#include "Viatra/Query/Test/TestFrame_0.h"
#include "Viatra/Query/Test/TestQueryGroup.h"
#include "Viatra/Query/Util/Optional.h"

namespace Viatra {
namespace Query {
namespace Test {

template<class ModelRoot>
class TestMatcher;

template<class ModelRoot>
class TestQuerySpecification {
public:
	using Matcher = TestMatcher<ModelRoot>;

	using QueryGroup = TestQueryGroup;

	static ::Viatra::Query::Plan::SearchPlan<TestFrame_0> get_plan_unbound__0(const ModelRoot* model) {
		using namespace ::Viatra::Query::Operations::Check;
		using namespace ::Viatra::Query::Operations::Extend;
	
		::Viatra::Query::Plan::SearchPlan<TestFrame_0> sp;
		
		
		sp.add_operation(create_IterateOverInstances(&TestFrame_0::_0, ::factory::Tank::type_id, model));
		sp.add_operation(create_NavigateSingleAssociation(&TestFrame_0::_0, &TestFrame_0::_1, &::factory::Tank::allapot));
		sp.add_operation(create_InstanceOfCheck(&TestFrame_0::_0, ::factory::Tank::type_id));
		
		return sp;
	}

};

} /* namespace Test */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__TEST__TEST_QUERY_SPECIFICATION_H_ */
