#ifndef VIATRA__QUERY__DEPLOYMENT__I_DERIVED_EXECUTES_DERIVED_H_
#define VIATRA__QUERY__DEPLOYMENT__I_DERIVED_EXECUTES_DERIVED_H_

#include <algorithm>
#include <stdexcept>
		
#include "Viatra/Query/Deployment/IDerivedExecutesMatcher.h"
#include "Viatra/Query/Matcher/ModelIndex.h"
#include "Viatra/Query/QueryEngine.h"

namespace Viatra {
namespace Query {
namespace Deployment {

template<class ModelRoot>
struct IDerivedExecutesUpdate{
	/*
	 * It is generated for update a reference collection in src's environment.
	 */
	static void update(ModelRoot modelRoot,int nodeID){
		/*
		 * Critical Section START
		 * Atomicity is mandatory
		 * Not supported parallel modifications and queries
		 */
		auto srcInstanceList = ModelIndex<typename std::remove_pointer< ::PlatformModel::INode >::type, ModelRoot>::instances(&modelRoot);
		auto srcIDPredicate = [nodeID](const ::PlatformModel::INode* src){
			return src->id == nodeID;
		};

		auto srcIt = std::find_if(srcInstanceList.begin(), srcInstanceList.end(), srcIDPredicate);

		if(srcIt == srcInstanceList.end()) throw new std::invalid_argument("::PlatformModel::INode ID not found.");

		auto engine = QueryEngine<ModelRoot>::of(&modelRoot);
		auto derivedExecutesMatcher = engine.template matcher< IDerivedExecutesQuerySpecification >();
		auto matches = derivedExecutesMatcher.matches(nodeID);
		auto trgInstanceList = ModelIndex<typename std::remove_pointer< ::RailRoadModel::ITrain >::type, ModelRoot>::instances(&modelRoot);

		std::vector< ::RailRoadModel::ITrain* > newDerivedList;

		for(auto match : matches){
			if(newDerivedList.end() == std::find(newDerivedList.begin(), newDerivedList.end(), match.train)) newDerivedList.push_back(match.train);
		}

		(*srcIt)->derivedExecutes.clear();
		(*srcIt)->derivedExecutes.insert((*srcIt)->derivedExecutes.begin(), newDerivedList.begin(), newDerivedList.end());

		/*
		* Critical Section END
		*/
	}
};

} /* namespace Deployment */
} /* namespace Query */
} /* namespace Viatra */

	

#endif /*  VIATRA__QUERY__DEPLOYMENT__I_DERIVED_EXECUTES_DERIVED_H_ */
