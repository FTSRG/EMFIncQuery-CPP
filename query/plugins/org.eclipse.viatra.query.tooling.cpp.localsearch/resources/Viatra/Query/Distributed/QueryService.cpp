
#include"QueryService.h"

using namespace Viatra::Query::Distributed;


#include"picojson.h"

/*
class QueryServiceBase
{
	std::string nodeName;
	std::unique_ptr<QueryServer> server;
	std::map<std::string, std::unique_ptr<QueryClient>> clients;

	IDGenerator querySessionIDGenerator;
	std::map < int, std::unique_ptr<QueryRunnerBase> > queryRunners;
};
*/

QueryServiceBase::QueryServiceBase(const char * configJSON, const char * nodeName)
{
	
}

QueryServiceBase::~QueryServiceBase()
{

}

