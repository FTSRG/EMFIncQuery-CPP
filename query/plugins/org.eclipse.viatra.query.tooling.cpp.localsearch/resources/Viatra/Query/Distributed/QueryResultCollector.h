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
				TaskID taskID;
				Request request;
				QueryServiceBase *service;

			public:
				QueryResultCollectorBase(TaskID taskID, const Request& request, QueryServiceBase *service)
					: taskID(std::move(taskID))
					, request(request)
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
				using Lock = std::unique_lock<std::mutex>;
				std::mutex mutex;

				ModelRoot *modelRoot;
			
				MatchSet matches;
				std::unordered_set<TaskID> remoteRunningTasks;
				std::atomic<bool> finishedLocally = false;

			public:

				QueryResultCollector(const TaskID taskID, const Request& request, QueryServiceBase *service, ModelRoot * modelRoot)
					: QueryResultCollectorBase(taskID, request, service)
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
						service.notifyCollectionDone(taskID);
				}

				void addRemoteMatches(const std::string& encodedMatches, const TaskID& taskID) override
				{
					Lock lck(mutex);
					MatchSet::ParseFromStringCallback(encodedMatches, modelRoot, [this](const Match& match) {
						matches.insert(match);
					});
					remoteRunningTasks.erase(taskID);
					if (finished())
						service.notifyCollectionDone(taskID);
						
				}

				bool finished()
				{
					if (!finishedLocally)
						return false;

					Lock lck(mutex);
					return remoteRunningTasks.empty();
				}


			};
			
		}
	}
}

#endif _VIATRA_QUERY_DISTRIBUTED_QUERYRESULT_COLLECTOR_547945234_
