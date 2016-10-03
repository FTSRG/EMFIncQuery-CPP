
#ifndef _VIATRA_QUERY_UTIL_NETWORK_H_
#define _VIATRA_QUERY_UTIL_NETWORK_H_

#include"../Util/network.h"

namespace Viatra {
	namespace Query {
		namespace Distributed {

			class QueryClient : public Network::Client
			{
				
			private:

			public:
				QueryClient(std::string ip, uint16_t port)
					: Network::Client(ip, port)
				{}

			};

		}
	}
}

#endif
