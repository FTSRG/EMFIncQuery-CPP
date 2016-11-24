#ifndef VIATRA__QUERY__SAFETYLOGIC__NEXT_SECTION_MATCH_H_
#define VIATRA__QUERY__SAFETYLOGIC__NEXT_SECTION_MATCH_H_

#include <stdint.h>
#include <unordered_set>
		
#include "PB_safetylogic.pb.h"
#include "Viatra/Query/MatchSet.h"
#include "Viatra/Query/Util/Convert.h"
#include "railRoadModel/Path.h"
#include "railRoadModel/RailRoadElement.h"
#include "railRoadModel/Turnout.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {

class NextSectionMatchSet;

struct NextSectionMatch {
	
	using MatchSet = NextSectionMatchSet;
	
	::railRoadModel::ITurnout* Current;
	::railRoadModel::IRailRoadElement* Old;
	::railRoadModel::IRailRoadElement* Next;
	
	bool operator==(const NextSectionMatch& other) const {
		return 
			Current == other.Current&&
			Old == other.Old&&
			Next == other.Next
		;
	}
	
	// Serialization and deserialization
	
	std::string SerializeAsString()
	{
		PB_NextSectionMatch pbMatch;
		
		pbMatch.set_current(Current == nullptr ? -1 : Current->id());
		pbMatch.set_old(Old == nullptr ? -1 : Old->id());
		pbMatch.set_next(Next == nullptr ? -1 : Next->id());
		
		return pbMatch.SerializeAsString();
	}
	
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_NextSectionMatch pbMatch;
		pbMatch.ParseFromString(str);
			
		Current = (pbMatch.current() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::ITurnout*>(mr->findModelElementByID(pbMatch.current()));
		
		Old = (pbMatch.old() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::IRailRoadElement*>(mr->findModelElementByID(pbMatch.old()));
		
		Next = (pbMatch.next() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::IRailRoadElement*>(mr->findModelElementByID(pbMatch.next()));
		
	}
	
	// toString
	
	std::string toString() const
	{
		std::string ret = "[";
		ret += "Current=";
		ret += (Current == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(Current->id()));
		ret += ",Old=";
		ret += (Old == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(Old->id()));
		ret += ",Next=";
		ret += (Next == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(Next->id()));
	
		return ret + ']';
	}
};

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Safetylogic::NextSectionMatch> {
	size_t operator()(const ::Viatra::Query::Safetylogic::NextSectionMatch& match) const {
		size_t h = 0;
		h+=std::hash<decltype(match.Current)>()(match.Current);
		h*=31;
		h+=std::hash<decltype(match.Old)>()(match.Old);
		h*=31;
		h+=std::hash<decltype(match.Next)>()(match.Next);
		return h;
	}
};
		
}

namespace Viatra {
namespace Query {
namespace Safetylogic {

		
class NextSectionMatchSet 
	: private std::unordered_set<NextSectionMatch>
{
	public:
	using std::unordered_set<NextSectionMatch>::insert;
	using std::unordered_set<NextSectionMatch>::clear;
	using std::unordered_set<NextSectionMatch>::empty;
	using std::unordered_set<NextSectionMatch>::size;
	using std::unordered_set<NextSectionMatch>::begin;
	using std::unordered_set<NextSectionMatch>::end;
	
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_NextSectionMatchSet pbMsgSet;
		pbMsgSet.ParseFromString(serialized_data);
		
		NextSectionMatch match;
		for (auto & pbMatch : pbMsgSet.matches())
		{
			match.Current = (pbMatch.current() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::ITurnout*>(mr->findModelElementByID(pbMatch.current()));
			
			match.Old = (pbMatch.old() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::IRailRoadElement*>(mr->findModelElementByID(pbMatch.old()));
			
			match.Next = (pbMatch.next() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::IRailRoadElement*>(mr->findModelElementByID(pbMatch.next()));
			
			
			action(match);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_NextSectionMatchSet pbMatchSet;
		
		for(auto& storedMatch: *this){
			auto & pbMatch = *pbMatchSet.add_matches();
			pbMatch.set_current(storedMatch.Current == nullptr ? -1 : storedMatch.Current->id());
			pbMatch.set_old(storedMatch.Old == nullptr ? -1 : storedMatch.Old->id());
			pbMatch.set_next(storedMatch.Next == nullptr ? -1 : storedMatch.Next->id());
		}
		return pbMatchSet.SerializeAsString();
	}
	
};

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__NEXT_SECTION_MATCH_H_ */
