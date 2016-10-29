#ifndef VIATRA__QUERY__DERIVED_INPUT__NEAR_BY_FRAME_0_H_
#define VIATRA__QUERY__DERIVED_INPUT__NEAR_BY_FRAME_0_H_

#include <Viatra/Query/Util/Convert.h>
#include <stdint.h>
#include <vector>
		
#include "PB_DerivedInput.pb.h"
#include "railRoadModel/RailRoadElement.h"
#include "railRoadModel/RobotPart.h"
#include "railRoadModel/Segment.h"
#include "railRoadModel/Train.h"

namespace Viatra {
namespace Query {
namespace DerivedInput {


class NearByFrame_0Vector;

struct NearByFrame_0 {
	
	using PBFrame = PB_NearByFrame_0;
	using FrameVector = NearByFrame_0Vector;
	
	::railRoadModel::IRobotPart* _0 = nullptr;
	int _1 = 0;
	::railRoadModel::ITrain* _2 = nullptr;
	int _3 = 0;
	int _4 = 0;
	double _5 = 0.0;
	double _6 = 0.0;
	double _7 = 0.0;
	double _8 = 0.0;
	double _9 = 0.0;
	double _10 = 0.0;
	::railRoadModel::ISegment* _11 = nullptr;
	::railRoadModel::IRailRoadElement* _12 = nullptr;
	// toString
	
	std::string toString() const
	{
		std::string ret = "[";
		ret += "robotPart=";
		ret += (_0 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(_0->id()));
		ret += ",robotPartID=";
		ret += Viatra::Query::Util::Convert::ToString(_1);
		ret += ",train=";
		ret += (_2 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(_2->id()));
		ret += ",trainID=";
		ret += Viatra::Query::Util::Convert::ToString(_3);
		ret += ",segID=";
		ret += Viatra::Query::Util::Convert::ToString(_4);
		ret += ",robX=";
		ret += Viatra::Query::Util::Convert::ToString(_5);
		ret += ",robY=";
		ret += Viatra::Query::Util::Convert::ToString(_6);
		ret += ",robZ=";
		ret += Viatra::Query::Util::Convert::ToString(_7);
		ret += ",segX=";
		ret += Viatra::Query::Util::Convert::ToString(_8);
		ret += ",segY=";
		ret += Viatra::Query::Util::Convert::ToString(_9);
		ret += ",segZ=";
		ret += Viatra::Query::Util::Convert::ToString(_10);
		ret += ",trackedSegment=";
		ret += (_11 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(_11->id()));
		ret += ",trainSegment=";
		ret += (_12 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(_12->id()));
	
		return ret + ']';
	}
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
		pbframe.set__10(_10);
		pbframe.set__11(_11 == nullptr ? -1 : _11->id());
		pbframe.set__12(_12 == nullptr ? -1 : _12->id());
		
		return pbframe.SerializeAsString();
	}
		
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_NearByFrame_0 pbframe;
		pbframe.ParseFromString(str);
		
		_0 = (pbframe._0() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::IRobotPart*>(mr->findModelElementByID(pbframe._0()));
		
		_1 = pbframe._1();
		
		_2 = (pbframe._2() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::ITrain*>(mr->findModelElementByID(pbframe._2()));
		
		_3 = pbframe._3();
		
		_4 = pbframe._4();
		
		_5 = pbframe._5();
		
		_6 = pbframe._6();
		
		_7 = pbframe._7();
		
		_8 = pbframe._8();
		
		_9 = pbframe._9();
		
		_10 = pbframe._10();
		
		_11 = (pbframe._11() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::ISegment*>(mr->findModelElementByID(pbframe._11()));
		
		_12 = (pbframe._12() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::IRailRoadElement*>(mr->findModelElementByID(pbframe._12()));
		
	}
};
		
class NearByFrame_0Vector 
	: private std::vector<NearByFrame_0>
{
	public:
	using std::vector<NearByFrame_0>::push_back;
	using std::vector<NearByFrame_0>::clear;
	using std::vector<NearByFrame_0>::empty;
	using std::vector<NearByFrame_0>::size;
	using std::vector<NearByFrame_0>::begin;
	using std::vector<NearByFrame_0>::end;
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_NearByFrame_0Vector pbFrameVector;
		pbFrameVector.ParseFromString(serialized_data);
		
		NearByFrame_0 frame;
		for (auto & pbFrame : pbFrameVector.frames())
		{
			frame._0 = (pbFrame._0() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::IRobotPart*>(mr->findModelElementByID(pbFrame._0()));
			
			frame._1 = pbFrame._1();
			
			frame._2 = (pbFrame._2() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::ITrain*>(mr->findModelElementByID(pbFrame._2()));
			
			frame._3 = pbFrame._3();
			
			frame._4 = pbFrame._4();
			
			frame._5 = pbFrame._5();
			
			frame._6 = pbFrame._6();
			
			frame._7 = pbFrame._7();
			
			frame._8 = pbFrame._8();
			
			frame._9 = pbFrame._9();
			
			frame._10 = pbFrame._10();
			
			frame._11 = (pbFrame._11() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::ISegment*>(mr->findModelElementByID(pbFrame._11()));
			
			frame._12 = (pbFrame._12() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::IRailRoadElement*>(mr->findModelElementByID(pbFrame._12()));
			
			
			action(frame);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_NearByFrame_0Vector pbFrameVector;
		
		for(auto& storedVector: *this){
			auto & pbFrame= *pbFrameVector.add_frames();
			pbFrame.set__0(storedVector._0 == nullptr ? -1 : storedVector._0->id());
			pbFrame.set__1(storedVector._1);
			pbFrame.set__2(storedVector._2 == nullptr ? -1 : storedVector._2->id());
			pbFrame.set__3(storedVector._3);
			pbFrame.set__4(storedVector._4);
			pbFrame.set__5(storedVector._5);
			pbFrame.set__6(storedVector._6);
			pbFrame.set__7(storedVector._7);
			pbFrame.set__8(storedVector._8);
			pbFrame.set__9(storedVector._9);
			pbFrame.set__10(storedVector._10);
			pbFrame.set__11(storedVector._11 == nullptr ? -1 : storedVector._11->id());
			pbFrame.set__12(storedVector._12 == nullptr ? -1 : storedVector._12->id());
		}
		return pbFrameVector.SerializeAsString();
	}
};


} /* namespace DerivedInput */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED_INPUT__NEAR_BY_FRAME_0_H_ */
