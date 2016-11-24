#ifndef VIATRA__QUERY__SNCL_RUNTIME__NUM_IN_EQUALITY_WITH_MEMBER_FRAME_0_H_
#define VIATRA__QUERY__SNCL_RUNTIME__NUM_IN_EQUALITY_WITH_MEMBER_FRAME_0_H_

#include <Viatra/Query/Util/Convert.h>
#include <stdint.h>
#include <vector>
		
#include "PB_sncl_runtime.pb.h"
#include "arch/CL.h"
#include "arch/SN.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {


class NumInEqualityWithMemberFrame_0Vector;

struct NumInEqualityWithMemberFrame_0 {
	
	using PBFrame = PB_NumInEqualityWithMemberFrame_0;
	using FrameVector = NumInEqualityWithMemberFrame_0Vector;
	
	::arch::ICL* _0 = nullptr;
	int _1 = 0;
	::arch::ISN* _2 = nullptr;
	int _4 = 0;
	// toString
	
	std::string toString() const
	{
		std::string ret = "[";
		ret += "C1=";
		ret += (_0 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(_0->id()));
		ret += ",N=";
		ret += Viatra::Query::Util::Convert::ToString(_1);
		ret += ",S1=";
		ret += (_2 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(_2->id()));
		ret += ",.virtual{2}=";
		ret += Viatra::Query::Util::Convert::ToString(_4);
	
		return ret + ']';
	}
	// Serialization and deserialization
	std::string SerializeAsString()
	{
		PB_NumInEqualityWithMemberFrame_0 pbframe;
		
		pbframe.set__0(_0 == nullptr ? -1 : _0->id());
		pbframe.set__1(_1);
		pbframe.set__2(_2 == nullptr ? -1 : _2->id());
		pbframe.set__4(_4);
		
		return pbframe.SerializeAsString();
	}
		
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_NumInEqualityWithMemberFrame_0 pbframe;
		pbframe.ParseFromString(str);
		
		_0 = (pbframe._0() == -1) 
			? nullptr 
			: dynamic_cast<::arch::ICL*>(mr->findModelElementByID(pbframe._0()));
		
		_1 = pbframe._1();
		
		_2 = (pbframe._2() == -1) 
			? nullptr 
			: dynamic_cast<::arch::ISN*>(mr->findModelElementByID(pbframe._2()));
		
		_4 = pbframe._4();
		
	}
};
		
class NumInEqualityWithMemberFrame_0Vector 
	: private std::vector<NumInEqualityWithMemberFrame_0>
{
	public:
	using std::vector<NumInEqualityWithMemberFrame_0>::push_back;
	using std::vector<NumInEqualityWithMemberFrame_0>::clear;
	using std::vector<NumInEqualityWithMemberFrame_0>::empty;
	using std::vector<NumInEqualityWithMemberFrame_0>::size;
	using std::vector<NumInEqualityWithMemberFrame_0>::begin;
	using std::vector<NumInEqualityWithMemberFrame_0>::end;
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_NumInEqualityWithMemberFrame_0Vector pbFrameVector;
		pbFrameVector.ParseFromString(serialized_data);
		
		NumInEqualityWithMemberFrame_0 frame;
		for (auto & pbFrame : pbFrameVector.frames())
		{
			frame._0 = (pbFrame._0() == -1) 
				? nullptr 
				: dynamic_cast<::arch::ICL*>(mr->findModelElementByID(pbFrame._0()));
			
			frame._1 = pbFrame._1();
			
			frame._2 = (pbFrame._2() == -1) 
				? nullptr 
				: dynamic_cast<::arch::ISN*>(mr->findModelElementByID(pbFrame._2()));
			
			frame._4 = pbFrame._4();
			
			
			action(frame);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_NumInEqualityWithMemberFrame_0Vector pbFrameVector;
		
		for(auto& storedVector: *this){
			auto & pbFrame= *pbFrameVector.add_frames();
			pbFrame.set__0(storedVector._0 == nullptr ? -1 : storedVector._0->id());
			pbFrame.set__1(storedVector._1);
			pbFrame.set__2(storedVector._2 == nullptr ? -1 : storedVector._2->id());
			pbFrame.set__4(storedVector._4);
		}
		return pbFrameVector.SerializeAsString();
	}
};


} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__NUM_IN_EQUALITY_WITH_MEMBER_FRAME_0_H_ */
