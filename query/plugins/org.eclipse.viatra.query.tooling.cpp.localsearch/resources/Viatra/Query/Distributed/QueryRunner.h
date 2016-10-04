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

				std::set<HierarchiclaID>

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
				ConcurrentQueue<QueryTask<QuerySpecification>> tasks;
				std::atomic_flag terminated;

			public:
				QueryRunner(uint64_t sessionID)
					: QueryRunnerBase(sessionID)
				{}

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