
#include"Viatra/Query/DerivedInput/FrozenStateAPI.h"
#include"Viatra/Query/DistributedQueries/IsDangerous.h"
#include"model/ModelRoot.h"

#include"Viatra/Query/Util/Logger.h"
#include"Viatra/Query/Distributed/QueryService.h"
#include"Viatra/Query/DistributedQueries/QueryRunnerFactory.h"

#include<iostream>

#include "UpdateModel.h"

using Viatra::Query::Util::Logger;

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
	Logger::SetThisThreadName("MAIN");
	const char * arg = argc > 1 ? argv[1] : "nodeA";
	// Creating the Local Model from the image
	Viatra::Query::Model::ModelRoot modelRoot("configuration.json", arg);

	QueryService service("configuration.json", arg, &modelRoot);
	service.start();

	try {

		while (true) {
			Logger::Log("main loop");
			auto id = Logger::Identer();

			Logger::Log("UpdateModel");
			UpdateModel(arg, &modelRoot);

			Logger::Log("CheckSystemState");
			CheckSystemState(service);
		}

	}
	catch (const char * c)
	{
		Logger::Log("Exception as const char: ", c);
	}
	catch (std::exception& ex)
	{
		Logger::Log("Exception: ", ex.what());
	}
	catch (...)
	{
		Logger::Log("Dobjal rendes kivetelt basszus....");
	}


	return 0;
}