#include "gtest/gtest.h"
#include "Arch/arch_def.h"
#include "ArchIndex.h"
#include "Viatra/Query/QueryEngine.h"

#include "Viatra/Query/Query_clos/PconnectedMatcher.h"

namespace {

// The fixture for testing class SNCLGenCpp.
class SNCLGenCppTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  SNCLGenCppTest() {
    // You can do set-up work for each test here.
  }

  virtual ~SNCLGenCppTest() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).

    //The objects below have another storage.
    //arch::Node:_instances, collection: std::list<...>
    //arch::CL::_instances, collection: std::list<...>
    auto c1 = new arch::CL(); c1->name = "C1"; clStore.push_back(c1);
  	auto c2 = new arch::CL(); c2->name = "C2"; clStore.push_back(c2);
  	auto c3 = new arch::CL(); c3->name = "C3"; clStore.push_back(c3);
  	auto c4 = new arch::CL(); c4->name = "C4"; clStore.push_back(c4);
  	auto c5 = new arch::CL(); c5->name = "C5"; clStore.push_back(c5);
  	auto c6 = new arch::CL(); c6->name = "C6"; clStore.push_back(c6);

    //arch::SN::_instances, collection: std::list<...>
    auto s1 = new arch::SN(); s1->name = "S1"; snStore.push_back(s1);
    auto s2 = new arch::SN(); s2->name = "S2"; snStore.push_back(s2);
  	auto s3 = new arch::SN(); s3->name = "S3"; snStore.push_back(s3);
  	auto s4 = new arch::SN(); s4->name = "S4"; snStore.push_back(s4);
  	auto s5 = new arch::SN(); s5->name = "S5"; snStore.push_back(s5);

    //Setting up a ring with four SN and an isolated island.
  	s1->link.push_back(s2);
  	s2->link.push_back(s3);
  	s4->link.push_back(s3);
  	s4->link.push_back(s1);
  	s1->link.push_back(s4);
    numOfLinks = 8; // e.g. S1--link--S2 counts two times, once inorder and traversal
    numOfRingMembers = 4; // number of SNs which connected via link association

    c1->cnn=s1; c2->cnn=s2; c3->cnn=s3; c4->cnn=s4;
  	c5->cnn=s5; c6->cnn=s5;

    engine = ::Viatra::Query::QueryEngine<::arch::SN>::of(s1);
    matcher = engine.matcher<::Viatra::Query::Query_clos::PconnectedQuerySpecification>();
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
    for(auto cl : clStore){
      delete cl;
    }
    clStore.clear();
    for(auto sn : snStore){
      delete sn;
    }
    snStore.clear();
  }

  // Objects declared here can be used by all tests in the test case for SNCLGenCpp.
  std::list<::arch::SN> snStore;
  std::list<::arch::CL> clStore;
  QueryEngine<::arch::SN> engine;
  QuerySpecification<::arch::SN>::Matcher matcher;

  int numOfLinks;
  int numOfRingMembers;
};

bool valid(::Viatra::Query::Query_clos::LinkedMatch match){
  for(auto node : match.S1->link){
    if(node == S2) return true;
  }
  for(auto node : match.S2->link){
    if(node == S1) return true;
  }
  return false;
}

// Tests that the LinkedMatcher found all matches and checks that really linked one to the other.
//
TEST_F(SNCLGenCppTest, LinkedQueryTest) {
  //Stores the members of the queried match's SNs.
  std::unordered_set<::arch::Node> checkList;
  auto matches = matcher.matches();
  ASSERT_EQ(numOfLinks,matches.size());
  for(auto m : matches){
    checkList.push_back(m.S1);
    checkList.push_back(m.S2);
    if(!valid(m)) FAIL() << "LinkedQuery found an incorrect match: " << m.S1->name << "-" << m.S2->name;
  }
  ASSERT_EQ(numOfRingMembers, checkList.size());
}

}

// Tests that SNCLGenCpp does Xyz.
TEST_F(SNCLGenCppTest, DoesXyz) {
  // Exercises the Xyz feature of SNCLGenCpp.
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
