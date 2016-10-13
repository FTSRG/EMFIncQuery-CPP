

#include"QueryClient.h"

#include"MessageProtocol.pb.h"
#include"../Util/Logger.h"

#include<iostream>

using namespace Viatra::Query::Distributed;
using namespace Viatra::Query::Util;


QueryClient::QueryClient(std::string ip, uint16_t port, std::string initiatorNode)
	: Network::Client(ip, port)
{
	initiateConnection(initiatorNode);

	thread = std::make_unique<std::thread>([&]() {
		Logger::SetThisThreadName(Util::concat("ClientProcessor(", ip, ",", port, ")"));
		try {
			Client::run();
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what();
		}
		catch (const std::string& ex)
		{
			std::cout << ex;
		}
		catch (const char *c)
		{
			std::cout << c;
		}
		catch (...)
		{
			std::cout << "Something catched other than std::exception, string, or const char*";
		}
	});
}

void QueryClient::initiateConnection(std::string initiatorNode)
{
	Logger::Log("QueryClient::initiateConnection initiatorNode=", initiatorNode);
	auto rqid = rqidGenerator.generate();
	Protobuf::QueryRequest queryRequest;
	queryRequest.set_rqid(rqid);
	queryRequest.set_msgtype(Protobuf::MsgType::INITIATE_CONNECTION);
	queryRequest.mutable_initiateconnection()->set_nodename(initiatorNode);
	sendMessage(queryRequest);
	Logger::Log("QueryClient::initiateConnection done");
}

void QueryClient::startQuerySession(uint64_t sessionID, int queryID)
{
	Logger::Log("QueryClient::startQuerySession sessionID=", sessionID, ", queryID=", queryID );
	auto rqid = rqidGenerator.generate();
	Protobuf::QueryRequest queryRequest;
	queryRequest.set_rqid(rqid);
	queryRequest.set_msgtype(Protobuf::MsgType::START_QUERY_SESSION);
	queryRequest.mutable_startquerysession()->set_sessionid(sessionID);
	queryRequest.mutable_startquerysession()->set_queryid(queryID);
	sendMessage(queryRequest);
	Logger::Log("QueryClient::startQuerySession done");
	
}


void QueryClient::process_message(Network::Buffer message){
	Protobuf::QueryResponse queryResponse;
	queryResponse.ParseFromArray(message.data(), message.size());
	switch (queryResponse.msgtype())
	{
		case Protobuf::MsgType::INITIATE_CONNECTION: 
		{
			auto initiateConnectionResponse = queryResponse.mutable_initiateconnectionresponse();
			std::string msg = initiateConnectionResponse->message();
			if (msg == "OK")
			{
				Logger::Log("Initiating connection was succesful!");
				state = State::READY;
			}
			else
			{
				Logger::Log("Error while connecting to other server:\n" , msg , "\n");
				errorMessage = msg;
				state = State::ERROR;
			}
		}
		break;

		case Protobuf::MsgType::START_QUERY_SESSION:
		{
			std::string msg = queryResponse.mutable_startquerysessionresponse()->message();
			if (msg == "OK") {
				readyQuerySessions.insert(queryResponse.mutable_startquerysessionresponse()->sessionid());
			}
			else
			{
				std::cout << "Error while connecting to other server:\n" + msg + "\n" << std::endl;
				errorMessage = msg;
				state = State::ERROR;
			}
		}
		break;



	}


}