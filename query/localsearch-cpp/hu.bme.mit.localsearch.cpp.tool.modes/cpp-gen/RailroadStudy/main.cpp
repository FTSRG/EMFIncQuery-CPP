
#include"Viatra/Query/DerivedInput/FrozenStateAPI.h"
#include"Viatra/Query/DistributedQueries/IsDangerous.h"
#include"model/ModelRoot.h"

#include"Viatra/Query/Util/Logger.h"
#include"Viatra/Query/Distributed/QueryService.h"
#include"Viatra/Query/DistributedQueries/QueryRunnerFactory.h"

#include<iostream>
#include<windows.h>

#include "UpdateModel.h"

using Viatra::Query::Util::Logger;

using namespace Viatra::Query;
using Viatra::Query::DistributedQueries::IsDangerous;

using QueryService = Viatra::Query::Distributed::QueryService <
	Viatra::Query::Model::ModelRoot,
	DistributedQueries::QueryRunnerFactory
>;

void setColor(int color){
	static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void CheckSystemState(QueryService& service)
{
	static auto first = true;
	static auto future = service.RunNewQuery<IsDangerous, IsDangerous::NoBind>();
	if (!first)
	{
		future = future->reanimate();
	}
	first = false;


	auto resultSet = future->getResultMatchSet();
	if (resultSet.size() > 0)
	{
		setColor(12);
		std::cout << "FAULT    , IsDangerous result:";
		for (auto & result : resultSet)
			std::cout << "  " << result.toString() << std::endl;
		setColor(7);
	}
	else
	{
		setColor(10);
		std::cout << "CHECKED  , IsDangerous query result is empty" << std::endl;
		setColor(7);
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
			std::cout << "main loop" << std::endl;
			auto id = Logger::Identer();

			std::cout << "UpdateModel" << std::endl;
			UpdateModel(arg, &modelRoot);

			std::cout << "CheckSystemState" << std::endl;
			CheckSystemState(service);
		}

	}
	catch (const char * c)
	{
		std::cout << "Exception as const char: " << c << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Dobjal rendes kivetelt basszus...." << std::endl;
	}


	return 0;
}