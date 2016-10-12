
#include"QueryService.h"

#include"MessageProtocol.pb.h"
#include"QueryResultCollector.h"
#include"QueryTask.h"
#include"picojson.h"

#include<fstream>


using namespace Viatra::Query::Distributed;

/*
{
	"nodes" : [
		{
			"name" : "nodeA",
			"ip" : "127.0.0.1",
			"port" : 54321,
			"IDGenStart" : 0,
			"IDGenMod": 10
		},
		...
	]
}
*/

QueryServiceBase::QueryServiceBase(const char * configJSON, const char * localNodeName)
{
	using Util::Logger;
	Logger::Log("QueryServiceBase");

	if (localNodeName == std::string())
		throw std::invalid_argument("local Node must be a non-empty string");
	try {

		Logger::Log("Processing json");

		std::ifstream ifs(configJSON);
		picojson::value root;
		std::string err = picojson::parse(root, ifs);
		if (!err.empty()) {
			throw err;
		}

		this->nodeName = "";
		auto nodeArray = root.get("nodes").get<picojson::value::array>();
		for (auto & node : nodeArray)
		{
			auto name = node.get("name").get<std::string>();
			auto ip = node.get("ip").get<std::string>();
			auto port = node.get("port").get<int64_t>();
			auto IDGenStart = node.get("IDGenStart").get<int64_t>();
			auto IDGenMod = node.get("IDGenMod").get<int64_t>();

			if (name == localNodeName)
			{
				Logger::Log("Local node found:", name);
				if (this->nodeName != "")
					throw std::logic_error("The node configuration file contains multiple nodes with the same name");
				this->nodeName = name;
				this->querySessionIDGenerator.reconfigurate(IDGenStart, IDGenMod);

				this->server = std::make_unique<QueryServer>((uint16_t)port, this);

			}
			else
			{
				Logger::Log("Remote node found:", name);
				if (remoteNodes.count(name) > 0)
					throw std::logic_error("The node configuration file contains multiple nodes with the same name");

				auto & nodeInfo = remoteNodes[name];
				nodeInfo.name = name;
				nodeInfo.ip = ip;
				nodeInfo.port = (uint16_t)port;
			}
		}

		Logger::Log("Starting the server...");
		server->runAsync();
		Logger::Log("Server started");

		using std::chrono::system_clock;
		std::chrono::seconds timeout(60);
		system_clock::time_point start = system_clock::now();

		Logger::Log("Starting the clients...");
		for (auto & name_node : remoteNodes)
		{
			auto & nodeInfo = name_node.second;

			while (true)
			{
				try {
					nodeInfo.client = std::make_unique<QueryClient>(nodeInfo.ip, (uint16_t)nodeInfo.port, this->nodeName);
					break;
				}
				catch (...)
				{
					if (system_clock::now() - start > timeout)
					{
						server = nullptr;
						throw;
					}
				}
			}
		}

		Logger::Log("Clients started...");

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
