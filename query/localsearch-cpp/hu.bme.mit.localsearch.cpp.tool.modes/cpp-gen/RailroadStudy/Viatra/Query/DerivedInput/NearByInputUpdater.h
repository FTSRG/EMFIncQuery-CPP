#ifndef VIATRA__QUERY__DERIVED_INPUT__NEAR_BY_INPUT_UPDATER_H_
#define VIATRA__QUERY__DERIVED_INPUT__NEAR_BY_INPUT_UPDATER_H_

#include <algorithm>
#include <stdexcept>
		
#include "Viatra/Query/DerivedInput/NearByMatcher.h"
#include "Viatra/Query/Matcher/ModelIndex.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace DerivedInput {

struct NearByInputUpdater{
	/*
	 * It is generated for only sending vector coordinates into the model instance. 
	 * The Derived feature has a source and a target, their id must be given in update function parameter i.e. (srcID, trgID, ...).
	 * If that isn't guaranteed this code crashes in compile time.
	 */
	static void update(::Viatra::Query::Model::ModelRoot* modelRoot,int robotPartID, int trainID, int segID, double robX, double robY, double robZ, double segX, double segY, double segZ){
		/*
		 * Critical Section START
		 * Atomicity is mandatory
		 * Not supported parallel modifications and queries
		 */			
		using Viatra::Query::Util::Logger;
		auto srcInstanceList = ModelIndex<::railRoadModel::IRobotPart, ::Viatra::Query::Model::ModelRoot>::instances(modelRoot);
		Logger::Log("::railRoadModel::IRobotPart list size: ", srcInstanceList.size());
		auto srcIDPredicate = [robotPartID](const ::railRoadModel::IRobotPart* src){
			Logger::Log("::railRoadModel::IRobotPart present ID= ", src->get_id(), " == ", turnoutID);
			return src->get_id() == robotPartID;
		};
		
		auto srcObj = std::find_if(srcInstanceList.begin(), srcInstanceList.end(), srcIDPredicate);
		
		if(srcObj == srcInstanceList.end()) throw std::invalid_argument("::railRoadModel::IRobotPart ID not found");
		
		auto engine = QueryEngine<::Viatra::Query::Model::ModelRoot>::of(modelRoot);
		auto nearByMatcher = engine.template matcher< NearByQuerySpecification >();
		auto matches = nearByMatcher.matches_robotPartID_trainID_segID_robX_robY_robZ_segX_segY_segZ(robotPartID, trainID, segID, robX, robY, robZ, segX, segY, segZ);
		
		auto trgInstanceList = ModelIndex<::railRoadModel::ITrain, ::Viatra::Query::Model::ModelRoot>::instances(modelRoot);
		Logger::Log("::railRoadModel::ITrain list size: ", trgInstanceList.size());
		auto trgIDPredicate = [trainID](const ::railRoadModel::ITrain* trg){
			Logger::Log("::railRoadModel::ITrain present ID= ", trg->get_id(), " == ", stateID);
			return trg->get_id() == trainID;
		};
		
		auto trgObj = std::find_if(trgInstanceList.begin(), trgInstanceList.end(), trgIDPredicate);
		
		if(trgObj == trgInstanceList.end()) throw std::invalid_argument("::railRoadModel::ITrain ID not found in InputUpdater");
		if(matches.size() > 0){	
			auto tempTrg = std::find_if((*srcObj)->get_nearBy().begin(), (*srcObj)->get_nearBy().end(), trgIDPredicate);
			
			if(tempTrg == (*srcObj)->get_nearBy().end()){ 
				Logger::Log("nearBy association inserted between (ID-ID) = ", robotPartID, "-", trainID);
				(*srcObj)->get_nearBy().push_back(*trgObj);
			}
		}
			else if(tempTrg != (*srcObj)->get_nearBy().end()){ 
				Logger::Log("nearBy association removed between (ID-ID) = ", robotPartID, "-", trainID);
				(*srcObj)->get_nearBy().erase(tempTrg);
			}
		/*
		* Critical Section END
		*/
	}
};

} /* namespace DerivedInput */
} /* namespace Query */
} /* namespace Viatra */

	

#endif /*  VIATRA__QUERY__DERIVED_INPUT__NEAR_BY_INPUT_UPDATER_H_ */
