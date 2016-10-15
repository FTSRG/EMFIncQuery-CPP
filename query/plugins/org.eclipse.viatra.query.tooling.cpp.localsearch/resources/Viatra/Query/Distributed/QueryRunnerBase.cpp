
#include"QueryRunnerDecl.h"

using namespace Viatra::Query::Distributed;


QueryRunnerBase::QueryRunnerBase(uint64_t sessionID, int queryID)
	: sessionID(sessionID)
	, queryID(queryID)
{
	Logger::Log("QueryRunnerBase::QueryRunnerBase sessionID=", sessionID, ", queryID=", queryID);
}
QueryRunnerBase::~QueryRunnerBase()
{
	Logger::Log("QueryRunnerBase::~QueryRunnerBase");
	terminate();
	join();
}

void QueryRunnerBase::terminate() {
	Logger::Log("QueryRunnerBase::terminate");
	terminated = true;
}

void QueryRunnerBase::join() {
	Logger::Log("QueryRunnerBase::join");
	if (runnerThread)
		runnerThread->join();
	else
		Util::Logger::Log("Join called on a non-running QueryRunner!");
}


bool QueryRunnerBase::ready() {
	return _ready.load(std::memory_order::memory_order_acquire);
}
