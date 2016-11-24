#ifndef VIATRA__QUERY__SAFETYLOGIC__QUERY_RUNNER_FACTORY_H_
#define VIATRA__QUERY__SAFETYLOGIC__QUERY_RUNNER_FACTORY_H_

#include <memory>
#include <stdexcept>
		
#include "Viatra/Query/Distributed/QueryRunner.h"
#include "Viatra/Query/Distributed/QueryService.h"
#include "Viatra/Query/safetylogic/currentlyConnected.h"
#include "Viatra/Query/safetylogic/isDangerous.h"
#include "Viatra/Query/safetylogic/nextSection.h"
#include "Viatra/Query/safetylogic/notNull.h"
#include "Viatra/Query/safetylogic/shouldCollide.h"
#include "Viatra/Query/safetylogic/trainHitsAnotherTrain.h"
#include "Viatra/Query/safetylogic/trainHitsAnotherTrainNext.h"
#include "Viatra/Query/safetylogic/trainHitsAnotherTrainNextAfterNext.h"
#include "Viatra/Query/safetylogic/trainsAreTooClose.h"
#include "Viatra/Query/safetylogic/viablePaths.h"

namespace Viatra {
namespace Query {
namespace Safetylogic {

template<class ModelRoot>
class QueryRunnerFactory{
public:

	static std::shared_ptr<Viatra::Query::Distributed::QueryRunnerBase> Create(int queryID, int64_t sessionID, ModelRoot * modelRoot, Viatra::Query::Distributed::QueryServiceBase * service)
	{
		switch(queryID){
			case 10:
				return std::make_unique<
					Viatra::Query::Distributed::QueryRunner<RootedNextSection<ModelRoot>>
				>(sessionID, modelRoot, service, queryID);
			case 20:
				return std::make_unique<
					Viatra::Query::Distributed::QueryRunner<RootedIsDangerous<ModelRoot>>
				>(sessionID, modelRoot, service, queryID);
			case 7:
				return std::make_unique<
					Viatra::Query::Distributed::QueryRunner<RootedCurrentlyConnected<ModelRoot>>
				>(sessionID, modelRoot, service, queryID);
			case 8:
			case 11:
			case 14:
			case 16:
			case 18:
				return std::make_unique<
					Viatra::Query::Distributed::QueryRunner<RootedNotNull<ModelRoot>>
				>(sessionID, modelRoot, service, queryID);
			case 12:
				return std::make_unique<
					Viatra::Query::Distributed::QueryRunner<RootedTrainsAreTooClose<ModelRoot>>
				>(sessionID, modelRoot, service, queryID);
			case 17:
				return std::make_unique<
					Viatra::Query::Distributed::QueryRunner<RootedTrainHitsAnotherTrain<ModelRoot>>
				>(sessionID, modelRoot, service, queryID);
			case 9:
				return std::make_unique<
					Viatra::Query::Distributed::QueryRunner<RootedViablePaths<ModelRoot>>
				>(sessionID, modelRoot, service, queryID);
			case 15:
				return std::make_unique<
					Viatra::Query::Distributed::QueryRunner<RootedTrainHitsAnotherTrainNext<ModelRoot>>
				>(sessionID, modelRoot, service, queryID);
			case 13:
				return std::make_unique<
					Viatra::Query::Distributed::QueryRunner<RootedTrainHitsAnotherTrainNextAfterNext<ModelRoot>>
				>(sessionID, modelRoot, service, queryID);
			case 19:
				return std::make_unique<
					Viatra::Query::Distributed::QueryRunner<RootedShouldCollide<ModelRoot>>
				>(sessionID, modelRoot, service, queryID);
		}
		throw std::invalid_argument("Cannot instantiate Query runner from the given queryID!");
	}	

};

} /* namespace Safetylogic */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SAFETYLOGIC__QUERY_RUNNER_FACTORY_H_ */
