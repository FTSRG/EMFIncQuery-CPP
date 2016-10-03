#ifndef VIATRA__QUERY__DERIVED_FEATURES__REF_SEG_MATCH_H_
#define VIATRA__QUERY__DERIVED_FEATURES__REF_SEG_MATCH_H_

#include <stdint.h>
		
#include "RailRoadModel/Point.h"
#include "RailRoadModel/RobotPart.h"
#include "RailRoadModel/Segment.h"
#include "proto_gen.pb.h"

namespace Viatra {
namespace Query {
namespace DerivedFeatures {

struct RefSegMatch {
	
	::RailRoadModel::IRobotPart* robotPart;
	int robotPartID;
	::RailRoadModel::ISegment* segment;
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
	
		// Serialization and deserialization
	
		std::string SerializeAsString()
		{
			PB_RefSegMatch pbframe;
			
			pbframe.set_robotpart(robotPart == nullptr ? -1 : robotPart->id());
			pbframe.set_robotpartid(robotPartID);
			pbframe.set_segment(segment == nullptr ? -1 : segment->id());
			pbframe.set_segmentid(segmentID);
			pbframe.set_robx(robX);
			pbframe.set_roby(robY);
			pbframe.set_robz(robZ);
	
			return pbframe.SerializeAsString();
		}
	
		template<typename ModelRoot>
		void ParseFromString(std::string str, ModelRoot *mr)
		{
			PB_RefSegMatch pbframe;
			pbframe.ParseFromString(str);
	
			robotPart = (pbframe.robotpart() == -1) 
				? nullptr 
				: dynamic_cast<::RailRoadModel::IRobotPart*>(mr->findModelElementByID(pbframe.robotpart()));
			
			robotPartID = pbframe.robotpartid();
			
			segment = (pbframe.segment() == -1) 
				? nullptr 
				: dynamic_cast<::RailRoadModel::ISegment*>(mr->findModelElementByID(pbframe.segment()));
			
			segmentID = pbframe.segmentid();
			
			robX = pbframe.robx();
			
			robY = pbframe.roby();
			
			robZ = pbframe.robz();
			
		}
};		

} /* namespace DerivedFeatures */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::DerivedFeatures::RefSegMatch> {
	size_t operator()(const ::Viatra::Query::DerivedFeatures::RefSegMatch& match) const {
		size_t h = 0;
		h+=std::hash<decltype(match.robotPart)>()(match.robotPart);
		h*=31;
		h+=std::hash<decltype(match.robotPartID)>()(match.robotPartID);
		h*=31;
		h+=std::hash<decltype(match.segment)>()(match.segment);
		h*=31;
		h+=std::hash<decltype(match.segmentID)>()(match.segmentID);
		h*=31;
		h+=std::hash<decltype(match.robX)>()(match.robX);
		h*=31;
		h+=std::hash<decltype(match.robY)>()(match.robY);
		h*=31;
		h+=std::hash<decltype(match.robZ)>()(match.robZ);
		return h;
	}
};
		
}

#endif /*  VIATRA__QUERY__DERIVED_FEATURES__REF_SEG_MATCH_H_ */
