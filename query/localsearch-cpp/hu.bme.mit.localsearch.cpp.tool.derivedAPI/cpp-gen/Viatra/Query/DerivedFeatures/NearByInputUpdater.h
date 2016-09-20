#ifndef VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_INPUT_UPDATER_H_
#define VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_INPUT_UPDATER_H_

#include <algorithm>
#include <stdexcept>
		
#include "Viatra/Query/DerivedFeatures/NearByMatcher.h"
#include "Viatra/Query/Matcher/ModelIndex.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace DerivedFeatures {

template<class ModelRoot>
struct NearByInputUpdate{
	/*
	 * It is generated for only sending vector coordinates into the model instance. 
	 * The Derived feature has a source and a target, their id must be given in update function parameter i.e. (srcID, trgID, ...).
	 * If that isn't guaranteed this code crashes in compile time.
	 */
	static void update(ModelRoot modelRoot,int robotPartID, int trainID, double robX, double robY, double robZ, double trX, double trY, double trZ){
		/*
		 * Critical Section START
		 * Atomicity is mandatory
		 * Not supported parallel modifications and queries
		 */
		auto srcInstanceList = ModelIndex<typename std::remove_pointer< ::RailRoadModel::RobotPart >::type, ModelRoot>::instances(&modelRoot);
		auto srcIDPredicate = [robotPartID](const ::RailRoadModel::RobotPart* src){
			return src->id == robotPartID;
		};
		
		auto srcObj = std::find_if(srcInstanceList.begin(), srcInstanceList.end(), srcIDPredicate);
		
		if(srcObj == srcInstanceList.end()) throw new std::invalid_argument("::RailRoadModel::RobotPart ID not found");
		
		auto trgInstanceList = ModelIndex<typename std::remove_pointer< ::RailRoadModel::Train >::type, ModelRoot>::instances(&modelRoot);
		auto trgIDPredicate = [trainID](const ::RailRoadModel::Train* trg){
			return trg->id == trainID;
		};
		
		auto trgObj = std::find_if(trgInstanceList.begin(), trgInstanceList.end(), trgIDPredicate);
		
		if(trgObj == trgInstanceList.end()) throw new std::invalid_argument("::RailRoadModel::Train ID not found");
		
		auto engine = QueryEngine<ModelRoot>::of(&modelRoot);
		auto nearByMatcher = engine.template matcher< NearByQuerySpecification >();
		auto matches = nearByMatcher.matches(robotPartID, trainID, robX, robY, robZ, trX, trY, trZ);
		
		auto tempTrg = std::find_if((*srcObj)->nearBy.begin(), (*srcObj)->nearBy.end(), trgIDPredicate);
		
		if(matches.size() > 0){	if(tempTrg == (*srcObj)->nearBy.end()) (*srcObj)->nearBy.push_back(*trgObj);}
		else if(tempTrg != (*srcObj)->nearBy.end()) (*srcObj)->nearBy.erase(tempTrg);
		
		/*
		* Critical Section END
		*/
	}
};

} /* namespace DerivedFeatures */
} /* namespace Query */
} /* namespace Viatra */

	

#endif /*  VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_INPUT_UPDATER_H_ */
