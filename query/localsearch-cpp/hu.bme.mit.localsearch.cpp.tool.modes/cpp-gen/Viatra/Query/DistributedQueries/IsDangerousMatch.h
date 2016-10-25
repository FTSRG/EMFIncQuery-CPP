#ifndef VIATRA__QUERY__DISTRIBUTED_QUERIES__IS_DANGEROUS_MATCH_H_
#define VIATRA__QUERY__DISTRIBUTED_QUERIES__IS_DANGEROUS_MATCH_H_

#include <stdint.h>
#include <unordered_set>
		
#include "PB_DistributedQueries.pb.h"
#include "Viatra/Query/MatchSet.h"
#include "Viatra/Query/Util/Convert.h"
#include "railRoadModel/Frozen.h"
#include "railRoadModel/Segment.h"
#include "railRoadModel/Train.h"
#include "railRoadModel/Turnout.h"

namespace Viatra {
namespace Query {
namespace DistributedQueries {

class IsDangerousMatchSet;

struct IsDangerousMatch {
	
	using MatchSet = IsDangerousMatchSet;
	
	::railRoadModel::ISegment* segment;
	::railRoadModel::ITurnout* turnout;
	::railRoadModel::ITrain* train;
	
	bool operator==(const IsDangerousMatch& other) const {
		return 
			segment == other.segment&&
			turnout == other.turnout&&
			train == other.train
		;
	}
	
	// Serialization and deserialization
	
	std::string SerializeAsString()
	{
		PB_IsDangerousMatch pbMatch;
		
		pbMatch.set_segment(segment == nullptr ? -1 : segment->id());
		pbMatch.set_turnout(turnout == nullptr ? -1 : turnout->id());
		pbMatch.set_train(train == nullptr ? -1 : train->id());
		
		return pbMatch.SerializeAsString();
	}
	
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_IsDangerousMatch pbMatch;
		pbMatch.ParseFromString(str);
			
		segment = (pbMatch.segment() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::ISegment*>(mr->findModelElementByID(pbMatch.segment()));
		
		turnout = (pbMatch.turnout() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::ITurnout*>(mr->findModelElementByID(pbMatch.turnout()));
		
		train = (pbMatch.train() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::ITrain*>(mr->findModelElementByID(pbMatch.train()));
		
	}
	
	// toString
	
	std::string toString() const
	{
		std::string ret = "[";
		ret += "segment=";
		ret += (segment == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(segment->id()));
		ret += ",turnout=";
		ret += (turnout == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(turnout->id()));
		ret += ",train=";
		ret += (train == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(train->id()));
	
		return ret + ']';
	}
};

} /* namespace DistributedQueries */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::DistributedQueries::IsDangerousMatch> {
	size_t operator()(const ::Viatra::Query::DistributedQueries::IsDangerousMatch& match) const {
		size_t h = 0;
		h+=std::hash<decltype(match.segment)>()(match.segment);
		h*=31;
		h+=std::hash<decltype(match.turnout)>()(match.turnout);
		h*=31;
		h+=std::hash<decltype(match.train)>()(match.train);
		return h;
	}
};
		
}

namespace Viatra {
namespace Query {
namespace DistributedQueries {

		
class IsDangerousMatchSet 
	: private std::unordered_set<IsDangerousMatch>
{
	public:
	using std::unordered_set<IsDangerousMatch>::insert;
	using std::unordered_set<IsDangerousMatch>::clear;
	using std::unordered_set<IsDangerousMatch>::empty;
	using std::unordered_set<IsDangerousMatch>::size;
	using std::unordered_set<IsDangerousMatch>::begin;
	using std::unordered_set<IsDangerousMatch>::end;
	
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_IsDangerousMatchSet pbMsgSet;
		pbMsgSet.ParseFromString(serialized_data);
		
		IsDangerousMatch match;
		for (auto & pbMatch : pbMsgSet.matches())
		{
			match.segment = (pbMatch.segment() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::ISegment*>(mr->findModelElementByID(pbMatch.segment()));
			
			match.turnout = (pbMatch.turnout() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::ITurnout*>(mr->findModelElementByID(pbMatch.turnout()));
			
			match.train = (pbMatch.train() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::ITrain*>(mr->findModelElementByID(pbMatch.train()));
			
			
			action(match);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_IsDangerousMatchSet pbMatchSet;
		
		for(auto& storedMatch: *this){
			auto & pbMatch = *pbMatchSet.add_matches();
			pbMatch.set_segment(storedMatch.segment == nullptr ? -1 : storedMatch.segment->id());
			pbMatch.set_turnout(storedMatch.turnout == nullptr ? -1 : storedMatch.turnout->id());
			pbMatch.set_train(storedMatch.train == nullptr ? -1 : storedMatch.train->id());
		}
		return pbMatchSet.SerializeAsString();
	}
	
};

} /* namespace DistributedQueries */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DISTRIBUTED_QUERIES__IS_DANGEROUS_MATCH_H_ */
