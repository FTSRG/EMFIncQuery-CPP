#ifndef VIATRA__QUERY__SNCL_RUNTIME__COUNT_LINKS_MATCH_H_
#define VIATRA__QUERY__SNCL_RUNTIME__COUNT_LINKS_MATCH_H_

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

class CountLinksMatchSet;

struct CountLinksMatch {
	
	using MatchSet = CountLinksMatchSet;
	
	::arch::ICL* C1;
	int numOfSN;
	int numOfCL;
	
	bool operator==(const CountLinksMatch& other) const {
		return 
			C1 == other.C1&&
			numOfSN == other.numOfSN&&
			numOfCL == other.numOfCL
		;
	}
	
	// Serialization and deserialization
	
	std::string SerializeAsString()
	{
		PB_CountLinksMatch pbMatch;
		
		pbMatch.set_c1(C1 == nullptr ? -1 : C1->id());
		pbMatch.set_numofsn(numOfSN);
		pbMatch.set_numofcl(numOfCL);
		
		return pbMatch.SerializeAsString();
	}
	
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_CountLinksMatch pbMatch;
		pbMatch.ParseFromString(str);
			
		C1 = (pbMatch.c1() == -1) 
			? nullptr 
			: dynamic_cast<::arch::ICL*>(mr->findModelElementByID(pbMatch.c1()));
		
		numOfSN = pbMatch.numofsn();
		
		numOfCL = pbMatch.numofcl();
		
	}
	
	// toString
	
	std::string toString() const
	{
		std::string ret = "[";
		ret += "C1=";
		ret += (C1 == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(C1->id()));
		ret += ",numOfSN=";
		ret += Viatra::Query::Util::Convert::ToString(numOfSN);
		ret += ",numOfCL=";
		ret += Viatra::Query::Util::Convert::ToString(numOfCL);
	
		return ret + ']';
	}
};

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Sncl_runtime::CountLinksMatch> {
	size_t operator()(const ::Viatra::Query::Sncl_runtime::CountLinksMatch& match) const {
		size_t h = 0;
		h+=std::hash<decltype(match.C1)>()(match.C1);
		h*=31;
		h+=std::hash<decltype(match.numOfSN)>()(match.numOfSN);
		h*=31;
		h+=std::hash<decltype(match.numOfCL)>()(match.numOfCL);
		return h;
	}
};
		
}

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

		
class CountLinksMatchSet 
	: private std::unordered_set<CountLinksMatch>
{
	public:
	using std::unordered_set<CountLinksMatch>::insert;
	using std::unordered_set<CountLinksMatch>::clear;
	using std::unordered_set<CountLinksMatch>::empty;
	using std::unordered_set<CountLinksMatch>::size;
	using std::unordered_set<CountLinksMatch>::begin;
	using std::unordered_set<CountLinksMatch>::end;
	
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_CountLinksMatchSet pbMsgSet;
		pbMsgSet.ParseFromString(serialized_data);
		
		CountLinksMatch match;
		for (auto & pbMatch : pbMsgSet.matches())
		{
			match.C1 = (pbMatch.c1() == -1) 
				? nullptr 
				: dynamic_cast<::arch::ICL*>(mr->findModelElementByID(pbMatch.c1()));
			
			match.numOfSN = pbMatch.numofsn();
			
			match.numOfCL = pbMatch.numofcl();
			
			
			action(match);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_CountLinksMatchSet pbMatchSet;
		
		for(auto& storedMatch: *this){
			auto & pbMatch = *pbMatchSet.add_matches();
			pbMatch.set_c1(storedMatch.C1 == nullptr ? -1 : storedMatch.C1->id());
			pbMatch.set_numofsn(storedMatch.numOfSN);
			pbMatch.set_numofcl(storedMatch.numOfCL);
		}
		return pbMatchSet.SerializeAsString();
	}
	
};

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__COUNT_LINKS_MATCH_H_ */
