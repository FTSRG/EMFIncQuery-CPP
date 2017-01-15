#ifndef VIATRA__QUERY__ITERATOR_QUERY__ROBOT_IS_SAFE_MATCH_H_
#define VIATRA__QUERY__ITERATOR_QUERY__ROBOT_IS_SAFE_MATCH_H_

		
#include "railRoadModel/RobotPart.h"
#include "railRoadModel/Train.h"

namespace Viatra {
namespace Query {
namespace IteratorQuery {

struct RobotIsSafeMatch {
	
	::railRoadModel::RobotPart* rp;
	::railRoadModel::Train* tr;
	
	bool operator==(const RobotIsSafeMatch& other) const {
		return 
			rp == other.rp&&
			tr == other.tr
		;
	}
	
};		

} /* namespace IteratorQuery */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::IteratorQuery::RobotIsSafeMatch> {
	size_t operator()(const ::Viatra::Query::IteratorQuery::RobotIsSafeMatch& match) const {
		return 
					std::hash<decltype(match.rp)>()(match.rp)^
					std::hash<decltype(match.tr)>()(match.tr)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__ITERATOR_QUERY__ROBOT_IS_SAFE_MATCH_H_ */
