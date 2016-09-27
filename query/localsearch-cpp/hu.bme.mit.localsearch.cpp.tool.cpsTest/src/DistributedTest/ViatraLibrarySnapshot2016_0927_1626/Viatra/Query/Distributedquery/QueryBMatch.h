#ifndef VIATRA__QUERY__DISTRIBUTEDQUERY__QUERY_B_MATCH_H_
#define VIATRA__QUERY__DISTRIBUTEDQUERY__QUERY_B_MATCH_H_

#include <Viatra/Query/Model/ModelRoot.h>
#include <stdint.h>
		
#include "cyberPhysicalSystem/ApplicationInstance.h"
#include "cyberPhysicalSystem/HostInstance.h"
#include "proto_gen.pb.h"

namespace Viatra {
namespace Query {
namespace Distributedquery {

struct QueryBMatch {
	
	::cyberPhysicalSystem::IApplicationInstance* a1;
	::cyberPhysicalSystem::IHostInstance* h1;
	
	bool operator==(const QueryBMatch& other) const {
		return 
			a1 == other.a1&&
			h1 == other.h1
		;
	}
	
		// Serialization and deserialization
				
		std::string SerializeAsString()
		{
			PB_QueryBMatch pbframe;
			
			pbframe.set_a1(a1 == nullptr ? -1 : a1->id());
			pbframe.set_h1(h1 == nullptr ? -1 : h1->id());
	
			return pbframe.SerializeAsString();
		}
	
		void ParseFromString(std::string str, Viatra::Query::Model::ModelRoot *mr)
		{
			PB_QueryBMatch pbframe;
			pbframe.ParseFromString(str);
	
			a1 = (pbframe.a1() == -1) 
				? nullptr 
				: dynamic_cast<::cyberPhysicalSystem::IApplicationInstance*>(mr->findModelElementByID(pbframe.a1()));
			
			h1 = (pbframe.h1() == -1) 
				? nullptr 
				: dynamic_cast<::cyberPhysicalSystem::IHostInstance*>(mr->findModelElementByID(pbframe.h1()));
			
		}
};		

} /* namespace Distributedquery */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Distributedquery::QueryBMatch> {
	size_t operator()(const ::Viatra::Query::Distributedquery::QueryBMatch& match) const {
		size_t h = 0;
		h+=std::hash<decltype(match.a1)>()(match.a1);
		h*=31;
		h+=std::hash<decltype(match.h1)>()(match.h1);
		return h;
	}
};
		
}

#endif /*  VIATRA__QUERY__DISTRIBUTEDQUERY__QUERY_B_MATCH_H_ */
