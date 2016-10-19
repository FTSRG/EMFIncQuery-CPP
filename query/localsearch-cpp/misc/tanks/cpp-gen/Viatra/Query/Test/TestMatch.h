#ifndef VIATRA__QUERY__TEST__TEST_MATCH_H_
#define VIATRA__QUERY__TEST__TEST_MATCH_H_

		
#include "factory/Halmazallapot.h"
#include "factory/Tank.h"

namespace Viatra {
namespace Query {
namespace Test {

struct TestMatch {
	
	::factory::Tank* tank;
	::factory::Halmazallapot* allapot;
	
	bool operator==(const TestMatch& other) const {
		return 
			tank == other.tank&&
			allapot == other.allapot
		;
	}
	
};		

} /* namespace Test */
} /* namespace Query */
} /* namespace Viatra */

namespace std {

template<> struct hash<::Viatra::Query::Test::TestMatch> {
	size_t operator()(const ::Viatra::Query::Test::TestMatch& match) const {
		return 
					std::hash<decltype(match.tank)>()(match.tank)^
					std::hash<decltype(match.allapot)>()(match.allapot)
		;
	}
};
		
}

#endif /*  VIATRA__QUERY__TEST__TEST_MATCH_H_ */
