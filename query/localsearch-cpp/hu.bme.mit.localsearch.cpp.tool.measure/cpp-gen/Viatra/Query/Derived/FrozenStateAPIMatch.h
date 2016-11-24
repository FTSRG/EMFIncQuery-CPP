#ifndef VIATRA__QUERY__DERIVED__FROZEN_STATE_A_P_I_MATCH_H_
#define VIATRA__QUERY__DERIVED__FROZEN_STATE_A_P_I_MATCH_H_

#include <stdint.h>
#include <unordered_set>
		
#include "PB_derived.pb.h"
#include "Viatra/Query/MatchSet.h"
#include "Viatra/Query/Util/Convert.h"
#include "railRoadModel/Frozen.h"
#include "railRoadModel/Turnout.h"

namespace Viatra {
namespace Query {
namespace Derived {

class FrozenStateAPIMatchSet;

struct FrozenStateAPIMatch {
	
	using MatchSet = FrozenStateAPIMatchSet;
	
	::railRoadModel::ITurnout* turnout;
	int turnoutID;
	::railRoadModel::IFrozen* frozen;
	int stateID;
	double turnoutTemp;
	
	bool operator==(const FrozenStateAPIMatch& other) const {
		return 
			turnout == other.turnout&&
			turnoutID == other.turnoutID&&
			frozen == other.frozen&&
			stateID == other.stateID&&
			turnoutTemp == other.turnoutTemp
		;
	}
	
	// Serialization and deserialization
	
	std::string SerializeAsString()
	{
		PB_FrozenStateAPIMatch pbMatch;
		
		pbMatch.set_turnout(turnout == nullptr ? -1 : turnout->id());
		pbMatch.set_turnoutid(turnoutID);
		pbMatch.set_frozen(frozen == nullptr ? -1 : frozen->id());
		pbMatch.set_stateid(stateID);
		pbMatch.set_turnouttemp(turnoutTemp);
		
		return pbMatch.SerializeAsString();
	}
	
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_FrozenStateAPIMatch pbMatch;
		pbMatch.ParseFromString(str);
			
		turnout = (pbMatch.turnout() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::ITurnout*>(mr->findModelElementByID(pbMatch.turnout()));
		
		turnoutID = pbMatch.turnoutid();
		
		frozen = (pbMatch.frozen() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::IFrozen*>(mr->findModelElementByID(pbMatch.frozen()));
		
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
		ret += ",frozen=";
		ret += (frozen == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(frozen->id()));
		ret += ",stateID=";
		ret += Viatra::Query::Util::Convert::ToString(stateID);
		ret += ",turnoutTemp=";
		ret += Viatra::Query::Util::Convert::ToString(turnoutTemp);
	
		return ret + ']';
	}
};

} /* namespace Derived */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Derived::FrozenStateAPIMatch> {
	size_t operator()(const ::Viatra::Query::Derived::FrozenStateAPIMatch& match) const {
		size_t h = 0;
		h+=std::hash<decltype(match.turnout)>()(match.turnout);
		h*=31;
		h+=std::hash<decltype(match.turnoutID)>()(match.turnoutID);
		h*=31;
		h+=std::hash<decltype(match.frozen)>()(match.frozen);
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
namespace Derived {

		
class FrozenStateAPIMatchSet 
	: private std::unordered_set<FrozenStateAPIMatch>
{
	public:
	using std::unordered_set<FrozenStateAPIMatch>::insert;
	using std::unordered_set<FrozenStateAPIMatch>::clear;
	using std::unordered_set<FrozenStateAPIMatch>::empty;
	using std::unordered_set<FrozenStateAPIMatch>::size;
	using std::unordered_set<FrozenStateAPIMatch>::begin;
	using std::unordered_set<FrozenStateAPIMatch>::end;
	
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_FrozenStateAPIMatchSet pbMsgSet;
		pbMsgSet.ParseFromString(serialized_data);
		
		FrozenStateAPIMatch match;
		for (auto & pbMatch : pbMsgSet.matches())
		{
			match.turnout = (pbMatch.turnout() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::ITurnout*>(mr->findModelElementByID(pbMatch.turnout()));
			
			match.turnoutID = pbMatch.turnoutid();
			
			match.frozen = (pbMatch.frozen() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::IFrozen*>(mr->findModelElementByID(pbMatch.frozen()));
			
			match.stateID = pbMatch.stateid();
			
			match.turnoutTemp = pbMatch.turnouttemp();
			
			
			action(match);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_FrozenStateAPIMatchSet pbMatchSet;
		
		for(auto& storedMatch: *this){
			auto & pbMatch = *pbMatchSet.add_matches();
			pbMatch.set_turnout(storedMatch.turnout == nullptr ? -1 : storedMatch.turnout->id());
			pbMatch.set_turnoutid(storedMatch.turnoutID);
			pbMatch.set_frozen(storedMatch.frozen == nullptr ? -1 : storedMatch.frozen->id());
			pbMatch.set_stateid(storedMatch.stateID);
			pbMatch.set_turnouttemp(storedMatch.turnoutTemp);
		}
		return pbMatchSet.SerializeAsString();
	}
	
};

} /* namespace Derived */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED__FROZEN_STATE_A_P_I_MATCH_H_ */
