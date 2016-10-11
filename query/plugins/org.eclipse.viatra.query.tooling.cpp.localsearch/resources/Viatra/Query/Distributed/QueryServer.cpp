
#include "QueryServer.h"
#include "QueryService.h"

#include "MessageProtocol.pb.h"

Viatra::Query::Distributed::QueryServer::QueryServer(uint16_t port, QueryServiceBase * service)
	: Network::Server(port)
	, service(service)
{
				
}

Viatra::Query::Distributed::QueryServer::~QueryServer()
{
				
}

void Viatra::Query::Distributed::QueryServer::accept_connection(Network::Connection * c)
{

}
void Viatra::Query::Distributed::QueryServer::process_message(Network::Connection * connection, Network::Buffer message)
{
	Protobuf::QueryRequest queryRequest;
	queryRequest.ParseFromArray(message.data(), message.size());
	
	switch (queryRequest.msgtype())
	{
		case Protobuf::MsgType::INITIATE_CONNECTION: {
			auto & request = queryRequest.initiateconnection();
			auto responseMessage = service->initiateConnection(connection, request.nodename());
				
			Protobuf::QueryResponse queryResponse;
			queryResponse.set_rqid(queryRequest.rqid());
			queryResponse.set_msgtype(queryRequest.msgtype());
				
			queryResponse.mutable_initiateconnectionresponse()->set_message(responseMessage);
			sendMessage(connection, Network::Buffer(queryResponse));
		}
		break;

		case Protobuf::MsgType::START_QUERY_SESSION: {
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
				service->continueQuery(
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
	}

}





