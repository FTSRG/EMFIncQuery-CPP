#ifndef VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_FRAME_0_H_
#define VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_FRAME_0_H_

#include <stdint.h>
		
#include "RailRoadModel/RobotPart.h"
#include "RailRoadModel/Train.h"
#include "proto_gen.pb.h"

namespace Viatra {
namespace Query {
namespace DerivedFeatures {

struct NearByFrame_0 {
	
	::RailRoadModel::IRobotPart* _0;
	int _1;
	::RailRoadModel::ITrain* _2;
	int _3;
	double _4;
	double _5;
	double _6;
	double _7;
	double _8;
	double _9;

	// Serialization and deserialization
	
	std::string SerializeAsString()
	{
		PB_NearByFrame_0 pbframe;
		
		pbframe.set__0(_0 == nullptr ? -1 : _0->id());
		pbframe.set__1(_1);
		pbframe.set__2(_2 == nullptr ? -1 : _2->id());
		pbframe.set__3(_3);
		pbframe.set__4(_4);
		pbframe.set__5(_5);
		pbframe.set__6(_6);
		pbframe.set__7(_7);
		pbframe.set__8(_8);
		pbframe.set__9(_9);

		return pbframe.SerializeAsString();
	}

	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_NearByFrame_0 pbframe;
		pbframe.ParseFromString(str);

		_0 = (pbframe._0() == -1) 
			? nullptr 
			: dynamic_cast<::RailRoadModel::IRobotPart*>(mr->findModelElementByID(pbframe._0()));
		
		_1 = pbframe._1();
		
		_2 = (pbframe._2() == -1) 
			? nullptr 
			: dynamic_cast<::RailRoadModel::ITrain*>(mr->findModelElementByID(pbframe._2()));
		
		_3 = pbframe._3();
		
		_4 = pbframe._4();
		
		_5 = pbframe._5();
		
		_6 = pbframe._6();
		
		_7 = pbframe._7();
		
		_8 = pbframe._8();
		
		_9 = pbframe._9();
		
	}
};

} /* namespace DerivedFeatures */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED_FEATURES__NEAR_BY_FRAME_0_H_ */
