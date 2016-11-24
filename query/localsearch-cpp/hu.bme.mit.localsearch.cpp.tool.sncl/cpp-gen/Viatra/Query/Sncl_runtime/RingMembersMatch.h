#ifndef VIATRA__QUERY__SNCL_RUNTIME__RING_MEMBERS_MATCH_H_
#define VIATRA__QUERY__SNCL_RUNTIME__RING_MEMBERS_MATCH_H_

#include <stdint.h>
#include <unordered_set>
		
#include "PB_sncl_runtime.pb.h"
#include "Viatra/Query/MatchSet.h"
#include "Viatra/Query/Util/Convert.h"
#include "arch/CL.h"
#include "arch/SN.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

class RingMembersMatchSet;

struct RingMembersMatch {
	
	using MatchSet = RingMembersMatchSet;
	
	::arch::ICL* C1;
	
	bool operator==(const RingMembersMatch& other) const {
		return 
			C1 == other.C1
		;
	}
	
	// Serialization and deserialization
	
	std::string SerializeAsString()
	{
		PB_RingMembersMatch pbMatch;
		
		pbMatch.set_c1(C1 == nullptr ? -1 : C1->id());
		
		return pbMatch.SerializeAsString();
	}
	
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_RingMembersMatch pbMatch;
		pbMatch.ParseFromString(str);
			
		C1 = (pbMatch.c1() == -1) 
			? nullptr 
			: dynamic_cast<::arch::ICL*>(mr->findModelElementByID(pbMatch.c1()));
		
	}
	
	// toString
	
	std::string toString() const
	{
		std::string ret = "[";
		ret += "C1=";
		ret += (C1 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(C1->id()));
	
		return ret + ']';
	}
};

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Sncl_runtime::RingMembersMatch> {
	size_t operator()(const ::Viatra::Query::Sncl_runtime::RingMembersMatch& match) const {
		size_t h = 0;
		h+=std::hash<decltype(match.C1)>()(match.C1);
		return h;
	}
};
		
}

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

		
class RingMembersMatchSet 
	: private std::unordered_set<RingMembersMatch>
{
	public:
	using std::unordered_set<RingMembersMatch>::insert;
	using std::unordered_set<RingMembersMatch>::clear;
	using std::unordered_set<RingMembersMatch>::empty;
	using std::unordered_set<RingMembersMatch>::size;
	using std::unordered_set<RingMembersMatch>::begin;
	using std::unordered_set<RingMembersMatch>::end;
	
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_RingMembersMatchSet pbMsgSet;
		pbMsgSet.ParseFromString(serialized_data);
		
		RingMembersMatch match;
		for (auto & pbMatch : pbMsgSet.matches())
		{
			match.C1 = (pbMatch.c1() == -1) 
				? nullptr 
				: dynamic_cast<::arch::ICL*>(mr->findModelElementByID(pbMatch.c1()));
			
			
			action(match);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_RingMembersMatchSet pbMatchSet;
		
		for(auto& storedMatch: *this){
			auto & pbMatch = *pbMatchSet.add_matches();
			pbMatch.set_c1(storedMatch.C1 == nullptr ? -1 : storedMatch.C1->id());
		}
		return pbMatchSet.SerializeAsString();
	}
	
};

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__RING_MEMBERS_MATCH_H_ */
