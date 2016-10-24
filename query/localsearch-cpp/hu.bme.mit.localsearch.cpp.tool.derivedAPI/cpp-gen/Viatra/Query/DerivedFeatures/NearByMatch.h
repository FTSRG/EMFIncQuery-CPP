#ifndef VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_MATCH_H_
#define VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_MATCH_H_

#include <stdint.h>
		
#include "RailRoadModel/RobotPart.h"
#include "RailRoadModel/Train.h"
#include "proto_gen.pb.h"

namespace Viatra {
namespace Query {
namespace DerivedFeatures {

struct NearByMatch {
	
	::RailRoadModel::IRobotPart* robotPart;
	int robotPartID;
	::RailRoadModel::ITrain* train;
	int trainID;
	double robX;
	double robY;
	double robZ;
	double trX;
	double trY;
	double trZ;
	
	bool operator==(const NearByMatch& other) const {
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
	
		// Serialization and deserialization
	
		std::string SerializeAsString()
		{
			PB_NearByMatch pbframe;
			
			pbframe.set_robotpart(robotPart == nullptr ? -1 : robotPart->id());
			pbframe.set_robotpartid(robotPartID);
			pbframe.set_train(train == nullptr ? -1 : train->id());
			pbframe.set_trainid(trainID);
			pbframe.set_robx(robX);
			pbframe.set_roby(robY);
			pbframe.set_robz(robZ);
			pbframe.set_trx(trX);
			pbframe.set_try(trY);
			pbframe.set_trz(trZ);
	
			return pbframe.SerializeAsString();
		}
	
		template<typename ModelRoot>
		void ParseFromString(std::string str, ModelRoot *mr)
		{
			PB_NearByMatch pbframe;
			pbframe.ParseFromString(str);
	
			robotPart = (pbframe.robotpart() == -1) 
				? nullptr 
				: dynamic_cast<::RailRoadModel::IRobotPart*>(mr->findModelElementByID(pbframe.robotpart()));
			
			robotPartID = pbframe.robotpartid();
			
			train = (pbframe.train() == -1) 
				? nullptr 
				: dynamic_cast<::RailRoadModel::ITrain*>(mr->findModelElementByID(pbframe.train()));
			
			trainID = pbframe.trainid();
			
			robX = pbframe.robx();
			
			robY = pbframe.roby();
			
			robZ = pbframe.robz();
			
			trX = pbframe.trx();
			
			trY = pbframe.try();
			
			trZ = pbframe.trz();
			
		}
};		

} /* namespace DerivedFeatures */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::DerivedFeatures::NearByMatch> {
	size_t operator()(const ::Viatra::Query::DerivedFeatures::NearByMatch& match) const {
		size_t h = 0;
		h+=std::hash<decltype(match.robotPart)>()(match.robotPart);
		h*=31;
		h+=std::hash<decltype(match.robotPartID)>()(match.robotPartID);
		h*=31;
		h+=std::hash<decltype(match.train)>()(match.train);
		h*=31;
		h+=std::hash<decltype(match.trainID)>()(match.trainID);
		h*=31;
		h+=std::hash<decltype(match.robX)>()(match.robX);
		h*=31;
		h+=std::hash<decltype(match.robY)>()(match.robY);
		h*=31;
		h+=std::hash<decltype(match.robZ)>()(match.robZ);
		h*=31;
		h+=std::hash<decltype(match.trX)>()(match.trX);
		h*=31;
		h+=std::hash<decltype(match.trY)>()(match.trY);
		h*=31;
		h+=std::hash<decltype(match.trZ)>()(match.trZ);
		return h;
	}
};
		
}

#endif /*  VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_MATCH_H_ */
