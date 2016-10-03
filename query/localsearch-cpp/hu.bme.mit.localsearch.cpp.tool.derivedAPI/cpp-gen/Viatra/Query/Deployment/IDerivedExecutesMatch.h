#ifndef VIATRA__QUERY__DEPLOYMENT__I_DERIVED_EXECUTES_MATCH_H_
#define VIATRA__QUERY__DEPLOYMENT__I_DERIVED_EXECUTES_MATCH_H_

#include <stdint.h>
		
#include "PlatformModel/Node.h"
#include "RailRoadModel/Segment.h"
#include "RailRoadModel/Train.h"
#include "proto_gen.pb.h"

namespace Viatra {
namespace Query {
namespace Deployment {

struct IDerivedExecutesMatch {
	
	::PlatformModel::INode* node;
	int nodeID;
	::RailRoadModel::ITrain* train;
	int trainID;
	
	bool operator==(const IDerivedExecutesMatch& other) const {
		return 
			node == other.node&&
			nodeID == other.nodeID&&
			train == other.train&&
			trainID == other.trainID
		;
	}
	
		// Serialization and deserialization
	
		std::string SerializeAsString()
		{
			PB_IDerivedExecutesMatch pbframe;
			
			pbframe.set_node(node == nullptr ? -1 : node->id());
			pbframe.set_nodeid(nodeID);
			pbframe.set_train(train == nullptr ? -1 : train->id());
			pbframe.set_trainid(trainID);
	
			return pbframe.SerializeAsString();
		}
	
		template<typename ModelRoot>
		void ParseFromString(std::string str, ModelRoot *mr)
		{
			PB_IDerivedExecutesMatch pbframe;
			pbframe.ParseFromString(str);
	
			node = (pbframe.node() == -1) 
				? nullptr 
				: dynamic_cast<::PlatformModel::INode*>(mr->findModelElementByID(pbframe.node()));
			
			nodeID = pbframe.nodeid();
			
			train = (pbframe.train() == -1) 
				? nullptr 
				: dynamic_cast<::RailRoadModel::ITrain*>(mr->findModelElementByID(pbframe.train()));
			
			trainID = pbframe.trainid();
			
		}
};		

} /* namespace Deployment */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Deployment::IDerivedExecutesMatch> {
	size_t operator()(const ::Viatra::Query::Deployment::IDerivedExecutesMatch& match) const {
		size_t h = 0;
		h+=std::hash<decltype(match.node)>()(match.node);
		h*=31;
		h+=std::hash<decltype(match.nodeID)>()(match.nodeID);
		h*=31;
		h+=std::hash<decltype(match.train)>()(match.train);
		h*=31;
		h+=std::hash<decltype(match.trainID)>()(match.trainID);
		return h;
	}
};
		
}

#endif /*  VIATRA__QUERY__DEPLOYMENT__I_DERIVED_EXECUTES_MATCH_H_ */
