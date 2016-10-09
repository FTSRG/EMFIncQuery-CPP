
#ifndef _VIATRA_QUERY_UTIL_NETWORK_H_
#define _VIATRA_QUERY_UTIL_NETWORK_H_

#include"../Util/network.h"

namespace Viatra {
	namespace Query {
		namespace Distributed {

			class QueryClient : private Network::Client
			{
				
			private:
				std::unique_ptr<std::thread> thread;

			public:
				QueryClient(std::string ip, uint16_t port)
					: Network::Client(ip, port)
				{}

				QueryClient(const QueryClient&) = delete;
				void operator=(const QueryClient&) = delete;

				~QueryClient()
				{}

				void runAsync() {
					thread = std::make_unique<std::thread>([this]() {
						Client::run();
					});
				}

			};

		}
	}
}

#endif
