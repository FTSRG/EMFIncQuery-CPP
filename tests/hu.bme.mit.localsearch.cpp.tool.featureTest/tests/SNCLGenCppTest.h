// **************************************
//
// COPY ME NEXT TO GENERATED MAKEFILE
//
// **************************************
//Source: https://github.com/google/googletest/blob/master/googletest/docs/Documentation.md
//You need to compile with -lgtest

#include "ITestSNCL.h"

using namespace ::Viatra::Query;
using namespace ::Viatra::Query::Query_clos;

// The fixture for testing class SNCLGenCpp.
class SNCLGenCppTest: public ITestSNCL {
  // You can remove any or all of the following functions if its body
  // is empty.
public:
  QueryEngine<::arch::SN> engine = QueryEngine<::arch::SN>::empty();
  LinkedQuerySpecification<::arch::SN>::Matcher linkedMatcher
        = engine.matcher<LinkedQuerySpecification>();
  PconnectedQuerySpecification<::arch::SN>::Matcher pconnectedMatcher
        = engine.matcher<PconnectedQuerySpecification>();

  SNCLGenCppTest() {
    // You can do set-up work for each test here.
  }

  virtual ~SNCLGenCppTest() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  static bool validMatch(LinkedMatch match){
    for(auto node : match.S1->link){
      if(node == match.S2) return true;
    }
    for(auto node : match.S2->link){
      if(node == match.S1) return true;
    }
    return false;
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:
protected:
  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).

    //The objects below have another storage.
    //arch::Node:_instances, collection: std::list<...>
    //arch::CL::_instances, collection: std::list<...>
    auto c1 = new ::arch::CL(); c1->name = "C1"; clStore.push_back(c1);
  	auto c2 = new ::arch::CL(); c2->name = "C2"; clStore.push_back(c2);
  	auto c3 = new ::arch::CL(); c3->name = "C3"; clStore.push_back(c3);
  	auto c4 = new ::arch::CL(); c4->name = "C4"; clStore.push_back(c4);
  	auto c5 = new ::arch::CL(); c5->name = "C5"; clStore.push_back(c5);
  	auto c6 = new ::arch::CL(); c6->name = "C6"; clStore.push_back(c6);

    //arch::SN::_instances, collection: std::list<...>
    auto s1 = new ::arch::SN(); s1->name = "S1"; snStore.push_back(s1);
    auto s2 = new ::arch::SN(); s2->name = "S2"; snStore.push_back(s2);
  	auto s3 = new ::arch::SN(); s3->name = "S3"; snStore.push_back(s3);
  	auto s4 = new ::arch::SN(); s4->name = "S4"; snStore.push_back(s4);
  	auto s5 = new ::arch::SN(); s5->name = "S5"; snStore.push_back(s5);

    //Setting up a ring with four SN and an isolated island.
  	s1->link.push_back(s2);
  	s2->link.push_back(s3);
  	s4->link.push_back(s3);
  	s4->link.push_back(s1);
  	s1->link.push_back(s4);
    numOfLinks = 8; // e.g. S1--link--S2 counts two times, once inorder and once traversal
    numOfRingMembers = 4; // number of SNs which connected via link association

    //Set references between objects
    c1->cnn=s1; c2->cnn=s2; c3->cnn=s3; c4->cnn=s4;
  	c5->cnn=s5; c6->cnn=s5;

    //The root object and choosed objects for testing
    modelroot = s2;
    deletableSN = s5;
    deletableCL = c2;

    PconnectedMatch m;
    m.C1 = c1; m.C2 = c5; notConnectedSet.insert(m);  //C1-C5
    m.C2 = c6; notConnectedSet.insert(m);             //C1-C6
    m.C1 = c2; notConnectedSet.insert(m);             //C2-C6
    m.C2 = c5; notConnectedSet.insert(m);             //C2-C5
    m.C1 = c3; notConnectedSet.insert(m);             //C3-C5
    m.C2 = c6; notConnectedSet.insert(m);             //C3-C6
    m.C1 = c4; notConnectedSet.insert(m);             //C4-C6
    m.C2 = c5; notConnectedSet.insert(m);             //C4-C5
    m.C1 = c6; m.C2 = c1; notConnectedSet.insert(m);  //C6-C1
    m.C1 = c5; notConnectedSet.insert(m);             //C5-C1
    m.C2 = c2; notConnectedSet.insert(m);             //C5-C2
    m.C1 = c6; notConnectedSet.insert(m);             //C6-C2
    m.C2 = c3; notConnectedSet.insert(m);             //C6-C3
    m.C1 = c5; notConnectedSet.insert(m);             //C5-C3
    m.C2 = c4; notConnectedSet.insert(m);             //C5-C4
    m.C1 = c6; notConnectedSet.insert(m);             //C6-C4
   }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
    numOfLinks = 0;
    numOfRingMembers = 0;
    modelroot = nullptr;
    for(auto cl : clStore){
      delete cl;
    }
    clStore.clear();
    for(auto sn : snStore){
      delete sn;
    }
    snStore.clear();
  }
};
