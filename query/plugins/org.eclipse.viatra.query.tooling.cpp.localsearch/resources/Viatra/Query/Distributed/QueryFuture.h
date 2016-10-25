#pragma once

#include"Viatra/Query/MatchSet.h"
#include"QueryResultCollector.h"
#include"QueryRunner.h"
#include<memory>
#include<condition_variable>

namespace Viatra{
	namespace Query {
		namespace Distributed {
			class QueryRunnerBase;
			class QueryServiceBase;

			class QueryFutureBase {
				// Barát osztály
				friend class QueryRunnerBase;
				friend class QueryServiceBase;

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

				using Lock = std::unique_lock<std::mutex>;
				std::mutex readyMutex;

				std::shared_ptr<QueryRunner<RootedQuery>> concreteRunner;

			public:
				QueryFuture(std::shared_ptr<QueryRunner<RootedQuery>> runner)
					: QueryFutureBase(std::static_pointer_cast<QueryRunnerBase>(runner))
				{
					this->concreteRunner = runner;
				}
								
				MatchSet get() {
					return concreteRunner->getResultMatchSet();
				}
				
			};

		}
	}
}