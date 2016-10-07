#pragma once

#include"QueryTask.h"
#include"../util/network.h"

#include<unordered_set>
#include<mutex>
#include<atomic>
#include<stdint.h>

namespace Viatra {
	namespace Query {
		namespace Distributed {

			class QueryResultCollectorBase { 
			public:
				virtual ~QueryResultCollectorBase() {}

				virtual void addRemoteMatches(uint8_t bytes, int len, TaskID taskId) = 0;
			};

			// RootedQuery = QueryClass<ModelRoot>
			// An object for collecting the results of a subtask of a query session
			template<class RootedQuery>
			class QueryResultCollector : public QueryResultCollectorBase {
				// The ModelRoot for the Query 
				using ModelRoot = typename RootedQuery::ModelRoot;
				using Match = typename RootedQuery::Match;

			private:
				std::mutex resultMutex;

				typename ModelRoot * modelRoot;

				TaskID task;
				std::unordered_set<TaskID> remoteTasks;
				std::unordered_set<typename RootedQuery::Match> matches;
				std::atomic<bool> finishedLocally = false;

			public:
				void addLocalMatches(std::unordered_set<typename RootedQuery::Match> && matches2add)
				{
					auto lock = std::unique_lock(resultMutex);

					for(auto && match : matches2add)
						matches.insert(match);
					finishedLocally = true;
				}
				
				void addRemoteMatches(uint8_t bytes, int len, TaskID taskId) override
				{
					auto lock = std::unique_lock(resultMutex);
					using Match = typename RootedQuery::Match;
					Match::ParseMatchSet()


					for (auto && match : matches2add)
						matches.insert(match);
				}

				bool finished()
				{
					return finishedLocally;
				}

				~QueryResultCollector() {}

			};
			
		}
	}
}