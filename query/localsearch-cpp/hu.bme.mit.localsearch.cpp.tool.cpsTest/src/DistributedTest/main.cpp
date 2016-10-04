
#include<Viatra/Query/Distributed/QueryService.h>

#include<iostream>
#include<string>

#include<Viatra/Query/Distributedquery/QueryRunnerFactory.h>
#include<Viatra/Query/Distributedquery/QueryBQuerySpecification.h>
#include<Model/ModelRoot.h>

int server_test(int argc, char **argv);

// Entry point
int main(int argc, char **argv) {
	try {
		
		auto arg = "cfg1.json";

		// Create a query service and run it on the main thread

		Viatra::Query::Distributed::QueryService<
			Viatra::Query::Model::ModelRoot, 
			Viatra::Query::Distributedquery::QueryRunnerFactory
		>	service(arg);

		auto thread = service.run_async();

		service.RunNewQuery<Viatra::Query::Distributedquery::QueryBQuerySpecification>();

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
