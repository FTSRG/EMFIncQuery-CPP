

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
	void process_message(Network::Buffer message) override
	{
		char * begin = (char*)message.data();
		char * end = (char*)message.data() + message.size();

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
	void process_message(Network::Connection * c, Network::Buffer message) override
	{
		char * begin = (char*)message.data();
		char * end = (char*)message.data() + message.size();
		std::cout << "The  client said: \"" + std::string(begin, end) + "\"" << std::endl;

		char buffer[BUFSIZE];
		Network::Buffer out(snprintf(buffer, BUFSIZE, " Nice message \"%.*s\"", message.size(), begin));
		memcpy(out.data(), buffer, out.size());

		sendMessage(c, std::move(out));
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

			char buffer[BUFSIZE];
			Network::Buffer out(snprintf(buffer, BUFSIZE, "It is the %d. message from me", i));
			memcpy(out.data(), buffer, out.size());

			client.sendMessage(std::move(out));
		}
			

		std::this_thread::sleep_for(std::chrono::seconds(4));
		t.join();

		return 0;
	}
	else
		throw "server or client mode must be provided";

}
