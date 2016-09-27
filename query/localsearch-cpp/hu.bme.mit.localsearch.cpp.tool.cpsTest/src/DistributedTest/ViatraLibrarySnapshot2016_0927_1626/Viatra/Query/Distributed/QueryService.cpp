
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
	void config(const char * cfgFile);
	void run();

};

void QueryService::QueryServiceImpl::config(const char * cfgFile)
{
	std::ifstream ifs(cfgFile);
	picojson::value root;
	std::string err = picojson::parse(root, ifs);
	if (!err.empty()) {
		throw err;
	}
}

void QueryService::QueryServiceImpl::run()
{

}

QueryService::QueryService(const char* cfgFile)
{
	impl->config(cfgFile);
}

void QueryService::run()
{
	impl->run();
}

QueryService::~QueryService()
{
	// default delegated to unique_ptr
}
