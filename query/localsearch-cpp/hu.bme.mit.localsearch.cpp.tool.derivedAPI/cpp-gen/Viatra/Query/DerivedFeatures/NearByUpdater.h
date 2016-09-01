#ifndef VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_UPDATER_H_
#define VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_UPDATER_H_

#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Matcher/ModelIndex.h"

#include "RailRoadModel/RobotPart.h"
#include "RailRoadModel/Train.h"

#include "Viatra/Query/DerivedFeatures/NearByFrame_0.h"
#include "Viatra/Query/DerivedFeatures/NearByMatch.h"
#include "Viatra/Query/DerivedFeatures/NearByQuerySpecification.h"
#include "Viatra/Query/DerivedFeatures/NearByMatcher.h"

namespace Viatra {
	namespace Query {

    struct ModelRoot
  	{
  		ModelRoot(){}

  		~ModelRoot(){}
  	};

		template<typename T>
		struct ModelIndex<T, ModelRoot> {
			static const std::list<T*>& instances(const ModelRoot* modelRoot)
			{
				return T::_instances;
			}
		};
	}
}

namespace Viatra {
namespace Query {
namespace DerivedFeatures {
} /* namespace DerivedFeatures */
} /* namespace Query */
} /* namespace Viatra */

using namespace ::Viatra::Query;

template<class ModelRoot>
static void update(int robotPartID, int trainID, double robX, double robY, double robZ, double trX, double trY, double trZ){
	auto comparator = [](const ::RailRoadModel::RobotPart* a,const ::RailRoadModel::RobotPart* b){ return a->id < b->id;};
  std::map<::RailRoadModel::RobotPart*, std::vector<::RailRoadModel::Train*>,
    std::function<bool(const ::RailRoadModel::RobotPart* a,const ::RailRoadModel::RobotPart* b)>>
      derivedKnowledge(comparator);
	/*
	 * Critical Section START
	 * Atomicity is mandatory
	 * Not supported parallel modifications and queries
	 */
	ModelRoot modelRoot;
	auto instanceList = ModelIndex<typename std::remove_pointer<::RailRoadModel::RobotPart>::type, ModelRoot>::instances(&modelRoot);
	for(auto& src : instanceList){
		src->nearBy.clear();
		derivedKnowledge[src];
	}

	QueryEngine<ModelRoot> engine = QueryEngine<ModelRoot>::empty();
	DerivedFeatures::NearByMatcher<ModelRoot> nearByMatcher = engine.matcher<DerivedFeatures::NearByQuerySpecification>();
	auto matches = nearByMatcher.matches(robotPartID, trainID, robX, robY, robZ, trX, trY, trZ);

	for(auto match : matches) derivedKnowledge[match.robotPart].push_back(match.train);
	for(auto& src : instanceList){
		 auto srcMapIterator = derivedKnowledge.find(src);
		 if(srcMapIterator != derivedKnowledge.end()){
			 for(auto& trg : srcMapIterator->second) src->nearBy.push_back(trg);
		 }
	}
	/*
	* Critical Section END
	*/
}

#endif /*  VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_UPDATER_H_ */
