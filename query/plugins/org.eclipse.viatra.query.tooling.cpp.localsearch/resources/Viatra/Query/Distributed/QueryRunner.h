
#ifndef _VIATRA_QUERY_DISTRIBUTED_QUERY_RUNNER_H_
#define _VIATRA_QUERY_DISTRIBUTED_QUERY_RUNNER_H_

#include"QueryTask.h"
#include"QueryResultCollector.h"
#include"../Util/ConcurrentQueue.h"
#include"../Util/HierarchicalID.h"

#include<memory>
#include<atomic>
#include<exception>

namespace Viatra {
	namespace Query {
		namespace Distributed {

			class QueryFutureBase;
			class QueryServiceBase;
			
			class QueryRunnerBase : public std::enable_shared_from_this<QueryRunnerBase>{
			protected:
				uint64_t sessionID;
				std::atomic<bool> terminated;
				std::atomic<bool> _ready;
				std::unique_ptr<std::thread> runnerThread;

			public:
				QueryRunnerBase(uint64_t sessionID) 
					: sessionID(sessionID)
				{}
				virtual ~QueryRunnerBase() 
				{
					terminate();
					join();
				}

				virtual std::unique_ptr<QueryFutureBase> start() = 0;

				void terminate(){ terminated = true; }
				void join()	{ 
					if (runnerThread)
						runnerThread->join();
					else
						throw std::logic_error("Join called on a non-running QueryRunner!");
				}
				bool ready() { return _ready; }

				virtual void addTask(const std::string& nodeName, TaskID taskID, int body, int operation, std::string frame) = 0;

			};

			template<typename RootedQuery>
			class QueryRunner : public QueryRunnerBase
			{
				using ModelRoot = typename RootedQuery::ModelRoot;
				using Match = typename RootedQuery::Match;
				using Matcher = typename RootedQuery::Matcher;
				using QueryGroup = typename RootedQuery::QueryGroup;
				using QueryTaskT = QueryTask<RootedQuery>;
				
				//std::unordered_set<Util::HierarchicalID<uint64_t>> remoteSubTaskIDs;
				Util::ConcurrentQueue<QueryTaskT> localTasks;

				QueryServiceBase *queryService;
				Matcher matcher;
				ModelRoot * modelRoot;
				TaskID currentTaskID;

			public:
				QueryRunner(uint64_t sessionID, ModelRoot * modelRoot, QueryServiceBase *queryService)
					: QueryRunnerBase(sessionID)
					, queryService(queryService)
					, modelRoot(modelRoot)
					, matcher(modelRoot, QueryGroup::instance()->context(), this)
				{}

				// Distribues the query execution to all the other nodes from a given state in the body
				void GlobalIterateOverInstances(int bodyIndex, int opIndex, std::string encodedFrame) {

				}
				
				virtual void addTask(const std::string& destNodeName, TaskID taskID, int body, int operation, std::string frame) override
				{
					auto collector = new QueryResultCollector<RootedQuery>(taskID, destNodeName, queryService, modelRoot);
					auto shared_collector = std::shared_ptr<QueryResultCollectorBase>(collector);

					queryService->addSubResultCollector(sessionID, taskID, shared_collector, destNodeName);
					QueryTaskT task(frame, body, operation, collector);
					localTasks.push(std::move(task));
				}

				void run()
				{
					while (!terminated)
					{
						try {

							QueryTaskT task = localTasks.pop(std::chrono::milliseconds(100));
							currentTaskID = task.id;
							auto partialResult = matcher.continueExec(task.EncodedMatchingFrame, task.bodyIndex, task.operationIndex);
							task.collector->addLocalMatches(std::move(partialResult));


						}
						catch (Viatra::Query::Util::ConcurrentQueueTimeout&){
						}
					}
				}

				std::unique_ptr<QueryFutureBase> start() {
					QueryFuture<RootedQuery> * future = new QueryFuture<RootedQuery>(
						QueryRunnerBase::shared_from_this()
						);
					std::unique_ptr<QueryFutureBase> unique(future);

					runnerThread = std::make_unique<std::thread>([this]() {
						run();
					});

					return unique;
				}
			};
					
		}
	}
}

#endif 
