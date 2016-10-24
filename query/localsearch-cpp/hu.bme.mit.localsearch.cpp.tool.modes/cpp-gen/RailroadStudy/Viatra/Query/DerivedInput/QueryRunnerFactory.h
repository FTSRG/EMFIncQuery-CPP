#ifndef VIATRA__QUERY__DERIVED_INPUT__QUERY_RUNNER_FACTORY_H_
#define VIATRA__QUERY__DERIVED_INPUT__QUERY_RUNNER_FACTORY_H_

#include <memory>
#include <stdexcept>
		
#include "Viatra/Query/DerivedInput/frozenStateAPI.h"
#include "Viatra/Query/Distributed/QueryRunner.h"
#include "Viatra/Query/Distributed/QueryService.h"

namespace Viatra {
namespace Query {
namespace DerivedInput {

template<class ModelRoot>
class QueryRunnerFactory{
public:

	static std::shared_ptr<Viatra::Query::Distributed::QueryRunnerBase> Create(int queryID, int64_t sessionID, ModelRoot * modelRoot, Viatra::Query::Distributed::QueryServiceBase * service)
	{
		switch(queryID){
			case 4:
			case 5:
				return std::make_unique<
					Viatra::Query::Distributed::QueryRunner<RootedFrozenStateAPI<ModelRoot>>
				>(sessionID, modelRoot, service, queryID);
		}
		throw std::invalid_argument("Cannot instantiate Query runner from the given queryID!");
	}	

};

} /* namespace DerivedInput */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__DERIVED_INPUT__QUERY_RUNNER_FACTORY_H_ */
