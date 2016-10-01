
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
VIATRA_FUNCTION void Viatra::Query::Distributed::QueryServer::process_message(Network::Connection * c, Network::byte * bytes, int len)
{
	QueryServerRequest qsr;
	qsr.ParseFromArray(bytes, len);
	

}





