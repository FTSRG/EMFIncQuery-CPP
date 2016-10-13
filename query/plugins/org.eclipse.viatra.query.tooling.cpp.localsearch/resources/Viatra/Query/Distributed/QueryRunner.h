
#ifndef _VIATRA_QUERY_DISTRIBUTED_QUERY_RUNNER_H_655365773
#define _VIATRA_QUERY_DISTRIBUTED_QUERY_RUNNER_H_655365773

#include"QueryRunnerDecl.h"

#include"QueryTask.h"
#include"QueryResultCollector.h"
#include"../Util/ConcurrentQueue.h"
#include"../Util/HierarchicalID.h"
#include"../Util/Logger.h"

#include<memory>
#include<atomic>
#include<exception>

namespace Viatra {
	namespace Query {
		namespace Distributed {
			
			// Distribues the query execution to all the other nodes from a given state
			// Runner Thread
			template<typename RootedQuery>
			void QueryRunner<RootedQuery>::PropagateFrameVector(int body, int operation, const std::string& encodedFrameVector) {
				Logger::Log("QueryRunner::PropagateFrameVector");
				TaskID taskID = currentTask->createRemoteSubtask();
				queryService->continueQueryRemotely(currentTask, body, operation, encodedFrameVector);
			}

			template<typename RootedQuery>
			void QueryRunner<RootedQuery>::addStartTask(std::weak_ptr<QueryFutureBase> future, int body, std::string encodedFrameVector) {
				Logger::Log("QueryRunner::addStartTask");
				Logger::Identer ident;

				Logger::Log("QueryRunner::addStartTask -- create toplevel result collector");
				auto taskID = TaskID::CreateTopLevel(body);
				auto collector = new QueryResultCollector<RootedQuery>(sessionID, taskID, queryService, modelRoot);
				std::shared_ptr<QueryResultCollectorBase> shared_collector(collector);

				Logger::Log("QueryRunner::addStartTask -- registering toplevel result collector");
				queryService->registerTopLevelResultCollector(sessionID, taskID, shared_collector, future);
				topLevelCollectorHolders.push_back(shared_collector);
				topLevelCollectors.push_back(collector);

				Logger::Log("QueryRunner::addStartTask -- Instantiate task");
				QueryTask<RootedQuery> task(taskID, encodedFrameVector, body, 0, collector);
				// Concurrent queue, so its thread safe to simply push our task
				localTasks.push(std::move(task));
			}

			// Run the QueryRunners main processing loop
			// runs on QueryRunner thread
			template<typename RootedQuery>
			void QueryRunner<RootedQuery>::run()
			{
				Util::Logger::SetThisThreadName(Util::concat("Runner-", sessionID));
				Logger::Log("QueryRunner::run");
				while (!terminated)
				{
					try {
						auto task = std::move(localTasks.pop(std::chrono::milliseconds(100)));
						currentTask = &task;
						auto partialResult = matcher.continueExec(task.encodedFrameVector, task.bodyIndex, task.operationIndex);
						task.collector->addLocalMatches(std::move(partialResult));
						currentTask = nullptr;
					}
					catch (Viatra::Query::Util::ConcurrentQueueTimeout&) {
					}
				}
			}

			template<typename RootedQuery>
			QueryRunner<RootedQuery>::QueryRunner(uint64_t sessionID, ModelRoot * modelRoot, QueryServiceBase *queryService, int queryID)
				: QueryRunnerBase(sessionID, queryID)
				, queryService(queryService)
				, modelRoot(modelRoot)
				, matcher(modelRoot, QueryGroup::instance()->context(), this)
			{
				Logger::Log("QueryRunner::QueryRunner");
			}
				
			// add a remote incoming task to the query runner for process
			// Custom thread
			template<typename RootedQuery>
			void QueryRunner<RootedQuery>::addTask(TaskID taskID, int body, int operation, std::string frame, const Request& request)
			{
				Logger::Log("QueryRunner::addTask");
				auto collector = new QueryResultCollector<RootedQuery>(sessionID, taskID, queryService, modelRoot);
				std::shared_ptr<QueryResultCollectorBase> shared_collector(collector);
					
				queryService->registerSubResultCollector(sessionID, taskID, shared_collector, request);

				QueryTask<RootedQuery> task(taskID, frame, body, operation, collector);
				// Concurrent queue, so its thread safe to simply push our task
				localTasks.push(std::move(task));
			}


			// start global querying and returns a future to access the results of the query
			template<typename RootedQuery>
			void QueryRunner<RootedQuery>::startGlobalQuery( std::weak_ptr<QueryFutureBase> future, typename RootedQuery::BindInfo bindInfo) {
				Logger::Log("QueryRunner::startGlobalQuery");
				Logger::Identer ident;
				if (runnerThread)
					throw std::logic_error("The query is already running!");

				Logger::Log("QueryRunner::startGlobalQuery -- Add starting tasks");
				for (auto &body_frame : bindInfo.encodedFrameVector)
					addStartTask(future, body_frame.first, body_frame.second);

				Logger::Log("QueryRunner::startGlobalQuery -- Starting runner thread");
				runnerThread = std::make_unique<std::thread>([this]() {
					run();
				});

			}

			// starts local query serving
			template<typename RootedQuery>
			std::unique_ptr<QueryFutureBase> QueryRunner<RootedQuery>::startLocalQuery() {
				Logger::Log("QueryRunner::startLocalQuery");
				Logger::Identer ident;
				if (runnerThread)
					throw std::logic_error("The query is already running!");

				Logger::Log("QueryRunner::startLocalQuery -- Starting runner thread");
				runnerThread = std::make_unique<std::thread>([this]() {
					run();
				});
			}



			template<typename RootedQuery>
			bool QueryRunner<RootedQuery>::ready() {
				Logger::Log("QueryRunner::ready");
				for (auto & collector : topLevelCollectorHolders)
				{
					if (!collector->finished()) {
						Logger::Log("QueryRunner::ready -- false");
						return false;
					}
				}
				Logger::Log("QueryRunner::ready -- true");
				return true;
			}
					
		}
	}
}

#endif 
