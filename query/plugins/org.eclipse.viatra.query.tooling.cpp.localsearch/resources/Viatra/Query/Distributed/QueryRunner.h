#pragma once

#include<atomic>
#include"QueryTask.h"
#include"../Util/ConcurrentQueue.h"
#include"../Util/HierarchicalID.h"

namespace Viatra {
	namespace Query {
		namespace Distributed {

			class QueryRunnerBase {
				uint64_t sessionID;


			public:
				QueryRunnerBase(uint64_t sessionID) 
					: sessionID(sessionID)
				{}
				virtual ~QueryRunnerBase() {}
				virtual void run() = 0;
				
			};

			template<typename QuerySpecification>
			class QueryRunner : public QueryRunnerBase
			{
				std::unordered_set<Util::HierarchicalID<uint64_t>> remoteTaskIDs;
				Util::ConcurrentQueue<QueryTask<QuerySpecification>> localTasks;
				std::atomic_flag terminated;

			public:
				QueryRunner(uint64_t sessionID)
					: QueryRunnerBase(sessionID)
				{}

				void MergeMatchResult(Util::HierarchicalID<uint64_t> remoteTaskID, std::string && serailizedMatchset)
				{
					using Match = typename QuerySpecification::Match;
					


				}

				void addTask(const QueryTask<QuerySpecification>& task)
				{
					tasks.push(std::move(task));
				}

				void addTask(QueryTask<QuerySpecification>&& task)
				{
					tasks.push(std::move(task));
				}

				void terminate()
				{
					terminated = true;
				}
				
				void run() override
				{
					while (!terminated)
					{
						tasks.pop();
					}
				}
			};
					
		}
	}
}