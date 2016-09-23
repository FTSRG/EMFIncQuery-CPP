
#ifndef _VIATRA_QUERY_DISTRIBUTED_QUERYSERVICE_H_
#define _VIATRA_QUERY_DISTRIBUTED_QUERYSERVICE_H_

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
				QueryService(const char* cfgFile);
				// Run the Service
				void run();
				// Deinitialize the service
				~QueryService();
			};

		}
	}
}


#endif