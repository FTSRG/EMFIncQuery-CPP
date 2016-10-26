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
		using Viatra::Query::Util::Logger;
		auto srcInstanceList = ModelIndex<::railRoadModel::ITurnout, ::Viatra::Query::Model::ModelRoot>::instances(modelRoot);
		Logger::Log("::railRoadModel::ITurnout list size: ", srcInstanceList.size());
		auto srcIDPredicate = [turnoutID](const ::railRoadModel::ITurnout* src){
			Logger::Log("::railRoadModel::ITurnout present ID= ", src->get_id(), " == ", turnoutID);
			return src->get_id() == turnoutID;
		};
		
		auto srcObj = std::find_if(srcInstanceList.begin(), srcInstanceList.end(), srcIDPredicate);
		
		if(srcObj == srcInstanceList.end()) throw std::invalid_argument("::railRoadModel::ITurnout ID not found");
		
		auto engine = QueryEngine<::Viatra::Query::Model::ModelRoot>::of(modelRoot);
		auto currentStateMatcher = engine.template matcher< FrozenStateAPIQuerySpecification >();
		auto matches = currentStateMatcher.matches_turnoutID_stateID_turnoutTemp(turnoutID, stateID, turnoutTemp);
		
		auto trgInstanceList = ModelIndex<::railRoadModel::IFrozen, ::Viatra::Query::Model::ModelRoot>::instances(modelRoot);
		Logger::Log("::railRoadModel::IFrozen list size: ", trgInstanceList.size());
		auto trgIDPredicate = [stateID](const ::railRoadModel::IFrozen* trg){
			Logger::Log("::railRoadModel::IFrozen present ID= ", trg->get_id(), " == ", stateID);
			return trg->get_id() == stateID;
		};
		
		auto trgObj = std::find_if(trgInstanceList.begin(), trgInstanceList.end(), trgIDPredicate);
		
		if(trgObj == trgInstanceList.end()) throw std::invalid_argument("::railRoadModel::IFrozen ID not found in InputUpdater");
		if(matches.size() > 0){	
			Logger::Log("currentState association inserted between (ID-ID) = ", turnoutID, "-", stateID);
			(*srcObj)->set_currentState(*trgObj);
		}
		else if((*trgObj) == (*srcObj)->get_currentState()){
			Logger::Log("currentState association removed between (ID-ID) = ", turnoutID, "-", stateID);
			 (*srcObj)->set_currentState(nullptr);
		 }
		/*
		* Critical Section END
		*/
	}
};

} /* namespace DerivedInput */
} /* namespace Query */
} /* namespace Viatra */

	

#endif /*  VIATRA__QUERY__DERIVED_INPUT__FROZEN_STATE_A_P_I_INPUT_UPDATER_H_ */
