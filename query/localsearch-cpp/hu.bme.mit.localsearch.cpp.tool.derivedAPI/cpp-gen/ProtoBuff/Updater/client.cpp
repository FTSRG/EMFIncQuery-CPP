#include <iostream>
#include <thread>

#include <grpc/grpc.h>
#include <grpc++/channel.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc++/security/credentials.h>
#include <derived.grpc.pb.h>

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientWriter;
using grpc::Status;
using derivedAPI::LocationInfo;
using derivedAPI::NearInfo;
using derivedAPI::Reply;
using derivedAPI::Vector;

Vector* MakeVector(double x, double y, double z){
	Vector* v = new Vector();
	v->set_x(x);
	v->set_y(y);
	v->set_z(z);
	return v;
}

LocationInfo* MakeLocationInfo(long id, Vector* vec){
	LocationInfo* li = new LocationInfo();
	li->set_id(id);
	li->set_allocated_location(vec);
	return li;
}

NearInfo* MakeNearInfo(LocationInfo* robot, LocationInfo* train){
	NearInfo* ni = new NearInfo();
	ni->set_allocated_robot(robot);
	ni->set_allocated_train(train);
	return ni;
}

class DerivedAPIClient{
public:
	explicit DerivedAPIClient(std::shared_ptr<Channel> channel)
	 : stub_(derivedAPI::NearBy::NewStub(channel)){
		 
		robot = MakeVector(10.5, 8, 10);
		
		trainPath1_.push_back(MakeVector(10, 10, 10));
		trainPath1_.push_back(MakeVector(13,  9, 10.5));
		trainPath1_.push_back(MakeVector(16,  8, 11));
		trainPath1_.push_back(MakeVector(18,  5, 11.5));
		trainPath1_.push_back(MakeVector(16,  7, 12));
		trainPath1_.push_back(MakeVector(14,8.5, 11.5));
		trainPath1_.push_back(MakeVector(12,  9, 10.5));
		trainPath1_.push_back(MakeVector(11, 9.5, 10));
		trainPath1_.push_back(MakeVector(10, 10, 10));
		
		trainPath2_.push_back(MakeVector(13, 10, 10));
		trainPath2_.push_back(MakeVector(16,  9, 9.5));
		trainPath2_.push_back(MakeVector(19,  8, 9));
		trainPath2_.push_back(MakeVector(21,  5, 8.5));
		trainPath2_.push_back(MakeVector(19,  7, 8));
		trainPath2_.push_back(MakeVector(17,8.5, 8.5));
		trainPath2_.push_back(MakeVector(15,  9, 9.5));
		trainPath2_.push_back(MakeVector(14, 9.5, 10));
		trainPath2_.push_back(MakeVector(13, 10, 10));
	}
	
	~DerivedAPIClient(){
		for(auto vec : trainPath1_) delete vec;
		trainPath1_.clear();
		for(auto vec : trainPath2_) delete vec;
		trainPath2_.clear();
		delete robot;
	}
	
	void nearBy(){
		ClientContext context;
		Reply rep;
		std::unique_ptr<ClientWriter<NearInfo>> writer(
			stub_->nearBy(&context, &rep));
		auto fv = [](std::unique_ptr<ClientWriter<NearInfo>> &writer, Vector* robot, std::vector<Vector*> &trainPath, int id){
			for(auto vec : trainPath){
				std::cout << "Train "<< id << " : (" << vec->x() << ", " << vec->y() << ", " << vec->z() << ")" << std::endl;
				NearInfo* info = MakeNearInfo(MakeLocationInfo(3, robot), MakeLocationInfo(id, vec));
				if(!writer->Write(*info)){
					//Broken stream.
					break;
				}
				//info->clear_robot();
				//info->clear_train();
				//delete info;
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			}
		};
		fv(writer, robot, trainPath1_, 1);
		fv(writer, robot, trainPath2_, 2);
		writer->WritesDone();
		Status status = writer->Finish();
		
		if(!status.ok()) std::cout << "DerivedAPI rpc failed" << std::endl;
		else std::cout << "Reply: " << rep.code();
	}
	
private:
	std::unique_ptr<derivedAPI::NearBy::Stub> stub_;
	Vector* robot;
	std::vector<Vector*> trainPath1_;
	std::vector<Vector*> trainPath2_;
};

int main(int argc, char** argv){
	DerivedAPIClient api(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
	api.nearBy();
	
}