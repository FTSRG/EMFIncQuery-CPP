#ifndef VIATRA__QUERY__SAFETYLOGIC__VIABLE_PATHS_FRAME_4_H_
#define VIATRA__QUERY__SAFETYLOGIC__VIABLE_PATHS_FRAME_4_H_

#include <Viatra/Query/Util/Convert.h>
#include <stdint.h>
#include <vector>
		
#include "PB_safetylogic.pb.h"
#include "railRoadModel/Path.h"
#include "railRoadModel/RailRoadElement.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {


class ViablePathsFrame_4Vector;

struct ViablePathsFrame_4 {
	
	using PBFrame = PB_ViablePathsFrame_4;
	using FrameVector = ViablePathsFrame_4Vector;
	
	::railRoadModel::ITurnout* _0 = nullptr;
	::railRoadModel::IPath* _1 = nullptr;
	::railRoadModel::IRailRoadElement* _2 = nullptr;
	bool _3 = false;
	::railRoadModel::IRailRoadElement* _4 = nullptr;
	// toString
	
	std::string toString() const
	{
		std::string ret = "[";
		ret += "This=";
		ret += (_0 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(_0->id()));
		ret += ",path=";
		ret += (_1 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(_1->id()));
		ret += ",top=";
		ret += (_2 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(_2->id()));
		ret += ",.virtual{0}=";
		ret += Viatra::Query::Util::Convert::ToString(_3);
		ret += ",divergent=";
		ret += (_4 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(_4->id()));
	
		return ret + ']';
	}
	// Serialization and deserialization
	std::string SerializeAsString()
	{
		PB_ViablePathsFrame_4 pbframe;
		
		pbframe.set__0(_0 == nullptr ? -1 : _0->id());
		pbframe.set__1(_1 == nullptr ? -1 : _1->id());
		pbframe.set__2(_2 == nullptr ? -1 : _2->id());
		pbframe.set__3(_3);
		pbframe.set__4(_4 == nullptr ? -1 : _4->id());
		
		return pbframe.SerializeAsString();
	}
		
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_ViablePathsFrame_4 pbframe;
		pbframe.ParseFromString(str);
		
		_0 = (pbframe._0() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::ITurnout*>(mr->findModelElementByID(pbframe._0()));
		
		_1 = (pbframe._1() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::IPath*>(mr->findModelElementByID(pbframe._1()));
		
		_2 = (pbframe._2() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::IRailRoadElement*>(mr->findModelElementByID(pbframe._2()));
		
		_3 = pbframe._3();
		
		_4 = (pbframe._4() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::IRailRoadElement*>(mr->findModelElementByID(pbframe._4()));
		
	}
};
		
class ViablePathsFrame_4Vector 
	: private std::vector<ViablePathsFrame_4>
{
	public:
	using std::vector<ViablePathsFrame_4>::push_back;
	using std::vector<ViablePathsFrame_4>::clear;
	using std::vector<ViablePathsFrame_4>::empty;
	using std::vector<ViablePathsFrame_4>::size;
	using std::vector<ViablePathsFrame_4>::begin;
	using std::vector<ViablePathsFrame_4>::end;
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_ViablePathsFrame_4Vector pbFrameVector;
		pbFrameVector.ParseFromString(serialized_data);
		
		ViablePathsFrame_4 frame;
		for (auto & pbFrame : pbFrameVector.frames())
		{
			frame._0 = (pbFrame._0() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::ITurnout*>(mr->findModelElementByID(pbFrame._0()));
			
			frame._1 = (pbFrame._1() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::IPath*>(mr->findModelElementByID(pbFrame._1()));
			
			frame._2 = (pbFrame._2() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::IRailRoadElement*>(mr->findModelElementByID(pbFrame._2()));
			
			frame._3 = pbFrame._3();
			
			frame._4 = (pbFrame._4() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::IRailRoadElement*>(mr->findModelElementByID(pbFrame._4()));
			
			
			action(frame);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_ViablePathsFrame_4Vector pbFrameVector;
		
		for(auto& storedVector: *this){
			auto & pbFrame= *pbFrameVector.add_frames();
			pbFrame.set__0(storedVector._0 == nullptr ? -1 : storedVector._0->id());
			pbFrame.set__1(storedVector._1 == nullptr ? -1 : storedVector._1->id());
			pbFrame.set__2(storedVector._2 == nullptr ? -1 : storedVector._2->id());
			pbFrame.set__3(storedVector._3);
			pbFrame.set__4(storedVector._4 == nullptr ? -1 : storedVector._4->id());
		}
		return pbFrameVector.SerializeAsString();
	}
};


} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__VIABLE_PATHS_FRAME_4_H_ */
