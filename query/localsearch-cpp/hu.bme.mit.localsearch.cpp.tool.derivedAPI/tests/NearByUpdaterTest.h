// **************************************
//
// COPY ME NEXT TO GENERATED MAKEFILE
//
// **************************************
#include <unordered_set>
#include "gtest/gtest.h"

#include "Viatra/Query/DerivedFeatures/NearByUpdater.h"

/**
 * @author Krisztian Toth
 */

 using namespace ::Viatra::Query;
 using namespace ::Viatra::Query::DerivedFeatures;
 using namespace ::RailRoadModel;
 
 class NearByUpdaterTest: public ::testing::Test {
  // You can remove any or all of the following functions if its body
  // is empty.
public:
  NearByUpdaterTest() {
    robotX = 10;
	robotY = 10;
	robotZ = 10;
	trainX = 10;
	trainY = 10;
	trainZ = 10;
  }

  virtual ~NearByUpdaterTest() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  void SetUp(){
	auto t1 = new Train(); t1->id = 1; trains.push_back(t1);
	auto t2 = new Train(); t2->id = 2; trains.push_back(t2);
	auto t3 = new Train(); t3->id = 3; trains.push_back(t3);
	auto r4 = new RobotPart(); r4->id = 4; robotparts.push_back(r4);
	auto r5 = new RobotPart(); r5->id = 5; robotparts.push_back(r5);
	auto r6 = new RobotPart(); r6->id = 6; robotparts.push_back(r6);
  }

  void TearDown(){
	  for(auto train : trains) delete train;
	  trains.clear();
	  for(auto rp : robotparts) delete rp;
	  robotparts.clear();
  }

  // Objects declared here can be used by all tests in the test case for NearByUpdaterTest.
	ModelRoot modelRoot;
	std::list<Train*> trains;
	std::list<RobotPart*> robotparts;
	double robotX, robotY, robotZ, trainX, trainY, trainZ;
};