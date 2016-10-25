


#include"Viatra/Query/DerivedInput/FrozenStateAPI.h"
#include"Viatra/Query/DerivedInput/QueryRunnerFactory.h"
#include"Viatra/Query/DistributedQueries/IsDangerous.h"
#include"model/ModelRoot.h"


#include"Viatra/Query/Distributed/QueryService.h"


#include<iostream>

int main(int argc, char**argv)
{
	using namespace Viatra::Query;
	using Viatra::Query::DistributedQueries::IsDangerous;

	Viatra::Query::Distributed::QueryService < Viatra::Query::Model::ModelRoot, DerivedInput::QueryRunnerFactory > service(
		"model.json", argv[1]
		);

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

	return 0;
}