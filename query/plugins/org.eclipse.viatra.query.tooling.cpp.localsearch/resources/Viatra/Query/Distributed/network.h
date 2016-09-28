

#ifndef _NETWORK_NETWORK_H_
#define _NETWORK_NETWORK_H_


#include<string>
#include<stdint.h>
#include<memory>
#include<vector>

#ifdef _VIATRA_HEADER_ONLY_
	#define VIATRA_FUNCTION inline
#else
	#define VIATRA_FUNCTION
#endif
#define VIATRA_INLINE_FUNCTION inline
	
namespace Viatra{
namespace Query{
namespace Distributed{
namespace Network
{
	using byte = uint8_t;

	class Connection;

	class Server {
		class ServerImpl;
		friend class Server::ServerImpl;
		friend class Connection;

		std::unique_ptr<ServerImpl> impl;
		
	public:
		Server() = delete;


		VIATRA_FUNCTION Server(uint16_t port);
		VIATRA_FUNCTION virtual ~Server();

		// Run the server on the current thread
		VIATRA_FUNCTION void run();
		void sendMessage(Connection * c, byte * buffer, int len);
	protected:
		VIATRA_FUNCTION virtual void process_message(Connection * c, byte * bytes, int len) = 0;

	};

	class Client {
		class ClientImpl;
		friend class Client::ClientImpl;

		std::unique_ptr<ClientImpl> impl;

	public:
		Client() = delete;
		VIATRA_FUNCTION Client(std::string ip, uint16_t port);
		VIATRA_FUNCTION virtual ~Client();

		// Run the client on the current thread
		VIATRA_FUNCTION void run();
		VIATRA_FUNCTION void sendMessage(byte * buffer, int len);
	protected:
		VIATRA_FUNCTION virtual void process_message(byte * bytes, int len) = 0;

	};
}
}
}
}

#ifdef _VIATRA_HEADER_ONLY_
	#include"network.cpp"
#endif

#endif