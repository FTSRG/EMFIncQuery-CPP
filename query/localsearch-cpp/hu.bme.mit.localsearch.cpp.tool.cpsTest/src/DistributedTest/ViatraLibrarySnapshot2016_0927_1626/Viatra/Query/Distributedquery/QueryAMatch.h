#ifndef VIATRA__QUERY__DISTRIBUTEDQUERY__QUERY_A_MATCH_H_
#define VIATRA__QUERY__DISTRIBUTEDQUERY__QUERY_A_MATCH_H_

#include <Viatra/Query/Model/ModelRoot.h>
#include <stdint.h>
#include <string>
		
#include "cyberPhysicalSystem/ApplicationInstance.h"
#include "cyberPhysicalSystem/HostInstance.h"
#include "proto_gen.pb.h"

namespace Viatra {
namespace Query {
namespace Distributedquery {

struct QueryAMatch {
	
	::cyberPhysicalSystem::IHostInstance* h1;
	::std::string pw;
	::cyberPhysicalSystem::AppState state;
	
	bool operator==(const QueryAMatch& other) const {
		return 
			h1 == other.h1&&
			pw == other.pw&&
			state == other.state
		;
	}
	
		// Serialization and deserialization
				
		std::string SerializeAsString()
		{
			PB_QueryAMatch pbframe;
			
			pbframe.set_h1(h1 == nullptr ? -1 : h1->id());
			pbframe.set_pw(pw);
			pbframe.set_state((int32_t)state);
	
			return pbframe.SerializeAsString();
		}
	
		void ParseFromString(std::string str, Viatra::Query::Model::ModelRoot *mr)
		{
			PB_QueryAMatch pbframe;
			pbframe.ParseFromString(str);
	
			h1 = (pbframe.h1() == -1) 
				? nullptr 
				: dynamic_cast<::cyberPhysicalSystem::IHostInstance*>(mr->findModelElementByID(pbframe.h1()));
			
			pw = pbframe.pw();
			
			state = (::cyberPhysicalSystem::AppState)pbframe.state();
			
		}
};		

} /* namespace Distributedquery */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Distributedquery::QueryAMatch> {
	size_t operator()(const ::Viatra::Query::Distributedquery::QueryAMatch& match) const {
		size_t h = 0;
		h+=std::hash<decltype(match.h1)>()(match.h1);
		h*=31;
		h+=std::hash<decltype(match.pw)>()(match.pw);
		h*=31;
		h+=match.state;
		return h;
	}
};
		
}

#endif /*  VIATRA__QUERY__DISTRIBUTEDQUERY__QUERY_A_MATCH_H_ */
