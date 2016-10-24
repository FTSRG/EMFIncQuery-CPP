#ifndef VIATRA__QUERY__DISTRIBUTED_QUERIES__IS_DANGEROUS_FRAME_0_H_
#define VIATRA__QUERY__DISTRIBUTED_QUERIES__IS_DANGEROUS_FRAME_0_H_

#include <Viatra/Query/Util/Convert.h>
#include <stdint.h>
#include <vector>
		
#include "proto_gen.pb.h"
#include "railRoadModel/RobotPart.h"
#include "railRoadModel/Train.h"

namespace Viatra {
namespace Query {
namespace DistributedQueries {


class IsDangerousFrame_0Vector;

struct IsDangerousFrame_0 {
	
	using PBFrame = PB_IsDangerousFrame_0;
	using FrameVector = IsDangerousFrame_0Vector;
	
	::railRoadModel::IRobotPart* _0 = nullptr;
	::railRoadModel::ITrain* _1 = nullptr;
	// toString
	
	std::string toString() const
	{
		std::string ret = "[";
		ret += "rp=";
		ret += (_0 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(_0->id()));
		ret += ",tr=";
		ret += (_1 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(_1->id()));
	
		return ret + ']';
	}
	// Serialization and deserialization
	std::string SerializeAsString()
	{
		PB_IsDangerousFrame_0 pbframe;
		
		pbframe.set__0(_0 == nullptr ? -1 : _0->id());
		pbframe.set__1(_1 == nullptr ? -1 : _1->id());
		
		return pbframe.SerializeAsString();
	}
		
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_IsDangerousFrame_0 pbframe;
		pbframe.ParseFromString(str);
		
		_0 = (pbframe._0() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::IRobotPart*>(mr->findModelElementByID(pbframe._0()));
		
		_1 = (pbframe._1() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::ITrain*>(mr->findModelElementByID(pbframe._1()));
		
	}
};
		
class IsDangerousFrame_0Vector 
	: private std::vector<IsDangerousFrame_0>
{
	public:
	using std::vector<IsDangerousFrame_0>::push_back;
	using std::vector<IsDangerousFrame_0>::clear;
	using std::vector<IsDangerousFrame_0>::empty;
	using std::vector<IsDangerousFrame_0>::size;
	using std::vector<IsDangerousFrame_0>::begin;
	using std::vector<IsDangerousFrame_0>::end;
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_IsDangerousFrame_0Vector pbFrameVector;
		pbFrameVector.ParseFromString(serialized_data);
		
		IsDangerousFrame_0 frame;
		for (auto & pbFrame : pbFrameVector.frames())
		{
			frame._0 = (pbFrame._0() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::IRobotPart*>(mr->findModelElementByID(pbFrame._0()));
			
			frame._1 = (pbFrame._1() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::ITrain*>(mr->findModelElementByID(pbFrame._1()));
			
			
			action(frame);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_IsDangerousFrame_0Vector pbFrameVector;
		
		for(auto& storedVector: *this){
			auto & pbFrame= *pbFrameVector.add_frames();
			pbFrame.set__0(storedVector._0 == nullptr ? -1 : storedVector._0->id());
			pbFrame.set__1(storedVector._1 == nullptr ? -1 : storedVector._1->id());
		}
		return pbFrameVector.SerializeAsString();
	}
};


} /* namespace DistributedQueries */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DISTRIBUTED_QUERIES__IS_DANGEROUS_FRAME_0_H_ */
