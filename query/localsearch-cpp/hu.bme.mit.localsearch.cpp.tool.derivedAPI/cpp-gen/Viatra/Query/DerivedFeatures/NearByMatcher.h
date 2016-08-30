#ifndef VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_MATCHER_H_
#define VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_MATCHER_H_

#include <unordered_set>

#include "Viatra/Query/DerivedFeatures/NearByFrame_0.h"
#include "Viatra/Query/DerivedFeatures/NearByMatch.h"
#include "Viatra/Query/DerivedFeatures/NearByQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace DerivedFeatures {

template<class ModelRoot>
class NearByMatcher {
public:
	NearByMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context)
		: _model(model), _context(context) {
	}/*
	std::unordered_set<NearByMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;

		std::unordered_set<NearByMatch> matches;

		{
			auto sp = NearByQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<NearByFrame_0>(sp, *_context);


			for (auto&& frame : exec) {
				NearByMatch match;

				match.robotPart = static_cast<::RailRoadModel::RobotPart*>(frame._0);
				match.robotPartID = static_cast<int>(frame._1);
				match.train = static_cast<::RailRoadModel::Train*>(frame._2);
				match.trainID = static_cast<int>(frame._3);
				match.robX = static_cast<double>(frame._4);
				match.robY = static_cast<double>(frame._5);
				match.robZ = static_cast<double>(frame._6);
				match.trX = static_cast<double>(frame._7);
				match.trY = static_cast<double>(frame._8);
				match.trZ = static_cast<double>(frame._9);

				matches.insert(match);
			}
		}


		return matches;
	}*/
	std::unordered_set<NearByMatch> matches(int robotPartID, int trainID, double robX, double robY, double robZ, double trX, double trY, double trZ) const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;

		std::unordered_set<NearByMatch> matches;

		{
			auto sp = NearByQuerySpecification<ModelRoot>::get_plan_robotPartID_trainID_robX_robY_robZ_trX_trY_trZ__0(_model);
			NearByFrame_0 frame;
			frame._1 = robotPartID;
			frame._3 = trainID;
			frame._4 = robX;
			frame._5 = robY;
			frame._6 = robZ;
			frame._7 = trX;
			frame._8 = trY;
			frame._9 = trZ;

			auto exec = SearchPlanExecutor<NearByFrame_0>(sp, *_context).prepare(frame);


			for (auto&& frame : exec) {
				NearByMatch match;

				match.robotPart = static_cast<::RailRoadModel::RobotPart*>(frame._0);
				match.robotPartID = static_cast<int>(frame._1);
				match.train = static_cast<::RailRoadModel::Train*>(frame._2);
				match.trainID = static_cast<int>(frame._3);
				match.robX = static_cast<double>(frame._4);
				match.robY = static_cast<double>(frame._5);
				match.robZ = static_cast<double>(frame._6);
				match.trX = static_cast<double>(frame._7);
				match.trY = static_cast<double>(frame._8);
				match.trZ = static_cast<double>(frame._9);

				matches.insert(match);
			}
		}


		return matches;
	}

private:
	const ModelRoot* _model;
	const ::Viatra::Query::Matcher::ISearchContext* _context;
};

} /* namespace DerivedFeatures */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_MATCHER_H_ */
