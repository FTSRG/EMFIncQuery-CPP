
#ifndef _VIATRA_QUERY_DISTRIBUTED_QUERYSERVER_
#define _VIATRA_QUERY_DISTRIBUTED_QUERYSERVER_

#include "../Util/network.h"

namespace Viatra {
	namespace Query {
		namespace Distributed {
			
			class QueryServiceBase;

			class QueryServer : private Network::Server
			{
				QueryServiceBase * service;
			public:
				QueryServer(uint16_t port, QueryServiceBase * service);
				~QueryServer();
			protected:
				void accept_connection(Network::Connection * c) override;
				void process_message(Network::Connection * c, Network::Buffer message)override;
			};

		}
	}
}

#ifdef _VIAATRA_HEADER_ONLY_
#include"QueryServer.cpp"
#endif

#endif
