
#include"Viatra/Query/DerivedInput/FrozenStateAPI.h"
#include"Viatra/Query/DistributedQueries/IsDangerous.h"
#include"model/ModelRoot.h"

#include"Viatra/Query/Util/Logger.h"
#include"Viatra/Query/Distributed/QueryService.h"
#include"Viatra/Query/DistributedQueries/QueryRunnerFactory.h"

#include<iostream>
#include<chrono>
#include<windows.h>

#include "UpdateModel.h"


constexpr int test_count = 200;
constexpr double update_freq = 100;	// 10 millisec
constexpr double update_period = 1.0 / update_freq;

struct Record{
	double checkTime;
};

std::vector<Record> data;

auto start_time = std::chrono::high_resolution_clock::now();

long long nanos() {
	auto end_time = std::chrono::high_resolution_clock::now();
	return std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count();
}

double seconds() {
	return nanos() / (1000 * 1000 * 1000 * 1.0);
}

using Viatra::Query::Util::Logger;

using namespace Viatra::Query;
using Viatra::Query::DistributedQueries::IsDangerous;
using ModelRoot = Viatra::Query::Model::ModelRoot;


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
}

std::thread runCheckingThread(QueryService & service) {
	return std::thread([&service]()mutable{
	
		double lastT = seconds();
		for (int i = 0; i < test_count; ++i)
		{
			CheckSystemState(service);

			auto time = seconds();
			data.push_back({time - lastT});
			lastT = time;
		}
	});
}

std::thread runUpdatingThread(const char* nodeName, ModelRoot *modelRoot) {
	return std::thread([nodeName, modelRoot]()mutable {
		double nextT = seconds() + update_period;
		for (int i = 0; i < test_count; ++i)
		{
			UpdateModel(nodeName, modelRoot);

			while (seconds() < nextT)
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
			nextT += update_period;
		}
	});
}




int main(int argc, char**argv)
{
	data.reserve(test_count);
	Logger::SetThisThreadName("MAIN");
	const char * nodeName = argc > 1 ? argv[1] : "nodeA";
	// Creating the Local Model from the image
	Viatra::Query::Model::ModelRoot modelRoot("configuration.json", nodeName);

	QueryService service("configuration.json", nodeName, &modelRoot);
	service.start();

	try {

		runUpdatingThread(nodeName, &modelRoot);

		std::this_thread::sleep_for(std::chrono::seconds(1));

		auto checkThread = runCheckingThread(service);
		checkThread.join();

		for (auto & record : data)
		{
			std::cout << record.checkTime << ";";
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