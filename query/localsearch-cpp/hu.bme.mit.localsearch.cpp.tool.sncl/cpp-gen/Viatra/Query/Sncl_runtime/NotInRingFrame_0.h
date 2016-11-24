#ifndef VIATRA__QUERY__SNCL_RUNTIME__NOT_IN_RING_FRAME_0_H_
#define VIATRA__QUERY__SNCL_RUNTIME__NOT_IN_RING_FRAME_0_H_

#include <Viatra/Query/Util/Convert.h>
#include <stdint.h>
#include <vector>
		
#include "PB_sncl_runtime.pb.h"
#include "arch/CL.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {


class NotInRingFrame_0Vector;

struct NotInRingFrame_0 {
	
	using PBFrame = PB_NotInRingFrame_0;
	using FrameVector = NotInRingFrame_0Vector;
	
	::arch::ICL* _0 = nullptr;
	int _1 = 0;
	int _3 = 0;
	// toString
	
	std::string toString() const
	{
		std::string ret = "[";
		ret += "C1=";
		ret += (_0 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(_0->id()));
		ret += ",.virtual{0}=";
		ret += Viatra::Query::Util::Convert::ToString(_1);
		ret += ",.virtual{1}=";
		ret += Viatra::Query::Util::Convert::ToString(_3);
	
		return ret + ']';
	}
	// Serialization and deserialization
	std::string SerializeAsString()
	{
		PB_NotInRingFrame_0 pbframe;
		
		pbframe.set__0(_0 == nullptr ? -1 : _0->id());
		pbframe.set__1(_1);
		pbframe.set__3(_3);
		
		return pbframe.SerializeAsString();
	}
		
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_NotInRingFrame_0 pbframe;
		pbframe.ParseFromString(str);
		
		_0 = (pbframe._0() == -1) 
			? nullptr 
			: dynamic_cast<::arch::ICL*>(mr->findModelElementByID(pbframe._0()));
		
		_1 = pbframe._1();
		
		_3 = pbframe._3();
		
	}
};
		
class NotInRingFrame_0Vector 
	: private std::vector<NotInRingFrame_0>
{
	public:
	using std::vector<NotInRingFrame_0>::push_back;
	using std::vector<NotInRingFrame_0>::clear;
	using std::vector<NotInRingFrame_0>::empty;
	using std::vector<NotInRingFrame_0>::size;
	using std::vector<NotInRingFrame_0>::begin;
	using std::vector<NotInRingFrame_0>::end;
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_NotInRingFrame_0Vector pbFrameVector;
		pbFrameVector.ParseFromString(serialized_data);
		
		NotInRingFrame_0 frame;
		for (auto & pbFrame : pbFrameVector.frames())
		{
			frame._0 = (pbFrame._0() == -1) 
				? nullptr 
				: dynamic_cast<::arch::ICL*>(mr->findModelElementByID(pbFrame._0()));
			
			frame._1 = pbFrame._1();
			
			frame._3 = pbFrame._3();
			
			
			action(frame);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_NotInRingFrame_0Vector pbFrameVector;
		
		for(auto& storedVector: *this){
			auto & pbFrame= *pbFrameVector.add_frames();
			pbFrame.set__0(storedVector._0 == nullptr ? -1 : storedVector._0->id());
			pbFrame.set__1(storedVector._1);
			pbFrame.set__3(storedVector._3);
		}
		return pbFrameVector.SerializeAsString();
	}
};


} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__NOT_IN_RING_FRAME_0_H_ */
