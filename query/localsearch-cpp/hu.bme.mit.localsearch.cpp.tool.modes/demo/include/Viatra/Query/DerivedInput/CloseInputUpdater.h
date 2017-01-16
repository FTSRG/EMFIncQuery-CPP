#ifndef VIATRA__QUERY__DERIVED_INPUT__CLOSE_INPUT_UPDATER_H_
#define VIATRA__QUERY__DERIVED_INPUT__CLOSE_INPUT_UPDATER_H_

#include <algorithm>
#include <stdexcept>
		
#include "Viatra/Query/DerivedInput/CloseMatcher.h"
#include "Viatra/Query/Derived/DerivedInputQueryQueryGroup.h"
#include "Viatra/Query/Matcher/ModelIndex.h"

namespace Viatra {
namespace Query {
namespace DerivedInput {

struct CloseInputUpdate{
	/*
	 * It is generated for only sending vector coordinates into the model instance.
	 * The Derived feature has a source and a target, their id must be given in update function parameter i.e. (srcID, trgID, ...).
	 * If that isn't guaranteed this code crashes in compile time.
	 */
	static void update(::Viatra::Query::ModelRoot* modelRoot,int robotPartID, int trainID, double robX, double robY, double robZ, double trX, double trY, double trZ){
		/*
		 * Critical Section START
		 * Atomicity is mandatory
		 * Not supported parallel modifications and queries
		 */
		auto srcInstanceList = ModelIndex<::railRoadModel::RobotPart, ::Viatra::Query::ModelRoot>::instances(modelRoot);
		auto srcIDPredicate = [=](const ::railRoadModel::RobotPart* src){
			return src->id == robotPartID;
		};

		auto srcObj = std::find_if(srcInstanceList.begin(), srcInstanceList.end(), srcIDPredicate);

		if(srcObj == srcInstanceList.end()) throw new std::invalid_argument("::railRoadModel::RobotPart ID not found");

		//auto engine = QueryEngine<::Viatra::Query::ModelRoot>::of(modelRoot);
		//auto closeMatcher = engine.template matcher< CloseQuerySpecification >();
		CloseMatcher closeMatcher(modelRoot, DerivedInputQueryGroup::instance()->context());
		auto matches = closeMatcher.matches(robotPartID, trainID, robX, robY, robZ, trX, trY, trZ);

		auto trgInstanceList = ModelIndex<::railRoadModel::Train, ::Viatra::Query::ModelRoot>::instances(modelRoot);
		auto trgIDPredicate = [=](const ::railRoadModel::Train* trg){
			return trg->id == trainID;
		};

		auto trgIt = std::find_if(trgInstanceList.begin(), trgInstanceList.end(), trgIDPredicate);

		if(trgIt == trgInstanceList.end()) throw new std::invalid_argument("::railRoadModel::Train ID not found");

		auto tempTrg = std::find_if((*srcObj)->close.begin(), (*srcObj)->close.end(), trgIDPredicate);
		if(matches.size() > 0){				
			if(tempTrg == (*srcObj)->close.end()){
				(*srcObj)->close.push_back(*trgIt);
			}
		}else if(tempTrg != (*srcObj)->close.end()){
				(*srcObj)->close.erase(tempTrg);
		}

		/*
		* Critical Section END
		*/
	}
};

} /* namespace DerivedInput */
} /* namespace Query */
} /* namespace Viatra */



#endif /*  VIATRA__QUERY__DERIVED_INPUT__CLOSE_INPUT_UPDATER_H_ */
