

#include<iostream>
#include<string>

#include<Viatra/Query/Util/Logger.h>

#include<Model/ModelRoot.h>
#include<Viatra/Query/Distributed/QueryService.h>
#include<Viatra/Query/Distributedquery/QueryA.h>
#include<Viatra/Query/Distributedquery/QueryB.h>
#include<Viatra/Query/Distributedquery/QueryC.h>
#include<Viatra/Query/Distributedquery/QueryRunnerFactory.h>

int server_test(int argc, char **argv);

// Entry point
int main(int argc, char **argv) {
	using Logger = Viatra::Query::Util::Logger;

	Logger::SetThisThreadName("MAIN THREAD");
	Logger::Log("Start of main function");

//	return server_test(argc, argv);
		
	Viatra::Query::Distributed::QueryService<
		Viatra::Query::Model::ModelRoot, 
		Viatra::Query::Distributedquery::QueryRunnerFactory
	>	service("model.json", argv[1]);
		
	service.start();

	try {

		using Viatra::Query::Distributedquery::QueryA;
		using Viatra::Query::Distributedquery::QueryB;
		using Viatra::Query::Distributedquery::QueryC;
	
		if (argv[1] == std::string("nodeA")) {
			Logger::Log("int main(...) -- if (argv[1] == std::string(\"nodeA\"))");
			auto result = service.RunNewQuery<QueryA, QueryA::NoBind>();

			Logger::Log("int main(...) -- future obtained");
			while (!result->ready())
				std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		else
		{
			for (;;)
				std::this_thread::sleep_for(std::chrono::seconds(1));
		}

		Logger::Log("End of main function");
	}
	catch (const std::exception& ex)
	{
		Logger::Log(ex.what());
	}
	catch (const std::string& ex)
	{
		Logger::Log(ex);
	}
	catch (const char *c)
	{
		Logger::Log(c);
	}
	catch (...)
	{
		Logger::Log("Something catched other than std::exception, string, or const char*");
	}


	return 0;
}
