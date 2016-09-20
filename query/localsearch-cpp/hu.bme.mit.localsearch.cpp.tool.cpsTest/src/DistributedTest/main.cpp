// GTestProba2.cpp : Defines the entry point for the console application.
//

#include"ModelRoot.h"

#include<iostream>
#include<string>

int main(int argc, char **argv) {

	try {

		/*
		if(argc < 2)
			return 0;
		auto arg = argv[1]
		*/
	
		auto arg = "cfg1.json";

		ModelRoot modelRoot(arg);


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
		std::cout << "Something catched";
	}


	return 0;
}
