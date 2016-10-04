// **************************************
//
// COPY ME NEXT TO GENERATED MAKEFILE
//
// **************************************
#pragma once
#include <unordered_set>
#include "gtest/gtest.h"

#include "Arch/arch_def.h"
#include "Arch/ModelRoot.h"

/**
 * @author Krisztian Toth
 */

 using namespace ::Viatra::Query;

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
  std::list<::arch::ISN*> snStore;
  std::list<::arch::ICL*> clStore;
  ::arch::ISN* deletableSN = nullptr;
  ::arch::ICL* deletableCL = nullptr;

  Model::ModelRoot modelRoot;
};
