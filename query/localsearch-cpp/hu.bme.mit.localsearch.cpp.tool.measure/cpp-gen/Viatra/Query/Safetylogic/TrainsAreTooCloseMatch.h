#ifndef VIATRA__QUERY__SAFETYLOGIC__TRAINS_ARE_TOO_CLOSE_MATCH_H_
#define VIATRA__QUERY__SAFETYLOGIC__TRAINS_ARE_TOO_CLOSE_MATCH_H_

#include <stdint.h>
#include <unordered_set>
		
#include "PB_safetylogic.pb.h"
#include "Viatra/Query/MatchSet.h"
#include "Viatra/Query/Util/Convert.h"
#include "railRoadModel/RailRoadElement.h"
#include "railRoadModel/Segment.h"
#include "railRoadModel/Train.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {

class TrainsAreTooCloseMatchSet;

struct TrainsAreTooCloseMatch {
	
	using MatchSet = TrainsAreTooCloseMatchSet;
	
	::railRoadModel::ITrain* Offender;
	::railRoadModel::ITrain* Victim;
	
	bool operator==(const TrainsAreTooCloseMatch& other) const {
		return 
			Offender == other.Offender&&
			Victim == other.Victim
		;
	}
	
	// Serialization and deserialization
	
	std::string SerializeAsString()
	{
		PB_TrainsAreTooCloseMatch pbMatch;
		
		pbMatch.set_offender(Offender == nullptr ? -1 : Offender->id());
		pbMatch.set_victim(Victim == nullptr ? -1 : Victim->id());
		
		return pbMatch.SerializeAsString();
	}
	
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_TrainsAreTooCloseMatch pbMatch;
		pbMatch.ParseFromString(str);
			
		Offender = (pbMatch.offender() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::ITrain*>(mr->findModelElementByID(pbMatch.offender()));
		
		Victim = (pbMatch.victim() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::ITrain*>(mr->findModelElementByID(pbMatch.victim()));
		
	}
	
	// toString
	
	std::string toString() const
	{
		std::string ret = "[";
		ret += "Offender=";
		ret += (Offender == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(Offender->id()));
		ret += ",Victim=";
		ret += (Victim == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(Victim->id()));
	
		return ret + ']';
	}
};

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Safetylogic::TrainsAreTooCloseMatch> {
	size_t operator()(const ::Viatra::Query::Safetylogic::TrainsAreTooCloseMatch& match) const {
		size_t h = 0;
		h+=std::hash<decltype(match.Offender)>()(match.Offender);
		h*=31;
		h+=std::hash<decltype(match.Victim)>()(match.Victim);
		return h;
	}
};
		
}

namespace Viatra {
namespace Query {
namespace Safetylogic {

		
class TrainsAreTooCloseMatchSet 
	: private std::unordered_set<TrainsAreTooCloseMatch>
{
	public:
	using std::unordered_set<TrainsAreTooCloseMatch>::insert;
	using std::unordered_set<TrainsAreTooCloseMatch>::clear;
	using std::unordered_set<TrainsAreTooCloseMatch>::empty;
	using std::unordered_set<TrainsAreTooCloseMatch>::size;
	using std::unordered_set<TrainsAreTooCloseMatch>::begin;
	using std::unordered_set<TrainsAreTooCloseMatch>::end;
	
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_TrainsAreTooCloseMatchSet pbMsgSet;
		pbMsgSet.ParseFromString(serialized_data);
		
		TrainsAreTooCloseMatch match;
		for (auto & pbMatch : pbMsgSet.matches())
		{
			match.Offender = (pbMatch.offender() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::ITrain*>(mr->findModelElementByID(pbMatch.offender()));
			
			match.Victim = (pbMatch.victim() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::ITrain*>(mr->findModelElementByID(pbMatch.victim()));
			
			
			action(match);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_TrainsAreTooCloseMatchSet pbMatchSet;
		
		for(auto& storedMatch: *this){
			auto & pbMatch = *pbMatchSet.add_matches();
			pbMatch.set_offender(storedMatch.Offender == nullptr ? -1 : storedMatch.Offender->id());
			pbMatch.set_victim(storedMatch.Victim == nullptr ? -1 : storedMatch.Victim->id());
		}
		return pbMatchSet.SerializeAsString();
	}
	
};

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__TRAINS_ARE_TOO_CLOSE_MATCH_H_ */
