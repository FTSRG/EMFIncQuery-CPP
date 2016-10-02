
#ifndef _VIATRA_QUERY_DISTRIBUTED_QUERYSERVICE_H_
#define _VIATRA_QUERY_DISTRIBUTED_QUERYSERVICE_H_

#ifdef _VIATRA_HEADER_ONLY_
#define VIATRA_FUNCTION inline
#else
#define VIATRA_FUNCTION
#endif
#define VIATRA_INLINE_FUNCTION inline

#include<memory>
#include<unordered_set>
#include<mutex>
#include<map>

#include"QueryServer.h"
#include"QueryClient.h"

namespace Viatra {
	namespace Query {
		namespace Distributed {
			
			template<typename ModelRoot, typename QueryRunnerFactory>
			class QueryService
			{		

				QueryServer server;
				std::vector<QueryClient> clients;

				std::map < int, std::unique_ptr<QueryRunnerBase> > queryRunners;
				
				int64_t startID, increment, nextID;
				std::mutex id_mutex;
				int64_t generateID()
				{
					std::unique_lock<std::mutex> lock(id_mutex);
					auto id = nextID;
					nextID += increment;
					return id;
				}

			public:

				template<typename T> 
				using MatchT<QS> = typename QuerySpecification::Match;
				using MatcherT<QS> = typename QuerySpecification::Matcher;

				template<typename QuerySpec>
				std::unordered_set<Match<QuerySpec>> RunQuery()
				{

				}

				template<typename QuerySpec>
				std::future<std::unordered_set<Match<QuerySpec>>> DistributeToNodes(
					
				);

			};


			/**
			class QueryService
			{
				// PIMPL idiom for hiding implementation, and avoid recompiling of the source base on change
				class QueryServiceImpl;
				std::unique_ptr<QueryServiceImpl> impl;
				
			public:
				// Initialize the Service by giving a config file
				VIATRA_FUNCTION QueryService(const char* cfgFile);
				// Run the Service
				VIATRA_FUNCTION void run();

				template<typename Frame>
				VIATRA_INLINE_FUNCTION void DistributeExecutionToNodes(int QueryID, int bodyIndex, int operationIndex, const Frame& frame)
				{
				}
				// Deinitialize the service
				VIATRA_FUNCTION ~QueryService();
			};
			*/
		}
	}
}

#ifdef _VIATRA_HEADER_ONLY_
#include"QueryService.cpp"
#endif

#endif