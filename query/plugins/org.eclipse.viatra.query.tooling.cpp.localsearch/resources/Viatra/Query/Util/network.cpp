
#define ASIO_STANDALONE
#include"network.h"

#define ASIO_DISABLE_CONSTEXPR 1

#include<asio/asio.hpp>
#include<iostream>

namespace Network
{
	using asio::ip::tcp;
	using byte = uint8_t;

	enum class Participant : int {};


	static constexpr int INT_ENCODE_SIZE = 4;
	static_assert(Buffer::HEADER == INT_ENCODE_SIZE, "Buffer size and INT_ENCODE_SIZE must be the same");
	
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


	void Buffer::calculate_header() {
		encodeInt(len, buf.get());
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
						std::cout << "Connection::read_async_msgheader - Error: ( ec || length != INT_ENCODE_SIZE ) with ec=" << ec << std::endl;
						socket.close();
						return;
					}

					int messagesize = decodeInt(&data[0]);
					read_async_msgbody(messagesize);

				});
			}

			void read_async_msgbody(int msgSize)
			{
				Buffer msgBuffer(msgSize);
				
				auto data = msgBuffer.data();
				auto size = msgBuffer.size();

				asio::async_read(socket,
					asio::buffer(data, size),
					[this, msgBuffer = std::move(msgBuffer), msgSize](std::error_code ec, std::size_t length) mutable
				{
					if (ec || length != msgSize)
					{
						std::cout << "Connection::read_async_msgbody - Error: ( ec || length != msgSize ) with ec=" << ec << std::endl;
						socket.close();
						return;
					}

					server->process_message(this, std::move(msgBuffer));

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
					auto conn = new Connection(server, std::move(nextSocket));
					connections.emplace_back(conn);
					server->accept_connection(conn);
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

	void Server::run()
	{
		impl->run();
	}
	
	Server::~Server()
	{

	}

	void Server::sendMessage(Connection * c, Buffer message)
	{				
		auto framedData = message.framed_data();
		auto framedSize = message.framed_size();
		asio::async_write(c->socket,
			asio::buffer(framedData, framedSize),
			[this, store_message = std::move(message)](std::error_code ec, std::size_t length)
			{
				if (ec) {
					std::cout << "Server::sendMessage - Error during sending message, ec=" << ec ;
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
				std::cout << "Error during connection ClientImpl::connect_async ec=" << ec << std::endl;
				throw std::string("Error during connection" );
			}

			this->read_async_msgheader();

		}

		void read_async_msgheader()
		{
			std::unique_ptr<byte[]> header(new byte[INT_ENCODE_SIZE]);
			auto dataptr = header.get();

			asio::async_read(socket,
				asio::buffer(dataptr, INT_ENCODE_SIZE),
				[this, header = std::move(header)](std::error_code ec, std::size_t length)
			{
				if (ec || length != INT_ENCODE_SIZE)
				{
					std::cout << "ClientImpl::read_async_msgheader error" << std::endl;
					socket.close();
					return;
				}

				int messagesize = decodeInt(&header[0]);
				read_async_msgbody(messagesize);
				
			});
		}

		void read_async_msgbody(int msgSize)
		{
			Buffer buffer(msgSize);

			auto bufferData = buffer.data();
			auto bufferSize = buffer.size();

			asio::async_read(socket,
				asio::buffer(bufferData, bufferSize),
				[this, messageBuffer = std::move(buffer), msgSize](std::error_code ec, std::size_t length) mutable
			{
				if (ec || length != msgSize)
				{
					std::cout << "ClientImpl::read_async_msgbody error" << std::endl;
					socket.close();
					return;
				}

				client->process_message(std::move(messageBuffer)); 
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


	void Client::run()
	{
		impl->run();
	}

	Client::~Client()
	{

	}

	
	void Client::sendMessage(Buffer message)
	{
		auto messageFramedData = message.framed_data();
		auto messageFramedSize = message.framed_size();
		asio::async_write(impl->socket,
			asio::buffer(messageFramedData, messageFramedSize),
			[this, keep_message_alive = std::move(message)](std::error_code ec, std::size_t length)
		{
			if (ec) {
				std::cout << "Error during sending message Client::sendMessage" << ec << std::endl;
			}
		});

	}
	
}