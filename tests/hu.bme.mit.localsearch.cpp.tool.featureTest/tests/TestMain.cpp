// **************************************
//
// COPY ME NEXT TO GENERATED MAKEFILE
//
// **************************************
#include "gtest/gtest.h"
#include "SNCLGenCppTest.h"
/**
 * @author Krisztian Toth
 */
/*
 * Unit testing for generated code from queries below.
 * package hu.bme.mit.localsearch.cpp.tool.featuretest.query
 * import "http://arch.ecore/model"
 * @Bind(parameters={S1})
 * pattern linked(S1,S2){SN(S1);	SN(S2);SN.link(S1,S2);} or
 * {SN(S1); SN(S2); SN.link(S2,S1);}
 *
 * pattern pconnected(C1,C2){SN(S1);	CL.cnn(C1,S1); CL.cnn(C2,S1);} or
 * {	CL.cnn(C1,S1); CL.cnn(C2,S2); find linked+(S1,S2);}
 */
namespace {

 /* Test that the LinkedMatcher found all matches and checks that really linked one to the other.
  * First checks that the number of matches is correct.
  * Secondly checks the validity of matches.
  * Thirdly checks that the numbor of SNs in the ring is correct.
  */
  TEST_F(SNCLGenCppTest, linkedQueryUnboundTest) {
    std::unordered_set<::std::string> checkList; //Stores the members of the queried match's SN's names.
    auto matches = linkedMatcher.matches();
    ASSERT_EQ(numOfLinks,matches.size());
    for(auto m : matches){
      checkList.insert(m.S1->name);
      checkList.insert(m.S2->name);
      if(!SNCLGenCppTest::validMatch(m)) FAIL() << "Unbound LinkedQuery found an invalid match: "
        << m.S1->name << "-" << m.S2->name;
    }
    int i = 0;
    for(auto name : checkList) i++;
    ASSERT_EQ(numOfRingMembers, checkList.size());
  }

 /*
  * Testing matcher function with one parameter, signature matches(::arch::SN* S1).
  * It iterates over the SN instances and query the linked SN's.
  * Checks the cardinality of linked SN's and checks the validity of found match.
  */
  TEST_F(SNCLGenCppTest, linkedQuerySimpleBoundTest) {
    for(auto sn : snStore){
      auto matches = linkedMatcher.matches(sn);
      if(sn->name != "S5"){
        ASSERT_EQ(2,matches.size());
        for(auto m : matches){
          if(!SNCLGenCppTest::validMatch(m)) FAIL() << "Bound LinkedQuery found an invalid match: "
            << m.S1->name << "-" << m.S2->name;
        }
      }
      else{
        ASSERT_EQ(0,matches.size());
      }
    }
  }

 /*
  * Testing matcher function with two parameter, signature matches(::arch::SN* S1, ::arch::SN* S2).
  * It checks every SN with every SN (cartesian product).
  * If the matcher finds connection, then checks it.
  * If the matcher finds no connection, then checks it.
  */
TEST_F(SNCLGenCppTest, linkedQueryDoubleBoundTest) {
    for(auto s1 : snStore){
      for(auto s2 : snStore){
        auto matches = linkedMatcher.matches(s1,s2);
        if(matches.size() > 0)
          for(auto m : matches){
            if(!SNCLGenCppTest::validMatch(m)) FAIL() << "Bound LinkedQuery found an invalid match: "
              << m.S1->name << "-" << m.S2->name;
          }
        else{
          LinkedMatch m1;
          m1.S1 = s1;
          m1.S2 = s2;
          if(SNCLGenCppTest::validMatch(m1)) FAIL() << "Query didn't find a match: "
            << m1.S1->name << "-" << m1.S2->name;
        }
      }
    }
  }
 /*
  * Testing for pconnected functionality.
  * It generates every combination of CL's, then filters the predefined combinations.
  * After filtering theoretically the queried and filtered set contains the same elements.
  */
  TEST_F(SNCLGenCppTest, pconnectedUnboundTest){
    auto queriedMatches = pconnectedMatcher.matches();
    std::unordered_set<PconnectedMatch> clMatches;
    for(auto c1 : clStore){
      for(auto c2 : clStore){
        PconnectedMatch m; m.C1 = c1; m.C2 = c2;
        clMatches.insert(m);
      }
    }
    for(auto notConnectedMatch: notConnectedSet){
      auto it = clMatches.find(notConnectedMatch);
      ASSERT_NE(it,clMatches.end());
      clMatches.erase(it);
      it = queriedMatches.find(notConnectedMatch);
      ASSERT_EQ(it, queriedMatches.end());
    }
    for(auto match : clMatches){
      auto it = queriedMatches.find(match);
      if(it == queriedMatches.end()) FAIL() << "Query didn't find a match: "
        << match.C1->name << "-" << match.C2->name << std::endl;
    }
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
