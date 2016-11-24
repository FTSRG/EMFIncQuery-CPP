#ifndef VIATRA__QUERY__SNCL_RUNTIME__GREATER_THAN_ONE_S_N_CONNECTION_FRAME_0_H_
#define VIATRA__QUERY__SNCL_RUNTIME__GREATER_THAN_ONE_S_N_CONNECTION_FRAME_0_H_

#include <Viatra/Query/Util/Convert.h>
#include <stdint.h>
#include <vector>
		
#include "PB_sncl_runtime.pb.h"
#include "arch/CL.h"
#include "arch/SN.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {


class GreaterThanOneSNConnectionFrame_0Vector;

struct GreaterThanOneSNConnectionFrame_0 {
	
	using PBFrame = PB_GreaterThanOneSNConnectionFrame_0;
	using FrameVector = GreaterThanOneSNConnectionFrame_0Vector;
	
	::arch::ICL* _0 = nullptr;
	int _1 = 0;
	int _2 = 0;
	int _3 = 0;
	int _5 = 0;
	::arch::ISN* _6 = nullptr;
	// toString
	
	std::string toString() const
	{
		std::string ret = "[";
		ret += "C1=";
		ret += (_0 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(_0->id()));
		ret += ",.virtual{4}=";
		ret += Viatra::Query::Util::Convert::ToString(_1);
		ret += ",.virtual{2}=";
		ret += Viatra::Query::Util::Convert::ToString(_2);
		ret += ",.virtual{1}=";
		ret += Viatra::Query::Util::Convert::ToString(_3);
		ret += ",.virtual{3}=";
		ret += Viatra::Query::Util::Convert::ToString(_5);
		ret += ",S1=";
		ret += (_6 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(_6->id()));
	
		return ret + ']';
	}
	// Serialization and deserialization
	std::string SerializeAsString()
	{
		PB_GreaterThanOneSNConnectionFrame_0 pbframe;
		
		pbframe.set__0(_0 == nullptr ? -1 : _0->id());
		pbframe.set__1(_1);
		pbframe.set__2(_2);
		pbframe.set__3(_3);
		pbframe.set__5(_5);
		pbframe.set__6(_6 == nullptr ? -1 : _6->id());
		
		return pbframe.SerializeAsString();
	}
		
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_GreaterThanOneSNConnectionFrame_0 pbframe;
		pbframe.ParseFromString(str);
		
		_0 = (pbframe._0() == -1) 
			? nullptr 
			: dynamic_cast<::arch::ICL*>(mr->findModelElementByID(pbframe._0()));
		
		_1 = pbframe._1();
		
		_2 = pbframe._2();
		
		_3 = pbframe._3();
		
		_5 = pbframe._5();
		
		_6 = (pbframe._6() == -1) 
			? nullptr 
			: dynamic_cast<::arch::ISN*>(mr->findModelElementByID(pbframe._6()));
		
	}
};
		
class GreaterThanOneSNConnectionFrame_0Vector 
	: private std::vector<GreaterThanOneSNConnectionFrame_0>
{
	public:
	using std::vector<GreaterThanOneSNConnectionFrame_0>::push_back;
	using std::vector<GreaterThanOneSNConnectionFrame_0>::clear;
	using std::vector<GreaterThanOneSNConnectionFrame_0>::empty;
	using std::vector<GreaterThanOneSNConnectionFrame_0>::size;
	using std::vector<GreaterThanOneSNConnectionFrame_0>::begin;
	using std::vector<GreaterThanOneSNConnectionFrame_0>::end;
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_GreaterThanOneSNConnectionFrame_0Vector pbFrameVector;
		pbFrameVector.ParseFromString(serialized_data);
		
		GreaterThanOneSNConnectionFrame_0 frame;
		for (auto & pbFrame : pbFrameVector.frames())
		{
			frame._0 = (pbFrame._0() == -1) 
				? nullptr 
				: dynamic_cast<::arch::ICL*>(mr->findModelElementByID(pbFrame._0()));
			
			frame._1 = pbFrame._1();
			
			frame._2 = pbFrame._2();
			
			frame._3 = pbFrame._3();
			
			frame._5 = pbFrame._5();
			
			frame._6 = (pbFrame._6() == -1) 
				? nullptr 
				: dynamic_cast<::arch::ISN*>(mr->findModelElementByID(pbFrame._6()));
			
			
			action(frame);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_GreaterThanOneSNConnectionFrame_0Vector pbFrameVector;
		
		for(auto& storedVector: *this){
			auto & pbFrame= *pbFrameVector.add_frames();
			pbFrame.set__0(storedVector._0 == nullptr ? -1 : storedVector._0->id());
			pbFrame.set__1(storedVector._1);
			pbFrame.set__2(storedVector._2);
			pbFrame.set__3(storedVector._3);
			pbFrame.set__5(storedVector._5);
			pbFrame.set__6(storedVector._6 == nullptr ? -1 : storedVector._6->id());
		}
		return pbFrameVector.SerializeAsString();
	}
};


} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__GREATER_THAN_ONE_S_N_CONNECTION_FRAME_0_H_ */
