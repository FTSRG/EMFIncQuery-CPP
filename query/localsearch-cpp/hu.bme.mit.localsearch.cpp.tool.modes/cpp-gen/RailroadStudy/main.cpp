


#include"Viatra/Query/DerivedInput/FrozenStateAPI.h"
#include"Viatra/Query/DerivedInput/QueryRunnerFactory.h"
#include"Viatra/Query/DistributedQueries/IsDangerous.h"
#include"model/ModelRoot.h"


#include"Viatra/Query/Distributed/QueryService.h"

int main(int argc, char**argv)
{
	using namespace Viatra::Query;
	using Viatra::Query::DistributedQueries::IsDangerous;

	Viatra::Query::Distributed::QueryService < Viatra::Query::Model::ModelRoot, DerivedInput::QueryRunnerFactory > service(
		"model.json", argv[1]
		);

	auto future = service.RunNewQuery<IsDangerous, IsDangerous::NoBind>();

	future.get();

	return 0;
}