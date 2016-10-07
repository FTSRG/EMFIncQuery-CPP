#pragma once

#include"Viatra/Query/MatchSet.h"
#include"QueryRunner.h"
#include"memory"

namespace Viatra{
	namespace Query {
		namespace Distributed {

			class QueryFutureBase {
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
			public:
				QueryFuture(std::shared_ptr<QueryRunnerBase> runner)
					: QueryFutureBase(runner)
				{}
								
			};

		}
	}
}