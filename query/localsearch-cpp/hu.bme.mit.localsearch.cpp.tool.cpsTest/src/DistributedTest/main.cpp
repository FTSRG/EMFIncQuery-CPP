

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
	try {
		using Logger = Viatra::Query::Util::Logger;
		Logger::SetThisThreadName("MAIN THREAD");
		Logger::Log("Start of main function");

	//	return server_test(argc, argv);
		
		Viatra::Query::Distributed::QueryService<
			Viatra::Query::Model::ModelRoot, 
			Viatra::Query::Distributedquery::QueryRunnerFactory
		>	service("model.json", argv[1]);
		
		using Viatra::Query::Distributedquery::QueryB;
	
		if (argv[1] == std::string("nodeA")) {
			Logger::Log("int main(...) - if (argv[1] == std::string(\"nodeA\"))");
			auto result = service.RunNewQuery<QueryB, QueryB::NoBind>();
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
		std::cout << ex.what();
	}
	catch (const std::string& ex)
	{
		std::cout << ex;
	}
	catch (const char *c)
	{
		std::cout << c;
	}
	catch (...)
	{
		std::cout << "Something catched other than std::exception, string, or const char*";
	}


	return 0;
}
