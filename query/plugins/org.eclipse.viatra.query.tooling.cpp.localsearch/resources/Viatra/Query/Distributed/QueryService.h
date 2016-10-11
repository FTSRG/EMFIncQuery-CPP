
#ifndef _VIATRA_QUERY_DISTRIBUTED_QUERYSERVICE_H_34r12413__
#define _VIATRA_QUERY_DISTRIBUTED_QUERYSERVICE_H_34r12413__

#include<memory>
#include<unordered_set>
#include<mutex>
#include<map>
#include<future>
#include<unordered_set>

#include"../Model/IModelElemService.h"


#include"QueryRunner.h"
#include"QueryServer.h"
#include"QueryClient.h"
#include"IDGenerator.h"
#include"QueryFuture.h"

namespace Viatra {
	namespace Query {
		namespace Distributed {

			class QueryFutureBase;
			class QueryTaskBase;
			class QueryResultCollectorBase;

			// Information struct for a processing node
			struct NodeInfo {
				std::string name;
				std::string ip;
				uint16_t port;

				// The client for the server on the remote node
				std::unique_ptr<QueryClient> client;
				// The Connection in our server to the remote node
				Network::Connection * connection;
			};

			// Information struct about the collection of results of a subtask
			struct CollectorInfo {
				// true for response being served, false for the top-level result collector
				bool remote;
				// Collector class which collects the subresult
				std::shared_ptr<QueryResultCollectorBase> collector;
				
				// nodename in case of remote sequests being served
				std::string nodeName;
				
				// in case its a top level result collector
				QueryFutureBase *future;
				
				
				
				CollectorInfo(bool remote, std::shared_ptr<QueryResultCollectorBase> collector, std::string nodeName, QueryFutureBase *future)
					: remote(remote)
					, collector(std::move(collector))
					, nodeName(std::move(nodeName))
					, future(future)
				{}

			};

			// Type independent baseclass for QueryService
			class QueryServiceBase
			{

			public:
				QueryServiceBase(const char *configJSON, const char * nodeName);
				~QueryServiceBase();
			protected:
				using Lock = std::unique_lock<std::recursive_mutex>;
				std::recursive_mutex mutex;
				std::map<std::string, NodeInfo> remoteNodes;

				std::string nodeName;
				std::unique_ptr<QueryServer> server;
				
				IDGenerator querySessionIDGenerator;
				std::map< uint64_t , std::shared_ptr<QueryRunnerBase> > queryRunners;

				// ResultCollectors for remote tasks
				std::map< uint64_t, std::map<TaskID, std::shared_ptr<CollectorInfo>, TaskID::compare > > localResultCollectors;
				
			public:

				void addSubResultCollector(uint64_t sessionID, TaskID taskID, std::shared_ptr<QueryResultCollectorBase> collector, std::string destNode)
				{
					Lock lck(mutex);
					localResultCollectors[sessionID][taskID] = std::make_shared<CollectorInfo>(true, collector, destNode, nullptr);
				}

				void addTopLevelResultCollector(uint64_t sessionID, TaskID taskID, std::shared_ptr<QueryResultCollectorBase> collector, QueryFutureBase *future)
				{
					Lock lck(mutex);
					localResultCollectors[sessionID][taskID] = std::make_shared<CollectorInfo>(false, collector, "", future);
				}
				
				// Start Local Query Session on all other node and waiting for the result(stub)
				void startRemoteQuerySessions(uint64_t sessionID, int queryID); 
				
				void acceptRemoteMatchSet(uint64_t sessionID, const TaskID& taskID, const std::string& encodedMatchSet);
				
				std::string initiateConnection(Network::Connection* connection, std::string nodeName)
				{
					Lock lck(mutex);
					if (remoteNodes.find(nodeName) == remoteNodes.end())
						return std::string("ERROR: No node named \"") + nodeName + "\" is part of the configuration in this server";
				}

				bool checkNodeConnection(std::string nodeName, Network::Connection * connection)
				{
					Lock lck(mutex);
					auto find = remoteNodes.find(nodeName);
					if (find == remoteNodes.end())
						return false;
					return find->second.connection == connection;
				}
				
				// runs on Server Thread
				virtual std::string startLocalQuerySession(uint64_t sessionID, int queryID) = 0;
				// runs on Server Thread
				virtual void continueQueryLocally(const Request& request, uint64_t sessionID, const TaskID& taskID, int body, int operation, const std::string& frame) = 0;
				
				// runs on QueryRunner Thread
				void continueQueryRemotely(QueryTaskBase* currentTask, int body, int operation, const std::string& encodedFrameVector);


			};

			template<typename ModelRoot, template<typename> class QueryRunnerFactoryTemplate>
			class QueryService : public QueryServiceBase
			{
			private:
				ModelRoot modelRoot;
			public:
				using QueryRunnerFactory = QueryRunnerFactoryTemplate<ModelRoot>;

				// Helper type functions for a Query Class
				template<template<typename>typename QueryTemplate> using MatchOf = typename QueryTemplate<ModelRoot>::Match;
				template<template<typename>typename QueryTemplate> using MatcherOf = typename QueryTemplate<ModelRoot>::Matcher;
				
				VIATRA_FUNCTION QueryService(const char *configJSON, const char *nodeName)
					: QueryServiceBase(configJSON, nodeName)
					, modelRoot(configJSON, nodeName)
				{
				}
				VIATRA_FUNCTION ~QueryService()
				{

				}

				// usage: queryService.RunNewQuery<QueryName>()
				template<  template<typename>class QueryTemplate, class RootedQuery = QueryTemplate<ModelRoot> >
				std::unique_ptr<QueryFuture<RootedQuery>> RunNewQuery()
				{
					Lock lck(mutex);
					using RootedQuery = QueryTemplate<ModelRoot>;

					auto sessionID = querySessionIDGenerator.generate();
					auto queryID = RootedQuery::queryID;
					
					startLocalQuerySession(sessionID, queryID);
					startRemoteQuerySessions(sessionID, queryID);

					auto future = queryRunners[sessionID]->start();

					std::unique_ptr<QueryFuture<RootedQuery>> ret{
						dynamic_cast<QueryFuture<RootedQuery>*>(future.get())
					};
					// on succesful dynamic cast
					future.release();
					return ret;
				}

				virtual std::string startLocalQuerySession(uint64_t sessionID, int queryID) override
				{
					Lock lck(mutex);
					if (queryRunners[sessionID])
						return "ERROR: QuerySession with the given sessionID is already running in this node!";

					queryRunners[sessionID] = QueryRunnerFactory::Create(queryID, sessionID, &modelRoot, this);
					return "OK";
				}

				virtual void continueQueryLocally(const Request& request, uint64_t sessionID, const TaskID& taskID, int body, int operation, const std::string& frame) override
				{
					Lock lck(mutex);
					auto runner = queryRunners.at(sessionID);
					runner->addTask(request, taskID, body, operation, frame);
				}
			};
		}
	}
}


#endif
