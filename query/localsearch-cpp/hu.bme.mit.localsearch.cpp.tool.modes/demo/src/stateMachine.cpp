#include "StatechartEngine/interface_in.h"
#include "StatechartEngine/interface_out.h"

//#define DEBUG

#ifndef DEBUG
#include "ros/ros.h"
#include "demo/TrainSlow.h"
#include "demo/TrainStop.h"
#endif

#include <iostream>
#include "railRoadModel_def.h"
#include <vector>
#include <chrono>
#include <thread>


#define nullptr 0

using namespace railRoadModel;

std::vector<Train*> trElements;
std::vector<RobotPart*> rpElements;

#ifndef DEBUG
// # ROS communication
ros::NodeHandle* n;
ros::Publisher slowStream_pub;
ros::Publisher stopStream_pub;
#endif

bool initializedComm = false;


void sendStopMessage(int trainID, bool stop){
#ifndef DEBUG
  uint8_t isStop = 0;
  if(stop) isStop = 1;
  demo::TrainStop trainStopMsg;
  trainStopMsg.trainID = trainID;
  trainStopMsg.stopTrain = isStop;
  if(initializedComm) stopStream_pub.publish(trainStopMsg);
#endif
}

void sendSlowDownMessage(int trainID, bool slowDown){
#ifndef DEBUG  
  uint8_t isSlow = 0;
  if(slowDown) isSlow = 1;
  demo::TrainSlow trainSlowMsg;
  trainSlowMsg.trainID = trainID;
  trainSlowMsg.slowDown = isSlow;
  if(initializedComm) slowStream_pub.publish(trainSlowMsg);
#endif
}

void init_Comm(int argc, char** argv ){
#ifndef DEBUG
  ros::init(argc, argv, "stateMachine");
  n = new ros::NodeHandle();
  slowStream_pub = n->advertise<demo::TrainSlow>("slowStream", 1000);
  stopStream_pub = n->advertise<demo::TrainStop>("stopStream", 1000);
#endif
  initializedComm = true;
}
// #

void init(int argc, char** argv){
	//Robot* r = new Robot(); rElements.push_back(r);
//TODO Determine RobotPart ids
	RobotPart* rp1 = new RobotPart(); rp1->id=1; rpElements.push_back(rp1);
	RobotPart* rp2 = new RobotPart(); rp2->id=2; rpElements.push_back(rp2);
	RobotPart* rp3 = new RobotPart(); rp3->id=3; rpElements.push_back(rp3);
//TODO Get Train id
	Train* tr1 = new Train(); tr1->id = 11; trElements.push_back(tr1);
	Train* tr2 = new Train(); tr2->id = 12; trElements.push_back(tr2);
	Train* tr3 = new Train(); tr3->id = 13; trElements.push_back(tr3);

	init_Comm(argc, argv);
}

void destruct(){
	for(auto element : trElements){
		delete element;
	}
	for(auto element : rpElements){
		delete element;
	}
	trElements.clear();
	rpElements.clear();
#ifndef DEBUG
	ros::shutdown();
	delete n;
#endif
}

int main(int argc, char** argv) {
  // Queue handler would also come here. Example in timer_tester_main.cpp
  init(argc, argv);
  std::cout << "---Start---" << std::endl;
  logStates();
  evaluate("clk");
  std::cout << "-Sig: CLK---" << std::endl;
  evaluate("turnOn");
  std::cout << "-Sig: TurnON---" << std::endl;
  logStates();
  evaluate("clk");
  std::cout << "-Sig: CLK---" << std::endl;
  logStates();
  for(auto rp : rpElements){
	  for(auto tr : trElements){
		  rp->close.push_back(tr);
		  //std::cout << rp->id << " RobotPart close to " << tr->id << "Train" << std::endl;
		  break;
	  }
	  break;
  }
  evaluate("clk");
  logStates();
  for(auto rp : rpElements){
	  for(auto tr : trElements){
		  rp->veryClose.push_back(tr);
		  //std::cout << rp->id << " RobotPart close to " << tr->id << "Train" << std::endl;
		  break;
	  }
	  break;
  }
  evaluate("clk");
  logStates();
  for(auto rp : rpElements){
	  rp->close.clear();
	  rp->veryClose.clear();
  }
  evaluate("clk");
  logStates();
  std::cout << "---End---" << std::endl;
  destruct();
  return 0;
}
