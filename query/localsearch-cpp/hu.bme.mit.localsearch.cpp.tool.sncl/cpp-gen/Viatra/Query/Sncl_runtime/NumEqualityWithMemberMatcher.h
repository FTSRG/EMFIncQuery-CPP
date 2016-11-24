#ifndef VIATRA__QUERY__SNCL_RUNTIME__NUM_EQUALITY_WITH_MEMBER_MATCHER_H_
#define VIATRA__QUERY__SNCL_RUNTIME__NUM_EQUALITY_WITH_MEMBER_MATCHER_H_

#include <unordered_set>
		
#include "Viatra/Query/Distributed/QueryRunner.h"
#include "Viatra/Query/Plan/DistSearchPlanExecutor.h"
#include "Viatra/Query/Plan/SearchPlanExecutor.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Sncl_runtime/NumEqualityWithMemberFrame_0.h"
#include "Viatra/Query/Sncl_runtime/NumEqualityWithMemberMatch.h"
#include "Viatra/Query/Sncl_runtime/NumEqualityWithMemberQuerySpecification.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

template<typename>class RootedNumEqualityWithMember;
		
template<class ModelRoot>
class NumEqualityWithMemberMatcher {
	using QueryRunnerT = ::Viatra::Query::Distributed::QueryRunner<RootedNumEqualityWithMember<ModelRoot>>;
public:
	NumEqualityWithMemberMatcher(
	const ModelRoot* model, const ::Viatra::Query::Matcher::ISearchContext* context, QueryRunnerT * queryRunner) 
		: _model(model), _context(context), _queryRunner(queryRunner) {
	}
	std::unordered_set<NumEqualityWithMemberMatch> matches() const {
					using ::Viatra::Query::Matcher::ISearchContext;
		using ::Viatra::Query::Plan::SearchPlan;
		using ::Viatra::Query::Plan::SearchPlanExecutor;
		using ::Viatra::Query::Matcher::ClassHelper;
	
		std::unordered_set<NumEqualityWithMemberMatch> matches;
	
		{
			auto sp = NumEqualityWithMemberQuerySpecification<ModelRoot>::get_plan_unbound__0(_model);
			auto exec = SearchPlanExecutor<NumEqualityWithMemberFrame_0>(sp, *_context);
			
			
			for (auto&& frame : exec) {
				NumEqualityWithMemberMatch match;
			
				match.C1 = static_cast<::arch::ICL*>(frame._0);
			
				matches.insert(match);
			}
		}
		
	
		return matches;
	}
		void continue_0(NumEqualityWithMemberFrame_0& frame, int startOpIndex, NumEqualityWithMemberMatchSet& results, std::map<int, NumEqualityWithMemberFrame_0Vector>& subFrames) const {
			using ::Viatra::Query::Matcher::ISearchContext;
			using ::Viatra::Query::Plan::SearchPlan;
			using ::Viatra::Query::Plan::DistSearchPlanExecutor;
			using ::Viatra::Query::Matcher::ClassHelper;
		
			auto sp = NumEqualityWithMemberQuerySpecification<ModelRoot>::get_plan_unbound__0(_model, &subFrames);
			
			auto unprepared_exec = DistSearchPlanExecutor<NumEqualityWithMemberFrame_0>(sp, *_context, 0, startOpIndex);	
			auto exec = unprepared_exec.prepare(frame);
			
			for (auto&& frame : exec) {
				NumEqualityWithMemberMatch match;
			
				match.C1 = static_cast<::arch::ICL*>(frame._0);
			
				results.insert(match);
			}
		
		}
		
		
	NumEqualityWithMemberMatchSet continueExec(std::string strFrameVector, int bodyID, int startOpIndex){
		switch(bodyID){
			case 0: {
				NumEqualityWithMemberMatchSet resultSet;
				
				// TODO: optimize by using a simple array/vector
				std::map<int, NumEqualityWithMemberFrame_0Vector> frameVectors;
				
				// For each frame
				NumEqualityWithMemberFrame_0Vector::ParseFromStringCallback( strFrameVector, _model, [&](NumEqualityWithMemberFrame_0& frame){
					continue_0(frame, startOpIndex, resultSet, frameVectors);														
				});
				// frameVectors are now update with possible subtask needed to be done
				for (auto & op_pbframe : frameVectors)
				{
					_queryRunner->PropagateFrameVector(bodyID, op_pbframe.first, op_pbframe.second.SerializeAsString());
				}
			
				return resultSet;
			}
			default:
				throw "Matcher continue function has an unidentified bodyID";
			break;
		}
	}
			std::map<int, std::string> distributedStartPoint()
			{
				std::map<int, std::string> ret;
	
				{
					NumEqualityWithMemberFrame_0Vector	vector;
					vector.push_back(NumEqualityWithMemberFrame_0{});
					ret[0] = vector.SerializeAsString();
				}	
				return ret;
			}
							
private:
	QueryRunnerT * _queryRunner;
	const ModelRoot* _model;
	const ::Viatra::Query::Matcher::ISearchContext* _context;
};

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__NUM_EQUALITY_WITH_MEMBER_MATCHER_H_ */
