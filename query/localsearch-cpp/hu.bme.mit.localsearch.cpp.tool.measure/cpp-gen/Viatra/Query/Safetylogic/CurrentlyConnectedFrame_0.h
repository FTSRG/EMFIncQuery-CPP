#ifndef VIATRA__QUERY__SAFETYLOGIC__CURRENTLY_CONNECTED_FRAME_0_H_
#define VIATRA__QUERY__SAFETYLOGIC__CURRENTLY_CONNECTED_FRAME_0_H_

#include <Viatra/Query/Util/Convert.h>
#include <stdint.h>
#include <vector>
		
#include "PB_safetylogic.pb.h"
#include "railRoadModel/RailRoadElement.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {


class CurrentlyConnectedFrame_0Vector;

struct CurrentlyConnectedFrame_0 {
	
	using PBFrame = PB_CurrentlyConnectedFrame_0;
	using FrameVector = CurrentlyConnectedFrame_0Vector;
	
	::railRoadModel::ITurnout* _0 = nullptr;
	::railRoadModel::IRailRoadElement* _1 = nullptr;
	bool _2 = false;
	// toString
	
	std::string toString() const
	{
		std::string ret = "[";
		ret += "This=";
		ret += (_0 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(_0->id()));
		ret += ",connectedTo=";
		ret += (_1 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(_1->id()));
		ret += ",.virtual{0}=";
		ret += Viatra::Query::Util::Convert::ToString(_2);
	
		return ret + ']';
	}
	// Serialization and deserialization
	std::string SerializeAsString()
	{
		PB_CurrentlyConnectedFrame_0 pbframe;
		
		pbframe.set__0(_0 == nullptr ? -1 : _0->id());
		pbframe.set__1(_1 == nullptr ? -1 : _1->id());
		pbframe.set__2(_2);
		
		return pbframe.SerializeAsString();
	}
		
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_CurrentlyConnectedFrame_0 pbframe;
		pbframe.ParseFromString(str);
		
		_0 = (pbframe._0() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::ITurnout*>(mr->findModelElementByID(pbframe._0()));
		
		_1 = (pbframe._1() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::IRailRoadElement*>(mr->findModelElementByID(pbframe._1()));
		
		_2 = pbframe._2();
		
	}
};
		
class CurrentlyConnectedFrame_0Vector 
	: private std::vector<CurrentlyConnectedFrame_0>
{
	public:
	using std::vector<CurrentlyConnectedFrame_0>::push_back;
	using std::vector<CurrentlyConnectedFrame_0>::clear;
	using std::vector<CurrentlyConnectedFrame_0>::empty;
	using std::vector<CurrentlyConnectedFrame_0>::size;
	using std::vector<CurrentlyConnectedFrame_0>::begin;
	using std::vector<CurrentlyConnectedFrame_0>::end;
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_CurrentlyConnectedFrame_0Vector pbFrameVector;
		pbFrameVector.ParseFromString(serialized_data);
		
		CurrentlyConnectedFrame_0 frame;
		for (auto & pbFrame : pbFrameVector.frames())
		{
			frame._0 = (pbFrame._0() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::ITurnout*>(mr->findModelElementByID(pbFrame._0()));
			
			frame._1 = (pbFrame._1() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::IRailRoadElement*>(mr->findModelElementByID(pbFrame._1()));
			
			frame._2 = pbFrame._2();
			
			
			action(frame);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_CurrentlyConnectedFrame_0Vector pbFrameVector;
		
		for(auto& storedVector: *this){
			auto & pbFrame= *pbFrameVector.add_frames();
			pbFrame.set__0(storedVector._0 == nullptr ? -1 : storedVector._0->id());
			pbFrame.set__1(storedVector._1 == nullptr ? -1 : storedVector._1->id());
			pbFrame.set__2(storedVector._2);
		}
		return pbFrameVector.SerializeAsString();
	}
};


} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__CURRENTLY_CONNECTED_FRAME_0_H_ */
