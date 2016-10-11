

#include"QueryClient.h"

#include"MessageProtocol.pb.h"

#include<iostream>

using namespace Viatra::Query::Distributed;


QueryClient::QueryClient(std::string ip, uint16_t port, std::string initiatorNode)
	: Network::Client(ip, port)
{
	initiateConnection(initiatorNode);

	thread = std::make_unique<std::thread>([this]() {
		Client::run();
	});
}

void QueryClient::initiateConnection(std::string initiatorNode)
{
	auto rqid = rqidGenerator.generate();
	Protobuf::QueryRequest queryRequest;
	queryRequest.set_rqid(rqid);
	queryRequest.set_msgtype(Protobuf::MsgType::INITIATE_CONNECTION);
	queryRequest.mutable_initiateconnection()->set_nodename(initiatorNode);
	sendMessage(queryRequest);
}

void QueryClient::startQuerySession(uint64_t sessionID, int queryID)
{
	auto rqid = rqidGenerator.generate();

	Protobuf::QueryRequest queryRequest;
	queryRequest.set_rqid(rqid);
	queryRequest.set_msgtype(Protobuf::MsgType::START_QUERY_SESSION);
	queryRequest.mutable_startquerysession()->set_sessionid(sessionID);
	queryRequest.mutable_startquerysession()->set_queryid(queryID);
	sendMessage(queryRequest);
	
}


void QueryClient::process_message(Network::Buffer message){
	Protobuf::QueryResponse queryResponse;
	queryResponse.ParseFromArray(message.data(), message.size());
	switch (queryResponse.msgtype())
	{
		case Protobuf::MsgType::INITIATE_CONNECTION: 
		{
			std::string msg = queryResponse.mutable_initiateconnectionresponse()->message();
			if (msg == "OK")
				state = State::READY;
			else
			{
				std::cout << "Error while connecting to other server:\n" + msg + "\n" << std::endl;
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