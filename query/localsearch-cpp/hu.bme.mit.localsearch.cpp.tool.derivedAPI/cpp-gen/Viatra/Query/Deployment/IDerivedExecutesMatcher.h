#ifndef VIATRA__QUERY__DEPLOYMENT__I_DERIVED_EXECUTES_MATCHER_H_
#define VIATRA__QUERY__DEPLOYMENT__I_DERIVED_EXECUTES_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Deployment/IDerivedExecutesFrame_0.h"
#include "Viatra/Query/Deployment/IDerivedExecutesFrame_1.h"
#include "Viatra/Query/Deployment/IDerivedExecutesMatch.h"
#include "Viatra/Query/Deployment/IDerivedExecutesQuerySpecification.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace Deployment {

template<class ModelRoot>
class IDerivedExecutesMatcher {
public:
	IDerivedExecutesMatcher(const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context) 
		: _model(model), _context(context) {
	}
	std::unordered_set<IDerivedExecutesMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<IDerivedExecutesMatch> matches;
	
		{
			auto sp = IDerivedExecutesQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<IDerivedExecutesFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				IDerivedExecutesMatch match;
			
				match.node = static_cast<::PlatformModel::Node*>(frame._0);
				match.nodeID = static_cast<int>(frame._1);
				match.train = static_cast<::RailRoadModel::Train*>(frame._2);
				match.trainID = static_cast<int>(frame._3);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = IDerivedExecutesQuerySpecification<ModelRoot>::get_plan_unbound__1(_model);
			auto exec = SearchPlanExecutor<IDerivedExecutesFrame_1>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				IDerivedExecutesMatch match;
			
				match.node = static_cast<::PlatformModel::Node*>(frame._0);
				match.nodeID = static_cast<int>(frame._1);
				match.train = static_cast<::RailRoadModel::Train*>(frame._2);
				match.trainID = static_cast<int>(frame._3);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
	std::unordered_set<IDerivedExecutesMatch> matches(int nodeID) const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<IDerivedExecutesMatch> matches;
	
		{
			auto sp = IDerivedExecutesQuerySpecification<ModelRoot>::get_plan_nodeID__0(_model);
			IDerivedExecutesFrame_0 frame;
			frame._1 = nodeID;
			
			auto exec = SearchPlanExecutor<IDerivedExecutesFrame_0>(sp, *_context).prepare(frame);
			
			
			for (auto&& frame : exec) {
				IDerivedExecutesMatch match;
			
				match.node = static_cast<::PlatformModel::Node*>(frame._0);
				match.nodeID = static_cast<int>(frame._1);
				match.train = static_cast<::RailRoadModel::Train*>(frame._2);
				match.trainID = static_cast<int>(frame._3);
			
				matches.insert(match);
			}
		}
		
		{
			auto sp = IDerivedExecutesQuerySpecification<ModelRoot>::get_plan_nodeID__1(_model);
			IDerivedExecutesFrame_1 frame;
			frame._1 = nodeID;
			
			auto exec = SearchPlanExecutor<IDerivedExecutesFrame_1>(sp, *_context).prepare(frame);
			
			
			for (auto&& frame : exec) {
				IDerivedExecutesMatch match;
			
				match.node = static_cast<::PlatformModel::Node*>(frame._0);
				match.nodeID = static_cast<int>(frame._1);
				match.train = static_cast<::RailRoadModel::Train*>(frame._2);
				match.trainID = static_cast<int>(frame._3);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
	
private:
	const ModelRoot* _model;
	const ::Viatra::Query::Matcher::ISearchContext* _context;
};

} /* namespace Deployment */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DEPLOYMENT__I_DERIVED_EXECUTES_MATCHER_H_ */
