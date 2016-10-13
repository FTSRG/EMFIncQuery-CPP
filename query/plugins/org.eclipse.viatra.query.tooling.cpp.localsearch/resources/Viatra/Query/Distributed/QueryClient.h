
#ifndef _VIATRA_QUERY_UTIL_NETWORK_H_
#define _VIATRA_QUERY_UTIL_NETWORK_H_

#include"../Util/network.h"
#include"IDGenerator.h"
#include<atomic>
#include<unordered_set>

namespace Viatra {
	namespace Query {
		namespace Distributed {
			
			class QueryClient : private Network::Client
			{
				enum class State {
					INITIATING = 0,
					READY = 1,
					ERROR = 2
				};

			private:
				std::unique_ptr<std::thread> thread;
				IDGenerator rqidGenerator{ 1, 1 };
				
				std::atomic<State> state = State::INITIATING; 
				std::string errorMessage;


				using Lock = std::unique_lock<std::mutex>;
				std::mutex mutex;
				std::unordered_set<uint64_t> readyQuerySessions;

				void initiateConnection(std::string initiatorNode);
				virtual void process_message(Network::Buffer message)override final;

			public:
				QueryClient(std::string ip, uint16_t port, std::string initiatorNode);
				QueryClient(const QueryClient&) = delete;
				void operator=(const QueryClient&) = delete;
				~QueryClient()	{}
				
				bool ready() { return state == State::READY; }

				bool isQuerySessionReady(int64_t sessionID) {
					Lock lck(mutex);
					return readyQuerySessions.count(sessionID) > 0;
				}

				bool error(std::string& errorMessage) {
					Lock lck(mutex);
					if (state != State::ERROR)
						return false;
					errorMessage = this->errorMessage;
					return true;
				}

				void startQuerySession(uint64_t sessionID, int queryID);

			};

		}
	}
}

#endif
