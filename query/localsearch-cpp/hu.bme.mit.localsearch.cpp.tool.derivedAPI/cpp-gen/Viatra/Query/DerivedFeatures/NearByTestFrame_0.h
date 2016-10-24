#ifndef VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_TEST_FRAME_0_H_
#define VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_TEST_FRAME_0_H_

#include <stdint.h>
		
#include "RailRoadModel/RobotPart.h"
#include "RailRoadModel/Train.h"
#include "proto_gen.pb.h"

namespace Viatra {
namespace Query {
namespace DerivedFeatures {

struct NearByTestFrame_0 {
	
	::RailRoadModel::IRobotPart* _0;
	::RailRoadModel::ITrain* _1;

	// Serialization and deserialization
	
	std::string SerializeAsString()
	{
		PB_NearByTestFrame_0 pbframe;
		
		pbframe.set__0(_0 == nullptr ? -1 : _0->id());
		pbframe.set__1(_1 == nullptr ? -1 : _1->id());

		return pbframe.SerializeAsString();
	}

	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_NearByTestFrame_0 pbframe;
		pbframe.ParseFromString(str);

		_0 = (pbframe._0() == -1) 
			? nullptr 
			: dynamic_cast<::RailRoadModel::IRobotPart*>(mr->findModelElementByID(pbframe._0()));
		
		_1 = (pbframe._1() == -1) 
			? nullptr 
			: dynamic_cast<::RailRoadModel::ITrain*>(mr->findModelElementByID(pbframe._1()));
		
	}
};

} /* namespace DerivedFeatures */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_TEST_FRAME_0_H_ */
