

#include<Viatra/Query/Distributed/QueryService.h>

#include<iostream>
#include<string>

#include<Viatra/Query/Distributedquery/QueryAFrame_0.h>

// Entry point
int main(int argc, char **argv) {
	Viatra::Query::Distributedquery::QueryAFrame_0 frame;
	frame._0 = nullptr;
	frame._1 = nullptr;
	frame._2 = nullptr;
	frame._3 = nullptr;

	std::string s = frame.serialize();

	frame._1++;

	frame.deserialize();


	try {
		
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
