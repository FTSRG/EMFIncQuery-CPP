#ifndef VIATRA__QUERY__SNCL_RUNTIME__NUM_EQUALITY_WITH_MEMBER_MATCH_H_
#define VIATRA__QUERY__SNCL_RUNTIME__NUM_EQUALITY_WITH_MEMBER_MATCH_H_

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

class NumEqualityWithMemberMatchSet;

struct NumEqualityWithMemberMatch {
	
	using MatchSet = NumEqualityWithMemberMatchSet;
	
	::arch::ICL* C1;
	
	bool operator==(const NumEqualityWithMemberMatch& other) const {
		return 
			C1 == other.C1
		;
	}
	
	// Serialization and deserialization
	
	std::string SerializeAsString()
	{
		PB_NumEqualityWithMemberMatch pbMatch;
		
		pbMatch.set_c1(C1 == nullptr ? -1 : C1->id());
		
		return pbMatch.SerializeAsString();
	}
	
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_NumEqualityWithMemberMatch pbMatch;
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

template<> struct hash<::Viatra::Query::Sncl_runtime::NumEqualityWithMemberMatch> {
	size_t operator()(const ::Viatra::Query::Sncl_runtime::NumEqualityWithMemberMatch& match) const {
		size_t h = 0;
		h+=std::hash<decltype(match.C1)>()(match.C1);
		return h;
	}
};
		
}

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

		
class NumEqualityWithMemberMatchSet 
	: private std::unordered_set<NumEqualityWithMemberMatch>
{
	public:
	using std::unordered_set<NumEqualityWithMemberMatch>::insert;
	using std::unordered_set<NumEqualityWithMemberMatch>::clear;
	using std::unordered_set<NumEqualityWithMemberMatch>::empty;
	using std::unordered_set<NumEqualityWithMemberMatch>::size;
	using std::unordered_set<NumEqualityWithMemberMatch>::begin;
	using std::unordered_set<NumEqualityWithMemberMatch>::end;
	
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_NumEqualityWithMemberMatchSet pbMsgSet;
		pbMsgSet.ParseFromString(serialized_data);
		
		NumEqualityWithMemberMatch match;
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
		PB_NumEqualityWithMemberMatchSet pbMatchSet;
		
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


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__NUM_EQUALITY_WITH_MEMBER_MATCH_H_ */
