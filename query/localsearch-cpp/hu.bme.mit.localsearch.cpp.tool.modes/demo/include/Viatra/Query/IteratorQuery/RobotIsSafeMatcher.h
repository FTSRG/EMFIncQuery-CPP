#ifndef VIATRA__QUERY__ITERATOR_QUERY__ROBOT_IS_SAFE_MATCHER_H_
#define VIATRA__QUERY__ITERATOR_QUERY__ROBOT_IS_SAFE_MATCHER_H_

#include <type_traits>
#include <unordered_set>
		
#include "Viatra/Query/IteratorQuery/RobotIsSafeMatch.h"
#include "Viatra/Query/IteratorQuery/RobotIsSafeQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Util/IsNull.h"

namespace Viatra {
namespace Query {
namespace IteratorQuery {

template<class ModelRoot>
class RobotIsSafeMatcher {
public:
	RobotIsSafeMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}

	std::unordered_set<RobotIsSafeMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<RobotIsSafeMatch> matches;
	
		{
			auto _classHelper = &_context->get_class_helper();		
			for(auto&& robotCollideWithTrain_0__rp : (ModelIndex<std::remove_pointer<::railRoadModel::RobotPart>::type, ModelRoot>::instances(_model))) {
				for(auto&& robotCollideWithTrain_0__tr : robotCollideWithTrain_0__rp->veryClose) {
					if(_classHelper->is_super_type(robotCollideWithTrain_0__rp->get_type_id(), ::railRoadModel::RobotPart::type_id)) {
						auto robotCollideWithTrain_0__rp_0 = robotCollideWithTrain_0__rp;
						if(_classHelper->is_super_type(robotCollideWithTrain_0__tr->get_type_id(), ::railRoadModel::Train::type_id)) {
							auto robotCollideWithTrain_0__tr_0 = robotCollideWithTrain_0__tr;
							if(_classHelper->is_super_type(robotCollideWithTrain_0__rp_0->get_type_id(), ::railRoadModel::RobotPart::type_id)) {
								auto robotCollideWithTrain_0__rp_1 = robotCollideWithTrain_0__rp_0;
								if(_classHelper->is_super_type(robotCollideWithTrain_0__rp_1->get_type_id(), ::railRoadModel::RobotPart::type_id)) {
									auto robotCollideWithTrain_0__rp_2 = robotCollideWithTrain_0__rp_1;
									if(_classHelper->is_super_type(robotCollideWithTrain_0__tr_0->get_type_id(), ::railRoadModel::Train::type_id)) {
										auto robotCollideWithTrain_0__tr_1 = robotCollideWithTrain_0__tr_0;
										::Viatra::Query::IteratorQuery::RobotIsSafeMatch match;
										match.rp = static_cast<::railRoadModel::RobotPart*>(robotCollideWithTrain_0__rp_2);
										match.tr = static_cast<::railRoadModel::Train*>(robotCollideWithTrain_0__tr_1);
										
										matches.insert(match);
									}
								}
							}
						}
					}
				}
			}
		}
		
		{
			auto _classHelper = &_context->get_class_helper();		
			for(auto&& robotNearTrain_0__rp : (ModelIndex<std::remove_pointer<::railRoadModel::RobotPart>::type, ModelRoot>::instances(_model))) {
				for(auto&& robotNearTrain_0__tr : robotNearTrain_0__rp->close) {
					if(_classHelper->is_super_type(robotNearTrain_0__rp->get_type_id(), ::railRoadModel::RobotPart::type_id)) {
						auto robotNearTrain_0__rp_0 = robotNearTrain_0__rp;
						if(_classHelper->is_super_type(robotNearTrain_0__tr->get_type_id(), ::railRoadModel::Train::type_id)) {
							auto robotNearTrain_0__tr_0 = robotNearTrain_0__tr;
							if(_classHelper->is_super_type(robotNearTrain_0__rp_0->get_type_id(), ::railRoadModel::RobotPart::type_id)) {
								auto robotNearTrain_0__rp_1 = robotNearTrain_0__rp_0;
								if(_classHelper->is_super_type(robotNearTrain_0__rp_1->get_type_id(), ::railRoadModel::RobotPart::type_id)) {
									auto robotNearTrain_0__rp_2 = robotNearTrain_0__rp_1;
									if(_classHelper->is_super_type(robotNearTrain_0__tr_0->get_type_id(), ::railRoadModel::Train::type_id)) {
										auto robotNearTrain_0__tr_1 = robotNearTrain_0__tr_0;
										::Viatra::Query::IteratorQuery::RobotIsSafeMatch match;
										match.rp = static_cast<::railRoadModel::RobotPart*>(robotNearTrain_0__rp_2);
										match.tr = static_cast<::railRoadModel::Train*>(robotNearTrain_0__tr_1);
										
										matches.insert(match);
									}
								}
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


#endif /*  VIATRA__QUERY__ITERATOR_QUERY__ROBOT_IS_SAFE_MATCHER_H_ */
