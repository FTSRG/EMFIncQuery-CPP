
#ifndef _VIATRA_QUERY_DISTRIBUTED_QUERY_RUNNER_H_655365773
#define _VIATRA_QUERY_DISTRIBUTED_QUERY_RUNNER_H_655365773

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

				virtual void addTask(const Request& request, TaskID taskID, int body, int operation, std::string frame) = 0;

			};

			template<typename RootedQuery>
			class QueryRunner : public QueryRunnerBase
			{
				using ModelRoot = typename RootedQuery::ModelRoot;
				using Match = typename RootedQuery::Match;
				using Matcher = typename RootedQuery::Matcher;
				using QueryGroup = typename RootedQuery::QueryGroup;
				
				//std::unordered_set<Util::HierarchicalID<uint64_t>> remoteSubTaskIDs;
				Util::ConcurrentQueue<QueryTask<RootedQuery>> localTasks;

				QueryServiceBase *queryService;
				Matcher matcher;
				ModelRoot * modelRoot;
				QueryTask<RootedQuery> *currentTask;

			public:
				QueryRunner(uint64_t sessionID, ModelRoot * modelRoot, QueryServiceBase *queryService)
					: QueryRunnerBase(sessionID)
					, queryService(queryService)
					, modelRoot(modelRoot)
					, matcher(modelRoot, QueryGroup::instance()->context(), this)
				{}
				
				// Distribues the query execution to all the other nodes from a given state in the 
				// Runner Thread
				void PropagateFrameVector(int body, int operation, const std::string& encodedFrameVector ) {
					TaskID taskID = currentTask->createSubtask();
					service->createRemoteSubtasks(currentTask, body, operation, encodedFrameVector);
				}
				
				// add a remote incoming task to the query runner for process
				virtual void addTask(const Request& request, TaskID taskID, int body, int operation, std::string frame) override
				{
					auto collector = new QueryResultCollector<RootedQuery>(taskID, request, queryService, modelRoot);
					std::shared_ptr<QueryResultCollectorBase> shared_collector(collector);

					queryService->addSubResultCollector(sessionID, taskID, shared_collector, request);
					QueryTask<RootedQuery> task(taskID, frame, body, operation, collector);
					localTasks.push(std::move(task));
				}

				// Run the QueryRunners main processing loop
				void run()
				{
					while (!terminated)
					{
						try {

							QueryTaskT task = localTasks.pop(std::chrono::milliseconds(100));
							currentTask = &task;
							auto partialResult = matcher.continueExec(task.encodedFrameVector, task.bodyIndex, task.operationIndex);
							task.collector->addLocalMatches(std::move(partialResult));
							currentTask = nullptr;
						}
						catch (Viatra::Query::Util::ConcurrentQueueTimeout&){
						}
					}
				}

				// start global querying and returns a future to access the results of the query
				std::unique_ptr<QueryFutureBase> startGlobalQuery() {
					QueryFuture<RootedQuery> * future = new QueryFuture<RootedQuery>(
						QueryRunnerBase::shared_from_this()
						);
					std::unique_ptr<QueryFutureBase> unique(future); 

					std::map<int, std::string> body_frame = matcher.distributedStartPoint();

					runnerThread = std::make_unique<std::thread>([this]() {
						run();
					});

					return unique;
				}

				// starts local query serving
				std::unique_ptr<QueryFutureBase> startLocalQuery() {
					runnerThread = std::make_unique<std::thread>([this]() {
						run();
					});
				}
			};
					
		}
	}
}

#endif 
