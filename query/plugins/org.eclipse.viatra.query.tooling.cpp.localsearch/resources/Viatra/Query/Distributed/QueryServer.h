
#ifndef _VIATRA_QUERY_DISTRIBUTED_QUERYSERVER_376r45w73566
#define _VIATRA_QUERY_DISTRIBUTED_QUERYSERVER_376r45w73566

#include "../Util/network.h"
#include "TaskID.h"
#include "Request.h"

#include<thread>

namespace Viatra {
	namespace Query {
		namespace Distributed {
						
			class QueryServiceBase;

			class QueryServer : private Network::Server
			{

			private:
				std::unique_ptr<std::thread> thread;
				QueryServiceBase * service;
			public:
				QueryServer(uint16_t port, QueryServiceBase * service);

				QueryServer(const QueryServer&) = delete;
				void operator=(const QueryServer&) = delete;

				~QueryServer();

				void runAsync() {
					thread = std::unique_ptr<std::thread>(
						new std::thread([this]() {
							Server::run();
						}
					));
				}

				void sendMatchResults(const Request& rq, const std::string& status, int64_t sessionID, TaskID taskID, const std::string& resultMatchSet);

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
