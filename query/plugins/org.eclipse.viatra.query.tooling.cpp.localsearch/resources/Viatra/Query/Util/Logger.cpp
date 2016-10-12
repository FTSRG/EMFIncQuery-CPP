
#include"Logger.h"

#include<iostream>
#include<mutex>

std::mutex Viatra::Query::Util::Logger::mutex;

std::map<std::thread::id, std::string>& Viatra::Query::Util::Logger::threadNames()
{
	static std::map<std::thread::id, std::string> map; 
	return map;
}

std::function<void(const std::string&, const std::string)>& Viatra::Query::Util::Logger::loggerFunc()
{
	static std::function<void(const std::string&, const std::string)> func = 
	[](const std::string & threadName, const std::string message)
	{
		std::cout << "Thread=" << threadName << ", " << message << std::endl;
	};

	return func;
}
