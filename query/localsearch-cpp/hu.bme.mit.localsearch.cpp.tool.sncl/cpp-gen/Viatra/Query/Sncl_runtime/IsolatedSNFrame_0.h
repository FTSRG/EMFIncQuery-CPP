#ifndef VIATRA__QUERY__SNCL_RUNTIME__ISOLATED_S_N_FRAME_0_H_
#define VIATRA__QUERY__SNCL_RUNTIME__ISOLATED_S_N_FRAME_0_H_

#include <Viatra/Query/Util/Convert.h>
#include <stdint.h>
#include <vector>
		
#include "PB_sncl_runtime.pb.h"
#include "arch/CL.h"
#include "arch/SN.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {


class IsolatedSNFrame_0Vector;

struct IsolatedSNFrame_0 {
	
	using PBFrame = PB_IsolatedSNFrame_0;
	using FrameVector = IsolatedSNFrame_0Vector;
	
	::arch::ICL* _0 = nullptr;
	::arch::ISN* _2 = nullptr;
	// toString
	
	std::string toString() const
	{
		std::string ret = "[";
		ret += "C1=";
		ret += (_0 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(_0->id()));
		ret += ",S1=";
		ret += (_2 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(_2->id()));
	
		return ret + ']';
	}
	// Serialization and deserialization
	std::string SerializeAsString()
	{
		PB_IsolatedSNFrame_0 pbframe;
		
		pbframe.set__0(_0 == nullptr ? -1 : _0->id());
		pbframe.set__2(_2 == nullptr ? -1 : _2->id());
		
		return pbframe.SerializeAsString();
	}
		
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_IsolatedSNFrame_0 pbframe;
		pbframe.ParseFromString(str);
		
		_0 = (pbframe._0() == -1) 
			? nullptr 
			: dynamic_cast<::arch::ICL*>(mr->findModelElementByID(pbframe._0()));
		
		_2 = (pbframe._2() == -1) 
			? nullptr 
			: dynamic_cast<::arch::ISN*>(mr->findModelElementByID(pbframe._2()));
		
	}
};
		
class IsolatedSNFrame_0Vector 
	: private std::vector<IsolatedSNFrame_0>
{
	public:
	using std::vector<IsolatedSNFrame_0>::push_back;
	using std::vector<IsolatedSNFrame_0>::clear;
	using std::vector<IsolatedSNFrame_0>::empty;
	using std::vector<IsolatedSNFrame_0>::size;
	using std::vector<IsolatedSNFrame_0>::begin;
	using std::vector<IsolatedSNFrame_0>::end;
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_IsolatedSNFrame_0Vector pbFrameVector;
		pbFrameVector.ParseFromString(serialized_data);
		
		IsolatedSNFrame_0 frame;
		for (auto & pbFrame : pbFrameVector.frames())
		{
			frame._0 = (pbFrame._0() == -1) 
				? nullptr 
				: dynamic_cast<::arch::ICL*>(mr->findModelElementByID(pbFrame._0()));
			
			frame._2 = (pbFrame._2() == -1) 
				? nullptr 
				: dynamic_cast<::arch::ISN*>(mr->findModelElementByID(pbFrame._2()));
			
			
			action(frame);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_IsolatedSNFrame_0Vector pbFrameVector;
		
		for(auto& storedVector: *this){
			auto & pbFrame= *pbFrameVector.add_frames();
			pbFrame.set__0(storedVector._0 == nullptr ? -1 : storedVector._0->id());
			pbFrame.set__2(storedVector._2 == nullptr ? -1 : storedVector._2->id());
		}
		return pbFrameVector.SerializeAsString();
	}
};


} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__ISOLATED_S_N_FRAME_0_H_ */
