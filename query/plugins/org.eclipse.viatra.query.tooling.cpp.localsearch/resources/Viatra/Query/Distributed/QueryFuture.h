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

				virtual void notifyCollectionDone() = 0;

				void terminate() {
					runner->terminate();
				}

				virtual bool ready() = 0;

				virtual ~QueryFutureBase() {}
			};

			// Future object for accessing the result or terminating a Query Session
			template<typename RootedQuery>
			class QueryFuture : public QueryFutureBase {
				using Match = typename RootedQuery::Match;
				using MatchSet = typename Match::MatchSet;

				using Lock = std::unique_lock<std::mutex>;
				std::mutex collectorMutex;

				std::shared_ptr<QueryRunner<RootedQuery>> concreteRunner;
				
				std::condition_variable readyCV;
				std::atomic<bool> _ready;
				std::vector<std::shared_ptr<QueryResultCollector<RootedQuery>>> topLevelCollectors;

			public:
				QueryFuture(std::shared_ptr<QueryRunner<RootedQuery>> runner, std::vector<std::shared_ptr<QueryResultCollector<RootedQuery>>> topLevelCollectors)
					: QueryFutureBase(std::static_pointer_cast<QueryRunnerBase>(runner))
					, topLevelCollectors(topLevelCollectors)
					, _ready(false)
				{
					this->concreteRunner = runner;
				}

				bool ready() override
				{
					return _ready;
				}

				void notifyCollectionDone() override {
					{
						Lock lck(collectorMutex);

						bool calculated_ready = true;
						for (auto & collector : topLevelCollectors)
							if (!collector->finished())
								calculated_ready = false;

						_ready.store(calculated_ready);
					}
					if (_ready)
						readyCV.notify_one();
				}

				std::shared_ptr<QueryFuture<RootedQuery>> reanimate()
				{
					return concreteRunner->startGlobalQuery();
				}
								
				MatchSet getResultMatchSet()
				{
					Lock lck(collectorMutex);
					Util::Logger::Log("readyCV.wait(...);");
					readyCV.wait(lck, [this] {
						Util::Logger::Log("Ready predicate wake");
						return _ready.load();
					});

					MatchSet ret;
					for (auto && collector : topLevelCollectors)
					{
						MatchSet matchSet(collector->obtainMatches());
						for (auto && match : matchSet)
							ret.insert(match);
					}

					Util::Logger::Log("readyCV.wait(...); ready!");
					return ret;
				}
				
			};

		}
	}
}