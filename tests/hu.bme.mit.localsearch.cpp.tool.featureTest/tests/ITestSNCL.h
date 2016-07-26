// **************************************
//
// COPY ME NEXT TO GENERATED MAKEFILE
//
// **************************************
#include "gtest/gtest.h"
#include "Arch/arch_def.h"
#include "ArchIndex.h"
#include "Viatra/Query/QueryEngine.h"

#include "Viatra/Query/Query_clos/LinkedMatcher.h"
#include "Viatra/Query/Query_clos/PconnectedMatcher.h"
#include "Viatra/Query/Query_clos/PconnectedMatch.h"

/**
 * @author Krisztian Toth
 */

 using namespace ::Viatra::Query;
 using namespace ::Viatra::Query::Query_clos;

class ITestSNCL : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  ITestSNCL() = default;

  virtual ~ITestSNCL() = default;

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() = 0;

  virtual void TearDown() = 0;

  // Objects declared here can be used by all tests in the test case for SNCLGenCpp.
  int numOfLinks;
  int numOfRingMembers;
  std::list<::arch::SN*> snStore;
  std::list<::arch::CL*> clStore;
  std::unordered_set<PconnectedMatch> notConnectedSet;
  ::arch::SN* modelroot = nullptr;
  ::arch::SN* deletableSN = nullptr;
  ::arch::CL* deletableCL = nullptr;
};
