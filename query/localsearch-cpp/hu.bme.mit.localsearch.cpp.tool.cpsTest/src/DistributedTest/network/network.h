
#ifndef _NETWORK_NETWORK_H_
#define _NETWORK_NETWORK_H_

#include<stdint.h>
#include<vector>
#include<memory>

namespace Network
{
	
	using MessageBuffer = std::vector<uint8_t>;

	class AnswerFuture
	{
		class AnswerFutureImpl;
		std::shared_ptr<AnswerFutureImpl> inner;
		
	public:
		~AnswerFuture();
		bool ready();
		MessageBuffer answer();
	};

	class Connection;

	class Client {
		Client(std::string, std::string ip);
		AnswerFuture sendMessage(MessageBuffer message);
	};

	template<typename Connection>
	class Server {

	protected:
		virtual MessageBuffer process(MessageBuffer message, Connection *client) = 0;
	public:
		Server();
		void run();
		~Server();

	};
}

#endif