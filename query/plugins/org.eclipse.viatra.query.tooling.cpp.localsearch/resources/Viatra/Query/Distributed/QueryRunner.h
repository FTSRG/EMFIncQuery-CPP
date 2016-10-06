
#ifndef _VIATRA_QUERY_DISTRIBUTED_QUERY_RUNNER_H_
#define _VIATRA_QUERY_DISTRIBUTED_QUERY_RUNNER_H_

#include<atomic>
#include"QueryTask.h"
#include"../Util/ConcurrentQueue.h"
#include"../Util/HierarchicalID.h"

namespace Viatra {
	namespace Query {
		namespace Distributed {

			class QueryRunnerBase {
			protected:
				uint64_t sessionID;
				std::atomic<bool> terminated;

			public:
				QueryRunnerBase(uint64_t sessionID) 
					: sessionID(sessionID)
				{}

				void terminate()
				{
					terminated = true;
				}

				virtual ~QueryRunnerBase() {}
				virtual void run() = 0;
				
			};

			template<typename ModelRoot, template<typename>class QueryTemplate>
			class QueryRunner : public QueryRunnerBase
			{
				using Query = QueryTemplate<ModelRoot>;
				using QuerySpecification = typename Query::QuerySpecification;
				using Match = typename Query::Match;
				using Matcher = typename Query::Matcher;
				using QueryGroup = typename Query::QueryGroup;
				
				using QueryTaskT = QueryTask<Query>;

				
				std::unordered_set<Util::HierarchicalID<uint64_t>> remoteSubTaskIDs;
				Util::ConcurrentQueue<QueryTaskT> localTasks;

				Matcher matcher;
				ModelRoot * modelRoot;

			public:
				QueryRunner(uint64_t sessionID, ModelRoot * modelRoot)
					: QueryRunnerBase(sessionID)
					, modelRoot(modelRoot)
					, matcher(modelRoot, QueryGroup::instance()->context())
				{}

				void MergeMatchResult(Util::HierarchicalID<uint64_t> remoteTaskID, std::string && serializedMatchset)
				{					
					Match::ParseMatchSet(serializedMatchset, [](Match& match) {
						
					});
				}

				void addTask(QueryTaskT& task)
				{
					localTasks.push(task);
				}

				void addTask(QueryTaskT&& task)
				{
					localTasks.push(std::move(task));
				}
				
				void run() override
				{

					while (!terminated)
					{
						try {
							QueryTaskT task = localTasks.pop(std::chrono::milliseconds(100));
							
							

						}
						catch (Viatra::Query::Util::ConcurrentQueueTimeout&){}
					}
				}
			};
					
		}
	}
}

#endif 
