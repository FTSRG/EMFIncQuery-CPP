
#ifndef _VIATRA_QUERY_DISTRIBUTED_QUERYSERVICE_H_
#define _VIATRA_QUERY_DISTRIBUTED_QUERYSERVICE_H_

#ifdef _VIATRA_HEADER_ONLY_
#define VIATRA_FUNCTION inline
#else
#define VIATRA_FUNCTION
#endif
#define VIATRA_INLINE_FUNCTION inline

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

			class QueryResultCollectorBase;

			struct NodeInfo {
				std::string name;
				std::string ip;
				uint16_t port;

				// The client to the server on the node
				std::unique_ptr<QueryClient> client;
				// The Connection to our server from the node
				Network::Connection * connection;
			};

			// Type independent baseclass for QueryService
			class QueryServiceBase
			{
			public:
				QueryServiceBase(const char *configJSON, const char * nodeName);
				~QueryServiceBase();
			protected:

				std::map<std::string, NodeInfo> nodes;

				std::string nodeName;
				std::unique_ptr<QueryServer> server;
				
				IDGenerator querySessionIDGenerator;
				std::map< uint64_t , std::shared_ptr<QueryRunnerBase> > queryRunners;
				std::map< std::tuple<uint64_t, TaskID>, std::unique_ptr<QueryResultCollectorBase> > localResultCollectors;

			public:
				
				// Start Local Query Session on all other node and waiting for the result(stub)
				void StartRemoteQuerySessions(uint64_t sessionID, int queryID); 
				
				void acceptRemoteMatchSet(uint64_t sessionID, const TaskID& taskID, const std::string& encodedMatchSet);
				
				std::string initiateConnection(Network::Connection* connection, std::string nodeName)
				{
					if (nodes.find(nodeName) == nodes.end())
						return std::string("ERROR: No node named \"") + nodeName + "\" is part of the configuration in this server";
				}

				bool checkNodeConnection(std::string nodeName, Network::Connection * connection)
				{
					auto find = nodes.find(nodeName);
					if (find == nodes.end())
						return false;
					return find->second.connection == connection;
					
				}
				
				// Start Local Query Session on this node (implementation)
				virtual std::string startLocalQuerySession(uint64_t sessionID, int queryID) = 0;
				virtual void continueQuery(const std::string &nodeName, uint64_t sessionID, const TaskID& taskID, int body, int operation, const std::string& frame) = 0;
				

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
					using RootedQuery = QueryTemplate<ModelRoot>;

					auto sessionID = querySessionIDGenerator.generate();
					auto queryID = RootedQuery::queryID;
					StartLocalQuerySession(sessionID, queryID);
					StartRemoteQuerySessions(sessionID, queryID);

					auto future = queryRunners[sessionID]->start();


					std::unique_ptr<QueryFuture<RootedQuery>> ret{
						dynamic_cast<QueryFuture<RootedQuery>*>(future.get())
					};
					// on succesful dynamic cast
					future.release();
					return ret;
				}
							

				/*
				template<typename QuerySpec>
				std::future<std::unordered_set<MatchT<QuerySpec>>> DistributeToNodes(

				);**/

				void run() {};

				std::thread run_async() {
					std::thread t(
							[this]() {
								this->run();
					});
					return std::move(t);
				}

				virtual std::string startLocalQuerySession(uint64_t sessionID, int queryID) override
				{
					if (queryRunners[sessionID])
						return "ERROR: QuerySession with the given sessionID is already running in this node!";

					queryRunners[sessionID] = QueryRunnerFactory::Create(queryID, sessionID, &modelRoot);
					return "OK";
				}

				virtual void continueQuery(std::string nodeName, uint64_t sessionID, TaskID taskID, int body, int operation, std::string frame) override
				{
					auto runner = queryRunners.at(sessionID);
					runner->addTask(nodeName, taskID, body, operation, frame);
				}
			};
		}
	}
}

#ifdef _VIATRA_HEADER_ONLY_
#include"QueryService.cpp"
#endif

#endif
