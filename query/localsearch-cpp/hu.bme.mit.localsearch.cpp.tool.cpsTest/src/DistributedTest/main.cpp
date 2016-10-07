

#include<iostream>
#include<string>

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
		return server_test(argc, argv);
		auto arg = "cfg1.json";

		// Create a query service and run it on the main thread

		Viatra::Query::Distributed::QueryService<
			Viatra::Query::Model::ModelRoot, 
			Viatra::Query::Distributedquery::QueryRunnerFactory
		>	service(arg, "nodeA");

		auto thread = service.run_async();

		service.RunNewQuery<Viatra::Query::Distributedquery::QueryB>();

	}
	catch (std::exception ex)
	{
		std::cout << ex.what();
	}
	catch (std::string ex)
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
