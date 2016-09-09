#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <stdexcept>

#include <grpc/grpc.h>
#include <grpc++/server.h>
#include <grpc++/server_builder.h>
#include <grpc++/server_context.h>
#include <grpc++/security/server_credentials.h>
#include "derived.grpc.pb.h"

#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/DerivedFeatures/NearByUpdater.h"
#include "Viatra/Query/DerivedFeatures/NearByTestMatcher.h"
#include "Viatra/Query/DerivedFeatures/DerivedFeaturesQueryGroup.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerReaderWriter;
using grpc::ServerWriter;
using grpc::Status;
using derivedAPI::LocationInfo;
using derivedAPI::NearInfo;
using derivedAPI::Reply;
using derivedAPI::Vector;

using namespace Viatra::Query;
using namespace Viatra::Query::DerivedFeatures;

class DerivedAPIImpl final : public derivedAPI::NearBy::Service{
public:
	DerivedAPIImpl(){
		auto t1 = new ::RailRoadModel::Train(); t1->id = 1; trains.push_back(t1);
		auto t2 = new ::RailRoadModel::Train(); t2->id = 2; trains.push_back(t2);
		auto r3 = new ::RailRoadModel::RobotPart(); r3->id = 3; robotparts.push_back(r3);
	}
	
	~DerivedAPIImpl(){
		for(auto train : trains) delete train;
		trains.clear();
		for(auto rp : robotparts) delete rp;
		robotparts.clear();
	}
	
	Status nearBy(ServerContext* context, ServerReader<NearInfo>* reader, Reply* response){
		std::cout << "------- NearBy Stream Start -------" << std::endl;
		ModelRoot modelRoot;
		auto engine = QueryEngine<ModelRoot>::of(&modelRoot);
		auto matcher = engine.matcher<NearByTestQuerySpecification>();
		try{
			NearInfo nInfo;
			while(reader->Read(&nInfo)){
				LocationInfo robot = nInfo.robot();
				LocationInfo train = nInfo.train();
				NearByUpdate<ModelRoot>::update(modelRoot, robot.id(), train.id(), 
				 robot.location().x(), robot.location().y(), robot.location().z(),
				 train.location().x(), train.location().y(), train.location().z());
				std::cout << "Got a message: Train " << train.id() << std::endl;
				auto matches = matcher.matches();
				for(auto&& match : matches){
					std::cout << "------ RobotPart" << match.robot->id << " ->nearBy-> Train" << match.train->id << std::endl;
				}
			}
		}catch(std::invalid_argument* e){
			std::cout << e->what() << std::endl;
			response->set_code(0);
			std::cout << "------- NearBy Stream END -------" << std::endl;
			return Status::OK;
		}
		response->set_code(1);
		std::cout << "------- NearBy Stream END -------" << std::endl;
		return Status::OK;
	}
private:
	std::vector<::RailRoadModel::Train*> trains;
	std::vector<::RailRoadModel::RobotPart*> robotparts;
};

int main(){
	std::string server_address("0.0.0.0:50051");
	DerivedAPIImpl* service = new DerivedAPIImpl();

	ServerBuilder builder;
	builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
	builder.RegisterService(service);
	std::unique_ptr<Server> server(builder.BuildAndStart());
	std::cout << "Server listening on " << server_address << std::endl;
	server->Wait();
	delete service;
}