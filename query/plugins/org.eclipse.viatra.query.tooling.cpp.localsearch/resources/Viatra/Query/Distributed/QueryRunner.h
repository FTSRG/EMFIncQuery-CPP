#pragma once

namespace Viatra {
	namespace Query {
		namespace Distributed {

			class QueryRunnerBase {
			private:

			protected:
				QueryRunnerBase(){}
				virtual ~QueryRunnerBase() {}
				virtual void run() = 0;

			public:
			};

			template<typename QuerySpecification>
			class QueryRunner : public QueryRunnerBase
			{
				ConcurrentQueue<QueryTask<QuerySpecification>> tasks;
				atomic_flag terminated = false;

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