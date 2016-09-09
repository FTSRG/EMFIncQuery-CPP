#ifndef VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_TEST_MATCH_H_
#define VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_TEST_MATCH_H_

		
#include "RailRoadModel/RobotPart.h"
#include "RailRoadModel/Train.h"

namespace Viatra {
namespace Query {
namespace DerivedFeatures {

struct NearByTestMatch {
	
	::RailRoadModel::RobotPart* robot;
	::RailRoadModel::Train* train;
	
	bool operator==(const NearByTestMatch& other) const {
		return 
			robot == other.robot&&
			train == other.train
		;
	}
	
};		

} /* namespace DerivedFeatures */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::DerivedFeatures::NearByTestMatch> {
	unsigned operator()(const ::Viatra::Query::DerivedFeatures::NearByTestMatch& match) const {
		return 
					std::hash<decltype(match.robot)>()(match.robot)^
					std::hash<decltype(match.train)>()(match.train)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_TEST_MATCH_H_ */
