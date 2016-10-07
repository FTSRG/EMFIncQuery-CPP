
#include"QueryService.h"

#include"MessageProtocol.pb.h"
#include"QueryResultCollector.h"
#include"picojson.h"

using namespace Viatra::Query::Distributed;

/*
class QueryServiceBase
{
	std::string nodeName;
	std::unique_ptr<QueryServer> server;
	std::map<std::string, std::unique_ptr<QueryClient>> clients;

	IDGenerator querySessionIDGenerator;
	std::map < int, std::unique_ptr<QueryRunnerBase> > queryRunners;
};
*/

QueryServiceBase::QueryServiceBase(const char * configJSON, const char * nodeName)
{
	
}

QueryServiceBase::~QueryServiceBase()
{

}

void QueryServiceBase::StartRemoteQuerySession(uint64_t sessionID, int queryID)
{
	Protobuf::QueryRequest request;
	request.set_rqid(0);

	Network::Buffer buffer(request);

	for (auto & c : clients)
		c.second->sendMessage(buffer.copy());
}

