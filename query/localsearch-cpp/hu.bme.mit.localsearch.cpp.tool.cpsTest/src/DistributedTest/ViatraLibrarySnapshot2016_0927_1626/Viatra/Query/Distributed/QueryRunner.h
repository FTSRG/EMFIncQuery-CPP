#pragma once

namespace Viatra {
	namespace Query {
		namespace Distributed {

			class QueryRunnerBase;

			class QuerySession
			{
			private:
				uint64_t id;
				std::unique_ptr<QueryRunnerBase> runner;

			public:
				template<typename QuerySpecification>
				QuerySession(uint64_t id);

			};

			class QueryRunnerBase {
			private:
				QuerySession *session;

			protected:
				QueryRunnerBase()
				{}

			public:
				void run();
			};

			template<typename QuerySpecification>
			class QueryRunner : public QueryRunnerBase
			{

			};

			template<typename QuerySpecification>
			QuerySession::QuerySession(uint64_t id)
				: queryRunner(new QueryRunner<QuerySpecification>())
			{
			}



			
		}
	}
}