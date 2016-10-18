#ifndef VIATRA__QUERY__QUERY__SZILARD_MATCH_H_
#define VIATRA__QUERY__QUERY__SZILARD_MATCH_H_

		
#include "factory/Szilard.h"
#include "factory/Tank.h"
#include "factory/Viz.h"

namespace Viatra {
namespace Query {
namespace Query {

struct SzilardMatch {
	
	::factory::Tank* tank;
	int tankID;
	::factory::Szilard* allapot;
	int allapotID;
	double homerseklet;
	
	bool operator==(const SzilardMatch& other) const {
		return 
			tank == other.tank&&
			tankID == other.tankID&&
			allapot == other.allapot&&
			allapotID == other.allapotID&&
			homerseklet == other.homerseklet
		;
	}
	
};		

} /* namespace Query */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Query::SzilardMatch> {
	size_t operator()(const ::Viatra::Query::Query::SzilardMatch& match) const {
		return 
					std::hash<decltype(match.tank)>()(match.tank)^
					std::hash<decltype(match.tankID)>()(match.tankID)^
					std::hash<decltype(match.allapot)>()(match.allapot)^
					std::hash<decltype(match.allapotID)>()(match.allapotID)^
					std::hash<decltype(match.homerseklet)>()(match.homerseklet)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__QUERY__SZILARD_MATCH_H_ */
