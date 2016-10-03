

#include<string>

#include<Viatra/Query/Util/network.h>
#include<iostream>
#include<thread>

constexpr int BUFSIZE = 6000;


class MyClient final : public Network::Client{

public:
	MyClient(std::string ip)
		: Client(ip, 54321)
	{	
	}
		
protected:
	void process_message(Network::byte * bytes, int len) override
	{
		char * begin = (char*)bytes;
		char * end = (char*)bytes + len;

		std::cout << "The server said: \"" + std::string(begin, end) + "\"" << std::endl;
	}
};

class MyServer final : public Network::Server {
public:
	MyServer()
		: Server(54321)
	{	
	}
protected:
	void process_message(Network::Connection * c, Network::byte * bytes, int len) override
	{
		char * begin = (char*)bytes;
		char * end = (char*)bytes + len;
		std::cout << "The  client said: \"" + std::string(begin, end) + "\"" << std::endl;

		char buffer[BUFSIZE];
		sendMessage(c, (Network::byte*)buffer, snprintf(buffer, BUFSIZE, " Nice message \"%.*s\"", len, begin));
	}

};

int server_test(int argc, char **argv)
{
	if (argc < 2)
		throw "Argc must be greater or equal to 2";

	if (std::string(argv[1]) == "server")
	{
		MyServer serv;
		serv.run();
		return 0;
	}
	else if (std::string(argv[1]) == "client")
	{
		MyClient client("localhost");
		std::thread t = std::thread([&client]() {
			client.run();
		});
		
		char buffer[BUFSIZE];
		for (int i = 1; i <= 10; ++i) {
			std::cout << "x";
			client.sendMessage((Network::byte*)buffer, snprintf(buffer, BUFSIZE, "It is the %d. message from me", i));
		}
			

		std::this_thread::sleep_for(std::chrono::seconds(4));
		t.join();

		return 0;
	}
	else
		throw "server or client mode must be provided";

}
