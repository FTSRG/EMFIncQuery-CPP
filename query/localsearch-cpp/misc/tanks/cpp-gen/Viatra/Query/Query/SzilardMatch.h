#ifndef VIATRA__QUERY__QUERY__SZILARD_MATCH_H_
#define VIATRA__QUERY__QUERY__SZILARD_MATCH_H_

		
#include "factory/Szilard.h"
#include "factory/Tartaly.h"
#include "factory/Viz.h"

namespace Viatra {
namespace Query {
namespace Query {

struct SzilardMatch {
	
	::factory::Tartaly* tartaly;
	int tartalyID;
	::factory::Szilard* dAllapot;
	int allapotID;
	double homerseklet;
	
	bool operator==(const SzilardMatch& other) const {
		return 
			tartaly == other.tartaly&&
			tartalyID == other.tartalyID&&
			dAllapot == other.dAllapot&&
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
					std::hash<decltype(match.tartaly)>()(match.tartaly)^
					std::hash<decltype(match.tartalyID)>()(match.tartalyID)^
					std::hash<decltype(match.dAllapot)>()(match.dAllapot)^
					std::hash<decltype(match.allapotID)>()(match.allapotID)^
					std::hash<decltype(match.homerseklet)>()(match.homerseklet)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__QUERY__SZILARD_MATCH_H_ */
