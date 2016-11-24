#ifndef VIATRA__QUERY__SNCL_RUNTIME__QUERY_RUNNER_FACTORY_H_
#define VIATRA__QUERY__SNCL_RUNTIME__QUERY_RUNNER_FACTORY_H_

#include <memory>
#include <stdexcept>
		
#include "Viatra/Query/Distributed/QueryRunner.h"
#include "Viatra/Query/Distributed/QueryService.h"
#include "Viatra/Query/sncl_runtime/countLinks.h"
#include "Viatra/Query/sncl_runtime/greaterThanOneSNConnection.h"
#include "Viatra/Query/sncl_runtime/isolatedCL.h"
#include "Viatra/Query/sncl_runtime/isolatedSN.h"
#include "Viatra/Query/sncl_runtime/linked.h"
#include "Viatra/Query/sncl_runtime/notInRing.h"
#include "Viatra/Query/sncl_runtime/numEqualityWithMember.h"
#include "Viatra/Query/sncl_runtime/numInEqualityWithMember.h"
#include "Viatra/Query/sncl_runtime/pconnected.h"
#include "Viatra/Query/sncl_runtime/ringMembers.h"

namespace Viatra {
namespace Query {
namespace Sncl_runtime {

template<class ModelRoot>
class QueryRunnerFactory{
public:

	static std::shared_ptr<Viatra::Query::Distributed::QueryRunnerBase> Create(int queryID, int64_t sessionID, ModelRoot * modelRoot, Viatra::Query::Distributed::QueryServiceBase * service)
	{
		switch(queryID){
			case 7:
				return std::make_unique<
					Viatra::Query::Distributed::QueryRunner<RootedGreaterThanOneSNConnection<ModelRoot>>
				>(sessionID, modelRoot, service, queryID);
			case 3:
			case 6:
			case 10:
			case 18:
			case 20:
				return std::make_unique<
					Viatra::Query::Distributed::QueryRunner<RootedPconnected<ModelRoot>>
				>(sessionID, modelRoot, service, queryID);
			case 1:
				return std::make_unique<
					Viatra::Query::Distributed::QueryRunner<RootedCountLinks<ModelRoot>>
				>(sessionID, modelRoot, service, queryID);
			case 4:
				return std::make_unique<
					Viatra::Query::Distributed::QueryRunner<RootedRingMembers<ModelRoot>>
				>(sessionID, modelRoot, service, queryID);
			case 17:
				return std::make_unique<
					Viatra::Query::Distributed::QueryRunner<RootedIsolatedCL<ModelRoot>>
				>(sessionID, modelRoot, service, queryID);
			case 9:
				return std::make_unique<
					Viatra::Query::Distributed::QueryRunner<RootedNotInRing<ModelRoot>>
				>(sessionID, modelRoot, service, queryID);
			case 11:
				return std::make_unique<
					Viatra::Query::Distributed::QueryRunner<RootedNumEqualityWithMember<ModelRoot>>
				>(sessionID, modelRoot, service, queryID);
			case 15:
				return std::make_unique<
					Viatra::Query::Distributed::QueryRunner<RootedIsolatedSN<ModelRoot>>
				>(sessionID, modelRoot, service, queryID);
			case 2:
			case 5:
			case 8:
			case 12:
			case 14:
			case 16:
			case 19:
			case 21:
				return std::make_unique<
					Viatra::Query::Distributed::QueryRunner<RootedLinked<ModelRoot>>
				>(sessionID, modelRoot, service, queryID);
			case 13:
				return std::make_unique<
					Viatra::Query::Distributed::QueryRunner<RootedNumInEqualityWithMember<ModelRoot>>
				>(sessionID, modelRoot, service, queryID);
		}
		throw std::invalid_argument("Cannot instantiate Query runner from the given queryID!");
	}	

};

} /* namespace Sncl_runtime */
} /* namespace Query */
} /* namespace Viatra */


#endif /*  VIATRA__QUERY__SNCL_RUNTIME__QUERY_RUNNER_FACTORY_H_ */
