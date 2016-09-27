
#include"QueryService.h"

#include"QueryRunner.h"
#include"QueryServer.h"
#include"QueryClient.h"
#include"Node.h"

#include<vector>
#include<memory>
#include<tuple>
#include<fstream>


#include<picojson.h>


using namespace Viatra::Query::Distributed;

class QueryService::QueryServiceImpl
{

	std::vector<std::tuple<Node, QueryClient>> remoteNodes;
	QueryServer queryServer;


public:
	VIATRA_FUNCTION void config(const char * cfgFile);
	VIATRA_FUNCTION void run();

};

VIATRA_FUNCTION void QueryService::QueryServiceImpl::config(const char * cfgFile)
{
	std::ifstream ifs(cfgFile);
	picojson::value root;
	std::string err = picojson::parse(root, ifs);
	if (!err.empty()) {
		throw err;
	}
}

VIATRA_FUNCTION void QueryService::QueryServiceImpl::run()
{

}

VIATRA_FUNCTION QueryService::QueryService(const char* cfgFile)
{
	impl->config(cfgFile);
}

VIATRA_FUNCTION void QueryService::run()
{
	impl->run();
}

VIATRA_FUNCTION QueryService::~QueryService()
{
	// default delegated to unique_ptr
}
