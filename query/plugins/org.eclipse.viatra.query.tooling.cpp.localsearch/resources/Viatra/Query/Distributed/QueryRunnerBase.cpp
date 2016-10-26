
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
	this->runnerThread->join();
}

void QueryRunnerBase::terminate() {
	Logger::Log("QueryRunnerBase::terminate");
	terminated = true;
}
