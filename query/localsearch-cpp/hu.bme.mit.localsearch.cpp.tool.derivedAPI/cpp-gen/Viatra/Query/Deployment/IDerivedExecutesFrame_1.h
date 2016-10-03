#ifndef VIATRA__QUERY__DEPLOYMENT__I_DERIVED_EXECUTES_FRAME_1_H_
#define VIATRA__QUERY__DEPLOYMENT__I_DERIVED_EXECUTES_FRAME_1_H_

#include <stdint.h>
		
#include "PlatformModel/Node.h"
#include "RailRoadModel/RailRoadElement.h"
#include "RailRoadModel/Segment.h"
#include "RailRoadModel/Train.h"
#include "proto_gen.pb.h"

namespace Viatra {
namespace Query {
namespace Deployment {

struct IDerivedExecutesFrame_1 {
	
	::PlatformModel::INode* _0;
	int _1;
	::RailRoadModel::ITrain* _2;
	int _3;
	::RailRoadModel::IRailRoadElement* _4;
	::RailRoadModel::ISegment* _5;

	// Serialization and deserialization
	
	std::string SerializeAsString()
	{
		PB_IDerivedExecutesFrame_1 pbframe;
		
		pbframe.set__0(_0 == nullptr ? -1 : _0->id());
		pbframe.set__1(_1);
		pbframe.set__2(_2 == nullptr ? -1 : _2->id());
		pbframe.set__3(_3);
		pbframe.set__4(_4 == nullptr ? -1 : _4->id());
		pbframe.set__5(_5 == nullptr ? -1 : _5->id());

		return pbframe.SerializeAsString();
	}

	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_IDerivedExecutesFrame_1 pbframe;
		pbframe.ParseFromString(str);

		_0 = (pbframe._0() == -1) 
			? nullptr 
			: dynamic_cast<::PlatformModel::INode*>(mr->findModelElementByID(pbframe._0()));
		
		_1 = pbframe._1();
		
		_2 = (pbframe._2() == -1) 
			? nullptr 
			: dynamic_cast<::RailRoadModel::ITrain*>(mr->findModelElementByID(pbframe._2()));
		
		_3 = pbframe._3();
		
		_4 = (pbframe._4() == -1) 
			? nullptr 
			: dynamic_cast<::RailRoadModel::IRailRoadElement*>(mr->findModelElementByID(pbframe._4()));
		
		_5 = (pbframe._5() == -1) 
			? nullptr 
			: dynamic_cast<::RailRoadModel::ISegment*>(mr->findModelElementByID(pbframe._5()));
		
	}
};

} /* namespace Deployment */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DEPLOYMENT__I_DERIVED_EXECUTES_FRAME_1_H_ */
