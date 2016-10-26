#ifndef VIATRA__QUERY__DERIVED_INPUT__OPERATIONAL_STATE_A_P_I_FRAME_0_H_
#define VIATRA__QUERY__DERIVED_INPUT__OPERATIONAL_STATE_A_P_I_FRAME_0_H_

#include <Viatra/Query/Util/Convert.h>
#include <stdint.h>
#include <vector>
		
#include "PB_DerivedInput.pb.h"
#include "railRoadModel/Operational.h"
#include "railRoadModel/Turnout.h"

namespace Viatra {
namespace Query {
namespace DerivedInput {


class OperationalStateAPIFrame_0Vector;

struct OperationalStateAPIFrame_0 {
	
	using PBFrame = PB_OperationalStateAPIFrame_0;
	using FrameVector = OperationalStateAPIFrame_0Vector;
	
	::railRoadModel::ITurnout* _0 = nullptr;
	int _1 = 0;
	::railRoadModel::IOperational* _2 = nullptr;
	int _3 = 0;
	double _4 = 0.0;
	// toString
	
	std::string toString() const
	{
		std::string ret = "[";
		ret += "turnout=";
		ret += (_0 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(_0->id()));
		ret += ",turnoutID=";
		ret += Viatra::Query::Util::Convert::ToString(_1);
		ret += ",operational=";
		ret += (_2 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(_2->id()));
		ret += ",stateID=";
		ret += Viatra::Query::Util::Convert::ToString(_3);
		ret += ",turnoutTemp=";
		ret += Viatra::Query::Util::Convert::ToString(_4);
	
		return ret + ']';
	}
	// Serialization and deserialization
	std::string SerializeAsString()
	{
		PB_OperationalStateAPIFrame_0 pbframe;
		
		pbframe.set__0(_0 == nullptr ? -1 : _0->id());
		pbframe.set__1(_1);
		pbframe.set__2(_2 == nullptr ? -1 : _2->id());
		pbframe.set__3(_3);
		pbframe.set__4(_4);
		
		return pbframe.SerializeAsString();
	}
		
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_OperationalStateAPIFrame_0 pbframe;
		pbframe.ParseFromString(str);
		
		_0 = (pbframe._0() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::ITurnout*>(mr->findModelElementByID(pbframe._0()));
		
		_1 = pbframe._1();
		
		_2 = (pbframe._2() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::IOperational*>(mr->findModelElementByID(pbframe._2()));
		
		_3 = pbframe._3();
		
		_4 = pbframe._4();
		
	}
};
		
class OperationalStateAPIFrame_0Vector 
	: private std::vector<OperationalStateAPIFrame_0>
{
	public:
	using std::vector<OperationalStateAPIFrame_0>::push_back;
	using std::vector<OperationalStateAPIFrame_0>::clear;
	using std::vector<OperationalStateAPIFrame_0>::empty;
	using std::vector<OperationalStateAPIFrame_0>::size;
	using std::vector<OperationalStateAPIFrame_0>::begin;
	using std::vector<OperationalStateAPIFrame_0>::end;
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_OperationalStateAPIFrame_0Vector pbFrameVector;
		pbFrameVector.ParseFromString(serialized_data);
		
		OperationalStateAPIFrame_0 frame;
		for (auto & pbFrame : pbFrameVector.frames())
		{
			frame._0 = (pbFrame._0() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::ITurnout*>(mr->findModelElementByID(pbFrame._0()));
			
			frame._1 = pbFrame._1();
			
			frame._2 = (pbFrame._2() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::IOperational*>(mr->findModelElementByID(pbFrame._2()));
			
			frame._3 = pbFrame._3();
			
			frame._4 = pbFrame._4();
			
			
			action(frame);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_OperationalStateAPIFrame_0Vector pbFrameVector;
		
		for(auto& storedVector: *this){
			auto & pbFrame= *pbFrameVector.add_frames();
			pbFrame.set__0(storedVector._0 == nullptr ? -1 : storedVector._0->id());
			pbFrame.set__1(storedVector._1);
			pbFrame.set__2(storedVector._2 == nullptr ? -1 : storedVector._2->id());
			pbFrame.set__3(storedVector._3);
			pbFrame.set__4(storedVector._4);
		}
		return pbFrameVector.SerializeAsString();
	}
};


} /* namespace DerivedInput */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED_INPUT__OPERATIONAL_STATE_A_P_I_FRAME_0_H_ */
