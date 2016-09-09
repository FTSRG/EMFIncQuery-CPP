#ifndef VIATRA__QUERY__DERIVED_FEATURES__ASSIGNED_TO_CAMERA_MATCH_H_
#define VIATRA__QUERY__DERIVED_FEATURES__ASSIGNED_TO_CAMERA_MATCH_H_

		
#include "PlatformModel/Camera.h"
#include "RailRoadModel/Segment.h"

namespace Viatra {
namespace Query {
namespace DerivedFeatures {

struct AssignedToCameraMatch {
	
	::PlatformModel::Camera* cam;
	::RailRoadModel::Segment* seg;
	
	bool operator==(const AssignedToCameraMatch& other) const {
		return 
			cam == other.cam&&
			seg == other.seg
		;
	}
	
};		

} /* namespace DerivedFeatures */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::DerivedFeatures::AssignedToCameraMatch> {
	unsigned operator()(const ::Viatra::Query::DerivedFeatures::AssignedToCameraMatch& match) const {
		return 
					std::hash<decltype(match.cam)>()(match.cam)^
					std::hash<decltype(match.seg)>()(match.seg)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__DERIVED_FEATURES__ASSIGNED_TO_CAMERA_MATCH_H_ */
