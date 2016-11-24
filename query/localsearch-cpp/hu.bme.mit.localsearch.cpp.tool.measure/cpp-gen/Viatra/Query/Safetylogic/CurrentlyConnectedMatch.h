#ifndef VIATRA__QUERY__SAFETYLOGIC__CURRENTLY_CONNECTED_MATCH_H_
#define VIATRA__QUERY__SAFETYLOGIC__CURRENTLY_CONNECTED_MATCH_H_

#include <stdint.h>
#include <unordered_set>
		
#include "PB_safetylogic.pb.h"
#include "Viatra/Query/MatchSet.h"
#include "Viatra/Query/Util/Convert.h"
#include "railRoadModel/RailRoadElement.h"
#include "railRoadModel/Turnout.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {

class CurrentlyConnectedMatchSet;

struct CurrentlyConnectedMatch {
	
	using MatchSet = CurrentlyConnectedMatchSet;
	
	::railRoadModel::ITurnout* This;
	::railRoadModel::IRailRoadElement* connectedTo;
	
	bool operator==(const CurrentlyConnectedMatch& other) const {
		return 
			This == other.This&&
			connectedTo == other.connectedTo
		;
	}
	
	// Serialization and deserialization
	
	std::string SerializeAsString()
	{
		PB_CurrentlyConnectedMatch pbMatch;
		
		pbMatch.set_this(This == nullptr ? -1 : This->id());
		pbMatch.set_connectedto(connectedTo == nullptr ? -1 : connectedTo->id());
		
		return pbMatch.SerializeAsString();
	}
	
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_CurrentlyConnectedMatch pbMatch;
		pbMatch.ParseFromString(str);
			
		This = (pbMatch.this() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::ITurnout*>(mr->findModelElementByID(pbMatch.this()));
		
		connectedTo = (pbMatch.connectedto() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::IRailRoadElement*>(mr->findModelElementByID(pbMatch.connectedto()));
		
	}
	
	// toString
	
	std::string toString() const
	{
		std::string ret = "[";
		ret += "This=";
		ret += (This == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(This->id()));
		ret += ",connectedTo=";
		ret += (connectedTo == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(connectedTo->id()));
	
		return ret + ']';
	}
};

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Safetylogic::CurrentlyConnectedMatch> {
	size_t operator()(const ::Viatra::Query::Safetylogic::CurrentlyConnectedMatch& match) const {
		size_t h = 0;
		h+=std::hash<decltype(match.This)>()(match.This);
		h*=31;
		h+=std::hash<decltype(match.connectedTo)>()(match.connectedTo);
		return h;
	}
};
		
}

namespace Viatra {
namespace Query {
namespace Safetylogic {

		
class CurrentlyConnectedMatchSet 
	: private std::unordered_set<CurrentlyConnectedMatch>
{
	public:
	using std::unordered_set<CurrentlyConnectedMatch>::insert;
	using std::unordered_set<CurrentlyConnectedMatch>::clear;
	using std::unordered_set<CurrentlyConnectedMatch>::empty;
	using std::unordered_set<CurrentlyConnectedMatch>::size;
	using std::unordered_set<CurrentlyConnectedMatch>::begin;
	using std::unordered_set<CurrentlyConnectedMatch>::end;
	
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_CurrentlyConnectedMatchSet pbMsgSet;
		pbMsgSet.ParseFromString(serialized_data);
		
		CurrentlyConnectedMatch match;
		for (auto & pbMatch : pbMsgSet.matches())
		{
			match.This = (pbMatch.this() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::ITurnout*>(mr->findModelElementByID(pbMatch.this()));
			
			match.connectedTo = (pbMatch.connectedto() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::IRailRoadElement*>(mr->findModelElementByID(pbMatch.connectedto()));
			
			
			action(match);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_CurrentlyConnectedMatchSet pbMatchSet;
		
		for(auto& storedMatch: *this){
			auto & pbMatch = *pbMatchSet.add_matches();
			pbMatch.set_this(storedMatch.This == nullptr ? -1 : storedMatch.This->id());
			pbMatch.set_connectedto(storedMatch.connectedTo == nullptr ? -1 : storedMatch.connectedTo->id());
		}
		return pbMatchSet.SerializeAsString();
	}
	
};

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__CURRENTLY_CONNECTED_MATCH_H_ */
