#ifndef VIATRA__QUERY__DISTRIBUTEDQUERY__QUERY_B_FRAME_0_H_
#define VIATRA__QUERY__DISTRIBUTEDQUERY__QUERY_B_FRAME_0_H_

#include <Viatra/Query/Model/ModelRoot.h>
#include <stdint.h>
		
#include "cyberPhysicalSystem/ApplicationInstance.h"
#include "cyberPhysicalSystem/HostInstance.h"
#include "proto_gen.pb.h"

namespace Viatra {
namespace Query {
namespace Distributedquery {

struct QueryBFrame_0 {
	
	::cyberPhysicalSystem::IApplicationInstance* _0;
	::cyberPhysicalSystem::IHostInstance* _1;

	// Serialization and deserialization
	
	std::string SerializeAsString()
	{
		PB_QueryBFrame_0 pbframe;
		
		pbframe.set__0(_0 == nullptr ? -1 : _0->id());
		pbframe.set__1(_1 == nullptr ? -1 : _1->id());

		return pbframe.SerializeAsString();
	}

	void ParseFromString(std::string str, Viatra::Query::Model::ModelRoot *mr)
	{
		PB_QueryBFrame_0 pbframe;
		pbframe.ParseFromString(str);

		_0 = (pbframe._0() == -1) 
			? nullptr 
			: dynamic_cast<::cyberPhysicalSystem::IApplicationInstance*>(mr->findModelElementByID(pbframe._0()));
		
		_1 = (pbframe._1() == -1) 
			? nullptr 
			: dynamic_cast<::cyberPhysicalSystem::IHostInstance*>(mr->findModelElementByID(pbframe._1()));
		
	}
};

} /* namespace Distributedquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DISTRIBUTEDQUERY__QUERY_B_FRAME_0_H_ */
