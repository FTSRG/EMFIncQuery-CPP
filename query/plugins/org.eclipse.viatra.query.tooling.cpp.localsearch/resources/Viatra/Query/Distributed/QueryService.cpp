
#include"QueryService.h"

#include"MessageProtocol.pb.h"
#include"QueryResultCollector.h"
#include"QueryTask.h"
#include"picojson.h"

#include<fstream>


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
	try {
		std::ifstream ifs(configJSON);
		picojson::value root;
		std::string err = picojson::parse(root, ifs);
		if (!err.empty()) {
			throw err;
		}

		auto elements = root.get("model").get<picojson::value::array>();


	}
	catch (...)
	{
		throw;
	}
}

QueryServiceBase::~QueryServiceBase()
{

}

void QueryServiceBase::startRemoteQuerySessions(uint64_t sessionID, int queryID)
{
	Protobuf::QueryRequest request;
	request.set_rqid(0);

	Network::Buffer buffer(request);

	for (auto & node : remoteNodes)
		throw "Not implemented QueryService.cpp StartRemoteQuerySessions";//	node.second.client->sendRequest(buffer.copy());
}


void QueryServiceBase::acceptRemoteMatchSet(uint64_t sessionID, const TaskID& taskID, const std::string& encodedMatchSet)
{
	TaskID parent = taskID.parent();
	auto & collectorInfo = localResultCollectors.at(sessionID).at(taskID);
	collectorInfo->collector->addRemoteMatches(encodedMatchSet, taskID);

}


// runs on QueryRunner Thread
void QueryServiceBase::continueQueryRemotely(QueryTaskBase* parentTask, int body, int operation, const std::string& encodedFrameVector)
{
	for (auto & name_nodeInfo : remoteNodes) {
		auto & nodeInfo = name_nodeInfo.second;
		TaskID taskID = parentTask->createRemoteSubtask();
	}
}
