
#ifndef _VIATRA_QUERY_DISTRIBUTED_QUERY_RUNNER_H_
#define _VIATRA_QUERY_DISTRIBUTED_QUERY_RUNNER_H_

#include"QueryTask.h"
#include"../Util/ConcurrentQueue.h"
#include"../Util/HierarchicalID.h"

#include<memory>
#include<atomic>
#include<exception>

namespace Viatra {
	namespace Query {
		namespace Distributed {

			class QueryFutureBase;
			
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

				virtual void addTask(const std::string& nodeName, TaskID taskID, int body, int operation, std::string frame);

			};

			template<typename RootedQuery>
			class QueryRunner : public QueryRunnerBase
			{
				using ModelRoot = typename RootedQuery::ModelRoot;
				using Match = typename RootedQuery::Match;
				using Matcher = typename RootedQuery::Matcher;
				using QueryGroup = typename RootedQuery::QueryGroup;
				using QueryTaskT = QueryTask<RootedQuery>;
				
				std::unordered_set<Util::HierarchicalID<uint64_t>> remoteSubTaskIDs;
				Util::ConcurrentQueue<QueryTaskT> localTasks;

				Matcher matcher;
				ModelRoot * modelRoot;

			public:
				QueryRunner(uint64_t sessionID, ModelRoot * modelRoot)
					: QueryRunnerBase(sessionID)
					, modelRoot(modelRoot)
					, matcher(modelRoot, QueryGroup::instance()->context(), this)
				{}

				// Distribues the query execution to all the other nodes from a given state in the body
				void GlobalIterateOverInstances(int bodyIndex, int opIndex, std::string encodedFrame) {
				
				}

				void MergeRemoteMatchResult(Util::HierarchicalID<uint64_t> remoteTaskID, std::string && serializedMatchset)
				{					
					MatchSet::ParseMatchSet(serializedMatchset, [](Match& match) {
						
					});
				}

				inline void addTask(QueryTaskT& task){
					localTasks.push(task);
				}

				inline void addTask(QueryTaskT&& task){
					localTasks.push(std::move(task));
				}
				virtual void addTask(const std::string& nodeName, TaskID taskID, int body, int operation, std::string frame)
				{
					std::shared_ptr<QueryResultCollector<RootedQuery>> collector(new QueryResultCollector<RootedQuery>(taskID));
					service->addResultCollector(collector);

				}

				void run()
				{

					while (!terminated)
					{
						try {
							QueryTaskT task = localTasks.pop(std::chrono::milliseconds(100));
							
						}
						catch (Viatra::Query::Util::ConcurrentQueueTimeout&){}
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
