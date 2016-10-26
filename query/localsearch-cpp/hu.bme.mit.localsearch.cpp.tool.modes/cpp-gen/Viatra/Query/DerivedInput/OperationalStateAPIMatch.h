#ifndef VIATRA__QUERY__DERIVED_INPUT__OPERATIONAL_STATE_A_P_I_MATCH_H_
#define VIATRA__QUERY__DERIVED_INPUT__OPERATIONAL_STATE_A_P_I_MATCH_H_

#include <stdint.h>
#include <unordered_set>
		
#include "PB_DerivedInput.pb.h"
#include "Viatra/Query/MatchSet.h"
#include "Viatra/Query/Util/Convert.h"
#include "railRoadModel/Operational.h"
#include "railRoadModel/Turnout.h"

namespace Viatra {
namespace Query {
namespace DerivedInput {

class OperationalStateAPIMatchSet;

struct OperationalStateAPIMatch {
	
	using MatchSet = OperationalStateAPIMatchSet;
	
	::railRoadModel::ITurnout* turnout;
	int turnoutID;
	::railRoadModel::IOperational* operational;
	int stateID;
	double turnoutTemp;
	
	bool operator==(const OperationalStateAPIMatch& other) const {
		return 
			turnout == other.turnout&&
			turnoutID == other.turnoutID&&
			operational == other.operational&&
			stateID == other.stateID&&
			turnoutTemp == other.turnoutTemp
		;
	}
	
	// Serialization and deserialization
	
	std::string SerializeAsString()
	{
		PB_OperationalStateAPIMatch pbMatch;
		
		pbMatch.set_turnout(turnout == nullptr ? -1 : turnout->id());
		pbMatch.set_turnoutid(turnoutID);
		pbMatch.set_operational(operational == nullptr ? -1 : operational->id());
		pbMatch.set_stateid(stateID);
		pbMatch.set_turnouttemp(turnoutTemp);
		
		return pbMatch.SerializeAsString();
	}
	
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_OperationalStateAPIMatch pbMatch;
		pbMatch.ParseFromString(str);
			
		turnout = (pbMatch.turnout() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::ITurnout*>(mr->findModelElementByID(pbMatch.turnout()));
		
		turnoutID = pbMatch.turnoutid();
		
		operational = (pbMatch.operational() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::IOperational*>(mr->findModelElementByID(pbMatch.operational()));
		
		stateID = pbMatch.stateid();
		
		turnoutTemp = pbMatch.turnouttemp();
		
	}
	
	// toString
	
	std::string toString() const
	{
		std::string ret = "[";
		ret += "turnout=";
		ret += (turnout == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(turnout->id()));
		ret += ",turnoutID=";
		ret += Viatra::Query::Util::Convert::ToString(turnoutID);
		ret += ",operational=";
		ret += (operational == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(operational->id()));
		ret += ",stateID=";
		ret += Viatra::Query::Util::Convert::ToString(stateID);
		ret += ",turnoutTemp=";
		ret += Viatra::Query::Util::Convert::ToString(turnoutTemp);
	
		return ret + ']';
	}
};

} /* namespace DerivedInput */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::DerivedInput::OperationalStateAPIMatch> {
	size_t operator()(const ::Viatra::Query::DerivedInput::OperationalStateAPIMatch& match) const {
		size_t h = 0;
		h+=std::hash<decltype(match.turnout)>()(match.turnout);
		h*=31;
		h+=std::hash<decltype(match.turnoutID)>()(match.turnoutID);
		h*=31;
		h+=std::hash<decltype(match.operational)>()(match.operational);
		h*=31;
		h+=std::hash<decltype(match.stateID)>()(match.stateID);
		h*=31;
		h+=std::hash<decltype(match.turnoutTemp)>()(match.turnoutTemp);
		return h;
	}
};
		
}

namespace Viatra {
namespace Query {
namespace DerivedInput {

		
class OperationalStateAPIMatchSet 
	: private std::unordered_set<OperationalStateAPIMatch>
{
	public:
	using std::unordered_set<OperationalStateAPIMatch>::insert;
	using std::unordered_set<OperationalStateAPIMatch>::clear;
	using std::unordered_set<OperationalStateAPIMatch>::empty;
	using std::unordered_set<OperationalStateAPIMatch>::size;
	using std::unordered_set<OperationalStateAPIMatch>::begin;
	using std::unordered_set<OperationalStateAPIMatch>::end;
	
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_OperationalStateAPIMatchSet pbMsgSet;
		pbMsgSet.ParseFromString(serialized_data);
		
		OperationalStateAPIMatch match;
		for (auto & pbMatch : pbMsgSet.matches())
		{
			match.turnout = (pbMatch.turnout() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::ITurnout*>(mr->findModelElementByID(pbMatch.turnout()));
			
			match.turnoutID = pbMatch.turnoutid();
			
			match.operational = (pbMatch.operational() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::IOperational*>(mr->findModelElementByID(pbMatch.operational()));
			
			match.stateID = pbMatch.stateid();
			
			match.turnoutTemp = pbMatch.turnouttemp();
			
			
			action(match);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_OperationalStateAPIMatchSet pbMatchSet;
		
		for(auto& storedMatch: *this){
			auto & pbMatch = *pbMatchSet.add_matches();
			pbMatch.set_turnout(storedMatch.turnout == nullptr ? -1 : storedMatch.turnout->id());
			pbMatch.set_turnoutid(storedMatch.turnoutID);
			pbMatch.set_operational(storedMatch.operational == nullptr ? -1 : storedMatch.operational->id());
			pbMatch.set_stateid(storedMatch.stateID);
			pbMatch.set_turnouttemp(storedMatch.turnoutTemp);
		}
		return pbMatchSet.SerializeAsString();
	}
	
};

} /* namespace DerivedInput */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED_INPUT__OPERATIONAL_STATE_A_P_I_MATCH_H_ */
