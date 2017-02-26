#ifndef VIATRA__QUERY__DISTRIBUTED_QUERIES__SHOULD_COLLIDE_MATCH_H_
#define VIATRA__QUERY__DISTRIBUTED_QUERIES__SHOULD_COLLIDE_MATCH_H_

#include <stdint.h>
#include <unordered_set>
		
#include "PB_DistributedQueries.pb.h"
#include "Viatra/Query/MatchSet.h"
#include "Viatra/Query/Util/Convert.h"
#include "railRoadModel/RobotPart.h"
#include "railRoadModel/Train.h"

namespace Viatra {
namespace Query {
namespace DistributedQueries {

class ShouldCollideMatchSet;

struct ShouldCollideMatch {
	
	using MatchSet = ShouldCollideMatchSet;
	
	::railRoadModel::IRobotPart* rp;
	::railRoadModel::ITrain* tr;
	
	bool operator==(const ShouldCollideMatch& other) const {
		return 
			rp == other.rp&&
			tr == other.tr
		;
	}
	
	// Serialization and deserialization
	
	std::string SerializeAsString()
	{
		PB_ShouldCollideMatch pbMatch;
		
		pbMatch.set_rp(rp == nullptr ? -1 : rp->id());
		pbMatch.set_tr(tr == nullptr ? -1 : tr->id());
		
		return pbMatch.SerializeAsString();
	}
	
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_ShouldCollideMatch pbMatch;
		pbMatch.ParseFromString(str);
			
		rp = (pbMatch.rp() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::IRobotPart*>(mr->findModelElementByID(pbMatch.rp()));
		
		tr = (pbMatch.tr() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::ITrain*>(mr->findModelElementByID(pbMatch.tr()));
		
	}
	
	// toString
	
	std::string toString() const
	{
		std::string ret = "[";
		ret += "rp=";
		ret += (rp == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(rp->id()));
		ret += ",tr=";
		ret += (tr == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(tr->id()));
	
		return ret + ']';
	}
};

} /* namespace DistributedQueries */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::DistributedQueries::ShouldCollideMatch> {
	size_t operator()(const ::Viatra::Query::DistributedQueries::ShouldCollideMatch& match) const {
		size_t h = 0;
		h+=std::hash<decltype(match.rp)>()(match.rp);
		h*=31;
		h+=std::hash<decltype(match.tr)>()(match.tr);
		return h;
	}
};
		
}

namespace Viatra {
namespace Query {
namespace DistributedQueries {

		
class ShouldCollideMatchSet 
	: private std::unordered_set<ShouldCollideMatch>
{
	public:
	using std::unordered_set<ShouldCollideMatch>::insert;
	using std::unordered_set<ShouldCollideMatch>::clear;
	using std::unordered_set<ShouldCollideMatch>::empty;
	using std::unordered_set<ShouldCollideMatch>::size;
	using std::unordered_set<ShouldCollideMatch>::begin;
	using std::unordered_set<ShouldCollideMatch>::end;
	
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_ShouldCollideMatchSet pbMsgSet;
		pbMsgSet.ParseFromString(serialized_data);
		
		ShouldCollideMatch match;
		for (auto & pbMatch : pbMsgSet.matches())
		{
			match.rp = (pbMatch.rp() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::IRobotPart*>(mr->findModelElementByID(pbMatch.rp()));
			
			match.tr = (pbMatch.tr() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::ITrain*>(mr->findModelElementByID(pbMatch.tr()));
			
			
			action(match);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_ShouldCollideMatchSet pbMatchSet;
		
		for(auto& storedMatch: *this){
			auto & pbMatch = *pbMatchSet.add_matches();
			pbMatch.set_rp(storedMatch.rp == nullptr ? -1 : storedMatch.rp->id());
			pbMatch.set_tr(storedMatch.tr == nullptr ? -1 : storedMatch.tr->id());
		}
		return pbMatchSet.SerializeAsString();
	}
	
};

} /* namespace DistributedQueries */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DISTRIBUTED_QUERIES__SHOULD_COLLIDE_MATCH_H_ */