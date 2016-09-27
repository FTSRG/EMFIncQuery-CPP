#ifndef VIATRA__QUERY__DISTRIBUTEDQUERY__QUERY_A_FRAME_0_H_
#define VIATRA__QUERY__DISTRIBUTEDQUERY__QUERY_A_FRAME_0_H_

#include <Viatra/Query/Model/ModelRoot.h>
#include <stdint.h>
#include <string>
		
#include "cyberPhysicalSystem/ApplicationInstance.h"
#include "cyberPhysicalSystem/HostInstance.h"
#include "proto_gen.pb.h"

namespace Viatra {
namespace Query {
namespace Distributedquery {

struct QueryAFrame_0 {
	
	::cyberPhysicalSystem::IHostInstance* _0;
	::std::string _1;
	::cyberPhysicalSystem::AppState _2;
	::cyberPhysicalSystem::IHostInstance* _3;
	::cyberPhysicalSystem::IApplicationInstance* _4;
	::cyberPhysicalSystem::IApplicationInstance* _5;

	// Serialization and deserialization
	
	std::string SerializeAsString()
	{
		PB_QueryAFrame_0 pbframe;
		
		pbframe.set__0(_0 == nullptr ? -1 : _0->id());
		pbframe.set__1(_1);
		pbframe.set__2((int32_t)_2);
		pbframe.set__3(_3 == nullptr ? -1 : _3->id());
		pbframe.set__4(_4 == nullptr ? -1 : _4->id());
		pbframe.set__5(_5 == nullptr ? -1 : _5->id());

		return pbframe.SerializeAsString();
	}

	void ParseFromString(std::string str, Viatra::Query::Model::ModelRoot *mr)
	{
		PB_QueryAFrame_0 pbframe;
		pbframe.ParseFromString(str);

		_0 = (pbframe._0() == -1) 
			? nullptr 
			: dynamic_cast<::cyberPhysicalSystem::IHostInstance*>(mr->findModelElementByID(pbframe._0()));
		
		_1 = pbframe._1();
		
		_2 = (::cyberPhysicalSystem::AppState)pbframe._2();
		
		_3 = (pbframe._3() == -1) 
			? nullptr 
			: dynamic_cast<::cyberPhysicalSystem::IHostInstance*>(mr->findModelElementByID(pbframe._3()));
		
		_4 = (pbframe._4() == -1) 
			? nullptr 
			: dynamic_cast<::cyberPhysicalSystem::IApplicationInstance*>(mr->findModelElementByID(pbframe._4()));
		
		_5 = (pbframe._5() == -1) 
			? nullptr 
			: dynamic_cast<::cyberPhysicalSystem::IApplicationInstance*>(mr->findModelElementByID(pbframe._5()));
		
	}
};

} /* namespace Distributedquery */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DISTRIBUTEDQUERY__QUERY_A_FRAME_0_H_ */
