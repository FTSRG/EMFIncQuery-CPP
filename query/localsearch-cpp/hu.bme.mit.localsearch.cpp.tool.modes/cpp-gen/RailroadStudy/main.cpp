
#include"Viatra/Query/DerivedInput/FrozenStateAPI.h"
#include"Viatra/Query/DistributedQueries/IsDangerous.h"
#include"model/ModelRoot.h"

#include"Viatra/Query/Distributed/QueryService.h"
#include"Viatra/Query/DistributedQueries/QueryRunnerFactory.h"

#include<iostream>


using namespace Viatra::Query;
using Viatra::Query::DistributedQueries::IsDangerous;

using QueryService = Viatra::Query::Distributed::QueryService <
	Viatra::Query::Model::ModelRoot,
	DistributedQueries::QueryRunnerFactory
>;


void CheckSystemState(QueryService& service)
{
	auto future = service.RunNewQuery<IsDangerous, IsDangerous::NoBind>();
	auto resultSet = future->get();
	if (resultSet.size() > 0)
	{
		std::cout << "FAULT    , IsDangerous result:";
		for (auto & result : resultSet)
			std::cout << "  " << result.toString() << std::endl;
	}
	else
	{
		std::cout << "CHECKED  , IsDangerous query result is empty";
	}

}

int main(int argc, char**argv)
{

	QueryService service("model.json", argv[1]);

	for (;;) {


		CheckSystemState(service);


	}


	return 0;
}