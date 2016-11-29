#include "Viatra/Query/DerivedInput/FrozenStateAPIInputUpdater.h"
#include "Viatra/Query/DistributedQueries/IsDangerousMatcher.h"
//#include"model/ModelRoot.h"

#include "Viatra/Query/QueryEngine.h"

//#include"Viatra/Query/Util/Logger.h"
//#include"Viatra/Query/Distributed/QueryService.h"
//#include"Viatra/Query/DistributedQueries/QueryRunnerFactory.h"

#include<iostream>
#include<chrono>
#include<iomanip>
//#include<windows.h>

#include "UpdateModel.h"


constexpr int test_count = 20;
constexpr double update_freq = 100;	// 10 millisec
constexpr double update_period = 1.0 / update_freq;

struct Record{
	double checkTime;
};

std::vector<Record> data;

auto start_time = std::chrono::high_resolution_clock::now();

long long nanos() {
	auto end_time = std::chrono::high_resolution_clock::now();
	return std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
}

double seconds() {
	return nanos() / (1000 * 1000 * 1000 * 1.0);
}

using namespace Viatra::Query;
using Viatra::Query::DistributedQueries::IsDangerous;
using ModelRoot = Viatra::Query::Model::ModelRoot;

void CheckSystemState()
{
	//TODO query
}

void runCheckingThread() {
    double lastT = seconds();
    for (int i = 0; i < test_count; ++i)
    {
        CheckSystemState();

        auto time = seconds();
        data.push_back({time - lastT});
        lastT = time;
    }
}

void runUpdatingThread(const char* nodeName, ModelRoot *modelRoot) {
    double nextT = seconds() + update_period;
    for (int i = 0; i < test_count; ++i)
    {
        UpdateModel(nodeName, modelRoot);

        while (seconds() < nextT)
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        nextT += update_period;
    }
}

void init(){
    
}

int main(int argc, char**argv)
{
	data.reserve(test_count);
	const char * nodeName = argc > 1 ? argv[1] : "nodeA";
	// Creating the Local Model from the image
    
    init();

	std::cout << "Start" << std::endl;
	Viatra::Query::Model::ModelRoot modelRoot;

	std::cout <<"Starting measure - done"<< std::endl;

	try {

		std::cout <<"try - runUpdatingThread"<< std::endl;
		runUpdatingThread(nodeName, &modelRoot);

		std::this_thread::sleep_for(std::chrono::seconds(1));

		std::cout <<"try - runCheckingThread"<< std::endl;
		runCheckingThread();

		std::cout <<"try - for"<< std::endl;
		for (auto & record : data)
		{
			std::cout << std::setprecision(5) << record.checkTime << ";";
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
		std::cout << "Unexpected exception...." << std::endl;
        throw;
	}


	return 0;
}
