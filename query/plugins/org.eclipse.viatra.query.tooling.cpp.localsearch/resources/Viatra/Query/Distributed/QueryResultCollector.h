#pragma once

#include"QueryTask.h"
#include"../util/network.h"

#include<unordered_set>
#include<mutex>
#include<atomic>
#include<stdint.h>
#include<string>

namespace Viatra {
	namespace Query {
		namespace Distributed {

			class QueryResultCollectorBase { 
			public:
				virtual ~QueryResultCollectorBase() {}
				virtual void addRemoteMatches(const std::string& encodedMatches, TaskID taskId) = 0;
			};

			// RootedQuery = QueryClass<ModelRoot>
			// An object for collecting the results of a subtask of a query session
			template<class RootedQuery>
			class QueryResultCollector : public QueryResultCollectorBase {
				// The ModelRoot for the Query 
				using ModelRoot = typename RootedQuery::ModelRoot;
				using Match = typename RootedQuery::Match;
				using MatchSet = typename Match::MatchSet;

			private:
				std::mutex resultMutex;

				ModelRoot * modelRoot;

				TaskID task;
				std::unordered_set<TaskID> remoteRunningTasks;
				MatchSet matches;

				std::atomic<bool> finishedLocally = false;

			public:

				QueryResultCollector(const TaskID taskID)
					: taskID(taskID)
				{}
				~QueryResultCollector() {}

				void addLocalMatches(std::unordered_set<typename RootedQuery::Match> && matches2add)
				{
					auto lock = std::unique_lock(resultMutex);

					for(auto && match : matches2add)
						matches.insert(match);
					finishedLocally = true;
				}

				void addRemoteMatches(const std::string& encodedMatches, TaskID taskID) override
				{
					auto lock = std::unique_lock(resultMutex);
					MatchSet::ParseFromStringCallback(encodedMatches, modelRoot, []() {
						throw "Not implemented QueryResultCollector::addRemoteMatches";
					};
					remoteRunningTasks.remove(taskID);
				}

				bool finished()
				{
					if (!finishedLocally)
						return false;

					auto lock = std::unique_lock(resultMutex);
					return remoteRunningTasks.empty();
				}


			};
			
		}
	}
}