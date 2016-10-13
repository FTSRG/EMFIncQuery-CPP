
#include "QueryServer.h"
#include "QueryService.h"

#include "MessageProtocol.pb.h"
#include "Request.h"
#include "../Util/Logger.h"

using namespace Viatra::Query::Distributed;

QueryServer::QueryServer(uint16_t port, QueryServiceBase * service)
	: Network::Server(port)
	, service(service)
{
	Util::Logger::Log("QueryServer::QueryServer");
}

QueryServer::~QueryServer()
{
	Util::Logger::Log("QueryServer::~QueryServer");
				
}

void QueryServer::sendMatchResults(const Request& rq, const std::string& status, int64_t sessionID, TaskID taskID, const std::string& resultMatchSet)
{
	Util::Logger::Log("QueryServer::sendMatchResults");
	int partIndex = 0;
	bool isFinalPart = true;

	Protobuf::QueryResponse response;
	response.set_rqid(rq.rqid);
	response.set_msgtype(Protobuf::MsgType::CONTINUE_QUERY_SESSION);
	auto & continueQuerySessionResponse = *response.mutable_continuequerysessionresponse();
	continueQuerySessionResponse.set_status(status);
	continueQuerySessionResponse.set_sessionid(sessionID);
	for(auto id : taskID)
		continueQuerySessionResponse.add_taskid(id);
	continueQuerySessionResponse.set_resultmatchset(resultMatchSet);
	
	sendMessage(rq.connecton, response);
}

void QueryServer::accept_connection(Network::Connection * c)
{
	Util::Logger::Log("QueryServer::accept_connection");

}
void QueryServer::process_message(Network::Connection * connection, Network::Buffer message)
{
	Util::Logger::Log("QueryServer::process_message");
	Util::Logger::Identer ident;

	Protobuf::QueryRequest queryRequest;
	queryRequest.ParseFromArray(message.data(), message.size());
		
	switch (queryRequest.msgtype())
	{
		case Protobuf::MsgType::INITIATE_CONNECTION: {
			Util::Logger::Log("QueryServer::process_message case Protobuf::MsgType::INITIATE_CONNECTION rqid=", queryRequest.rqid());
			auto & request = queryRequest.initiateconnection();
			auto responseMessage = service->process_initiateConnection(connection, request.nodename());
				
			Protobuf::QueryResponse queryResponse;
			queryResponse.set_rqid(queryRequest.rqid());
			queryResponse.set_msgtype(queryRequest.msgtype());
				
			queryResponse.mutable_initiateconnectionresponse()->set_message(responseMessage);
			sendMessage(connection, Network::Buffer(queryResponse));
		}
		break;

		case Protobuf::MsgType::START_QUERY_SESSION: {
			Util::Logger::Log("QueryServer::process_message case Protobuf::MsgType::START_QUERY_SESSION rqid=", queryRequest.rqid());
			Util::Logger::Identer ident2;
			auto & request = queryRequest.startquerysession();
			auto responseMessage = service->startLocalQuerySession(request.sessionid(), request.queryid());

			Protobuf::QueryResponse queryResponse;
			queryResponse.set_rqid(queryRequest.rqid());
			queryResponse.set_msgtype(queryRequest.msgtype());

			queryResponse.mutable_startquerysessionresponse()->set_message(responseMessage);

			sendMessage(connection, Network::Buffer(queryResponse));
		}
		break;
		
		case Protobuf::MsgType::CONTINUE_QUERY_SESSION: {
			Util::Logger::Log("QueryServer::process_message case Protobuf::MsgType::CONTINUE_QUERY_SESSION rqid=", queryRequest.rqid());
			auto & request = queryRequest.continuequerysession();

			bool nodeAndConnectionMatches = service->checkNodeConnection(request.nodename(), connection);

			if ( !nodeAndConnectionMatches)
			{
				Protobuf::QueryResponse queryResponse;
				queryResponse.set_rqid(queryRequest.rqid());
				queryResponse.set_msgtype(queryRequest.msgtype());
				queryResponse.mutable_continuequerysessionresponse()->set_status("ERROR: Nodename not matching with the connection");

			}
			else
			{
				service->continueQueryLocally(
					Request{connection, queryRequest.rqid()},
					request.sessionid(),
					request.taskid(),
					request.bodyindex(),
					request.operationindex(),
					request.frameasstring()
					);
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





