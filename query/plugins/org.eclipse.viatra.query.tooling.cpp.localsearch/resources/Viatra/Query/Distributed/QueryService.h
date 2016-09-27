
#ifndef _VIATRA_QUERY_DISTRIBUTED_QUERYSERVICE_H_
#define _VIATRA_QUERY_DISTRIBUTED_QUERYSERVICE_H_

#ifdef _VIATRA_HEADER_ONLY_
#define VIATRA_FUNCTION inline
#else
#define VIATRA_FUNCTION
#endif
#define VIATRA_INLINE_FUNCTION inline

#include<memory>

namespace Viatra {
	namespace Query {
		namespace Distributed {

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
				// Deinitialize the service
				VIATRA_FUNCTION ~QueryService();
			};

		}
	}
}

#ifdef _VIATRA_HEADER_ONLY_
#include"QueryService.cpp"
#endif

#endif