#ifndef VIATRA__QUERY__DERIVED_FEATURES__REF_SEG_MATCH_H_
#define VIATRA__QUERY__DERIVED_FEATURES__REF_SEG_MATCH_H_

		
#include "RailRoadModel/Point.h"
#include "RailRoadModel/RobotPart.h"
#include "RailRoadModel/Segment.h"

namespace Viatra {
namespace Query {
namespace DerivedFeatures {

struct RefSegMatch {
	
	::RailRoadModel::RobotPart* robotPart;
	int robotPartID;
	::RailRoadModel::Segment* segment;
	int segmentID;
	double robX;
	double robY;
	double robZ;
	
	bool operator==(const RefSegMatch& other) const {
		return 
			robotPart == other.robotPart&&
			robotPartID == other.robotPartID&&
			segment == other.segment&&
			segmentID == other.segmentID&&
			robX == other.robX&&
			robY == other.robY&&
			robZ == other.robZ
		;
	}
	
};		

} /* namespace DerivedFeatures */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::DerivedFeatures::RefSegMatch> {
	unsigned operator()(const ::Viatra::Query::DerivedFeatures::RefSegMatch& match) const {
		return 
					std::hash<decltype(match.robotPart)>()(match.robotPart)^
					std::hash<decltype(match.robotPartID)>()(match.robotPartID)^
					std::hash<decltype(match.segment)>()(match.segment)^
					std::hash<decltype(match.segmentID)>()(match.segmentID)^
					std::hash<decltype(match.robX)>()(match.robX)^
					std::hash<decltype(match.robY)>()(match.robY)^
					std::hash<decltype(match.robZ)>()(match.robZ)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__DERIVED_FEATURES__REF_SEG_MATCH_H_ */
