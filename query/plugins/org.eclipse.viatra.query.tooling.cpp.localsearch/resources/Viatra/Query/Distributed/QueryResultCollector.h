#ifndef _VIATRA_QUERY_DISTRIBUTED_QUERYRESULT_COLLECTOR_547945234_
#define _VIATRA_QUERY_DISTRIBUTED_QUERYRESULT_COLLECTOR_547945234_

#include"QueryServer.h"
#include"QueryService.h"
#include"QueryTask.h"
#include"Request.h"
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
				using Lock = std::unique_lock<std::mutex>;
				std::mutex mutex;

				uint64_t sessionID;
				TaskID taskID;
				QueryServiceBase *service;
				std::unordered_set<TaskID> remoteRunningTasks;
				std::atomic<bool> finishedLocally = false;

			public:
				QueryResultCollectorBase(uint64_t sessionID, TaskID taskID, QueryServiceBase *service)
					: taskID(std::move(taskID))
					, sessionID(sessionID)
					, service(service)
				{}

				virtual ~QueryResultCollectorBase() {}
				virtual void addRemoteMatches(const std::string& encodedMatches, const TaskID& taskId) = 0;
				
				bool finished()
				{
					if (!finishedLocally)
						return false;

					Lock lck(mutex);
					return remoteRunningTasks.empty();
				}
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
				MatchSet matches;

			public:

				QueryResultCollector(uint64_t sessionID, const TaskID taskID, QueryServiceBase *service, ModelRoot * modelRoot)
					: QueryResultCollectorBase(sessionID, taskID, service)
					, modelRoot(modelRoot)
				{}
				~QueryResultCollector() {}

				void addRemoteRunningTask(TaskID taskID)
				{
					Lock lck(mutex);
					remoteRunningTasks.insert(taskID);
				}

				void addLocalMatches(MatchSet && matches2add)
				{
					Lock lck(mutex);
					for(auto && match : matches2add)
						matches.insert(match);
					finishedLocally = true;
					if (finished())
						service->notifyCollectionDone(sessionID, taskID);
				}

				void addRemoteMatches(const std::string& encodedMatches, const TaskID& taskID) override
				{
					Lock lck(mutex);
					MatchSet::ParseFromStringCallback(encodedMatches, modelRoot, [this](const Match& match) {
						matches.insert(match);
					});
					remoteRunningTasks.erase(taskID);
					if (finished())
						service->notifyCollectionDone(sessionID, taskID);
						
				}
			};
			
		}
	}
}

#endif _VIATRA_QUERY_DISTRIBUTED_QUERYRESULT_COLLECTOR_547945234_
