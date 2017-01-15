#ifndef VIATRA__QUERY__ITERATOR_QUERY__ROBOT_NEAR_TRAIN_MATCHER_H_
#define VIATRA__QUERY__ITERATOR_QUERY__ROBOT_NEAR_TRAIN_MATCHER_H_

#include <type_traits>
#include <unordered_set>
		
#include "Viatra/Query/IteratorQuery/RobotNearTrainMatch.h"
#include "Viatra/Query/IteratorQuery/RobotNearTrainQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Util/IsNull.h"

namespace Viatra {
namespace Query {
namespace IteratorQuery {

template<class ModelRoot>
class RobotNearTrainMatcher {
public:
	RobotNearTrainMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<RobotNearTrainMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<RobotNearTrainMatch> matches;
	
		{
			auto _classHelper = &_context->get_class_helper();		
			for(auto&& rp : (ModelIndex<std::remove_pointer<::railRoadModel::RobotPart>::type, ModelRoot>::instances(_model))) {
				for(auto&& tr : rp->close) {
					if(_classHelper->is_super_type(rp->get_type_id(), ::railRoadModel::RobotPart::type_id)) {
						auto rp_0 = rp;
						if(_classHelper->is_super_type(tr->get_type_id(), ::railRoadModel::Train::type_id)) {
							auto tr_0 = tr;
							if(_classHelper->is_super_type(rp_0->get_type_id(), ::railRoadModel::RobotPart::type_id)) {
								auto rp_1 = rp_0;
								::Viatra::Query::IteratorQuery::RobotNearTrainMatch match;
								match.rp = static_cast<::railRoadModel::RobotPart*>(rp_1);
								match.tr = static_cast<::railRoadModel::Train*>(tr_0);
								
								matches.insert(match);
							}
						}
					}
				}
			}
		}
		
	
		return matches;
	}
	
private:
	const ModelRoot* _model;
	const ::Viatra::Query::Matcher::ISearchContext* _context;
};

} /* namespace IteratorQuery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__ITERATOR_QUERY__ROBOT_NEAR_TRAIN_MATCHER_H_ */
