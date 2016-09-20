
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

	class Client {
		AnswerFuture sendMessage(MessageBuffer message);
	};

	class Server {

	protected:
		virtual MessageBuffer process(MessageBuffer message)
	public:
		Server();
		void run();
		~Server();

		

	};
}