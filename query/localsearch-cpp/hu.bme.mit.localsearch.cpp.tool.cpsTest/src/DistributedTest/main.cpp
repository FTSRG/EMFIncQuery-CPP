

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
		//return server_test(argc, argv)

		Viatra::Query::Distributed::QueryService<
			Viatra::Query::Model::ModelRoot, 
			Viatra::Query::Distributedquery::QueryRunnerFactory
		>	service("config.json", argv[1]);
		
		auto result = service.RunNewQuery<Viatra::Query::Distributedquery::QueryB>();
		while (!result->ready())
			std::this_thread::sleep_for(std::chrono::seconds(1));


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
