#include <cmath>
#include <chrono>
#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <stdexcept>

#include "Viatra/Query/QueryEngine.h"
#include "Viatra/Query/Matcher/ModelIndex.h"

#include "model/RailRoadModel_def.h"
#include "ecore_def.h"
#include "Viatra/Query/DerivedFeatures/NearByMatcher.h"
#include "Viatra/Query/DerivedFeatures/NearByUpdater.h"

using namespace Viatra::Query;
using namespace Viatra::Query::DerivedFeatures;
using namespace std;
int main(){
  ModelRoot modelRoot;

  auto t1 = new ::RailRoadModel::Train(); t1->id = 1;
  auto t2 = new ::RailRoadModel::Train(); t2->id = 2;
  auto t3 = new ::RailRoadModel::Train(); t3->id = 3;
  auto r1 = new ::RailRoadModel::RobotPart(); r1->id = 4;
  auto r2 = new ::RailRoadModel::RobotPart(); r2->id = 5;
  auto r3 = new ::RailRoadModel::RobotPart(); r3->id = 6;

  //DEBUG
  for(auto& src : ::RailRoadModel::RobotPart::_instances){
    //DEBUG
    cout << "Source ID: " << src->id << endl;
    for(auto& trg : src->nearBy) cout << "Target ID: " << trg->id << endl;
  }
  cout << "Engine Created" << endl;
  cout << "Matcher Created" << endl;

  double robX=0.0; double robY=0.0; double robZ=0.0;
  double trX=0.0; double trY=0.0; double trZ=0.0;

  int i = 0;
  while(i < 6){
  	for(int j = 4; j <= 6; j++){ //RobotParts
      //cout << "RobotPart ID: " << j << "(" <<robX <<", " << robY << ", " << robZ << ")" << endl;
      for(int k = 1; k <= 3; k++){ //Trains
        NearByUpdate<ModelRoot>::update(modelRoot,j, k, robX, robY, robZ, trX, trY, trZ);
        //cout << "\tTrain ID: " << k << "(" <<trX <<", " << trY << ", " << trZ << ")" << endl;
      }
    }
  	cout << endl << "!!!!Updated" << endl;
    cout << "Objects status:" << endl;

    for(auto& src : ::RailRoadModel::RobotPart::_instances){
      cout << "Source ID: " << src->id << "(" <<robX <<", " << robY << ", " << robZ << ")" << endl;
      for(auto& trg : src->nearBy) cout << "\tTarget ID: " << trg->id << "(" <<trX <<", " << trY << ", " << trZ << ")" << endl;
    }
    i++;
    robX--; //robY--; robZ--;
    trX++; //trY++; trZ++;
  }
  
  cout << endl << endl << "Testing" << endl;
  try{
	  NearByUpdate<ModelRoot>::update(modelRoot,4, 10, robX, robY, robZ, trX, trY, trZ);
  }catch(invalid_argument* ex){
	  cout << "Exception occured: " << ex->what() << endl;
  }
  try{
	  NearByUpdate<ModelRoot>::update(modelRoot, 10, 1, robX, robY, robZ, trX, trY, trZ);
  }catch(invalid_argument* ex){
	  cout << "Exception occured: " << ex->what() << endl;
  }
  
}
