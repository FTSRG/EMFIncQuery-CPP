#ifndef VIATRA__QUERY__DERIVED_INPUT__FROZEN_STATE_A_P_I_INPUT_UPDATER_H_
#define VIATRA__QUERY__DERIVED_INPUT__FROZEN_STATE_A_P_I_INPUT_UPDATER_H_

#include <algorithm>
#include <stdexcept>
		
#include "Viatra/Query/DerivedInput/FrozenStateAPIMatcher.h"
#include "Viatra/Query/Matcher/ModelIndex.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace DerivedInput {

struct FrozenStateAPIInputUpdater{
	/*
	 * It is generated for only sending vector coordinates into the model instance. 
	 * The Derived feature has a source and a target, their id must be given in update function parameter i.e. (srcID, trgID, ...).
	 * If that isn't guaranteed this code crashes in compile time.
	 */
	static void update(::Viatra::Query::Model::ModelRoot* modelRoot,int turnoutID, int stateID, double turnoutTemp){
		/*
		 * Critical Section START
		 * Atomicity is mandatory
		 * Not supported parallel modifications and queries
		 */						
		auto srcInstanceList = ModelIndex<typename std::remove_pointer< ::railRoadModel::ITurnout >::type, ::Viatra::Query::Model::ModelRoot>::instances(modelRoot);
		auto srcIDPredicate = [turnoutID](const ::railRoadModel::ITurnout* src){
			return src->get_id() == turnoutID;
		};
		
		auto srcObj = std::find_if(srcInstanceList.begin(), srcInstanceList.end(), srcIDPredicate);
		
		if(srcObj == srcInstanceList.end()) throw new std::invalid_argument("::railRoadModel::ITurnout ID not found");
		
		auto engine = QueryEngine<::Viatra::Query::Model::ModelRoot>::of(modelRoot);
		auto currentStateMatcher = engine.template matcher< FrozenStateAPIQuerySpecification >();
		auto matches = currentStateMatcher.matches_turnoutID_stateID_turnoutTemp(turnoutID, stateID, turnoutTemp);
		
		auto trgInstanceList = ModelIndex<typename std::remove_pointer< ::railRoadModel::IFrozen >::type, ::Viatra::Query::Model::ModelRoot>::instances(modelRoot);
		auto trgIDPredicate = [stateID](const ::railRoadModel::IFrozen* trg){
			return trg->get_id() == stateID;
		};
		
		auto trgObj = std::find_if(trgInstanceList.begin(), trgInstanceList.end(), trgIDPredicate);
		
		if(trgObj == trgInstanceList.end()) throw new std::invalid_argument("::railRoadModel::IFrozen ID not found in InputUpdater");
		if(matches.size() > 0){	
			(*srcObj)->set_currentState(*trgObj);
		}
		else if((*trgObj) == (*srcObj)->get_currentState()) (*srcObj)->set_currentState(nullptr);
		/*
		* Critical Section END
		*/
	}
};

} /* namespace DerivedInput */
} /* namespace Query */
} /* namespace Viatra */

	

#endif /*  VIATRA__QUERY__DERIVED_INPUT__FROZEN_STATE_A_P_I_INPUT_UPDATER_H_ */
