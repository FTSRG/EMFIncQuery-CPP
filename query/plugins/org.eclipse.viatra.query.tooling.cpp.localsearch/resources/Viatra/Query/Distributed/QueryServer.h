
#ifndef _VIATRA_QUERY_DISTRIBUTED_QUERYSERVER_
#define _VIATRA_QUERY_DISTRIBUTED_QUERYSERVER_

#include "../Util/network.h"


#ifdef _VIATRA_HEADER_ONLY_
#define VIATRA_FUNCTION inline
#else
#define VIATRA_FUNCTION
#endif
#define VIATRA_INLINE_FUNCTION inline

namespace Viatra {
	namespace Query {
		namespace Distributed {

			class QueryServer : Network::Server
			{
			public:
				VIATRA_FUNCTION QueryServer(uint16_t port);
				VIATRA_FUNCTION ~QueryServer();
			protected:
				VIATRA_FUNCTION virtual void accept_connection(Network::Connection * c) override;
				VIATRA_FUNCTION virtual void process_message(Network::Connection * c, Network::Buffer message)override;
			};

		}
	}
}

#ifdef _VIAATRA_HEADER_ONLY_
#include"QueryServer.cpp"
#endif

#endif
