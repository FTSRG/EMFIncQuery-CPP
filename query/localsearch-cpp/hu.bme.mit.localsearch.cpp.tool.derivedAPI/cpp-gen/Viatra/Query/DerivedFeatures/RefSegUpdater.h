#ifndef VIATRA__QUERY__DERIVED_FEATURES__REF_SEG_UPDATER_H_
#define VIATRA__QUERY__DERIVED_FEATURES__REF_SEG_UPDATER_H_

#include <algorithm>
#include <stdexcept>
		
#include "Viatra/Query/DerivedFeatures/RefSegMatcher.h"
#include "Viatra/Query/Matcher/ModelIndex.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace DerivedFeatures {

template<class ModelRoot>
struct RefSegUpdate{
	static void update(ModelRoot modelRoot,int robotPartID, double robX, double robY, double robZ){
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
		
		auto trgInstanceList = ModelIndex<typename std::remove_pointer< ::RailRoadModel::Segment >::type, ModelRoot>::instances(&modelRoot);
		auto trgIDPredicate = [segmentID](const ::RailRoadModel::Segment* trg){
			return trg->id == segmentID;
		};
		
		auto trgObj = std::find_if(trgInstanceList.begin(), trgInstanceList.end(), trgIDPredicate);
		
		if(trgObj == trgInstanceList.end()) throw new std::invalid_argument("::RailRoadModel::Segment ID not found");
		
		auto engine = QueryEngine<ModelRoot>::of(&modelRoot);
		auto refSegmentMatcher = engine.template matcher< RefSegQuerySpecification >();
		auto matches = refSegmentMatcher.matches(robotPartID, robX, robY, robZ);
		
		auto tempTrg = std::find_if((*srcObj)->refSegment.begin(), (*srcObj)->refSegment.end(), trgIDPredicate);
		
		if(matches.size() > 0){	if(tempTrg == (*srcObj)->refSegment.end()) (*srcObj)->refSegment.push_back(*trgObj);}
		else if(tempTrg != (*srcObj)->refSegment.end()) (*srcObj)->refSegment.erase(tempTrg);
		
		/*
		* Critical Section END
		*/
	}
};

} /* namespace DerivedFeatures */
} /* namespace Query */
} /* namespace Viatra */

	

#endif /*  VIATRA__QUERY__DERIVED_FEATURES__REF_SEG_UPDATER_H_ */
