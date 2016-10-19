#ifndef VIATRA__QUERY__QUERY__SZILARD_MATCHER_H_
#define VIATRA__QUERY__QUERY__SZILARD_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/Query/SzilardFrame_0.h"
#include "Viatra/Query/Query/SzilardMatch.h"
#include "Viatra/Query/Query/SzilardQuerySpecification.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace Query {

template<class ModelRoot>
class SzilardMatcher {
public:
	SzilardMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}
	std::unordered_set<SzilardMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<SzilardMatch> matches;
	
		{
			auto sp = SzilardQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<SzilardFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				SzilardMatch match;
			
				match.tartaly = static_cast<::factory::Tartaly*>(frame._0);
				match.tartalyID = static_cast<int>(frame._1);
				match.dAllapot = static_cast<::factory::Szilard*>(frame._2);
				match.allapotID = static_cast<int>(frame._3);
				match.homerseklet = static_cast<double>(frame._4);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
	std::unordered_set<SzilardMatch> matches(int tartalyID, int allapotID, double homerseklet) const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<SzilardMatch> matches;
	
		{
			auto sp = SzilardQuerySpecification<ModelRoot>::get_plan_tartalyID_allapotID_homerseklet__0(_model);
			SzilardFrame_0 frame;
			frame._1 = tartalyID;
			frame._3 = allapotID;
			frame._4 = homerseklet;
			
			auto exec = SearchPlanExecutor<SzilardFrame_0>(sp, *_context).prepare(frame);
			
			
			for (auto&& frame : exec) {
				SzilardMatch match;
			
				match.tartaly = static_cast<::factory::Tartaly*>(frame._0);
				match.tartalyID = static_cast<int>(frame._1);
				match.dAllapot = static_cast<::factory::Szilard*>(frame._2);
				match.allapotID = static_cast<int>(frame._3);
				match.homerseklet = static_cast<double>(frame._4);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
	
private:
	const ModelRoot* _model;
	const ::Viatra::Query::Matcher::ISearchContext* _context;
};

} /* namespace Query */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__QUERY__SZILARD_MATCHER_H_ */
