#ifndef VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_TEST_MATCH_H_
#define VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_TEST_MATCH_H_

#include <stdint.h>
		
#include "RailRoadModel/RobotPart.h"
#include "RailRoadModel/Train.h"
#include "proto_gen.pb.h"

namespace Viatra {
namespace Query {
namespace DerivedFeatures {

struct NearByTestMatch {
	
	::RailRoadModel::IRobotPart* robot;
	::RailRoadModel::ITrain* train;
	
	bool operator==(const NearByTestMatch& other) const {
		return 
			robot == other.robot&&
			train == other.train
		;
	}
	
		// Serialization and deserialization
	
		std::string SerializeAsString()
		{
			PB_NearByTestMatch pbframe;
			
			pbframe.set_robot(robot == nullptr ? -1 : robot->id());
			pbframe.set_train(train == nullptr ? -1 : train->id());
	
			return pbframe.SerializeAsString();
		}
	
		template<typename ModelRoot>
		void ParseFromString(std::string str, ModelRoot *mr)
		{
			PB_NearByTestMatch pbframe;
			pbframe.ParseFromString(str);
	
			robot = (pbframe.robot() == -1) 
				? nullptr 
				: dynamic_cast<::RailRoadModel::IRobotPart*>(mr->findModelElementByID(pbframe.robot()));
			
			train = (pbframe.train() == -1) 
				? nullptr 
				: dynamic_cast<::RailRoadModel::ITrain*>(mr->findModelElementByID(pbframe.train()));
			
		}
};		

} /* namespace DerivedFeatures */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::DerivedFeatures::NearByTestMatch> {
	size_t operator()(const ::Viatra::Query::DerivedFeatures::NearByTestMatch& match) const {
		size_t h = 0;
		h+=std::hash<decltype(match.robot)>()(match.robot);
		h*=31;
		h+=std::hash<decltype(match.train)>()(match.train);
		return h;
	}
};
		
}

#endif /*  VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_TEST_MATCH_H_ */
