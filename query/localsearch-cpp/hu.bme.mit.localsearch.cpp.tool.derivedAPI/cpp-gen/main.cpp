#include <iostream>

#include "Viatra/Query/Deployment/IDerivedExecutesDerived.h"
#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Deployment/DeploymentQueryGroup.h"
#include "RailRoadModel/Segment.h"

using namespace Viatra::Query;
using namespace Viatra::Query::Deployment;
using namespace PlatformModel;
using namespace RailRoadModel;

ModelRoot modelRoot;

void print(Node &cam1){
	std::cout << "Camera " << cam1.id << ": ";
	std::cout << "Executes-[ ";
	for(auto it : cam1.executes){
		std::cout << "Segment" <<it->id << " ";
	}
	std::cout << "] " << std::endl;
	std::cout << "DerivedExecutes-[ ";
	for(auto it : cam1.derivedExecutes){
		std::cout << "Train" <<it->id << " ";
	}
	std::cout << "] " << std::endl;
}

void time(Node &cam1, Node &cam2){
	IDerivedExecutesUpdate<ModelRoot>::update(modelRoot, cam1.id);
	IDerivedExecutesUpdate<ModelRoot>::update(modelRoot, cam2.id);
	print(cam1);
	print(cam2);
}

int main(int argc, char **argv)
{
	std::cout << "Hello World" << std::endl;
	ModelRoot modelRoot;
	
	//declaration
	Node camera1; camera1.id = 0;
	Node camera2; camera2.id = 1;
	Segment seg1; seg1.id = 2;
	Segment seg2; seg2.id = 3;
	Segment seg3; seg3.id = 4;
	Segment seg4; seg4.id = 5;
	
	Train tr1; tr1.id = 6;
	Train tr2; tr2.id = 7;
	
	//config 
	seg1.connectedTo.push_back(&seg2); 
	seg2.connectedTo.push_back(&seg3); seg2.connectedTo.push_back(&seg1);
	seg3.connectedTo.push_back(&seg2); seg3.connectedTo.push_back(&seg4);
	seg4.connectedTo.push_back(&seg3);
	camera1.executes.push_back(&seg1); camera1.executes.push_back(&seg2);
	camera2.executes.push_back(&seg3); camera2.executes.push_back(&seg4);
	
	//runtime
	time(camera1, camera2);
	
	std::cout << std::endl <<  "+++ Time goes forward: ";
	tr1.currentlyOn = &seg1;
	std::cout << "Train1 on Segment2" << std::endl;
	time(camera1, camera2);
	
	std::cout << std::endl << "+++ Time goes forward: ";
	tr1.currentlyOn = &seg2;
	tr1.previouslyOn = &seg1;
	std::cout << "Train1 on Segment3" << std::endl;
	time(camera1, camera2);
	
	std::cout << std::endl << "+++ Time goes forward: ";
	tr1.currentlyOn = &seg3;
	tr1.previouslyOn = &seg2;
	std::cout << "Train1 on Segment4" << std::endl;
	time(camera1, camera2);
	
	std::cout << std::endl << "+++ Time goes forward: ";
	tr1.currentlyOn = &seg4;
	tr1.previouslyOn = &seg3;
	std::cout << "Train1 on Segment5" << std::endl;
	time(camera1, camera2);
	
	std::cout << std::endl << "+++ Time goes forward: ";
	tr2.currentlyOn = &seg1;
	std::cout << "Train2 on Segment2" << std::endl;
	time(camera1, camera2);
	
	std::cout << std::endl << "+++ Time goes forward: ";
	tr2.currentlyOn = &seg2;
	tr2.previouslyOn = &seg1;
	std::cout << "Train2 on Segment3" << std::endl;
	time(camera1, camera2);
	
	return 0;
}
