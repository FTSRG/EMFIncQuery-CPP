
#define ASIO_STANDALONE
#include"network.h"

#include<asio.hpp>
#include<iostream>


using asio::ip::tcp;

namespace Network
{
	using byte = uint8_t;

	enum class Participant : int {};


	static constexpr int INT_ENCODE_SIZE = 4;

	static void encodeInt(int what, byte* buffer)
	{
		buffer[0] = (what >> 24);
		buffer[1] = (what >> 16);
		buffer[2] = (what >> 8);
		buffer[3] = (what >> 0);
	}
	
	static int decodeInt(const byte* buffer)
	{
		return
			(int(buffer[0]) << 24) +
			(int(buffer[1]) << 16) +
			(int(buffer[2]) << 8) +
			(int(buffer[3]) << 0);
	}



	// 
	// 
	//		Server implementation
	// 
	// 

	class Connection {
		public:
			tcp::socket socket;
			Server * server;

			Connection(Server * server, tcp::socket socket)
				: socket(std::move(socket))
				, server(server)
			{
				read_async_msgheader();
			}

			void read_async_msgheader()
			{
				std::unique_ptr<byte[]> data(new byte[INT_ENCODE_SIZE]);
				auto dataptr = data.get();

				asio::async_read(socket,
					asio::buffer(dataptr, INT_ENCODE_SIZE),
					[this, data = std::move(data)](std::error_code ec, std::size_t length)
				{
					if (ec || length != INT_ENCODE_SIZE)
					{
						std::cout << "Error: ( ec || length != INT_ENCODE_SIZE ) with ec=" << ec << std::endl;
						socket.close();
						return;
					}

					int messagesize = decodeInt(&data[0]);
					read_async_msgbody(messagesize);

				});
			}

			void read_async_msgbody(int msgSize)
			{
				std::unique_ptr<byte[]> storagePtr(new byte[msgSize]);
				auto dataptr = storagePtr.get();
				
				asio::async_read(socket,
					asio::buffer(dataptr, msgSize),
					[this, data = std::move(storagePtr), msgSize](std::error_code ec, std::size_t length)
				{
					if (ec || length != msgSize)
					{
						std::cout << "Error: ( ec || length != msgSize ) witch ec=" << ec << std::endl;
						socket.close();
						return;
					}

					server->process_message(this, data.get(), msgSize);

					read_async_msgheader();
				});
			}
	};

	class Server::ServerImpl {
		friend class Server;
		Server *server;
		asio::io_service io_service;
		tcp::socket nextSocket;
		tcp::acceptor acceptor;
		std::vector<std::unique_ptr<Connection>> connections;
		
	public: 
		ServerImpl(Server * server, uint16_t port)
			: server(server)
			, io_service()
			, nextSocket(io_service)
			, acceptor(io_service, tcp::endpoint(tcp::v4(), port))
		{
			accept_connection();
		}

		void accept_connection()
		{
			acceptor.async_accept(nextSocket,
				[this](std::error_code ec)
			{
				if (!ec)
				{
					connections.emplace_back(std::make_unique<Connection>(server, std::move(nextSocket)));
				}
				accept_connection();
			});
		}

		void run()
		{
			io_service.run();
		}

	};


			
	Server::Server(uint16_t port)
		: impl(std::make_unique<ServerImpl>(this, port))
	{	
	}

	Server::~Server()
	{
		// default destructor for impl
	}

	void Server::run()
	{
		impl->run();
	}

	void Server::sendMessage(Connection * c, byte * msgBuffer, int msglen)
	{
		int encoded_len = INT_ENCODE_SIZE + msglen;
		
		std::unique_ptr<byte[]> encoded(new byte[encoded_len]);
		byte * dataptr = encoded.get();

		encodeInt(msglen, &encoded[0]);

		memcpy(&encoded[INT_ENCODE_SIZE], msgBuffer, msglen);

		
		asio::async_write(c->socket,
			asio::buffer(dataptr, encoded_len),
			[this, store_encoded = std::move(encoded)](std::error_code ec, std::size_t length)
			{
				if (ec) {
					std::cout << "Error during sending message " << ec ;
				}
			});
		
	}


	// 
	// 
	//		Client implementation
	// 
	// 


	class Client::ClientImpl {
		friend class Client;
		Client *client;
		asio::io_service io_service;
		tcp::socket socket;
		
	public: 

		ClientImpl(Client * client, std::string ip, uint16_t port)
			: client(client)
			, io_service()
			, socket(io_service)
		{
			std::cout << "ClientImpl::ClientImpl()" << std::endl;
			connect_async(ip, port);
		}

		void connect_async(const std::string& ip, uint16_t port)
		{
			std::stringstream ss;
			std::string _ip, _port;

			ss << ip << " " << port;
			ss >> _ip >> _port;

			auto endpoint_iterator = tcp::resolver(io_service).resolve({ _ip.c_str(), _port.c_str() });

			std::error_code ec;
			asio::connect(socket, tcp::resolver::iterator(endpoint_iterator), ec);
			
			if (ec) {
				std::cout << "Error during connection: " << ec << std::endl;
				throw std::string("Error during connection" );
			}

			this->read_async_msgheader();

		}

		void read_async_msgheader()
		{
			std::unique_ptr<byte[]> data(new byte[INT_ENCODE_SIZE]);
			auto dataptr = data.get();

			asio::async_read(socket,
				asio::buffer(dataptr, INT_ENCODE_SIZE),
				[this, data = std::move(data)](std::error_code ec, std::size_t length)
			{
				if (ec || length != INT_ENCODE_SIZE)
				{
					socket.close();
					return;
				}

				int messagesize = decodeInt(&data[0]);
				read_async_msgbody(messagesize);
				
			});
		}

		void read_async_msgbody(int msgSize)
		{
			std::unique_ptr<byte[]> data(new byte[msgSize]);
			auto dataptr = data.get();

			asio::async_read(socket,
				asio::buffer(dataptr, msgSize),
				[this, data = std::move(data), msgSize](std::error_code ec, std::size_t length)
			{
				if (ec || length != msgSize)
				{
					socket.close();
					return;
				}

				client->process_message(data.get(), msgSize); 
				read_async_msgheader();
			});
		}

		void run()
		{
			io_service.run();
		}

	};

	Client::Client(std::string ip, uint16_t port)
		: impl(std::make_unique<ClientImpl>(this, ip, port))
	{	
	}

	Client::~Client()
	{
		// destructor in impl
	}

	void Client::run()
	{
		impl->run();
	}

	
	void Client::sendMessage(byte * buffer, int len)
	{
		int encoded_len = INT_ENCODE_SIZE + len;

		std::unique_ptr<byte[]> encoded(new byte[encoded_len]);
		byte * dataptr = encoded.get();

		encodeInt(len, dataptr);

		memcpy(&dataptr[INT_ENCODE_SIZE], buffer, len);

		asio::async_write(impl->socket,
			asio::buffer(dataptr, encoded_len),
			[this, store_encoded = std::move(encoded)](std::error_code ec, std::size_t length)
		{
			if (ec) {
				std::cout << "Error during sending message " << ec << std::endl;
			}
		});

	}
	
}