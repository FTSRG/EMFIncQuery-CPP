#ifndef VIATRA__QUERY__SAFETYLOGIC__VIABLE_PATHS_MATCH_H_
#define VIATRA__QUERY__SAFETYLOGIC__VIABLE_PATHS_MATCH_H_

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

class ViablePathsMatchSet;

struct ViablePathsMatch {
	
	using MatchSet = ViablePathsMatchSet;
	
	::railRoadModel::ITurnout* This;
	::railRoadModel::IPath* path;
	
	bool operator==(const ViablePathsMatch& other) const {
		return 
			This == other.This&&
			path == other.path
		;
	}
	
	// Serialization and deserialization
	
	std::string SerializeAsString()
	{
		PB_ViablePathsMatch pbMatch;
		
		pbMatch.set_this(This == nullptr ? -1 : This->id());
		pbMatch.set_path(path == nullptr ? -1 : path->id());
		
		return pbMatch.SerializeAsString();
	}
	
	template<typename ModelRoot>
	void ParseFromString(std::string str, ModelRoot *mr)
	{
		PB_ViablePathsMatch pbMatch;
		pbMatch.ParseFromString(str);
			
		This = (pbMatch.this() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::ITurnout*>(mr->findModelElementByID(pbMatch.this()));
		
		path = (pbMatch.path() == -1) 
			? nullptr 
			: dynamic_cast<::railRoadModel::IPath*>(mr->findModelElementByID(pbMatch.path()));
		
	}
	
	// toString
	
	std::string toString() const
	{
		std::string ret = "[";
		ret += "This=";
		ret += (This == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(This->id()));
		ret += ",path=";
		ret += (path == nullptr ? "null" : Viatra::Query::Util::Convert::ToString(path->id()));
	
		return ret + ']';
	}
};

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Safetylogic::ViablePathsMatch> {
	size_t operator()(const ::Viatra::Query::Safetylogic::ViablePathsMatch& match) const {
		size_t h = 0;
		h+=std::hash<decltype(match.This)>()(match.This);
		h*=31;
		h+=std::hash<decltype(match.path)>()(match.path);
		return h;
	}
};
		
}

namespace Viatra {
namespace Query {
namespace Safetylogic {

		
class ViablePathsMatchSet 
	: private std::unordered_set<ViablePathsMatch>
{
	public:
	using std::unordered_set<ViablePathsMatch>::insert;
	using std::unordered_set<ViablePathsMatch>::clear;
	using std::unordered_set<ViablePathsMatch>::empty;
	using std::unordered_set<ViablePathsMatch>::size;
	using std::unordered_set<ViablePathsMatch>::begin;
	using std::unordered_set<ViablePathsMatch>::end;
	
	
	// Serialization and deserialization
	
	template<typename ModelRoot, typename Action>
	static void ParseFromStringCallback( const std::string& serialized_data, ModelRoot * mr, Action action )
	{
		PB_ViablePathsMatchSet pbMsgSet;
		pbMsgSet.ParseFromString(serialized_data);
		
		ViablePathsMatch match;
		for (auto & pbMatch : pbMsgSet.matches())
		{
			match.This = (pbMatch.this() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::ITurnout*>(mr->findModelElementByID(pbMatch.this()));
			
			match.path = (pbMatch.path() == -1) 
				? nullptr 
				: dynamic_cast<::railRoadModel::IPath*>(mr->findModelElementByID(pbMatch.path()));
			
			
			action(match);
		}
	}
	
	std::string SerializeAsString()
	{
		PB_ViablePathsMatchSet pbMatchSet;
		
		for(auto& storedMatch: *this){
			auto & pbMatch = *pbMatchSet.add_matches();
			pbMatch.set_this(storedMatch.This == nullptr ? -1 : storedMatch.This->id());
			pbMatch.set_path(storedMatch.path == nullptr ? -1 : storedMatch.path->id());
		}
		return pbMatchSet.SerializeAsString();
	}
	
};

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__VIABLE_PATHS_MATCH_H_ */
