#ifndef VIATRA__QUERY__SNCL_RUNTIME__LINKED_FRAME_1_H_
#define VIATRA__QUERY__SNCL_RUNTIME__LINKED_FRAME_1_H_

#include <Viatra/Query/Util/Convert.h>
#include <stdint.h>
#include <vector>
		
#include "PB_sncl_runtime.pb.h"
#include "arch/SN.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {


class LinkedFrame_1Vector;

struct LinkedFrame_1 {
	
	using PBFrame = PB_LinkedFrame_1;
	using FrameVector = LinkedFrame_1Vector;
	
	::arch::ISN* _0 = nullptr;
	::arch::ISN* _1 = nullptr;
	// toString
	
	std::string toString() const
	{
		std::string ret = "[";
		ret += "S1=";
		ret += (_0 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(_0->id()));
		ret += ",S2=";
		ret += (_1 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(_1->id()));
	
		return ret + ']';
	}
	// Serialization and deserialization
	std::string SerializeAsString()
	{
		PB_LinkedFrame_1 pbframe;
		
		pbframe.set__0(_0 == nullptr ? -1 : _0->id());
		pbframe.set__1(_1 == nullptr ? -1 : _1->id());
		
		return pbframe.SerializeAsString();
	}
		
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_LinkedFrame_1 pbframe;
		pbframe.ParseFromString(str);
		
		_0 = (pbframe._0() == -1) 
			? nullptr 
			: dynamic_cast<::arch::ISN*>(mr->findModelElementByID(pbframe._0()));
		
		_1 = (pbframe._1() == -1) 
			? nullptr 
			: dynamic_cast<::arch::ISN*>(mr->findModelElementByID(pbframe._1()));
		
	}
};
		
class LinkedFrame_1Vector 
	: private std::vector<LinkedFrame_1>
{
	public:
	using std::vector<LinkedFrame_1>::push_back;
	using std::vector<LinkedFrame_1>::clear;
	using std::vector<LinkedFrame_1>::empty;
	using std::vector<LinkedFrame_1>::size;
	using std::vector<LinkedFrame_1>::begin;
	using std::vector<LinkedFrame_1>::end;
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_LinkedFrame_1Vector pbFrameVector;
		pbFrameVector.ParseFromString(serialized_data);
		
		LinkedFrame_1 frame;
		for (auto & pbFrame : pbFrameVector.frames())
		{
			frame._0 = (pbFrame._0() == -1) 
				? nullptr 
				: dynamic_cast<::arch::ISN*>(mr->findModelElementByID(pbFrame._0()));
			
			frame._1 = (pbFrame._1() == -1) 
				? nullptr 
				: dynamic_cast<::arch::ISN*>(mr->findModelElementByID(pbFrame._1()));
			
			
			action(frame);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_LinkedFrame_1Vector pbFrameVector;
		
		for(auto& storedVector: *this){
			auto & pbFrame= *pbFrameVector.add_frames();
			pbFrame.set__0(storedVector._0 == nullptr ? -1 : storedVector._0->id());
			pbFrame.set__1(storedVector._1 == nullptr ? -1 : storedVector._1->id());
		}
		return pbFrameVector.SerializeAsString();
	}
};


} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__LINKED_FRAME_1_H_ */
