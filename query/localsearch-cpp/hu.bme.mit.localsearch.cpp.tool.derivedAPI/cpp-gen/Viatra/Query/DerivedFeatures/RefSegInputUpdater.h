#ifndef VIATRA__QUERY__DERIVED_FEATURES__REF_SEG_INPUT_UPDATER_H_
#define VIATRA__QUERY__DERIVED_FEATURES__REF_SEG_INPUT_UPDATER_H_

#include <algorithm>
#include <stdexcept>
		
#include "Viatra/Query/DerivedFeatures/RefSegMatcher.h"
#include "Viatra/Query/Matcher/ModelIndex.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace DerivedFeatures {

template<class ModelRoot>
struct RefSegInputUpdate{
	/*
	 * It is generated for only sending vector coordinates into the model instance. 
	 * The Derived feature has a source and a target, their id must be given in update function parameter i.e. (srcID, trgID, ...).
	 * If that isn't guaranteed this code crashes in compile time.
	 */
	static void update(ModelRoot modelRoot,int robotPartID, double robX, double robY, double robZ){
		/*
		 * Critical Section START
		 * Atomicity is mandatory
		 * Not supported parallel modifications and queries
		 */
		
		int thId = modelRoot.getID();
		modelRoot.getTicket(thID);
		modelRoot.wait();
		modelRoot.resourceMutex.lock();
		modelRoot.criticalBegin();
					
		auto srcInstanceList = ModelIndex<typename std::remove_pointer< ::RailRoadModel::IRobotPart >::type, ModelRoot>::instances(&modelRoot);
		auto srcIDPredicate = [robotPartID](const ::RailRoadModel::IRobotPart* src){
			return src->id == robotPartID;
		};
		
		auto srcObj = std::find_if(srcInstanceList.begin(), srcInstanceList.end(), srcIDPredicate);
		
		if(srcObj == srcInstanceList.end()) throw new std::invalid_argument("::RailRoadModel::IRobotPart ID not found");
		
		auto trgInstanceList = ModelIndex<typename std::remove_pointer< ::RailRoadModel::ISegment >::type, ModelRoot>::instances(&modelRoot);
		auto trgIDPredicate = [segmentID](const ::RailRoadModel::ISegment* trg){
			return trg->id == segmentID;
		};
		
		auto trgObj = std::find_if(trgInstanceList.begin(), trgInstanceList.end(), trgIDPredicate);
		
		if(trgObj == trgInstanceList.end()) throw new std::invalid_argument("::RailRoadModel::ISegment ID not found");
		
		auto engine = QueryEngine<ModelRoot>::of(&modelRoot);
		auto refSegmentMatcher = engine.template matcher< RefSegQuerySpecification >();
		auto matches = refSegmentMatcher.matches(robotPartID, robX, robY, robZ);
		
		auto tempTrg = std::find_if((*srcObj)->refSegment.begin(), (*srcObj)->refSegment.end(), trgIDPredicate);
		
		if(matches.size() > 0){	if(tempTrg == (*srcObj)->refSegment.end()) (*srcObj)->refSegment.push_back(*trgObj);}
		else if(tempTrg != (*srcObj)->refSegment.end()) (*srcObj)->refSegment.erase(tempTrg);
		
		modelRoot.criticalEnd();
		resourceMutex.unlock();
		/*
		* Critical Section END
		*/
	}
};

} /* namespace DerivedFeatures */
} /* namespace Query */
} /* namespace Viatra */

	

#endif /*  VIATRA__QUERY__DERIVED_FEATURES__REF_SEG_INPUT_UPDATER_H_ */
