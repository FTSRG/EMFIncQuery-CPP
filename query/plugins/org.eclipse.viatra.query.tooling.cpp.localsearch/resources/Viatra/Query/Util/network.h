

#ifndef _NETWORK_NETWORK_H_
#define _NETWORK_NETWORK_H_


#include<string>
#include<stdint.h>
#include<memory>
#include<vector>
#include <google/protobuf/message.h>
	
namespace Network
{
	class Client;
	class Server;

	using byte = uint8_t;
	
	class Buffer {
	private:
		size_t len;
		std::unique_ptr<byte[]> buf;

		void calculate_header();
	public:
		static constexpr auto HEADER = 4;

		Buffer(size_t len)
			: len(len)
			, buf(new byte[HEADER + len])
		{
			calculate_header();
		}
		
		Buffer(::google::protobuf::Message &protoMessage)
			: Buffer(protoMessage.ByteSize())
		{
			protoMessage.SerializeToArray(data(), size());
		}

		Buffer(const Buffer&) = delete;	// avoid copy
		Buffer(Buffer&&) = default;		// Move default by moving the buffer
		~Buffer() = default;			// delete by unique_ptr destructor

		Buffer copy()
		{
			Buffer ret(len);
			memcpy(ret.buf.get(), buf.get(), len);
			return std::move(ret);
		}
		
		byte& operator[](size_t index){
			return buf[HEADER + index];
		}
		const byte& operator[](size_t index) const {
			return buf[HEADER + index];
		}
		
		byte* data(){
			return &buf[HEADER];
		}
		const byte* data() const {
			return &buf[HEADER];
		}
		size_t size() const {
			return len;
		}
	private:
		friend class Network::Client;
		friend class Network::Server;
		const byte* framed_data() const {
			return &buf[0];
		}
		size_t framed_size() const {
			return HEADER + len;
		}


	};

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
		void stop();
		void sendMessage(Connection * c, Buffer message);
	protected:
		virtual void accept_connection(Network::Connection * c) {};
		virtual void process_message(Connection * c, Buffer message) = 0;

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
		void sendMessage(Buffer message);
	protected:
		virtual void process_message(Buffer message) = 0;

	};
}



#endif