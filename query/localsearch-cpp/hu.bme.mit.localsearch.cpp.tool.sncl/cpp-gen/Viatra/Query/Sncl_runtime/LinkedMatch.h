#ifndef VIATRA__QUERY__SNCL_RUNTIME__LINKED_MATCH_H_
#define VIATRA__QUERY__SNCL_RUNTIME__LINKED_MATCH_H_

#include <stdint.h>
#include <unordered_set>
		
#include "PB_sncl_runtime.pb.h"
#include "Viatra/Query/MatchSet.h"
#include "Viatra/Query/Util/Convert.h"
#include "arch/SN.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

class LinkedMatchSet;

struct LinkedMatch {
	
	using MatchSet = LinkedMatchSet;
	
	::arch::ISN* S1;
	::arch::ISN* S2;
	
	bool operator==(const LinkedMatch& other) const {
		return 
			S1 == other.S1&&
			S2 == other.S2
		;
	}
	
	// Serialization and deserialization
	
	std::string SerializeAsString()
	{
		PB_LinkedMatch pbMatch;
		
		pbMatch.set_s1(S1 == nullptr ? -1 : S1->id());
		pbMatch.set_s2(S2 == nullptr ? -1 : S2->id());
		
		return pbMatch.SerializeAsString();
	}
	
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_LinkedMatch pbMatch;
		pbMatch.ParseFromString(str);
			
		S1 = (pbMatch.s1() == -1) 
			? nullptr 
			: dynamic_cast<::arch::ISN*>(mr->findModelElementByID(pbMatch.s1()));
		
		S2 = (pbMatch.s2() == -1) 
			? nullptr 
			: dynamic_cast<::arch::ISN*>(mr->findModelElementByID(pbMatch.s2()));
		
	}
	
	// toString
	
	std::string toString() const
	{
		std::string ret = "[";
		ret += "S1=";
		ret += (S1 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(S1->id()));
		ret += ",S2=";
		ret += (S2 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(S2->id()));
	
		return ret + ']';
	}
};

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Sncl_runtime::LinkedMatch> {
	size_t operator()(const ::Viatra::Query::Sncl_runtime::LinkedMatch& match) const {
		size_t h = 0;
		h+=std::hash<decltype(match.S1)>()(match.S1);
		h*=31;
		h+=std::hash<decltype(match.S2)>()(match.S2);
		return h;
	}
};
		
}

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

		
class LinkedMatchSet 
	: private std::unordered_set<LinkedMatch>
{
	public:
	using std::unordered_set<LinkedMatch>::insert;
	using std::unordered_set<LinkedMatch>::clear;
	using std::unordered_set<LinkedMatch>::empty;
	using std::unordered_set<LinkedMatch>::size;
	using std::unordered_set<LinkedMatch>::begin;
	using std::unordered_set<LinkedMatch>::end;
	
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_LinkedMatchSet pbMsgSet;
		pbMsgSet.ParseFromString(serialized_data);
		
		LinkedMatch match;
		for (auto & pbMatch : pbMsgSet.matches())
		{
			match.S1 = (pbMatch.s1() == -1) 
				? nullptr 
				: dynamic_cast<::arch::ISN*>(mr->findModelElementByID(pbMatch.s1()));
			
			match.S2 = (pbMatch.s2() == -1) 
				? nullptr 
				: dynamic_cast<::arch::ISN*>(mr->findModelElementByID(pbMatch.s2()));
			
			
			action(match);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_LinkedMatchSet pbMatchSet;
		
		for(auto& storedMatch: *this){
			auto & pbMatch = *pbMatchSet.add_matches();
			pbMatch.set_s1(storedMatch.S1 == nullptr ? -1 : storedMatch.S1->id());
			pbMatch.set_s2(storedMatch.S2 == nullptr ? -1 : storedMatch.S2->id());
		}
		return pbMatchSet.SerializeAsString();
	}
	
};

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__LINKED_MATCH_H_ */
