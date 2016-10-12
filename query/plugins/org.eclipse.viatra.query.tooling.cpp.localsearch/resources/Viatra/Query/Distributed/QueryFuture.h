#pragma once

#include"Viatra/Query/MatchSet.h"
#include"QueryResultCollector.h"
#include"QueryRunner.h"
#include"memory"

namespace Viatra{
	namespace Query {
		namespace Distributed {

			class QueryFutureBase {
				// Barát osztály
				friend class QueryRunnerBase;

				std::shared_ptr<QueryRunnerBase> runner;

			public:
				QueryFutureBase() = delete;
				QueryFutureBase(const QueryFutureBase&) = delete;
				QueryFutureBase(QueryFutureBase&&) = default;

				QueryFutureBase(std::shared_ptr<QueryRunnerBase> runner)
					: runner(runner)
				{}

				void terminate() {
					runner->terminate();
				}

				bool ready() {
					return runner->ready();
				}

				virtual ~QueryFutureBase() {}
			};

			// Future object for accessing the result or terminating a Query Session
			template<typename RootedQuery>
			class QueryFuture : public QueryFutureBase {
				using Match = typename RootedQuery::Match;
				using MatchSet = typename Match::MatchSet;

				// Doesn't need to be shared since the baseclass keeps it alive
				QueryRunner<RootedQuery> *concreteRunner;

				std::vector<std::shared_ptr<QueryResultCollector<RootedQuery>>> runner;

			public:
				QueryFuture(std::shared_ptr<QueryRunnerBase> runner)
					: QueryFutureBase(runner)
				{
					this->concreteRunner = dynamic_cast<QueryRunner<RootedQuery>*>(runner.get());
				}
				
				MatchSet get() {
				
				}
			};

		}
	}
}