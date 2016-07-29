// **************************************
//
// COPY ME NEXT TO GENERATED MAKEFILE
//
// **************************************
#include "gtest/gtest.h"
#include "SNCLRuntimeTest.h"
#include "SNCLIteratorTest.h"
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
namespace Iterator {
 /*
  * Simple Test for uninitialized modell
  * Here the framework sets up the common environmet.
  */
  TEST_F(SNCLIteratorTest, EmptyInstances){
    TearDown();
    auto linkedMatches = linkedMatcher.matches();
    ASSERT_EQ(linkedMatches.size(), 0);
    auto pconnectedMatches = pconnectedMatcher.matches();
    ASSERT_EQ(pconnectedMatches.size(), 0);
  }

 /*
  *

  TEST_F(SNCLIteratorTest, isolatedUnboundTest){
    auto matches = isolatedMatcher.matches();
    if(matches.size() != 0) FAIL() << "Isolated matcher found invalid match: " << matches.begin()->C1->name;
    ::arch::CL* forDelete = nullptr;
    for(auto cl : clStore){
      if(cl->name == "C5") forDelete = cl;
    }
    clStore.remove(forDelete);
    delete deletableCL;
    matches = isolatedMatcher.matches();
    if(matches.size() == 0) FAIL() << "Isolated match didn't found the C5 Node.";
    if(matches.size() > 1) FAIL() << "Isolated matcher found more matches than expceted";
    ASSERT_EQ(matches.begin()->C1->name, "C6");
  }
*/
 /* Test that the LinkedMatcher found all matches and checks that really linked one to the other.
  * First checks that the number of matches is correct.
  * Secondly checks the validity of matches.
  * Thirdly checks that the numbor of SNs in the ring is correct.
  */
  TEST_F(SNCLIteratorTest, linkedQueryUnboundTest) {
    std::unordered_set<::std::string> checkList; //Stores the members of the queried match's SN's names.
    auto matches = linkedMatcher.matches();
    ASSERT_EQ(numOfLinks,matches.size());
    for(auto m : matches){
      checkList.insert(m.S1->name);
      checkList.insert(m.S2->name);
      if(!SNCLIteratorTest::validMatch(m)) FAIL() << "Unbound LinkedQuery found an invalid match: " << m.S1->name << "-" << m.S2->name;
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
  TEST_F(SNCLIteratorTest, linkedQuerySimpleBoundTest) {
    for(auto sn : snStore){
      auto matches = linkedMatcher.matches(sn);
      if(sn->name != "S5"){
        ASSERT_EQ(2,matches.size());
        for(auto m : matches){
          if(!SNCLIteratorTest::validMatch(m)) FAIL() << "Bound LinkedQuery found an invalid match: " << m.S1->name << "-" << m.S2->name;
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
TEST_F(SNCLIteratorTest, linkedQueryDoubleBoundTest) {
    for(auto s1 : snStore){
      for(auto s2 : snStore){
        auto matches = linkedMatcher.matches(s1,s2);
        if(matches.size() > 0)
          for(auto m : matches){
            if(!SNCLIteratorTest::validMatch(m)) FAIL() << "Bound LinkedQuery found an invalid match: " << m.S1->name << "-" << m.S2->name;
          }
        else{
          Sncl_iterator::LinkedMatch m1;
          m1.S1 = s1;
          m1.S2 = s2;
          if(SNCLIteratorTest::validMatch(m1)) FAIL() << "Query didn't find a match: "<< m1.S1->name << "-" << m1.S2->name;
        }
      }
    }
  }
 /*
  * Testing for pconnected functionality.
  * It generates every combination of CL's, then filters the predefined combinations.
  * After filtering theoretically the queried and filtered set contains the same elements.
  */
  TEST_F(SNCLIteratorTest, pconnectedUnboundTest){
    //Generate combinations
    std::unordered_set<Sncl_iterator::PconnectedMatch> combinationOfCls;
    for(auto c1 : clStore){
      for(auto c2 : clStore){
        Sncl_iterator::PconnectedMatch m; m.C1 = c1; m.C2 = c2;
        combinationOfCls.insert(m);
      }
    }
    //Filtering
    auto queriedMatches = pconnectedMatcher.matches();
    for(auto notConnectedMatch: notConnectedSet){
      auto it = combinationOfCls.find(notConnectedMatch);
      ASSERT_NE(it,combinationOfCls.end());
      combinationOfCls.erase(it);
      it = queriedMatches.find(notConnectedMatch);
      if(it != queriedMatches.end()) FAIL() << "Query found a match, that doesn't fit: " << it->C1->name << "-" << it->C2->name << std::endl;
    }
    //Check equality
    for(auto match : combinationOfCls){
      auto it = queriedMatches.find(match);
      if(it == queriedMatches.end()) FAIL() << "Query didn't find a match: " << match.C1->name << "-" << match.C2->name << std::endl;
    }
  }

 /*
  * Testing hot deletation of a Node.
  * After deletation, if the query return the match which
  * was connected through the deleted Node, that is inappropriate.
  * Q: Is it the users responsibility to delete an object properly?
  * A: Yes
  */
  TEST_F(SNCLIteratorTest,runtimeDeleteSN){
    std::string deletedName = deletableSN->name;
    snStore.remove(deletableSN);
    for(auto sn : snStore)
      for(auto it = sn->link.begin(); it != sn->link.end();++it)
        if(*it == deletableSN) sn->link.erase(it);
    for(auto cl : clStore)
      if(cl->cnn == deletableSN) cl->cnn = nullptr;
    delete deletableSN;
    try{
      auto queriedMatches = pconnectedMatcher.matches();
      for(auto match : queriedMatches){
        if(match.C1->name == "C5" && match.C2->name == "C6") FAIL() << "Not properly handled one SN's delete. SN.name = " << deletedName;
        if(match.C1->name == "C6" && match.C2->name == "C5") FAIL() << "Not properly handled one SN's delete. SN.name = " << deletedName;
      }
    }catch(...){
      FAIL() << "Unhandled exception";
    }
  }

 /*
  * Test in beta phase
  * Q: Is it the users responsibility to delete an object properly?
  * A: Yes
  */
  TEST_F(SNCLIteratorTest, runtimeDeleteCL){
    std::string deletedName = deletableCL->name;
    clStore.remove(deletableCL);
    delete deletableCL;
    try{
      auto queriedMatches = pconnectedMatcher.matches();
      for(auto match : queriedMatches){
        if(match.C1->name == "C2" || match.C2->name == "C2") FAIL() << "Not properly handled one CN's delete. CN.name = " << deletedName;
      }
    }catch(...){
      FAIL() << "Unhandled exception";
    }
  }
 /*
  * neg find test
  * CL not connected to any SN

  TEST_F(SNCLIteratorTest,runtimeCnnChangeToNullPTR){
    //deletableCL
  }
*/
}

namespace Runtime {
 /*
  * Simple Test for uninitialized modell
  * Here the framework sets up the common environmet.
  */
  TEST_F(SNCLRuntimeTest, EmptyInstances){
    TearDown();
    auto linkedMatches = linkedMatcher.matches();
    ASSERT_EQ(linkedMatches.size(), 0);
    auto pconnectedMatches = pconnectedMatcher.matches();
    ASSERT_EQ(pconnectedMatches.size(), 0);
  }

 /*
  *

  TEST_F(SNCLRuntimeTest, isolatedUnboundTest){
    auto matches = isolatedMatcher.matches();
    if(matches.size() != 0) FAIL() << "Isolated matcher found invalid match: " << matches.begin()->C1->name;
    ::arch::CL* forDelete = nullptr;
    for(auto cl : clStore){
      if(cl->name == "C5") forDelete = cl;
    }
    clStore.remove(forDelete);
    delete deletableCL;
    matches = isolatedMatcher.matches();
    if(matches.size() == 0) FAIL() << "Isolated match didn't found the C5 Node.";
    if(matches.size() > 1) FAIL() << "Isolated matcher found more matches than expceted";
    ASSERT_EQ(matches.begin()->C1->name, "C6");
  }
*/
 /* Test that the LinkedMatcher found all matches and checks that really linked one to the other.
  * First checks that the number of matches is correct.
  * Secondly checks the validity of matches.
  * Thirdly checks that the numbor of SNs in the ring is correct.
  */
  TEST_F(SNCLRuntimeTest, linkedQueryUnboundTest) {
    std::unordered_set<::std::string> checkList; //Stores the members of the queried match's SN's names.
    auto matches = linkedMatcher.matches();
    ASSERT_EQ(numOfLinks,matches.size());
    for(auto m : matches){
      checkList.insert(m.S1->name);
      checkList.insert(m.S2->name);
      if(!SNCLRuntimeTest::validMatch(m)) FAIL() << "Unbound LinkedQuery found an invalid match: " << m.S1->name << "-" << m.S2->name;
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
  TEST_F(SNCLRuntimeTest, linkedQuerySimpleBoundTest) {
    for(auto sn : snStore){
      auto matches = linkedMatcher.matches(sn);
      if(sn->name != "S5"){
        ASSERT_EQ(2,matches.size());
        for(auto m : matches){
          if(!SNCLRuntimeTest::validMatch(m)) FAIL() << "Bound LinkedQuery found an invalid match: " << m.S1->name << "-" << m.S2->name;
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
TEST_F(SNCLRuntimeTest, linkedQueryDoubleBoundTest) {
    for(auto s1 : snStore){
      for(auto s2 : snStore){
        auto matches = linkedMatcher.matches(s1,s2);
        if(matches.size() > 0)
          for(auto m : matches){
            if(!SNCLRuntimeTest::validMatch(m)) FAIL() << "Bound LinkedQuery found an invalid match: " << m.S1->name << "-" << m.S2->name;
          }
        else{
          Sncl_runtime::LinkedMatch m1;
          m1.S1 = s1;
          m1.S2 = s2;
          if(SNCLRuntimeTest::validMatch(m1)) FAIL() << "Query didn't find a match: "<< m1.S1->name << "-" << m1.S2->name;
        }
      }
    }
  }
 /*
  * Testing for pconnected functionality.
  * It generates every combination of CL's, then filters the predefined combinations.
  * After filtering theoretically the queried and filtered set contains the same elements.
  */
  TEST_F(SNCLRuntimeTest, pconnectedUnboundTest){
    //Generate combinations
    std::unordered_set<Sncl_runtime::PconnectedMatch> combinationOfCls;
    for(auto c1 : clStore){
      for(auto c2 : clStore){
        Sncl_runtime::PconnectedMatch m; m.C1 = c1; m.C2 = c2;
        combinationOfCls.insert(m);
      }
    }
    //Filtering
    auto queriedMatches = pconnectedMatcher.matches();
    for(auto notConnectedMatch: notConnectedSet){
      auto it = combinationOfCls.find(notConnectedMatch);
      ASSERT_NE(it,combinationOfCls.end());
      combinationOfCls.erase(it);
      it = queriedMatches.find(notConnectedMatch);
      //ASSERT_EQ(it, queriedMatches.end());(
      if(it != queriedMatches.end()) FAIL() << "Query found a match, that doesn't fit: " << it->C1->name << "-" << it->C2->name << std::endl;
    }
    //Check equality
    for(auto match : combinationOfCls){
      auto it = queriedMatches.find(match);
      if(it == queriedMatches.end()) FAIL() << "Query didn't find a match: " << match.C1->name << "-" << match.C2->name << std::endl;
    }
  }

 /*
  * Testing hot deletation of a Node.
  * After deletation, if the query return the match which
  * was connected through the deleted Node, that is inappropriate.
  * Q: Is it the users responsibility to delete an object properly?
  * A: Yes
  */
  TEST_F(SNCLRuntimeTest,runtimeDeleteSN){
    std::string deletedName = deletableSN->name;
    snStore.remove(deletableSN);
    for(auto sn : snStore)
      for(auto it = sn->link.begin(); it != sn->link.end();++it)
        if(*it == deletableSN) sn->link.erase(it);
    for(auto cl : clStore)
      if(cl->cnn == deletableSN) cl->cnn = nullptr;
    delete deletableSN;
    try{
      auto queriedMatches = pconnectedMatcher.matches();
      for(auto match : queriedMatches){
        if(match.C1->name == "C5" && match.C2->name == "C6") FAIL() << "Not properly handled one SN's delete. SN.name = " << deletedName;
        if(match.C1->name == "C6" && match.C2->name == "C5") FAIL() << "Not properly handled one SN's delete. SN.name = " << deletedName;
      }
    }catch(...){
      FAIL() << "Unhandled exception";
    }
  }

 /*
  * Test in beta phase
  * Q: Is it the users responsibility to delete an object properly?
  * A: Yes
  */
  TEST_F(SNCLRuntimeTest, runtimeDeleteCL){
    std::string deletedName = deletableCL->name;
    clStore.remove(deletableCL);
    delete deletableCL;
    try{
      auto queriedMatches = pconnectedMatcher.matches();
      for(auto match : queriedMatches){
        if(match.C1->name == "C2" || match.C2->name == "C2") FAIL() << "Not properly handled one CN's delete. CN.name = " << deletedName;
      }
    }catch(...){
      FAIL() << "Unhandled exception";
    }
  }
 /*
  * neg find test
  * CL not connected to any SN

  TEST_F(SNCLRuntimeTest,runtimeCnnChangeToNullPTR){
    //deletableCL
  }
*/
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
