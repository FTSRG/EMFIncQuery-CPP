

#include<Viatra/Query/Distributed/QueryService.h>

#include<iostream>
#include<string>

// Entry point
int main(int argc, char **argv) {

	try {

		/*
		if(argc < 2)
			return 0;
		auto arg = argv[1]
		*/

		auto arg = "cfg1.json";

		// Create a query service and run it on the main thread
		Viatra::Query::Distributed::QueryService service(arg);
		service.run();
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
		std::cout << "Something catched other than exception, string, or const char*";
	}


	return 0;
}
