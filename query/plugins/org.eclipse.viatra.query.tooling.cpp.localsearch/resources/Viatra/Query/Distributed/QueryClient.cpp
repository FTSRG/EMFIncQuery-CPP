

#include"QueryClient.h"

#include"MessageProtocol.pb.h"
#include"../Util/Logger.h"

#include<iostream>

using namespace Viatra::Query::Distributed;
using namespace Viatra::Query::Util;


QueryClient::QueryClient(std::string ip, uint16_t port, std::string initiatorNode)
	: Network::Client(ip, port)
{
	Logger::Log("QueryClient::QueryClient");
	initiateConnection(initiatorNode);

	thread = std::make_unique<std::thread>([&]() {
		Logger::SetThisThreadName(Util::concat("ClientProcessor(", ip, ",", port, ")"));
		try {
			Client::run();
		}
		catch (const std::exception& ex)
		{
			Logger::Log("Exception caught - ", ex.what());
		}
		catch (const std::string& ex)
		{
			Logger::Log("Exception caught - ", ex);
		}
		catch (const char *c)
		{
			Logger::Log("Exception caught - ", c);
		}
		catch (...)
		{
			Logger::Log("Exception caught - Something other than std::exception, string, or const char*");
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


//
//		Process responses from the server
//
void QueryClient::process_message(Network::Buffer message){
	Logger::Log("QueryClient::process_message");
	Protobuf::QueryResponse queryResponse;
	queryResponse.ParseFromArray(message.data(), message.size());
	switch (queryResponse.msgtype())
	{
		case Protobuf::MsgType::INITIATE_CONNECTION: 
		{
			Logger::Log("QueryClient::process_message -- case Protobuf::MsgType::INITIATE_CONNECTION");
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
				Lock lck(mutex);
				errorMessage = msg;
				state = State::ERROR;
			}
		}
		break;

		case Protobuf::MsgType::START_QUERY_SESSION:
		{
			Logger::Log("QueryClient::process_message -- case Protobuf::MsgType::START_QUERY_SESSION");
			std::string msg = queryResponse.mutable_startquerysessionresponse()->message();
			if (msg == "OK") {
				Logger::Log("QueryClient::process_message -- case Protobuf::MsgType::START_QUERY_SESSION -- OK");

				Lock lck(mutex);
				readyQuerySessions.insert(queryResponse.mutable_startquerysessionresponse()->sessionid());
			}
			else
			{
				Logger::Log("QueryClient::process_message -- case Protobuf::MsgType::START_QUERY_SESSION -- ERROR");
				Logger::Log("Error while connecting to other server:\n" , msg , "\n");
			}
		}
		break;

		default:
			Util::Logger::Log(" --------------------------------------------------------");
			Util::Logger::Log(" ------------- UNKNOWN MESSAGE TYPE IS READ -------------");
			Util::Logger::Log(" --------------------------------------------------------");
			break;
		
	}


}