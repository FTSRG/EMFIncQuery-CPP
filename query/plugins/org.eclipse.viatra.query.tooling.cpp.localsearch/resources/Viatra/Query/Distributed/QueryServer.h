
#ifndef _VIATRA_QUERY_DISTRIBUTED_QUERYSERVER_376r45w73566
#define _VIATRA_QUERY_DISTRIBUTED_QUERYSERVER_376r45w73566

#include "../Util/network.h"
#include "../Util/Logger.h"
#include "TaskID.h"
#include "Request.h"
#include "QueryRunnerDecl.h"

#include<thread>
#include<iostream>

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
					thread = std::unique_ptr<std::thread>(new std::thread([this]() {
						Util::Logger::SetThisThreadName("Server");
						Util::Logger::Log("Hello from server thread");
						try{
							Server::run();
						}
						catch (const std::exception& ex)
						{
							std::cout << ex.what();
						}
						catch (const std::string& ex)
						{
							std::cout << ex;
						}
						catch (const char *c)
						{
							std::cout << c;
						}
						catch (...)
						{
							std::cout << "Something catched other than std::exception, string, or const char*";
						}
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

#endif
