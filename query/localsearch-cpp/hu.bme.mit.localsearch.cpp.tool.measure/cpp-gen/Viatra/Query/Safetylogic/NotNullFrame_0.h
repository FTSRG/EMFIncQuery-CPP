#ifndef VIATRA__QUERY__SAFETYLOGIC__NOT_NULL_FRAME_0_H_
#define VIATRA__QUERY__SAFETYLOGIC__NOT_NULL_FRAME_0_H_

#include <Viatra/Query/Util/Convert.h>
#include <stdint.h>
#include <vector>
		
#include "PB_safetylogic.pb.h"
#include "railRoadModel/RailRoadElement.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {


class NotNullFrame_0Vector;

struct NotNullFrame_0 {
	
	using PBFrame = PB_NotNullFrame_0;
	using FrameVector = NotNullFrame_0Vector;
	
	::railRoadModel::IRailRoadElement* _0 = nullptr;
	// toString
	
	std::string toString() const
	{
		std::string ret = "[";
		ret += "Old=";
		ret += (_0 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(_0->id()));
	
		return ret + ']';
	}
	// Serialization and deserialization
	std::string SerializeAsString()
	{
		PB_NotNullFrame_0 pbframe;
		
		pbframe.set__0(_0 == nullptr ? -1 : _0->id());
		
		return pbframe.SerializeAsString();
	}
		
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_NotNullFrame_0 pbframe;
		pbframe.ParseFromString(str);
		
		_0 = (pbframe._0() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::IRailRoadElement*>(mr->findModelElementByID(pbframe._0()));
		
	}
};
		
class NotNullFrame_0Vector 
	: private std::vector<NotNullFrame_0>
{
	public:
	using std::vector<NotNullFrame_0>::push_back;
	using std::vector<NotNullFrame_0>::clear;
	using std::vector<NotNullFrame_0>::empty;
	using std::vector<NotNullFrame_0>::size;
	using std::vector<NotNullFrame_0>::begin;
	using std::vector<NotNullFrame_0>::end;
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_NotNullFrame_0Vector pbFrameVector;
		pbFrameVector.ParseFromString(serialized_data);
		
		NotNullFrame_0 frame;
		for (auto & pbFrame : pbFrameVector.frames())
		{
			frame._0 = (pbFrame._0() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::IRailRoadElement*>(mr->findModelElementByID(pbFrame._0()));
			
			
			action(frame);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_NotNullFrame_0Vector pbFrameVector;
		
		for(auto& storedVector: *this){
			auto & pbFrame= *pbFrameVector.add_frames();
			pbFrame.set__0(storedVector._0 == nullptr ? -1 : storedVector._0->id());
		}
		return pbFrameVector.SerializeAsString();
	}
};


} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__NOT_NULL_FRAME_0_H_ */
