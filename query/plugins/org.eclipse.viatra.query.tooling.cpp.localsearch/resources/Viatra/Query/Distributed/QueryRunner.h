
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
				queryService->continueQueryRemotely(sessionID, currentTask, body, operation, encodedFrameVector);
			}
			
			// Run the QueryRunners main processing loop
			// runs on QueryRunner thread
			template<typename RootedQuery>
			void QueryRunner<RootedQuery>::run()
			{
				try {
					Util::Logger::SetThisThreadName(Util::concat("Runner-", sessionID));
					Logger::Log("QueryRunner::run");
					while (!terminated)
					{
						Logger::Log("QueryRunner::while");
						Logger::Identer ident2;

						try {
							Logger::Log("QueryRunner::run -- try to pop task from queue");
							auto task = std::move(localTasks.pop(std::chrono::milliseconds(100)));
							Logger::Log("QueryRunner::run -- task obtained id=", task.id);

							currentTask = &task;

							typename Match::MatchSet partialResult;
							{
								Logger::Log("QueryRunner::run -- calculating partial result");
								Logger::Identer ident3;

								auto lck = modelRoot->acquireLock();
								partialResult = matcher.continueExec(task.encodedFrameVector, task.bodyIndex, task.operationIndex);
							}

							currentTask = nullptr;
							Logger::Log("QueryRunner::run -- add subresult to collector");
							if (auto sptr = task.collector.lock())
								sptr->addLocalMatches(std::move(partialResult));
							else
								throw std::logic_error("QueryRunner::run -- ERROR: weak pointer was invalidated before usage");
						}
						catch (Viatra::Query::Util::ConcurrentQueueTimeout&) {
							std::this_thread::sleep_for(std::chrono::seconds(1));
						}
						Logger::Log("QueryRunner::run -- terminated = ", (bool)terminated);
					}
				}
				catch (const std::exception& ex)
				{
					Logger::Log(ex.what());
				}
				catch (const std::string& ex)
				{
					Logger::Log(ex);
				}
				catch (const char *c)
				{
					Logger::Log(c);
				}
				catch (...)
				{
					Logger::Log("Something catched other than std::exception, string, or const char*");
				}
			}

			template<typename RootedQuery>
			QueryRunner<RootedQuery>::QueryRunner(uint64_t sessionID, ModelRoot * modelRoot, QueryServiceBase *queryService, int queryID, std::map<int, std::string> startingEncodedFrames)
				: QueryRunnerBase(sessionID, queryID)
				, queryService(queryService)
				, modelRoot(modelRoot)
				, matcher(modelRoot, QueryGroup::instance()->context(), this)
				, startingEncodedFrames(startingEncodedFrames)
			{
				Logger::Log("QueryRunner::QueryRunner");
			}
				
			// add a remote incoming task to the query runner for process
			// Custom thread
			template<typename RootedQuery>
			void QueryRunner<RootedQuery>::addTask(TaskID taskID, int body, int operation, std::string frame, const Request& request)
			{
				Lock lck(futureMutex);
				Logger::Log("QueryRunner::addTask");
				auto collector = new QueryResultCollector<RootedQuery>(sessionID, taskID, queryService, modelRoot);
				std::shared_ptr<QueryResultCollector<RootedQuery>> shared_collector(collector);
					
				queryService->registerSubResultCollector(sessionID, taskID, std::static_pointer_cast<QueryResultCollectorBase>(shared_collector), request);

				QueryTask<RootedQuery> task(taskID, frame, body, operation, shared_collector);
				// Concurrent queue, so its thread safe to simply push our task
				localTasks.push(std::move(task));
			}

			// start global querying and returns a future to access the results of the query
			template<typename RootedQuery>
			std::shared_ptr<QueryFuture<RootedQuery>> QueryRunner<RootedQuery>::startGlobalQuery() {
				Logger::Log("QueryRunner::startGlobalQuery");
				Logger::Identer ident;

				auto bodyCount = startingEncodedFrames.size();
				std::vector<std::shared_ptr<QueryResultCollector<RootedQuery>>> topLevelCollectors(bodyCount);
				std::vector<TaskID> topLevelIDs(bodyCount);
				
				int b = 0;
				Logger::Log("QueryRunner::startGlobalQuery -- Create starting tasks");
				for (auto &body_frame : startingEncodedFrames)
				{
					auto taskID = TaskID::CreateTopLevel((int)topLevelTaskIDGen.generate());
					auto collector = new QueryResultCollector<RootedQuery>(sessionID, taskID, queryService, modelRoot);
					std::shared_ptr<QueryResultCollector<RootedQuery>> shared_collector(collector);
					topLevelCollectors[b] = std::move(shared_collector);
					topLevelIDs[b] = taskID;
					++b;
				}
				
				std::shared_ptr<QueryFuture<RootedQuery>> future(new QueryFuture<RootedQuery>(shared_from_this(), topLevelCollectors));

				b = 0;
				for (auto &body_frame : startingEncodedFrames)
				{
					auto & encodedFrameVector = body_frame.second;
					auto taskID = topLevelIDs[b];
					auto body_id = body_frame.first;

					queryService->registerTopLevelResultCollector(sessionID, taskID, std::static_pointer_cast<QueryResultCollectorBase>(topLevelCollectors[b]), future);
					localTasks.push(QueryTask<RootedQuery>(taskID, encodedFrameVector, body_id, 0, topLevelCollectors[b]));
					++b;
				}
								
				Logger::Log("QueryRunner::startGlobalQuery -- Starting runner thread");
				if (!runnerThread)
				{
					runnerThread = std::make_unique<std::thread>([this]() {
						run();
					});
				}

				return future;
			}

			// starts local query serving
			template<typename RootedQuery>
			void QueryRunner<RootedQuery>::startLocalQueryServing(){
				Logger::Log("QueryRunner::startLocalQuery");
				Logger::Identer ident;
				if (runnerThread)
					throw std::logic_error("The query is already running!");

				Logger::Log("QueryRunner::startLocalQuery -- Starting runner thread");
				runnerThread = std::make_unique<std::thread>([this]() {
					run();
				});
			}

			
					
		}
	}
}

#endif 
