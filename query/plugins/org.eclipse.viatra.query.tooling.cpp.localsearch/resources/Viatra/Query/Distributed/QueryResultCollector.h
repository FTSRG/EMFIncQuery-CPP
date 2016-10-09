#pragma once

#include"QueryService.h"
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

			class QueryServiceBase;

			class QueryResultCollectorBase { 
			protected:
				TaskID taskID;
				std::string nodeName;
				QueryServiceBase *service;

			public:
				QueryResultCollectorBase(TaskID taskID, std::string nodeName, QueryServiceBase *service)
					: taskID(std::move(taskID))
					, nodeName(std::move(nodeName))
					, service(service)
				{}

				virtual ~QueryResultCollectorBase() {}
				virtual void addRemoteMatches(const std::string& encodedMatches, const TaskID& taskId) = 0;
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
				ModelRoot *modelRoot;

				std::mutex resultMutex;
				MatchSet matches;
				std::unordered_set<TaskID> remoteRunningTasks;
				std::atomic<bool> finishedLocally = false;

			public:

				QueryResultCollector(const TaskID taskID, std::string NodeName, QueryServiceBase *service, ModelRoot * modelRoot)
					: QueryResultCollectorBase(taskID, nodeName, service)
					, modelRoot(modelRoot)
				{}
				~QueryResultCollector() {}

				void addLocalMatches(std::unordered_set<typename RootedQuery::Match> && matches2add)
				{
					auto lock = std::unique_lock<std::mutex>(resultMutex);

					for(auto && match : matches2add)
						matches.insert(match);
					finishedLocally = true;
				}

				void addRemoteMatches(const std::string& encodedMatches, const TaskID& taskID) override
				{
					auto lock = std::unique_lock<decltype(resultMutex)>(resultMutex);
					MatchSet::ParseFromStringCallback(encodedMatches, modelRoot, [this](const Match& match) {
						matches.insert(match);
					});
					remoteRunningTasks.erase(taskID);
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