#ifndef VIATRA__QUERY__DISTRIBUTED_QUERIES__QUERY_RUNNER_FACTORY_H_
#define VIATRA__QUERY__DISTRIBUTED_QUERIES__QUERY_RUNNER_FACTORY_H_

#include <memory>
#include <stdexcept>
		
#include "Viatra/Query/Distributed/QueryRunner.h"
#include "Viatra/Query/Distributed/QueryService.h"
#include "Viatra/Query/DistributedQueries/checkingHell.h"
#include "Viatra/Query/DistributedQueries/isDangerous.h"
#include "Viatra/Query/DistributedQueries/shouldCollide.h"

namespace Viatra {
namespace Query {
namespace DistributedQueries {

template<class ModelRoot>
class QueryRunnerFactory{
public:

	static std::shared_ptr<Viatra::Query::Distributed::QueryRunnerBase> Create(int queryID, int64_t sessionID, ModelRoot * modelRoot, Viatra::Query::Distributed::QueryServiceBase * service)
	{
		switch(queryID){
			case 2:
				return std::make_unique<
					Viatra::Query::Distributed::QueryRunner<RootedIsDangerous<ModelRoot>>
				>(sessionID, modelRoot, service, queryID);
			case 3:
			case 4:
				return std::make_unique<
					Viatra::Query::Distributed::QueryRunner<RootedCheckingHell<ModelRoot>>
				>(sessionID, modelRoot, service, queryID);
			case 1:
				return std::make_unique<
					Viatra::Query::Distributed::QueryRunner<RootedShouldCollide<ModelRoot>>
				>(sessionID, modelRoot, service, queryID);
		}
		throw std::invalid_argument("Cannot instantiate Query runner from the given queryID!");
	}	

};

} /* namespace DistributedQueries */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DISTRIBUTED_QUERIES__QUERY_RUNNER_FACTORY_H_ */
