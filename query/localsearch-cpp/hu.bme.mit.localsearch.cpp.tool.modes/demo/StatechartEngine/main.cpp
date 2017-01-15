#include "interface_in.h"
#include <iostream>
#include "railRoadModel_def.h"
#include <vector>

#define nullptr 0

using namespace railRoadModel;

std::vector<Train*> trElements;
std::vector<RobotPart*> rpElements;

void init(){
	//Robot* r = new Robot(); rElements.push_back(r);
	RobotPart* rp1 = new RobotPart(); rp1->id=1; rpElements.push_back(rp1);
	RobotPart* rp2 = new RobotPart(); rp2->id=2; rpElements.push_back(rp2);
	RobotPart* rp3 = new RobotPart(); rp3->id=3; rpElements.push_back(rp3);
	
	Train* tr1 = new Train(); tr1->id = 11; trElements.push_back(tr1);
	Train* tr2 = new Train(); tr2->id = 12; trElements.push_back(tr2);
	Train* tr3 = new Train(); tr3->id = 13; trElements.push_back(tr3);
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
}

int main() {
  // Queue handler would also come here. Example in timer_tester_main.cpp
  init();
  std::cout << "---Start---" << std::endl;
  logStates();
  evaluate("clk");
  evaluate("turnOn");
  logStates();
  /*evaluate("clk");
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
  std::cout << "---End---" << std::endl;*/
  destruct();
  return 0;
}
