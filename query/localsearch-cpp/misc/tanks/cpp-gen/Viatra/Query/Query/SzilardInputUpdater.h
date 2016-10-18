#ifndef VIATRA__QUERY__QUERY__SZILARD_INPUT_UPDATER_H_
#define VIATRA__QUERY__QUERY__SZILARD_INPUT_UPDATER_H_

#include <algorithm>
#include <stdexcept>
		
#include "Viatra/Query/Matcher/ModelIndex.h"
#include "Viatra/Query/Query/SzilardMatcher.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace Query {

template<class ModelRoot>
struct SzilardInputUpdate{
	/*
	 * It is generated for only sending vector coordinates into the model instance. 
	 * The Derived feature has a source and a target, their id must be given in update function parameter i.e. (srcID, trgID, ...).
	 * If that isn't guaranteed this code crashes in compile time.
	 */
	static void update(ModelRoot modelRoot,int tankID, int allapotID, double homerseklet){
		/*
		 * Critical Section START
		 * Atomicity is mandatory
		 * Not supported parallel modifications and queries
		 */
		
		int thId = modelRoot.getID();
		modelRoot.getTicket(thID);
		modelRoot.wait();
		modelRoot.resourceMutex.lock();
		modelRoot.criticalBegin();
					
		auto srcInstanceList = ModelIndex<typename std::remove_pointer< ::factory::Tank >::type, ModelRoot>::instances(&modelRoot);
		auto srcIDPredicate = [tankID](const ::factory::Tank* src){
			return src->id == tankID;
		};
		
		auto srcObj = std::find_if(srcInstanceList.begin(), srcInstanceList.end(), srcIDPredicate);
		
		if(srcObj == srcInstanceList.end()) throw new std::invalid_argument("::factory::Tank ID not found");
		
		auto trgInstanceList = ModelIndex<typename std::remove_pointer< ::factory::Szilard >::type, ModelRoot>::instances(&modelRoot);
		auto trgIDPredicate = [allapotID](const ::factory::Szilard* trg){
			return trg->id == allapotID;
		};
		
		auto trgObj = std::find_if(trgInstanceList.begin(), trgInstanceList.end(), trgIDPredicate);
		
		if(trgObj == trgInstanceList.end()) throw new std::invalid_argument("::factory::Szilard ID not found");
		
		auto engine = QueryEngine<ModelRoot>::of(&modelRoot);
		auto allapotMatcher = engine.template matcher< SzilardQuerySpecification >();
		auto matches = allapotMatcher.matches(tankID, allapotID, homerseklet);
		
		auto tempTrg = std::find_if((*srcObj)->allapot.begin(), (*srcObj)->allapot.end(), trgIDPredicate);
		
		if(matches.size() > 0){	if(tempTrg == (*srcObj)->allapot.end()) (*srcObj)->allapot.push_back(*trgObj);}
		else if(tempTrg != (*srcObj)->allapot.end()) (*srcObj)->allapot.erase(tempTrg);
		
		modelRoot.criticalEnd();
		resourceMutex.unlock();
		/*
		* Critical Section END
		*/
	}
};

} /* namespace Query */
} /* namespace Query */
} /* namespace Viatra */

	

#endif /*  VIATRA__QUERY__QUERY__SZILARD_INPUT_UPDATER_H_ */
