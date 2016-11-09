
#include"Viatra/Query/DerivedInput/FrozenStateAPI.h"
#include"Viatra/Query/DistributedQueries/IsDangerous.h"
#include"model/ModelRoot.h"

#include"Viatra/Query/Util/Logger.h"
#include"Viatra/Query/Distributed/QueryService.h"
#include"Viatra/Query/DistributedQueries/QueryRunnerFactory.h"

#include<iostream>
#include<chrono>
#include<iomanip>
#include<windows.h>

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

std::unique_ptr<std::thread> runUpdatingThread(const char* nodeName, ModelRoot *modelRoot) {
	Logger::Log("kekd");
	auto t = std::make_unique<std::thread>([nodeName, modelRoot]() mutable {
		Logger::Log("safs");
		double nextT = seconds() + update_period;
		for (int i = 0; i < test_count; ++i)
		{
			Logger::Log("sdfsd");
			UpdateModel(nodeName, modelRoot);

			while (seconds() < nextT)
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
			nextT += update_period;
		}
		Logger::Log("sdfsdgsdg");
	});
	Logger::Log("Crajted");
	Logger::ThreadTest(std::chrono::seconds(5));
	return t;
}

int main(int argc, char**argv)
{
	data.reserve(test_count);
	Logger::SetThisThreadName("MAIN");
	const char * nodeName = argc > 1 ? argv[1] : "nodeA";
	// Creating the Local Model from the image

	Logger::Log("Import starting json");
	Viatra::Query::Model::ModelRoot modelRoot("configuration.json", nodeName);

	Logger::Log("Creating service");
	QueryService service("configuration.json", nodeName, &modelRoot);
	Logger::Log("Starting service");
	
	service.start();

	Logger::Log("Starting service - done");

	try {

		Logger::Log("try - runUpdatingThread");
		auto _ = runUpdatingThread(nodeName, &modelRoot);

		std::this_thread::sleep_for(std::chrono::seconds(1));

		Logger::Log("try - runCheckingThread");
		auto checkThread = runCheckingThread(service);
		checkThread.join();

		Logger::Log("try - for");
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
		std::cout << "Dobjal rendes kivetelt basszus...." << std::endl;
	}


	return 0;
}