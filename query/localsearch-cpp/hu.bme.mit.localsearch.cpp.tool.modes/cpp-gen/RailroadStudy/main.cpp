


#include"Viatra/Query/DerivedInput/FrozenStateAPI.h"
#include"Viatra/Query/DerivedInput/QueryRunnerFactory.h"
#include"model/ModelRoot.h"


#include"Viatra/Query/Distributed/QueryService.h"

int main(int argc, char**argv)
{
	using namespace Viatra::Query;

	Viatra::Query::Distributed::QueryService < Viatra::Query::Model::ModelRoot, DerivedInput::QueryRunnerFactory > service(
		"model.json", argv[1]
		);



	return 0;
}