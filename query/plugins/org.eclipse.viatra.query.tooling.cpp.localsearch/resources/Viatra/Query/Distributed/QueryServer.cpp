
#include "QueryServer.h"

#include "MessageProtocol.pb.h"

VIATRA_FUNCTION Viatra::Query::Distributed::QueryServer::QueryServer(uint16_t port)
	: Network::Server(port)
{
				
}

VIATRA_FUNCTION Viatra::Query::Distributed::QueryServer::~QueryServer()
{
				
}

VIATRA_FUNCTION void Viatra::Query::Distributed::QueryServer::accept_connection(Network::Connection * c)
{

}
VIATRA_FUNCTION void Viatra::Query::Distributed::QueryServer::process_message(Network::Connection * c, Network::Buffer message)
{
	Protobuf::QueryRequest qsr;
	qsr.ParseFromArray(message.data(), message.size());
	

}





