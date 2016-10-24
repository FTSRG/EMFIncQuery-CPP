

#include"QueryClient.h"

#include"QueryTask.h"
#include"QueryService.h"

#include"MessageProtocol.pb.h"
#include"../Util/Logger.h"

#include<iostream>

using namespace Viatra::Query::Distributed;
using namespace Viatra::Query::Util;


QueryClient::QueryClient(std::string ip, uint16_t port, std::string initiatorNode, QueryServiceBase * service)
	: Network::Client(ip, port)
	, service(service)
{
	Logger::Log("QueryClient::QueryClient");
	initiateConnection(initiatorNode);

	thread = std::make_unique<std::thread>([&]() {
		Logger::SetThisThreadName(Util::concat("CLI(", ip, ",", port, ")"));
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
	Logger::Identer();
	auto rqid = rqidGenerator.generate();
	Protobuf::QueryRequest queryRequest;
	queryRequest.set_rqid(rqid);
	queryRequest.set_msgtype(Protobuf::MsgType::INITIATE_CONNECTION);
	queryRequest.mutable_initiateconnection()->set_nodename(initiatorNode);
	sendMessage(Network::Buffer(queryRequest));
}

void QueryClient::startQuerySession(uint64_t sessionID, int queryID)
{
	Logger::Log("QueryClient::startQuerySession sessionID=", sessionID, ", queryID=", queryID );
	Logger::Identer();
	auto rqid = rqidGenerator.generate();
	Protobuf::QueryRequest queryRequest;
	queryRequest.set_rqid(rqid);
	queryRequest.set_msgtype(Protobuf::MsgType::START_QUERY_SESSION);
	queryRequest.mutable_startquerysession()->set_sessionid(sessionID);
	queryRequest.mutable_startquerysession()->set_queryid(queryID);
	sendMessage(Network::Buffer(queryRequest));
	waitingQuerySessions.insert(sessionID);
}

void QueryClient::continueQuerySession(const std::string& localNodeName, uint64_t sessionID, const TaskID& taskID, int body, int operation, const std::string& frameVectorStr)
{
	Logger::Log("QueryClient::continueQuerySession sessionID=", sessionID, ", taskID=", taskID);
	Logger::Identer();
	auto rqid = rqidGenerator.generate();
	Protobuf::QueryRequest queryRequest;
	queryRequest.set_rqid(rqid);
	queryRequest.set_msgtype(Protobuf::MsgType::CONTINUE_QUERY_SESSION);
	queryRequest.mutable_continuequerysession()->set_sessionid(sessionID);
	
	for(auto id_elem : taskID)
		queryRequest.mutable_continuequerysession()->add_taskid(id_elem);


	queryRequest.mutable_continuequerysession()->set_frameasstring(frameVectorStr);
	queryRequest.mutable_continuequerysession()->set_bodyindex(body);
	queryRequest.mutable_continuequerysession()->set_operationindex(operation);
	queryRequest.mutable_continuequerysession()->set_nodename(localNodeName);

	sendMessage(Network::Buffer(queryRequest));
}


//
//		Process responses from the server
//
void QueryClient::process_message(Network::Buffer message){
	Logger::Log("QueryClient::process_message");
	Logger::Identer ident;

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
				waitingQuerySessions.erase(queryResponse.mutable_startquerysessionresponse()->sessionid());
			}
			else
			{
				Logger::Log("QueryClient::process_message -- case Protobuf::MsgType::START_QUERY_SESSION -- ERROR");
				Logger::Log("Error while connecting to other server:\n" , msg , "\n");
			}
		}
		break;

		case Protobuf::MsgType::CONTINUE_QUERY_SESSION:
		{
			Logger::Log("QueryClient::process_message -- case Protobuf::MsgType::CONTINUE_QUERY_SESSION");
			auto continueQuerySessionResponse = queryResponse.mutable_continuequerysessionresponse();

			if (continueQuerySessionResponse->status() == "OK") {
				Logger::Log("QueryClient::process_message -- case Protobuf::MsgType::CONTINUE_QUERY_SESSION");
				int64_t sessionID = continueQuerySessionResponse->sessionid();
				Logger::Log("QueryClient::process_message -- aaaa");
				TaskID taskID = continueQuerySessionResponse->taskid();
				Logger::Log("QueryClient::process_message -- sssss");
				std::string resultMatchSet = continueQuerySessionResponse->resultmatchset();
				Logger::Log("QueryClient::process_message -- dddd");
				service->acceptRemoteMatchSet(sessionID, taskID, resultMatchSet);
				Logger::Log("QueryClient::process_message -- eeee");
			}
			else
			{
				Util::Logger::Log(" --------------------------------------------------------");
				Util::Logger::Log(" ------------ CONTINUE QUERY REQUEST FAILED -------------");
				Util::Logger::Log(" --------------------------------------------------------");
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