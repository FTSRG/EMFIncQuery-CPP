
#ifndef _NETWORK_NETWORK_H_
#define _NETWORK_NETWORK_H_

#include<string>
#include<stdint.h>
#include<memory>
#include<vector>

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


		Server(uint16_t port);
		virtual ~Server();

		// Run the server on the current thread
		void run();
		void sendMessage(Connection * c, byte * buffer, int len);
	protected:
		virtual void process_message(Connection * c, byte * bytes, int len) = 0;

	};

	class Client {
		class ClientImpl;
		friend class Client::ClientImpl;

		std::unique_ptr<ClientImpl> impl;

	public:
		Client() = delete;
		Client(std::string ip, uint16_t port);
		virtual ~Client();

		// Run the client on the current thread
		void run();
		void sendMessage(byte * buffer, int len);
	protected:
		virtual void process_message(byte * bytes, int len) = 0;

	};
}

#endif