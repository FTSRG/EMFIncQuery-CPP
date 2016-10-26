
#include"QueryService.h"

#include"MessageProtocol.pb.h"
#include"QueryResultCollector.h"
#include"QueryTask.h"
#include"picojson.h"
#include"../Util/Logger.h"

#include<fstream>


using namespace Viatra::Query::Distributed;
using namespace Viatra::Query::Util;

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
	Logger::Log("QueryServiceBase::QueryServiceBase");
	Logger::Identer id;

	if (localNodeName == std::string())
		throw std::invalid_argument("local Node must be a non-empty string");

	Logger::Log("Processing json");

	std::ifstream ifs(configJSON);
	picojson::value root;
	std::string err = picojson::parse(root, ifs);
	if (!err.empty()) {
		throw "JSON parse error: " + err;
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

}

void QueryServiceBase::start()
{
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
				nodeInfo.client = std::make_unique<QueryClient>(nodeInfo.ip, (uint16_t)nodeInfo.port, this->nodeName, this);
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
	Logger::Log("Waiting for client response");
	for (auto & name_node : remoteNodes)
	{
		auto & nodeInfo = name_node.second;

		while (!nodeInfo.client->ready())
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			if (system_clock::now() - start > timeout)
				std::string("Waiting for clients timeouted");			
		}
	}
	Logger::Log("Clients started...");
}

QueryServiceBase::~QueryServiceBase()
{

}

void QueryServiceBase::startRemoteQuerySessions(uint64_t sessionID, int queryID)
{
	Logger::Log("QueryServiceBase::startRemoteQuerySessions");
	Logger::Identer id;
	for (auto & name_node : remoteNodes)
	{
		auto & node = name_node.second;
		node.client->startQuerySession(sessionID, queryID);
	}		

	Logger::Log();
	for (auto & name_node : remoteNodes)
	{
		auto & node = name_node.second;
		while (!node.client->isQuerySessionReady(sessionID))
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}

	Logger::Log("QueryServiceBase::startRemoteQuerySessions - Waiting for query sessions to start... done");

}


void QueryServiceBase::acceptRemoteMatchSet(uint64_t sessionID, const TaskID& taskID, const std::string& encodedMatchSet)
{
	Lock lck;
	TaskID parent = taskID.parent();

	Logger::Log("QueryServiceBase::acceptRemoteMatchSet", taskID, " --> ", parent);

	auto & it = localResultCollectorInfos.find(sessionID);

	if (it == localResultCollectorInfos.end())
	{
		Logger::Log("There is no such session so processing the incoming match result is impossible");
		throw std::logic_error("There is no such session so processing the incoming match result is impossible");
	}
	auto & collectorInfoIt = it->second.find(parent);
	if (collectorInfoIt == it->second.end())
	{
		Logger::Log("The parent task is not in the collector map, so it cannot be processsed");
		throw std::logic_error("The parent task is not in the collector map, so it cannot be processsed");
	}


	collectorInfoIt->second->collector->addRemoteMatches(encodedMatchSet, taskID);
}


// runs on QueryRunner Thread
void QueryServiceBase::continueQueryRemotely(uint64_t sessionID, QueryTaskBase* parentTask, int body, int operation, const std::string& encodedFrameVector)
{
	Logger::Log("QueryServiceBase::continueQueryRemotely");
	for (auto & name_nodeInfo : remoteNodes) {
		TaskID taskID = parentTask->createRemoteSubtask();
		auto & nodeInfo = name_nodeInfo.second;
		nodeInfo.client->continueQuerySession(nodeName, sessionID, taskID, body, operation, encodedFrameVector);

	}
}

void QueryServiceBase::notifyCollectionDone(uint64_t sessionID, const TaskID& taskID)
{
	Lock lck(mutex);
	Util::Logger::Log("QueryServiceBase::notifyCollectionDone");
	Util::Logger::Identer();

	auto & collectorInfo = localResultCollectorInfos[sessionID].at(taskID);
	if (collectorInfo->remote)
	{
		Util::Logger::Log("server->sendMatchResults");
		server->sendMatchResults(collectorInfo->rq, "OK", sessionID, taskID, collectorInfo->collector->matchesAsString());
	}
	else
	{
		Util::Logger::Log("notifying runner that a collector is done");
		auto future = collectorInfo->future.lock();
		queryRunners[sessionID]->notifyCollectionDone();
	}

	localResultCollectorInfos[sessionID].erase(taskID);
}


