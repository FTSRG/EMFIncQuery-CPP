#ifndef VIATRA__QUERY__QUERY__SZILARD_DERIVED_H_
#define VIATRA__QUERY__QUERY__SZILARD_DERIVED_H_

#include <algorithm>
#include <stdexcept>
		
#include "Viatra/Query/Matcher/ModelIndex.h"
#include "Viatra/Query/Query/SzilardMatcher.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace Query {

template<class ModelRoot>
struct SzilardUpdate{
	/*
	 * It is generated for update a reference collection in src's environment.
	 */
	static void update(ModelRoot modelRoot,int tartalyID, int allapotID, double homerseklet){
		/*
		 * Critical Section START
		 * Atomicity is mandatory
		 * Not supported parallel modifications and queries
		 */
		auto srcInstanceList = ModelIndex<typename std::remove_pointer< ::factory::Tartaly >::type, ModelRoot>::instances(&modelRoot);
		auto srcIDPredicate = [tartalyID](const ::factory::Tartaly* src){
			return src->ID == tartalyID;
		};

		auto srcIt = std::find_if(srcInstanceList.begin(), srcInstanceList.end(), srcIDPredicate);

		if(srcIt == srcInstanceList.end()) throw std::invalid_argument("::factory::Tartaly ID not found.");

		auto engine = QueryEngine<ModelRoot>::of(&modelRoot);
		auto allapotMatcher = engine.template matcher< SzilardQuerySpecification >();
		auto matches = allapotMatcher.matches(tartalyID, allapotID, homerseklet);
		auto trgInstanceList = ModelIndex<typename std::remove_pointer< ::factory::Szilard >::type, ModelRoot>::instances(&modelRoot);

		
		::factory::Szilard* newDerivedMember = nullptr;
		for(auto match : matches){
			newDerivedMember = match.dAllapot;
		}
		if(newDerivedMember != nullptr) (*srcIt)->allapot = newDerivedMember;
		/*
		* Critical Section END
		*/
	}
};

} /* namespace Query */
} /* namespace Query */
} /* namespace Viatra */

	

#endif /*  VIATRA__QUERY__QUERY__SZILARD_DERIVED_H_ */
