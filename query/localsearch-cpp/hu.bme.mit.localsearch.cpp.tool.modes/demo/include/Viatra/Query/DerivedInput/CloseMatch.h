#ifndef VIATRA__QUERY__DERIVED_INPUT__CLOSE_MATCH_H_
#define VIATRA__QUERY__DERIVED_INPUT__CLOSE_MATCH_H_

		
#include "railRoadModel/RobotPart.h"
#include "railRoadModel/Train.h"

namespace Viatra {
namespace Query {
namespace DerivedInput {

struct CloseMatch {
	
	::railRoadModel::RobotPart* robotPart;
	int robotPartID;
	::railRoadModel::Train* train;
	int trainID;
	double robX;
	double robY;
	double robZ;
	double trX;
	double trY;
	double trZ;
	
	bool operator==(const CloseMatch& other) const {
		return 
			robotPart == other.robotPart&&
			robotPartID == other.robotPartID&&
			train == other.train&&
			trainID == other.trainID&&
			robX == other.robX&&
			robY == other.robY&&
			robZ == other.robZ&&
			trX == other.trX&&
			trY == other.trY&&
			trZ == other.trZ
		;
	}
	
};		

} /* namespace DerivedInput */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::DerivedInput::CloseMatch> {
	size_t operator()(const ::Viatra::Query::DerivedInput::CloseMatch& match) const {
		return 
					std::hash<decltype(match.robotPart)>()(match.robotPart)^
					std::hash<decltype(match.robotPartID)>()(match.robotPartID)^
					std::hash<decltype(match.train)>()(match.train)^
					std::hash<decltype(match.trainID)>()(match.trainID)^
					std::hash<decltype(match.robX)>()(match.robX)^
					std::hash<decltype(match.robY)>()(match.robY)^
					std::hash<decltype(match.robZ)>()(match.robZ)^
					std::hash<decltype(match.trX)>()(match.trX)^
					std::hash<decltype(match.trY)>()(match.trY)^
					std::hash<decltype(match.trZ)>()(match.trZ)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__DERIVED_INPUT__CLOSE_MATCH_H_ */
