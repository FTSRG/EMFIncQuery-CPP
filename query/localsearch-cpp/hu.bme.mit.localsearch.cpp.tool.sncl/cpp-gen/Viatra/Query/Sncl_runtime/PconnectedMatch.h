#ifndef VIATRA__QUERY__SNCL_RUNTIME__PCONNECTED_MATCH_H_
#define VIATRA__QUERY__SNCL_RUNTIME__PCONNECTED_MATCH_H_

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

class PconnectedMatchSet;

struct PconnectedMatch {
	
	using MatchSet = PconnectedMatchSet;
	
	::arch::ICL* C1;
	::arch::ICL* C2;
	
	bool operator==(const PconnectedMatch& other) const {
		return 
			C1 == other.C1&&
			C2 == other.C2
		;
	}
	
	// Serialization and deserialization
	
	std::string SerializeAsString()
	{
		PB_PconnectedMatch pbMatch;
		
		pbMatch.set_c1(C1 == nullptr ? -1 : C1->id());
		pbMatch.set_c2(C2 == nullptr ? -1 : C2->id());
		
		return pbMatch.SerializeAsString();
	}
	
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_PconnectedMatch pbMatch;
		pbMatch.ParseFromString(str);
			
		C1 = (pbMatch.c1() == -1) 
			? nullptr 
			: dynamic_cast<::arch::ICL*>(mr->findModelElementByID(pbMatch.c1()));
		
		C2 = (pbMatch.c2() == -1) 
			? nullptr 
			: dynamic_cast<::arch::ICL*>(mr->findModelElementByID(pbMatch.c2()));
		
	}
	
	// toString
	
	std::string toString() const
	{
		std::string ret = "[";
		ret += "C1=";
		ret += (C1 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(C1->id()));
		ret += ",C2=";
		ret += (C2 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(C2->id()));
	
		return ret + ']';
	}
};

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Sncl_runtime::PconnectedMatch> {
	size_t operator()(const ::Viatra::Query::Sncl_runtime::PconnectedMatch& match) const {
		size_t h = 0;
		h+=std::hash<decltype(match.C1)>()(match.C1);
		h*=31;
		h+=std::hash<decltype(match.C2)>()(match.C2);
		return h;
	}
};
		
}

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

		
class PconnectedMatchSet 
	: private std::unordered_set<PconnectedMatch>
{
	public:
	using std::unordered_set<PconnectedMatch>::insert;
	using std::unordered_set<PconnectedMatch>::clear;
	using std::unordered_set<PconnectedMatch>::empty;
	using std::unordered_set<PconnectedMatch>::size;
	using std::unordered_set<PconnectedMatch>::begin;
	using std::unordered_set<PconnectedMatch>::end;
	
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_PconnectedMatchSet pbMsgSet;
		pbMsgSet.ParseFromString(serialized_data);
		
		PconnectedMatch match;
		for (auto & pbMatch : pbMsgSet.matches())
		{
			match.C1 = (pbMatch.c1() == -1) 
				? nullptr 
				: dynamic_cast<::arch::ICL*>(mr->findModelElementByID(pbMatch.c1()));
			
			match.C2 = (pbMatch.c2() == -1) 
				? nullptr 
				: dynamic_cast<::arch::ICL*>(mr->findModelElementByID(pbMatch.c2()));
			
			
			action(match);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_PconnectedMatchSet pbMatchSet;
		
		for(auto& storedMatch: *this){
			auto & pbMatch = *pbMatchSet.add_matches();
			pbMatch.set_c1(storedMatch.C1 == nullptr ? -1 : storedMatch.C1->id());
			pbMatch.set_c2(storedMatch.C2 == nullptr ? -1 : storedMatch.C2->id());
		}
		return pbMatchSet.SerializeAsString();
	}
	
};

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__PCONNECTED_MATCH_H_ */
