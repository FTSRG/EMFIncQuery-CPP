#ifndef VIATRA__QUERY__TEST__TEST_MATCHER_H_
#define VIATRA__QUERY__TEST__TEST_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Test/TestFrame_0.h"
#include "Viatra/Query/Test/TestMatch.h"
#include "Viatra/Query/Test/TestQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Test {

template<class ModelRoot>
class TestMatcher {
public:
	TestMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}
	std::unordered_set<TestMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<TestMatch> matches;
	
		{
			auto sp = TestQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<TestFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				TestMatch match;
			
				match.tank = static_cast<::factory::Tank*>(frame._0);
				match.allapot = static_cast<::factory::Halmazallapot*>(frame._1);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
	
private:
	const ModelRoot* _model;
	const ::Viatra::Query::Matcher::ISearchContext* _context;
};

} /* namespace Test */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__TEST__TEST_MATCHER_H_ */
