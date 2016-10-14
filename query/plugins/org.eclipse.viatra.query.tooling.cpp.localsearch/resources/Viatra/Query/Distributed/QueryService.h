
#ifndef _VIATRA_QUERY_DISTRIBUTED_QUERYSERVICE_H_34r12413__
#define _VIATRA_QUERY_DISTRIBUTED_QUERYSERVICE_H_34r12413__


#include<map>
#include<mutex>
#include<atomic>
#include<future>
#include<memory>
#include<unordered_set>

#include"../Model/IModelElemService.h"
#include"../Util/Logger.h"

#include"QueryRunnerDecl.h"
#include"QueryServer.h"
#include"QueryClient.h"
#include"IDGenerator.h"
#include"QueryFuture.h"

namespace Viatra {
	namespace Query {
		namespace Distributed {

			class QueryFutureBase;
			struct QueryTaskBase;
			class QueryResultCollectorBase;

			// Information struct for a processing node
			struct NodeInfo {
				std::string name;
				std::string ip;
				uint16_t port;

				// The client for the server on the remote node
				std::unique_ptr<QueryClient> client;
				// The Connection in our server to the remote node
			//	std::atomic<Network::Connection*> connection = nullptr;
			};

			// Information struct about the collection of results of a subtask
			struct CollectorInfo {
				// true for response being served, false for the top-level result collector
				bool remote;
				// Collector class which collects the subresult
				std::shared_ptr<QueryResultCollectorBase> collector;
				
				// nodename in case of remote sequests being served
				Request rq;
				
				// in case its a top level result collector
				std::weak_ptr<QueryFutureBase> future;
				
				CollectorInfo(bool remote, std::shared_ptr<QueryResultCollectorBase> collector, const Request& rq, std::weak_ptr<QueryFutureBase> future)
					: remote(remote)
					, collector(std::move(collector))
					, rq(rq)
					, future(future)
				{}

			};

			// Type independent baseclass for QueryService
			class QueryServiceBase
			{
				template<typename>
				friend class QueryRunner;
			public:
				QueryServiceBase(const char *configJSON, const char * nodeName);
				~QueryServiceBase();
			protected:
				using Logger = Util::Logger;

				using Lock = std::unique_lock<std::recursive_mutex>;
				std::recursive_mutex mutex;

				// This map is fixed after construction, only the value's fields changes
				std::map<std::string, NodeInfo> remoteNodes;

				std::string nodeName;
				std::unique_ptr<QueryServer> server;
				
				IDGenerator querySessionIDGenerator;
				std::map< uint64_t , std::shared_ptr<QueryRunnerBase> > queryRunners;

				// ResultCollectors for remote tasks
				std::map< 
					uint64_t /* sessionID*/, 
					std::map<TaskID, std::shared_ptr<CollectorInfo>, TaskID::compare > 
				> localResultCollectorInfos;
				
				void registerTopLevelResultCollector(uint64_t sessionID, TaskID taskID, std::shared_ptr<QueryResultCollectorBase> collector, std::weak_ptr<QueryFutureBase> future)
				{
					Lock lck(mutex);
					localResultCollectorInfos[sessionID][taskID] = std::make_shared<CollectorInfo>(false, collector, Request{ nullptr, 0 }, future);
				}

			public:
				void start();

				void registerSubResultCollector(uint64_t sessionID, TaskID taskID, std::shared_ptr<QueryResultCollectorBase> collector, const Request& request)
				{
					Lock lck(mutex);
					localResultCollectorInfos[sessionID][taskID] = std::make_shared<CollectorInfo>(true, collector, request, std::weak_ptr<QueryFutureBase>());
				}
				
				// Start Local Query Session on all other node and waiting for the result(stub)
				void startRemoteQuerySessions(uint64_t sessionID, int queryID); 
				
				void acceptRemoteMatchSet(uint64_t sessionID, const TaskID& taskID, const std::string& encodedMatchSet);
				
				std::string process_initiateConnection(Network::Connection* connection, std::string nodeName)
				{
					Lock lck(mutex);
					if (remoteNodes.find(nodeName) == remoteNodes.end())
						return std::string("ERROR: No node named \"") + nodeName + "\" is part of the configuration in this server";
					return "OK";
				}

				/***
				bool checkNodeConnection(std::string nodeName, Network::Connection * connection)
				{
					Lock lck(mutex);
					auto find = remoteNodes.find(nodeName);
					if (find == remoteNodes.end())
						return false;
					
				}*/
				
				// runs on Server Thread
				virtual std::string startLocalQuerySession(uint64_t sessionID, int queryID) = 0;
				// runs on Server Thread
				void continueQueryLocally(const Request& request, uint64_t sessionID, const TaskID& taskID, int body, int operation, const std::string& frame)
				{
					Logger::Log("QueryServiceBase::continueQueryLocally");
					Lock lck(mutex);
					auto runner = queryRunners.at(sessionID);
					runner->addTask(taskID, body, operation, frame, request);
				}
				// runs on QueryRunner Thread
				void continueQueryRemotely(uint64_t sessionID, QueryTaskBase* currentTask, int body, int operation, const std::string& encodedFrameVector);

				// If the collection is done this function will be called
				void notifyCollectionDone(uint64_t sessionID, const TaskID& taskID);

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
				
				QueryService(const char *configJSON, const char *nodeName)
					: QueryServiceBase(configJSON, nodeName)
					, modelRoot(configJSON, nodeName)
				{
					Util::Logger::Log("QueryService::construct QueryService");
				}
				~QueryService()
				{
					Util::Logger::Log("QueryService::destruct QueryService");

				}
				
				// usage: queryService.RunNewQuery<QueryName>()
				template<
					class QueryClass, 
					class BindClass = typename QueryClass::NoBind, 
					class RootedQuery = typename QueryClass::RootedQuery<ModelRoot>,
					class... PARAMS
				>
				std::shared_ptr<QueryFuture<RootedQuery>> RunNewQuery(PARAMS... params)
				{
					Util::Logger::Log("QueryService::RunNewQuery");
					Util::Logger::Identer ident;

					static_assert(std::is_same<typename BindClass::QueryClass, QueryClass>::value, 
						"Bind class must be the query-s bind class!");
					static_assert(std::is_same<typename QueryClass::RootedQuery<ModelRoot>, RootedQuery>::value, 
						"Do not modify RootedQuery template parameter, use its default type");

					Lock lck(mutex);

					auto sessionID = querySessionIDGenerator.generate();
					auto queryID = BindClass::queryID;

					Util::Logger::Log("QueryService::RunNewQuery sessionID=", sessionID, ", queryID=", queryID);


					Util::Logger::Log("QueryService::RunNewQuery create QueryRunner");
					if (queryRunners[sessionID])
						throw std::logic_error("ERROR: QuerySession with the given sessionID is already running in this node! Check the ID generator settings!");
					auto queryRunner = std::make_shared<QueryRunner<RootedQuery>>(sessionID, &modelRoot, this, queryID);
					queryRunners[sessionID] = std::static_pointer_cast<QueryRunnerBase>(queryRunner);

					startRemoteQuerySessions(sessionID, queryID);

					Util::Logger::Log("QueryService::RunNewQuery create Future object");
					auto future = std::make_shared<QueryFuture<RootedQuery>>(queryRunner);

					//Util::Logger::Log("QueryService::RunNewQuery Building frames");
					auto builtFrames = BindClass::BuildFrames(params...);

					Util::Logger::Log("QueryService::RunNewQuery start Global querying");
					queryRunner->startGlobalQuery(std::static_pointer_cast<QueryFutureBase>(future), builtFrames);

					return future;
				}

				std::string startLocalQuerySession(uint64_t sessionID, int queryID) override
				{
					Util::Logger::Log("QueryService::startLocalQuerySession");
					Lock lck(mutex);
					if (queryRunners[sessionID])
						return "ERROR: QuerySession with the given sessionID is already running in this node!";

					std::shared_ptr<QueryRunnerBase> queryRunner = QueryRunnerFactory::Create(queryID, sessionID, &modelRoot, this);
					queryRunners[sessionID] = queryRunner;
					queryRunner->startLocalQueryServing();
					return "OK";
				}
								
			};
		}
	}
}


#endif
