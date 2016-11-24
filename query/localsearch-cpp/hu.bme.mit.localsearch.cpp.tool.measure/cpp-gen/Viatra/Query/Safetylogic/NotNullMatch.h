#ifndef VIATRA__QUERY__SAFETYLOGIC__NOT_NULL_MATCH_H_
#define VIATRA__QUERY__SAFETYLOGIC__NOT_NULL_MATCH_H_

#include <stdint.h>
#include <unordered_set>
		
#include "PB_safetylogic.pb.h"
#include "Viatra/Query/MatchSet.h"
#include "Viatra/Query/Util/Convert.h"
#include "railRoadModel/RailRoadElement.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {

class NotNullMatchSet;

struct NotNullMatch {
	
	using MatchSet = NotNullMatchSet;
	
	::railRoadModel::IRailRoadElement* Old;
	
	bool operator==(const NotNullMatch& other) const {
		return 
			Old == other.Old
		;
	}
	
	// Serialization and deserialization
	
	std::string SerializeAsString()
	{
		PB_NotNullMatch pbMatch;
		
		pbMatch.set_old(Old == nullptr ? -1 : Old->id());
		
		return pbMatch.SerializeAsString();
	}
	
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_NotNullMatch pbMatch;
		pbMatch.ParseFromString(str);
			
		Old = (pbMatch.old() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::IRailRoadElement*>(mr->findModelElementByID(pbMatch.old()));
		
	}
	
	// toString
	
	std::string toString() const
	{
		std::string ret = "[";
		ret += "Old=";
		ret += (Old == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(Old->id()));
	
		return ret + ']';
	}
};

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Safetylogic::NotNullMatch> {
	size_t operator()(const ::Viatra::Query::Safetylogic::NotNullMatch& match) const {
		size_t h = 0;
		h+=std::hash<decltype(match.Old)>()(match.Old);
		return h;
	}
};
		
}

namespace Viatra {
namespace Query {
namespace Safetylogic {

		
class NotNullMatchSet 
	: private std::unordered_set<NotNullMatch>
{
	public:
	using std::unordered_set<NotNullMatch>::insert;
	using std::unordered_set<NotNullMatch>::clear;
	using std::unordered_set<NotNullMatch>::empty;
	using std::unordered_set<NotNullMatch>::size;
	using std::unordered_set<NotNullMatch>::begin;
	using std::unordered_set<NotNullMatch>::end;
	
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_NotNullMatchSet pbMsgSet;
		pbMsgSet.ParseFromString(serialized_data);
		
		NotNullMatch match;
		for (auto & pbMatch : pbMsgSet.matches())
		{
			match.Old = (pbMatch.old() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::IRailRoadElement*>(mr->findModelElementByID(pbMatch.old()));
			
			
			action(match);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_NotNullMatchSet pbMatchSet;
		
		for(auto& storedMatch: *this){
			auto & pbMatch = *pbMatchSet.add_matches();
			pbMatch.set_old(storedMatch.Old == nullptr ? -1 : storedMatch.Old->id());
		}
		return pbMatchSet.SerializeAsString();
	}
	
};

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__NOT_NULL_MATCH_H_ */
