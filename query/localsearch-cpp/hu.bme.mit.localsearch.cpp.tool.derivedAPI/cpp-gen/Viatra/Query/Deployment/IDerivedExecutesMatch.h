#ifndef VIATRA__QUERY__DEPLOYMENT__I_DERIVED_EXECUTES_MATCH_H_
#define VIATRA__QUERY__DEPLOYMENT__I_DERIVED_EXECUTES_MATCH_H_

		
#include "PlatformModel/Node.h"
#include "RailRoadModel/RailRoadElement.h"
#include "RailRoadModel/Segment.h"
#include "RailRoadModel/Train.h"

namespace Viatra {
namespace Query {
namespace Deployment {

struct IDerivedExecutesMatch {
	
	::PlatformModel::Node* node;
	int nodeID;
	::RailRoadModel::Train* train;
	int trainID;
	
	bool operator==(const IDerivedExecutesMatch& other) const {
		return 
			node == other.node&&
			nodeID == other.nodeID&&
			train == other.train&&
			trainID == other.trainID
		;
	}
	
};		

} /* namespace Deployment */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Deployment::IDerivedExecutesMatch> {
	size_t operator()(const ::Viatra::Query::Deployment::IDerivedExecutesMatch& match) const {
		return 
					std::hash<decltype(match.node)>()(match.node)^
					std::hash<decltype(match.nodeID)>()(match.nodeID)^
					std::hash<decltype(match.train)>()(match.train)^
					std::hash<decltype(match.trainID)>()(match.trainID)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__DEPLOYMENT__I_DERIVED_EXECUTES_MATCH_H_ */
