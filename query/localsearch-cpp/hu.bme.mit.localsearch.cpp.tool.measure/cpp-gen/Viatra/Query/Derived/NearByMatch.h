#ifndef VIATRA__QUERY__DERIVED__NEAR_BY_MATCH_H_
#define VIATRA__QUERY__DERIVED__NEAR_BY_MATCH_H_

#include <stdint.h>
#include <unordered_set>
		
#include "PB_derived.pb.h"
#include "Viatra/Query/MatchSet.h"
#include "Viatra/Query/Util/Convert.h"
#include "railRoadModel/RailRoadElement.h"
#include "railRoadModel/RobotPart.h"
#include "railRoadModel/Segment.h"
#include "railRoadModel/Train.h"

namespace Viatra {
namespace Query {
namespace Derived {

class NearByMatchSet;

struct NearByMatch {
	
	using MatchSet = NearByMatchSet;
	
	::railRoadModel::IRobotPart* robotPart;
	int robotPartID;
	::railRoadModel::ITrain* train;
	int trainID;
	int segID;
	double robX;
	double robY;
	double robZ;
	double segX;
	double segY;
	double segZ;
	
	bool operator==(const NearByMatch& other) const {
		return 
			robotPart == other.robotPart&&
			robotPartID == other.robotPartID&&
			train == other.train&&
			trainID == other.trainID&&
			segID == other.segID&&
			robX == other.robX&&
			robY == other.robY&&
			robZ == other.robZ&&
			segX == other.segX&&
			segY == other.segY&&
			segZ == other.segZ
		;
	}
	
	// Serialization and deserialization
	
	std::string SerializeAsString()
	{
		PB_NearByMatch pbMatch;
		
		pbMatch.set_robotpart(robotPart == nullptr ? -1 : robotPart->id());
		pbMatch.set_robotpartid(robotPartID);
		pbMatch.set_train(train == nullptr ? -1 : train->id());
		pbMatch.set_trainid(trainID);
		pbMatch.set_segid(segID);
		pbMatch.set_robx(robX);
		pbMatch.set_roby(robY);
		pbMatch.set_robz(robZ);
		pbMatch.set_segx(segX);
		pbMatch.set_segy(segY);
		pbMatch.set_segz(segZ);
		
		return pbMatch.SerializeAsString();
	}
	
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_NearByMatch pbMatch;
		pbMatch.ParseFromString(str);
			
		robotPart = (pbMatch.robotpart() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::IRobotPart*>(mr->findModelElementByID(pbMatch.robotpart()));
		
		robotPartID = pbMatch.robotpartid();
		
		train = (pbMatch.train() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::ITrain*>(mr->findModelElementByID(pbMatch.train()));
		
		trainID = pbMatch.trainid();
		
		segID = pbMatch.segid();
		
		robX = pbMatch.robx();
		
		robY = pbMatch.roby();
		
		robZ = pbMatch.robz();
		
		segX = pbMatch.segx();
		
		segY = pbMatch.segy();
		
		segZ = pbMatch.segz();
		
	}
	
	// toString
	
	std::string toString() const
	{
		std::string ret = "[";
		ret += "robotPart=";
		ret += (robotPart == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(robotPart->id()));
		ret += ",robotPartID=";
		ret += Viatra::Query::Util::Convert::ToString(robotPartID);
		ret += ",train=";
		ret += (train == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(train->id()));
		ret += ",trainID=";
		ret += Viatra::Query::Util::Convert::ToString(trainID);
		ret += ",segID=";
		ret += Viatra::Query::Util::Convert::ToString(segID);
		ret += ",robX=";
		ret += Viatra::Query::Util::Convert::ToString(robX);
		ret += ",robY=";
		ret += Viatra::Query::Util::Convert::ToString(robY);
		ret += ",robZ=";
		ret += Viatra::Query::Util::Convert::ToString(robZ);
		ret += ",segX=";
		ret += Viatra::Query::Util::Convert::ToString(segX);
		ret += ",segY=";
		ret += Viatra::Query::Util::Convert::ToString(segY);
		ret += ",segZ=";
		ret += Viatra::Query::Util::Convert::ToString(segZ);
	
		return ret + ']';
	}
};

} /* namespace Derived */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Derived::NearByMatch> {
	size_t operator()(const ::Viatra::Query::Derived::NearByMatch& match) const {
		size_t h = 0;
		h+=std::hash<decltype(match.robotPart)>()(match.robotPart);
		h*=31;
		h+=std::hash<decltype(match.robotPartID)>()(match.robotPartID);
		h*=31;
		h+=std::hash<decltype(match.train)>()(match.train);
		h*=31;
		h+=std::hash<decltype(match.trainID)>()(match.trainID);
		h*=31;
		h+=std::hash<decltype(match.segID)>()(match.segID);
		h*=31;
		h+=std::hash<decltype(match.robX)>()(match.robX);
		h*=31;
		h+=std::hash<decltype(match.robY)>()(match.robY);
		h*=31;
		h+=std::hash<decltype(match.robZ)>()(match.robZ);
		h*=31;
		h+=std::hash<decltype(match.segX)>()(match.segX);
		h*=31;
		h+=std::hash<decltype(match.segY)>()(match.segY);
		h*=31;
		h+=std::hash<decltype(match.segZ)>()(match.segZ);
		return h;
	}
};
		
}

namespace Viatra {
namespace Query {
namespace Derived {

		
class NearByMatchSet 
	: private std::unordered_set<NearByMatch>
{
	public:
	using std::unordered_set<NearByMatch>::insert;
	using std::unordered_set<NearByMatch>::clear;
	using std::unordered_set<NearByMatch>::empty;
	using std::unordered_set<NearByMatch>::size;
	using std::unordered_set<NearByMatch>::begin;
	using std::unordered_set<NearByMatch>::end;
	
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_NearByMatchSet pbMsgSet;
		pbMsgSet.ParseFromString(serialized_data);
		
		NearByMatch match;
		for (auto & pbMatch : pbMsgSet.matches())
		{
			match.robotPart = (pbMatch.robotpart() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::IRobotPart*>(mr->findModelElementByID(pbMatch.robotpart()));
			
			match.robotPartID = pbMatch.robotpartid();
			
			match.train = (pbMatch.train() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::ITrain*>(mr->findModelElementByID(pbMatch.train()));
			
			match.trainID = pbMatch.trainid();
			
			match.segID = pbMatch.segid();
			
			match.robX = pbMatch.robx();
			
			match.robY = pbMatch.roby();
			
			match.robZ = pbMatch.robz();
			
			match.segX = pbMatch.segx();
			
			match.segY = pbMatch.segy();
			
			match.segZ = pbMatch.segz();
			
			
			action(match);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_NearByMatchSet pbMatchSet;
		
		for(auto& storedMatch: *this){
			auto & pbMatch = *pbMatchSet.add_matches();
			pbMatch.set_robotpart(storedMatch.robotPart == nullptr ? -1 : storedMatch.robotPart->id());
			pbMatch.set_robotpartid(storedMatch.robotPartID);
			pbMatch.set_train(storedMatch.train == nullptr ? -1 : storedMatch.train->id());
			pbMatch.set_trainid(storedMatch.trainID);
			pbMatch.set_segid(storedMatch.segID);
			pbMatch.set_robx(storedMatch.robX);
			pbMatch.set_roby(storedMatch.robY);
			pbMatch.set_robz(storedMatch.robZ);
			pbMatch.set_segx(storedMatch.segX);
			pbMatch.set_segy(storedMatch.segY);
			pbMatch.set_segz(storedMatch.segZ);
		}
		return pbMatchSet.SerializeAsString();
	}
	
};

} /* namespace Derived */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED__NEAR_BY_MATCH_H_ */
